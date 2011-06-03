#include "types.h"
#include <cut/2.6/cut.h>

void __CUT__OpType_to_str_test(void)
{
    const char *name = OpType_to_str(OpType_i);
    ASSERT(name != NULL, "Bad OpType.");
    ASSERT(name == "int", "Wrong one for int.");

    name = Opttype_to_str(OpType_c);
    ASSERT(name != NULL, "Bad OpType.");
    ASSERT(name == "char", "Wrong one for char.");
}
