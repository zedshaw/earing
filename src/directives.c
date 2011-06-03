#include "directives.h"
#include "grammar.h"
#include <assert.h>
#include <stdio.h>
#include <dlfcn.h>
#include "tst.h"
#include "util.h"
#include "module.h"
#include "error.h"
#include <gc/gc.h>
#include <gc/cord.h>
#include "list.h"


#define ARITY(d,n) assert(list_count(params) == (n) && "Directive " # d " takes " # n " parameter(s).")
#define ARITY_MIN(d,n) assert(list_count(params) >= (n) && "Directive " # d " takes at least " # n " parameter(s).")
#define REQUIRES(d,n,t) assert(TYPE((n),t) && "Directive " # d " takes an " # t " parameter.");


#define MAX_LIB_NAME 512

typedef struct Library {
    int len;
    char name[MAX_LIB_NAME];
    void *handle;
} Library;


/** Finds a FUNCTION that is in a library which has been loaded. */
void *Library_search(Module *state, Token *module, Token *name)
{
    Library *lib = tst_search(state->libraries, module->start, module->len);
    if(lib) {
        // found it try to find the method
        char fname[MAX_LIB_NAME];
        if(Token_copy(name, fname, MAX_LIB_NAME, TK_IDENT) == -1) {
            die(state, "Library file name %.*s is too long.", name->len, name->start);
            return NULL;
        }
        void *ptr = dlsym(lib->handle, fname);

        if(ptr) {
            return ptr;
        } else {
            die(state, "module %.*s, error loading library '%.*s': %s.", 
                    module->len, module->start, name->len, name->start, dlerror());
            return NULL;
        }
    } else {
        // not loaded yet, error
        return NULL;
    }
}

Library *Library_create(Module *state, Token *name)
{
    Library *lib = GC_MALLOC(sizeof(Library));
    lib->len = name->len;

    if(Token_copy(name, lib->name, MAX_LIB_NAME, TK_STR) == -1) {
        die(state, "Library name %.*s is too long.", name->len, name->start);
    }

    lib->handle = dlopen(lib->name, RTLD_NOW);

    if(!lib->handle) {
        die(state, "failed opening library %s: %s", lib->name, dlerror());
    }

    return lib;
}

void library_call(Module *state, array_t *params)
{
    ARITY(library_call, 2);
    REQUIRES(library, 0, STR);
    REQUIRES(library, 1, STR);

    Token *ident = ARG(0);
    Token *as = ARG(1);

    Library *lib = Library_create(state, ident);

    if(lib) {
        // came out alright, so now set the name in our list as the second parameter
        lib->len = Token_copy(as, lib->name, MAX_LIB_NAME, TK_STR);
        if(lib->len == -1) {
            die(state, "requested module name %.*s is too long, must be less than %d.",
                    as->len, as->start, MAX_LIB_NAME);
        }

        // store in the global library list
        state->libraries = tst_insert(state->libraries, lib->name, lib->len, lib);
    } else {
        exit(1);
    }
}


void code_size(Module *state, Parameters *params)
{
    ARITY(code_size, 1);
    REQUIRES(code_size, 0, INT);
    state->max_code_size = VALUE(0, int);
}

void leaf(Module *state, Parameters *params)
{
    ARITY(leaf, 0);
    state->current_is_leaf = 1;
}

void import(Module *state, array_t *params)
{
    size_t length = 0;
    CORD input = NULL;
    Module *target = NULL;
    char in_file[MAX_LIB_NAME];

    ARITY(import, 2);
    REQUIRES(import, 0, STR);
    REQUIRES(import, 1, STR);

    if(tst_search(state->imports, ARG(1)->data)) {
        // already loaded so just skip it
        return;
    }

    if(Token_copy(ARG(0), in_file, MAX_LIB_NAME, TK_STR) == -1) {
        die(state, "requested module name %s is too long, must be less than %d.",
                in_file, MAX_LIB_NAME);
    }

    input = mmap_file(in_file, &length);
    assert(input && "Failed to open the file you requested.");

    // compile the other file using the code size specified by the parent
    target = Module_create(in_file, state->max_code_size);

    // have to add it here to prevent recursive loads from going in a loop
    state->imports = tst_insert(state->imports, ARG(1)->start, ARG(1)->len, target);
    assert(state->imports && "Error importing into the parent namespace.");

    if(!Module_compile(target, input, length)) {
        die(target, "error parsing imported module %s.", in_file);
    }
}



void Module_register_default_directives(Module *state)
{
    Module_register_directive(state, "code_size", strlen("code_size"), code_size, NULL); 
    Module_register_directive(state, "import", strlen("import"), import, NULL); 
    Module_register_directive(state, "leaf", strlen("leaf"), leaf, NULL); 
    Module_register_directive(state, "library", strlen("library"), library_call, NULL);
}
