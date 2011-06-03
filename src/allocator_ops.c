/* these are included directly into src/ops.c */

#include "allocator.h"

int inst_size_of(Module *state, Token *type, array_t *params)
{
    if(type) {
        if(array_length(params) != 1)
            die(state, ":- sizeof requires 1 parameter for a type.");
    } else {
        if(array_length(params) != 2)
            die(state, ":- sizeof requires 2 parameters for data.");
    }
    
    return 1;
}

int inst_alloc(Module *state, Token *type, array_t *params) 
{
    if(array_length(params) != 2)
        die(state, ":- alloc requires 2 parameters.");
    if(type) die(state, ":- Operation alloc does not take a type.");

    int size = array_of(Token, params, 1)->value;

    jit_movi_i(array_of(Token, params, 0)->value, size);
    jit_prepare_i(1);
    jit_pusharg_p(array_of(Token, params, 0)->value);
    jit_finish(Allocator_malloc);
    jit_retval(array_of(Token, params, 0)->value);

    return 1;
}


int inst_realloc(Module *state, Token *type, array_t *params) 
{
    if(array_length(params) != 2)
        die(state, ":- realloc requires 2 parameters.");
    if(type) die(state, ":- Operation realloc does not take a type.");
    
    jit_movi_i(JIT_R0, array_of(Token, params, 1)->value);
    jit_prepare_i(2);
    jit_pusharg_i(JIT_R0);
    jit_pusharg_p(array_of(Token, params, 0)->value);

    jit_finish(Allocator_realloc);
    jit_retval(array_of(Token, params, 0)->value);

    return 1;
}


int inst_free(Module *state, Token *type, array_t *params) 
{
    if(array_length(params) != 1)
        die(state, ":- free requires 1 parameters.");
    if(type) die(state, ":- Operation free does not take a type.");

    jit_prepare_i(1);
    jit_pusharg_p(array_of(Token, params, 0)->value);
    jit_calli(Allocator_free);

    return 1;
}

int inst_collect(Module *state, Token *type, array_t *params) 
{
    if(array_length(params) != 0)
        die(state, ":- collect requires 0 parameters.");
    if(type) die(state, ":- Operation collect does not take a type.");
  
    jit_calli(Allocator_collect);

    return 1;
}
