#include <cut/2.6/cut.h>
#include "allocator.h"
#include <gc.h>

void __CUT_allocator_Bringup(void)
{
    GC_INIT();
}

void __CUT__Allocator_expression( void )
{
    Token alloc = {.value = 100L};

    Token *res = Allocator_expression(NULL, &alloc);
    ASSERT(res != NULL, "Failed to run allocator expression.");
    ASSERT(res->value, "Value wasn't set.");
}


void __CUT__Allocator_malloc(void)
{
    void *data = Allocator_malloc(100);
    ASSERT(data != NULL, "Failed to allocate.");
}


void __CUT__Allocator_realloc(void)
{
    void *data = Allocator_malloc(100);
    ASSERT(data != NULL, "Failed to allocate.");

    data = Allocator_realloc(data, 1000);
    ASSERT(data != NULL, "Failed to reallocate.");
}

void __CUT__Allocator_free(void)
{
    void *data = Allocator_malloc(100);
    Allocator_free(data);
}

void __CUT__Allocator_collect(void)
{
    Allocator_collect();

}
