#include "module.h"
#include "directives.h"
#include "grammar.h"
#include "error.h"
#include "array.h"
#include "hash.h"
#include <gc/gc.h>
#include <gc/cord.h>
#include <assert.h>


Function *Function_find(Module *state, CORD name)
{
    hnode_t *hn = hash_lookup(state->functions, name);
    return hn ? hnode_get(hn) : NULL;
}


void FunctionParam_create(Function *func, Token *ident, Token *type)
{
    FunctionParam *p = GC_MALLOC(sizeof(FunctionParam));
    assert(p && "Failed to allocate FunctionParam.");

    p->name = ident->data;
    p->type = type->value;
    
    array_add(func->params, p);
}


/* Returns a -1 when it doesn't find that parameter. */
int FunctionParam_index(Function *func, Token *ident)
{
    FunctionParam *param = NULL;
    size_t i = 0;

    for(i = 0; i < array_length(func->params); i++) {
        param = (CORD)array_at(func->params, i);
        if(CORD_cmp(param->name, ident->data) == 0) {
            return i;
        }
    }
    
    return -1;
}


Token *Function_resolve_param(Module *state, Function *func, Token *ident)
{
    if(!func) return ident;  // skip any processing if not in a function

    unsigned long value = (unsigned long)FunctionParam_index(func, ident);
    if(value != -1) {
        // it's a function parameter
        ident->value = value;
    } else {
        return NULL;
    }

    return ident;
}
