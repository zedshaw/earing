#include "error.h"
#include <stdarg.h>
#include <gc/cord.h>

static void print_location(Module *state)
{
    if(state) {
        printf("%s:%d: ", state->module_name, state->curline);
        if(state->current) {
            CORD_printf("in function %r, ", state->current->name);
        }
    }
}

void error(Module *state, const char *format, ...)
{
    va_list ap;
    va_start(ap, format);

    print_location(state);
    CORD_vprintf(format, ap);

    printf("\n");
}


void die(Module *state, const char *format, ...)
{
    va_list ap;
    va_start(ap, format);

    if(state) {
        print_location(state);
    }

    CORD_vprintf(format, ap);
    printf("\n");

    exit(1);
}
