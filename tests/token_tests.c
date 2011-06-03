#include <cut/2.6/cut.h>
#include "token.h"
#include "ops.h"
#include "grammar.h"
#include <gc.h>
#include <string.h>
#include <gc/cord.h>

void __CUT__Token_createBringup(void)
{
    GC_INIT();
}

void __CUT__Token_create( void )
{
    CORD data = CORD_from_char_star("100");
    Token *tk = Token_create(TK_INT, data, NULL);

    ASSERT(tk->id == TK_INT, "wrong id.");
    ASSERT(tk->value == 100, "wrong value.");

    tk = Token_create(TK_CHR, CORD_from_char_star("'A'"), NULL);
    ASSERT(tk->id == TK_CHR, "wrong id.");
    ASSERT(tk->value == 'A', "wrong value.");

    tk = Token_create(TK_FLOAT, CORD_from_char_star("1.1"), NULL);
    ASSERT(tk->id == TK_FLOAT, "wrong id.");
    ASSERT(tk->value <= 2.0f && tk->value >= 0.0f, "wrong value");

    tk = Token_create(TK_HEX, CORD_from_char_star("0xAE"), NULL);
    ASSERT(tk->id == TK_HEX, "wrong id.");
    ASSERT(tk->value == 0xAE, "wrong value");

    tk = Token_create(TK_REG, CORD_from_char_star("R0"), NULL);
    ASSERT(tk->id = TK_REG, "wrong id.");
    ASSERT(tk->value == 0, "wrong value.");
}


