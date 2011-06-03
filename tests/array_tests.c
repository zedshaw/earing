#include <cut/2.6/cut.h>
#include "array.h"
#include <gc.h>

#define ARRAY_BASE_SIZE 10

void __CUT__array_Bringup(void)
{
    GC_INIT();
}

void __CUT__array_create( void )
{
    array_t *ary = array_create(ARRAY_BASE_SIZE);

    ASSERT(ary != NULL, "Must create an array." );
    ASSERT(ary->size == ARRAY_BASE_SIZE, "Wrong size.");
    ASSERT(ary->end == 0, "End isn't at the beginning.");
    ASSERT(ary->data != NULL, "Data should be pointing somewhere.");
}


void __CUT__array_status(void)
{
    array_t *ary = array_create(ARRAY_BASE_SIZE);

    ASSERT(array_max(ary) == ARRAY_BASE_SIZE, "Wrong length.");
    ASSERT(!array_isfull(ary), "Should not be full.");
    ASSERT(array_isempty(ary), "Should be empty.");
    ASSERT(array_length(ary) == 0, "End should be right at 0.");
}


void __CUT__array_operations(void)
{
    array_t *ary = array_create(ARRAY_BASE_SIZE);
    int i = 0;
    size_t end = 0;

    end = array_add(ary, &i);
    ASSERT(end == 1, "array end should be 1.");
    ASSERT(!array_isempty(ary), "Array shouldn't be empty.");
    ASSERT(!array_isfull(ary), "Array shouldn't be full.");
    ASSERT(array_at(ary, 0) == &i, "Not the right value.");
    ASSERT(array_last(ary) == &i, "Not the right last.");

    void *ptr = array_pop(ary);
    ASSERT(array_isempty(ary), "Array should be empty.");
    ASSERT(ptr == &i, "Wrong value.");

    end = array_push(ary, &i);
    ASSERT(end == 1, "should be 1.");

    ary = array_create(1);
    end = array_push(ary, &i);
    ASSERT(array_isfull(ary), "Should be full.");
    ASSERT(!array_isempty(ary), "Should be empty.");
    ASSERT(array_at(ary, 0) == &i, "wrong value.");

    ptr = array_pop(ary);
    ASSERT(ptr == &i, "wrong value.");
    ASSERT(array_isempty(ary), "Should be empty.");
    ASSERT(array_pop(ary) == NULL, "pop should return NULL.");

    array_at(ary, 0) = (void *)4;
    ASSERT(array_at(ary, 0) == (void *)4, "Should be 4.");
    array_set(ary, 0, &i);
    ASSERT(array_at(ary, 0) == &i, "wrong value after set.");
}


void __CUT__array_extend(void)
{
    array_t *ary = array_create(1);
    int i = 0;

    array_add(ary, &i);
    ASSERT(array_isfull(ary), "Should be full.");

    ary = array_extend(ary, 1);
    ASSERT(!array_isfull(ary), "Should not be full.");

    array_add(ary, &i+1);
    ASSERT(array_isfull(ary), "Should be full.");

    ASSERT(array_pop(ary) == &i+1, "first pop wrong.");
    ASSERT(array_pop(ary) == &i, "second pop wrong.");

    ASSERT(!array_isfull(ary), "should not be full.");
    ASSERT(array_isempty(ary), "should be empty.");

    array_add(ary, &i);
    array_add(ary, &i+1);
    ary = array_extend(ary, 100);

    ASSERT(array_max(ary) == 102, "wrong length");
    ASSERT(array_length(ary) == 2, "wrong end.");
    ary = array_clamp(ary);

    ASSERT(array_max(ary) == 2, "wrong length after clamp.");
}


