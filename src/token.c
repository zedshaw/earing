#include "token.h"
#include <stdlib.h>
#include "grammar.h"
#include <assert.h>
#include <string.h>
#include <gc/gc.h>


Token *Token_create(int id, CORD data, f_inst_call call)
{
    Token *tk = GC_MALLOC(sizeof(Token)); 
    tk->id = id; 
    tk->data = data;
    tk->call = call;
    
    switch(id) {
        case TK_CHR:
             tk->value = (int)CORD_fetch(tk->data, 1);
             break;
        case TK_STR:
             tk->value = (unsigned long)CORD_to_char_star(tk->data);
             break;
        case TK_INT:
             tk->value = atoi(CORD_to_const_char_star(tk->data));
             break;
        case TK_FLOAT:
             tk->value = atof(CORD_to_const_char_star(tk->data));
             break;
        case TK_HEX:
             tk->value = (int)strtol(CORD_to_const_char_star(tk->data), NULL, 16);
             break;
        default:
             tk->value = 0;
    }

    return tk;
}

