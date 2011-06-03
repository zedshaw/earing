#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include "module.h"
#include "error.h"
#include <errno.h>
#include "list.h"

void run_function(Module *state, const char *named) 
{
    Function *func = NULL;

    func = tst_search(state->functions, named, strlen(named));

    if(!func) {
        printf("Undefined function: '%s'\n", named);
    } else {
        if(list_isempty(func->params)) {
            printf("Sorry, this function takes parameters so it's not supported to call it yet.\n");
            return;
        }

        switch(func->type) {
            case OpType_v:
                printf(">>\n"); func->fp.vptr(); break;
            case OpType_c:
                printf(">> %c\n", func->fp.cptr()); break;
            case OpType_uc:
                printf(">> %c\n", func->fp.ucptr()); break;
            case OpType_s:
                printf(">>  %i\n", func->fp.sptr()); break;
            case OpType_us:
                printf(">>  %i\n", func->fp.usptr()); break;
            case OpType_i:
                printf(">>  %d\n", func->fp.iptr()); break;
            case OpType_ui:
                printf(">>  %u\n", func->fp.uiptr()); break;
            case OpType_l:
                printf(">>  %ld\n", func->fp.lptr()); break;
            case OpType_ul:
                printf(">>  %lu\n", func->fp.ulptr()); break;
            case OpType_p:
                printf(">>  %p\n", func->fp.pptr()); break;
            case OpType_f:
                printf(">>  %f\n", func->fp.fptr()); break;
            case OpType_d:
                printf(">>  %f\n", func->fp.dptr()); break;
        }
    }
}

