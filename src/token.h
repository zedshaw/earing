#ifndef token_h
#define token_h

#include "array.h"
#include <gc/cord.h>

struct Module;
struct Token;

/** 
 * This is attached to operation tokens and is called later to do the actual byte code
 * generation.
 */
typedef int (*f_inst_call)(struct Module *state, struct Token *type, array_t *params);

/**
 * A Token holds almost all of the data, since an assembler is so simple
 * we can actually put the values inside the token.
 */
typedef struct Token {
    // all tokens have this
    int id;
    CORD data;

    // different tokens have these set mutually exclusive
    f_inst_call call;
    // lightning apparently does lots of casting, so we just need the biggest numeric for storage
    unsigned long value;
} Token;

Token *Token_create(int id, CORD data, f_inst_call call);

#define TK(I,C) (Token_create(I, CORD_from_char_star(te-ts,ts), C))
#define KW(T)  Parse(pParser, TK_##T, TK(TK_##T,0), state);
#define SYM(T)  Parse(pParser, TK_##T, TK(TK_##T,0), state);
#define IDENT() Parse(pParser, TK_IDENT, TK(TK_IDENT,0), state);
#define OP(T)  Parse(pParser, TK_OP, TK(TK_OP,inst_##T), state);
#define TYPE(T)  tk = TK(TK_TYPE,0); tk->value = OpType_##T; Parse(pParser, TK_TYPE, tk, state);
#define LABEL() Parse(pParser, TK_LABEL, TK(TK_LABEL,0), state);
#define NO_LEAF(name) if(state->current_is_leaf)\
        die(state, "You cannot do " # name " in a function declared %%leaf.");
#define REG(T)   tk = TK(TK_REG,0); tk->value = JIT_##T; Parse(pParser, TK_REG, tk, state);

#endif
