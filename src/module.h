#ifndef module_h
#define module_h

#include <stdio.h>
#include <string.h>
#include "tst.h"
#include "token.h"
#include <gc/cord.h>
#include "array.h"
#include "hash.h"
#include "types.h"
#include "function.h"

typedef struct Machine {
    tst_t *directives;
    tst_t *libraries;
    tst_t *modules;
} Machine;


typedef struct Module {
    CORD module_name;

    unsigned int curline;
    int errors;
    int current_is_leaf;  // kind of a hack, need something else
    Function *current;
    size_t max_code_size;

    hash_t *data;
    hash_t *imports;
    hash_t *libraries;
    hash_t *functions;
} Module;


typedef void(*Module_directive_cb)(Module *state, array_t *params);
typedef void(*Module_default_directives_cb)();

int Module_compile(Module *state, CORD source);

int Module_register_directive(Module *state, CORD name,
        Module_directive_cb call, Module_directive_cb destroy);

void Module_dump_directives(Module *state, FILE *out);
void Module_call_directive(Module *state, Token *ident, array_t *params);

Token *Module_resolve_function(Module *state, Token *module, Token *ident);
Token *Module_resolve_data(Module *state, Token *ident);
Token *Module_outside_function_data(Module *state, Token *func_ref, Token *ident);

Module *Module_resolve_module(Module *state, Token *ident);

Module *Module_create(const char *name, size_t max_code_size);

void Module_create_constant(Module *state, Token *ident, Token *expr);
void Module_create_function_constant(Module *state, Token *ident, Token *expr);

void Call_operation(Module *state, Function *func, Token *op, Token *type, array_t *params);

#endif


