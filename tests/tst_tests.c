#include <cut/2.6/cut.h>
#include "tst.h"
#include <gc.h>


void __CUT__tst_Bringup(void)
{
    GC_INIT();
}

void __CUT__tst_create(void)
{
    tst_t *t = NULL;
    void *result = NULL;
    void *result2 = NULL;
    int val = 10;
    tst_collect_t vals;

    t = tst_insert(t, "test", 4, &val);
    ASSERT(t != NULL, "Failed to create.");
    
    result = tst_search(t, "test", 4);
    ASSERT(result == &val, "Wrong value returned.");

    t = tst_insert(t, "testit", 6, &result);
    ASSERT(t != NULL, "Failed to add more.");
    result2 = tst_search(t, "testit", 6);
    ASSERT(result2 == &result, "Second result wasn't right.");

    vals = tst_collect(t, "te", 2);

    ASSERT(vals.length == 2, "Didn't find all of them on collect.");
    ASSERT(vals.values[1] == &val, "Wrong first value.");
    ASSERT(vals.values[0] == &result, "Wrong second value.");
}


