#include "allocator.h"
#include <gc/gc.h>
#include "error.h"


Token *Allocator_expression(Module *state, Token *tk)
{
    if(!tk) {
        die(state, ":- invalid identifier given to allocation");
        return NULL;
    } else {
        tk->value = (int)GC_MALLOC(tk->value);
        return tk;
    }
}


void *Allocator_malloc(int size)
{
    return GC_MALLOC(size);
}

void *Allocator_realloc(void *mem, int new_size)
{
    return GC_REALLOC(mem, new_size);
}

void Allocator_free(void *mem)
{
    GC_FREE(mem);
}

void Allocator_collect()
{
    GC_gcollect();
}
