#include <cut/2.6/cut.h>
#include "error.h"
#include <gc.h>

void __CUT_error_Bringup(void)
{
    GC_INIT();
}

void __CUT__error_test(void)
{
    CORD name = CORD_from_char_star("Zed A. Shaw");
    int tested = 10;

    error(NULL, "%d times I called %r", tested, name);
}
