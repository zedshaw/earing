#ifndef function_h
#define function_h

#include <lightning.h>
#include <gc/cord.h>
#include "types.h"
#include "array.h"
#include "hash.h"
#include "token.h"

struct Module;

typedef struct FunctionParam {
    int index;
    CORD name;
    OpType type;
} FunctionParam;

typedef struct Function {
    jit_insn *code;
    size_t code_len;
    jit_code fp;
    OpType type;
    CORD name;
    array_t *params;

    hash_t *data;
    hash_t *labels;
} Function;

Function *Function_create(struct Module *state, OpType type, CORD name, array_t *params);

Function *Function_find(struct Module *state, CORD name);

Function *Function_finalize(struct Module *state, Function *func, Token *end);

Token *Function_resolve_param(struct Module *state, Function *func, Token *ident);

void FunctionParam_create(Function *func, Token *ident, Token *type);

int FunctionParam_index(Function *func, Token *ident);


#endif
