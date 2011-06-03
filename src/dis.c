#include <udis86.h>
#include "module.h"
#include "sglib.h"


void dis_code_bytes(Function *func, ud_t *ud_obj)
{
    ud_set_input_buffer(ud_obj, func->code, func->code_len);
    printf("function %s(", func->name);

    int count;
    SGLIB_SORTED_LIST_MAP_ON_ELEMENTS(FunctionParam, func->params, i, next, {
        printf("%.*s : %s", i->len, i->name, OpType_to_str(i->type));
        if(count++ < func->nparams-1) printf(", ");
    });

    printf(") : %s\n", OpType_to_str(func->type));

    while(ud_disassemble(ud_obj)) {
        printf("\t%s\n", ud_insn_asm(ud_obj));
    }
    printf("end\n\n");
}

void dis_functions(Module *state)
{
    ud_t ud_obj;

    ud_init(&ud_obj);
    ud_set_mode(&ud_obj, 64);
    ud_set_syntax(&ud_obj, UD_SYN_INTEL);
    ud_set_vendor(&ud_obj, UD_VENDOR_AMD);

    tst_traverse(state->functions, (tst_traverse_cb)dis_code_bytes, &ud_obj);
}

