#ifndef label_h
#define label_h

#include "function.h"
#include <gc/cord.h>

typedef struct Label {
    jit_insn *ref;
    CORD name;
    int realized;
    array_t *back_refs;
} Label;


Label *Label_find_or_create(Function *func, Token *ident);

Token *Label_expression(Function *func, Token *tk);

void Label_statement(Function *func, Token *tk);

Label *Label_find(Function *func, Token *tk);

Label *Label_create_and_add(Function *func, Token *tk, int realized);

#endif
