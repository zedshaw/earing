#include "array.h"
#include <gc/gc.h>
#include <assert.h>


array_t *array_create(size_t size)
{
    array_t *ary = GC_MALLOC(sizeof(array_t) + size * sizeof(void *));
    ary->size = size;
    ary->end = 0;

    return ary;
}


size_t array_add(array_t *ary, void *el)
{
    assert(ary != NULL && "array_t can't be NULL.");
    assert(!array_isfull(ary) && "array_t is full.");
    assert(el != NULL && "can't put a NULL value in.");

    ary->data[ary->end] = el;
    ary->end++;

    return array_length(ary);
} 


void *array_pop(array_t *ary)
{
    assert(ary != NULL && "array_t can't be NULL.");

    if(ary->end == 0) {
        return NULL;
    } else {
        ary->end--;
        return ary->data[ary->end];
    }
}


array_t *array_extend(array_t *ary, size_t by)
{
    assert(ary != NULL && "array_t can't be NULL");
    assert(by != 0 && "can't extend by 0.");
    
    ary->size += by;

    ary = GC_REALLOC(ary, sizeof(array_t) + ary->size * sizeof(void *));

    return ary;
}


array_t *array_clamp(array_t *ary)
{
    assert(ary != NULL && "array_t can't be NULL");
    assert(!array_isempty(ary) && "can't clamp an empty array.");
   
    ary->size = ary->end;
    ary = GC_REALLOC(ary, sizeof(array_t) + ary->size * sizeof(void *));

    return ary;
}


