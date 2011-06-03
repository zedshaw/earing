#include "types.h"
#include <assert.h>


const char *OpType_strings[] = {
   "int", "uint", "long", "ulong",
   "ptr", "float", "double", "void",
   "char", "uchar", "short", "ushort"
};

const char *OpType_to_str(OpType type)
{
    assert(type >= 0 && type < 12 && "Invalid OpType_code");
    return OpType_strings[type];
}
