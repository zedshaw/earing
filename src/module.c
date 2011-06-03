#include "module.h"
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "directives.h"
#include "grammar.h"
#include <string.h>
#include "error.h"
#include <gc/gc.h>
#include <gc/cord.h>

Module *Module_create(const char *name, size_t max_code_size)
{
    Module *state = GC_MALLOC( sizeof(Module));
    assert(state && "Memory alloc failure for Module.");
    state->curline = 1;
    state->module_name = strdup(name);
    state->max_code_size = max_code_size;

    return state;
}

Module *Module_resolve_module(Module *state, Token *ident)
{
    if(CORD_cmp(ident->data, "self")) {
        return state;
    } else {
        return (Module *)tst_search(state->imports, ident->start, ident->len);
    }
}

Token *Module_resolve_function_data(Function *func, Token *ident)
{
    Token *expr = tst_search(func->data, ident->start, ident->len);
    if(expr) {
        *ident = *expr;  // copy it over reusing the ident
        return ident;
    } else {
        return NULL;
    }
}

Token *Module_outside_function_data(Module *state, Token *func_ref, Token *ident)
{
    Token *expr = NULL;
    Function *func = Function_find(state, func_ref->start, func_ref->len);

    if(func) expr = Module_resolve_function_data(func, ident);

    if(!expr) {
        die(state, "function %.*s doesn't have data named %.*s",
                func_ref->len, func_ref->start, ident->len, ident->start);
    }

    return expr;
}

Token *Module_resolve_data(Module *state, Token *ident)
{
    if(!state->current) {
        Token *expr = tst_search(state->data, ident->start, ident->len);
        if(expr) {
            return expr;
        } else {
            die(state, "failed to find %.*s module constant.", ident->len, ident->start);
            return NULL;
        }
    }

    Token *expr = Module_resolve_function_data(state->current, ident);

    if(expr) {
        return expr;
    } else {
        expr = Function_resolve_param(state, state->current, ident); 

        if(expr) {
            return expr;
        } else {
            // try to find it in the module
            expr = tst_search(state->data, ident->start, ident->len);

            if(expr) {
                *ident = *expr;
                return ident;
            } else {
                die(state, "failed to resolve %.*s, not a parameter or constant\n", 
                        ident->len, ident->start);
                return NULL;
            }
        }
    }
}

Token *Module_resolve_function(Module *state, Token *module, Token *ident)
{
    void *result = NULL;

    Module *mod = Module_resolve_module(state, module);
    if(mod) {
        Function *func = Function_find(mod, ident->start, ident->len);
        if(func) {
            result = func->code;
        }
    } else {
        result = Library_search(state, module, ident);
    }

    if(result != NULL) {
        // it's a function defined in this module
        ident->value = (unsigned long)result;
    } else {
        // it's not found so not a possible ident
        die(state, "did not find function %.*s in a library or module named %.*s.", 
                ident->len, ident->start,
                module->len, module->start);
    }

    return ident;
}

void Module_call_directive(Module *state, Token *ident, Parameters *params)
{
   Directive *to_call = (Directive *)tst_search(state->directives, ident->start, ident->len);

   if(to_call) {
       to_call->call(state, params);
   } else {
       die(state, "referenced directive %.*s which doesn't exist.", ident->len, ident->start);
   }
}

int Module_register_directive(Module *state, const char *name, int length, 
        Module_directive_cb call, Module_directive_cb destroy)
{
    Directive *d = GC_MALLOC(sizeof(Directive));
    assert(d && "Memory allocation failed for Directive.");
    
    if(tst_search(state->directives, name, length)) {
        die(state, "Directive %.*s already exists in the directive list.", length, name);
        return 0;
    } else {
        d->name = name;
        d->len = length;
        d->call = call;
        d->destroy = destroy;

        state->directives = tst_insert(state->directives, name, length, d);

        return 1;
    }
}

void Module_create_constant(Module *state, Token *ident, Token *expr)
{
    if(tst_search(state->data, ident->start, ident->len)) {
        die(state, "you already defined a constant named %.*s in this module.", 
                ident->len, ident->start);
    } else {
        state->data = tst_insert(state->data, ident->start, ident->len, expr);
        assert(state->data && "Unable to insert an element into the module data store.");

        if(expr->id == TK_STR) {
            // need to disconnect this from its actual source for reference later.
            expr->value = (unsigned long)strndup(expr->start, expr->len);
        }
    }
}

void Module_create_function_constant(Module *state, Token *ident, Token *expr)
{
    if(tst_search(state->current->data, ident->start, ident->len)) {
        die(state, "you already defined a function constant named %.*s", 
                ident->len, ident->start);
    } else {
        state->current->data = tst_insert(state->current->data, ident->start, ident->len, expr);
        assert(state->current->data && "Unable to insert an element into the module data store.");

        if(expr->id == TK_STR) {
            // need to disconnect this from its actual source for reference later.
            expr->value = (unsigned long)strndup(expr->start, expr->len);
        }
    }
}

void Module_dump_directives(Module *state, FILE *out)
{
    void dump(void *p, void *ignored) {
        Directive *d = p;
        fprintf(out, "directive: %.*s\n", d->len, d->name);
    }

    tst_traverse(state->directives, dump, NULL);
}

