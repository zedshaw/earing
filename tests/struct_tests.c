#include <cut/2.6/cut.h>
#include "struct.h"
#include <gc.h>
#include <stdio.h>


void __CUT__StructAlign_create( void )
{
    StructAlign sa = StructAlign_create();
    ASSERT(!StructAlign_indeterminate(sa), "Indeterminate structure alignment.");
    ASSERT(!StructAlign_multiple_cases(sa), "Mulitple possible cases for structure alignment.");
}



