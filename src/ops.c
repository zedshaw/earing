#include "module.h"
#include "allocator_ops.c"

int inst_addr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "addr requires 3 parameters.");
    if(!type)
        die(state, "addr requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_addr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_addr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_addr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_addr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_addr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_addr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_addr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation addr, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_addi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "addi requires 3 parameters.");
    if(!type)
        die(state, "addi requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_addi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_addi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_addi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_addi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_addi_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation addi, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_addxr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "addxr requires 3 parameters.");
    if(!type)
        die(state, "addxr requires type of: ['i', 'ui'].");

    switch(type->value) {
        
    case OpType_i:
        jit_addxr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_addxr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation addxr, only ['i', 'ui'] allowed.");
    }
    return 1;
}

int inst_addxi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "addxi requires 3 parameters.");
    if(!type)
        die(state, "addxi requires type of: ['i', 'ui'].");

    switch(type->value) {
        
    case OpType_i:
        jit_addxi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_addxi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation addxi, only ['i', 'ui'] allowed.");
    }
    return 1;
}

int inst_addcr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "addcr requires 3 parameters.");
    if(!type)
        die(state, "addcr requires type of: ['i', 'ui'].");

    switch(type->value) {
        
    case OpType_i:
        jit_addcr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_addcr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation addcr, only ['i', 'ui'] allowed.");
    }
    return 1;
}

int inst_addci(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "addci requires 3 parameters.");
    if(!type)
        die(state, "addci requires type of: ['i', 'ui'].");

    switch(type->value) {
        
    case OpType_i:
        jit_addci_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_addci_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation addci, only ['i', 'ui'] allowed.");
    }
    return 1;
}

int inst_subr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "subr requires 3 parameters.");
    if(!type)
        die(state, "subr requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_subr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_subr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_subr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_subr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_subr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_subr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_subr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation subr, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_subi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "subi requires 3 parameters.");
    if(!type)
        die(state, "subi requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_subi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_subi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_subi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_subi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_subi_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation subi, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_subxr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "subxr requires 3 parameters.");
    if(!type)
        die(state, "subxr requires type of: ['i', 'ui'].");

    switch(type->value) {
        
    case OpType_i:
        jit_subxr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_subxr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation subxr, only ['i', 'ui'] allowed.");
    }
    return 1;
}

int inst_subxi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "subxi requires 3 parameters.");
    if(!type)
        die(state, "subxi requires type of: ['i', 'ui'].");

    switch(type->value) {
        
    case OpType_i:
        jit_subxi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_subxi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation subxi, only ['i', 'ui'] allowed.");
    }
    return 1;
}

int inst_subcr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "subcr requires 3 parameters.");
    if(!type)
        die(state, "subcr requires type of: ['i', 'ui'].");

    switch(type->value) {
        
    case OpType_i:
        jit_subcr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_subcr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation subcr, only ['i', 'ui'] allowed.");
    }
    return 1;
}

int inst_subci(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "subci requires 3 parameters.");
    if(!type)
        die(state, "subci requires type of: ['i', 'ui'].");

    switch(type->value) {
        
    case OpType_i:
        jit_subci_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_subci_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation subci, only ['i', 'ui'] allowed.");
    }
    return 1;
}

int inst_rsbr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "rsbr requires 3 parameters.");
    if(!type)
        die(state, "rsbr requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_rsbr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_rsbr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_rsbr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_rsbr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_rsbr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_rsbr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_rsbr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation rsbr, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_rsbi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "rsbi requires 3 parameters.");
    if(!type)
        die(state, "rsbi requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_rsbi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_rsbi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_rsbi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_rsbi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_rsbi_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation rsbi, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_mulr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "mulr requires 3 parameters.");
    if(!type)
        die(state, "mulr requires type of: ['i', 'ui', 'l', 'ul', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_mulr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_mulr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_mulr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_mulr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_mulr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_mulr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation mulr, only ['i', 'ui', 'l', 'ul', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_muli(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "muli requires 3 parameters.");
    if(!type)
        die(state, "muli requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_muli_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_muli_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_muli_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_muli_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation muli, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_hmulr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "hmulr requires 3 parameters.");
    if(!type)
        die(state, "hmulr requires type of: ['i', 'ui'].");

    switch(type->value) {
        
    case OpType_i:
        jit_hmulr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_hmulr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation hmulr, only ['i', 'ui'] allowed.");
    }
    return 1;
}

int inst_hmuli(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "hmuli requires 3 parameters.");
    if(!type)
        die(state, "hmuli requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_hmuli_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_hmuli_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_hmuli_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_hmuli_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation hmuli, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_divr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "divr requires 3 parameters.");
    if(!type)
        die(state, "divr requires type of: ['i', 'ui', 'l', 'ul', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_divr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_divr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_divr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_divr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_divr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_divr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation divr, only ['i', 'ui', 'l', 'ul', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_divi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "divi requires 3 parameters.");
    if(!type)
        die(state, "divi requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_divi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_divi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_divi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_divi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation divi, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_modr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "modr requires 3 parameters.");
    if(!type)
        die(state, "modr requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_modr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_modr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_modr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_modr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation modr, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_modi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "modi requires 3 parameters.");
    if(!type)
        die(state, "modi requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_modi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_modi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_modi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_modi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation modi, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_andr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "andr requires 3 parameters.");
    if(!type)
        die(state, "andr requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_andr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_andr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_andr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_andr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation andr, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_andi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "andi requires 3 parameters.");
    if(!type)
        die(state, "andi requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_andi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_andi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_andi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_andi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation andi, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_orr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "orr requires 3 parameters.");
    if(!type)
        die(state, "orr requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_orr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_orr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_orr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_orr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation orr, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_ori(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ori requires 3 parameters.");
    if(!type)
        die(state, "ori requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_ori_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_ori_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_ori_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_ori_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ori, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_xorr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "xorr requires 3 parameters.");
    if(!type)
        die(state, "xorr requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_xorr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_xorr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_xorr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_xorr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation xorr, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_xori(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "xori requires 3 parameters.");
    if(!type)
        die(state, "xori requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_xori_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_xori_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_xori_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_xori_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation xori, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_lshr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "lshr requires 3 parameters.");
    if(!type)
        die(state, "lshr requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_lshr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_lshr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_lshr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_lshr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation lshr, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_lshi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "lshi requires 3 parameters.");
    if(!type)
        die(state, "lshi requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_lshi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_lshi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_lshi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_lshi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation lshi, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_rshr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "rshr requires 3 parameters.");
    if(!type)
        die(state, "rshr requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_rshr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_rshr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_rshr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_rshr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation rshr, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_rshi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "rshi requires 3 parameters.");
    if(!type)
        die(state, "rshi requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_rshi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_rshi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_rshi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_rshi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation rshi, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_negr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "negr requires 2 parameters.");
    if(!type)
        die(state, "negr requires type of: ['i', 'l'].");

    switch(type->value) {
        
    case OpType_i:
        jit_negr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_l:
        jit_negr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation negr, only ['i', 'l'] allowed.");
    }
    return 1;
}

int inst_notr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "notr requires 2 parameters.");
    if(!type)
        die(state, "notr requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_notr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_notr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_l:
        jit_notr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ul:
        jit_notr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation notr, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_ltr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ltr requires 3 parameters.");
    if(!type)
        die(state, "ltr requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_ltr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_ltr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_ltr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_ltr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_ltr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_ltr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_ltr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ltr, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_lti(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "lti requires 3 parameters.");
    if(!type)
        die(state, "lti requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_lti_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_lti_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_lti_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_lti_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_lti_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation lti, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_ler(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ler requires 3 parameters.");
    if(!type)
        die(state, "ler requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_ler_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_ler_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_ler_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_ler_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_ler_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_ler_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_ler_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ler, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_lei(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "lei requires 3 parameters.");
    if(!type)
        die(state, "lei requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_lei_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_lei_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_lei_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_lei_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_lei_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation lei, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_gtr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "gtr requires 3 parameters.");
    if(!type)
        die(state, "gtr requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_gtr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_gtr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_gtr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_gtr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_gtr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_gtr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_gtr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation gtr, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_gti(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "gti requires 3 parameters.");
    if(!type)
        die(state, "gti requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_gti_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_gti_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_gti_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_gti_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_gti_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation gti, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_ger(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ger requires 3 parameters.");
    if(!type)
        die(state, "ger requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_ger_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_ger_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_ger_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_ger_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_ger_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_ger_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_ger_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ger, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_gei(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "gei requires 3 parameters.");
    if(!type)
        die(state, "gei requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_gei_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_gei_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_gei_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_gei_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_gei_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation gei, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_eqr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "eqr requires 3 parameters.");
    if(!type)
        die(state, "eqr requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_eqr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_eqr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_eqr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_eqr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_eqr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_eqr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_eqr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation eqr, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_eqi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "eqi requires 3 parameters.");
    if(!type)
        die(state, "eqi requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_eqi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_eqi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_eqi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_eqi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_eqi_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation eqi, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_ner(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ner requires 3 parameters.");
    if(!type)
        die(state, "ner requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_ner_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_ner_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_ner_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_ner_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_ner_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_ner_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_ner_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ner, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_nei(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "nei requires 3 parameters.");
    if(!type)
        die(state, "nei requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_nei_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_nei_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_nei_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_nei_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_nei_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation nei, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_unltr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "unltr requires 3 parameters.");
    if(!type)
        die(state, "unltr requires type of: ['f', 'd'].");

    switch(type->value) {
        
    case OpType_f:
        jit_unltr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_unltr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation unltr, only ['f', 'd'] allowed.");
    }
    return 1;
}

int inst_unler(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "unler requires 3 parameters.");
    if(!type)
        die(state, "unler requires type of: ['f', 'd'].");

    switch(type->value) {
        
    case OpType_f:
        jit_unler_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_unler_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation unler, only ['f', 'd'] allowed.");
    }
    return 1;
}

int inst_ungtr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ungtr requires 3 parameters.");
    if(!type)
        die(state, "ungtr requires type of: ['f', 'd'].");

    switch(type->value) {
        
    case OpType_f:
        jit_ungtr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_ungtr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ungtr, only ['f', 'd'] allowed.");
    }
    return 1;
}

int inst_unger(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "unger requires 3 parameters.");
    if(!type)
        die(state, "unger requires type of: ['f', 'd'].");

    switch(type->value) {
        
    case OpType_f:
        jit_unger_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_unger_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation unger, only ['f', 'd'] allowed.");
    }
    return 1;
}

int inst_uneqr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "uneqr requires 3 parameters.");
    if(!type)
        die(state, "uneqr requires type of: ['f', 'd'].");

    switch(type->value) {
        
    case OpType_f:
        jit_uneqr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_uneqr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation uneqr, only ['f', 'd'] allowed.");
    }
    return 1;
}

int inst_ltgtr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ltgtr requires 3 parameters.");
    if(!type)
        die(state, "ltgtr requires type of: ['f', 'd'].");

    switch(type->value) {
        
    case OpType_f:
        jit_ltgtr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_ltgtr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ltgtr, only ['f', 'd'] allowed.");
    }
    return 1;
}

int inst_ordr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ordr requires 3 parameters.");
    if(!type)
        die(state, "ordr requires type of: ['f', 'd'].");

    switch(type->value) {
        
    case OpType_f:
        jit_ordr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_ordr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ordr, only ['f', 'd'] allowed.");
    }
    return 1;
}

int inst_unordr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "unordr requires 3 parameters.");
    if(!type)
        die(state, "unordr requires type of: ['f', 'd'].");

    switch(type->value) {
        
    case OpType_f:
        jit_unordr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_unordr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation unordr, only ['f', 'd'] allowed.");
    }
    return 1;
}

int inst_movr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "movr requires 2 parameters.");
    if(!type)
        die(state, "movr requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_movr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_movr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_l:
        jit_movr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ul:
        jit_movr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_p:
        jit_movr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_f:
        jit_movr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_d:
        jit_movr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation movr, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_movi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "movi requires 2 parameters.");
    if(!type)
        die(state, "movi requires type of: ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_movi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_movi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_l:
        jit_movi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ul:
        jit_movi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_p:
        jit_movi_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_f:
        jit_movi_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_d:
        jit_movi_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation movi, only ['i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_hton(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "hton requires 2 parameters.");
    if(!type)
        die(state, "hton requires type of: ['us', 'ui'].");

    switch(type->value) {
        
    case OpType_us:
        jit_hton_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_hton_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation hton, only ['us', 'ui'] allowed.");
    }
    return 1;
}

int inst_ntoh(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "ntoh requires 2 parameters.");
    if(!type)
        die(state, "ntoh requires type of: ['us', 'ui'].");

    switch(type->value) {
        
    case OpType_us:
        jit_ntoh_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_ntoh_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation ntoh, only ['us', 'ui'] allowed.");
    }
    return 1;
}

int inst_ldr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "ldr requires 2 parameters.");
    if(!type)
        die(state, "ldr requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_ldr_c (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_uc:
        jit_ldr_uc (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_s:
        jit_ldr_s (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_us:
        jit_ldr_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_i:
        jit_ldr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_ldr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_l:
        jit_ldr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ul:
        jit_ldr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_p:
        jit_ldr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_f:
        jit_ldr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_d:
        jit_ldr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation ldr, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_ldi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "ldi requires 2 parameters.");
    if(!type)
        die(state, "ldi requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_ldi_c (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_uc:
        jit_ldi_uc (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_s:
        jit_ldi_s (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_us:
        jit_ldi_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_i:
        jit_ldi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_ldi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_l:
        jit_ldi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ul:
        jit_ldi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_p:
        jit_ldi_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_f:
        jit_ldi_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_d:
        jit_ldi_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation ldi, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_ldxr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ldxr requires 3 parameters.");
    if(!type)
        die(state, "ldxr requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_ldxr_c (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_uc:
        jit_ldxr_uc (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_s:
        jit_ldxr_s (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_us:
        jit_ldxr_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_i:
        jit_ldxr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_ldxr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_ldxr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_ldxr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_ldxr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_ldxr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_ldxr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ldxr, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_ldxi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "ldxi requires 3 parameters.");
    if(!type)
        die(state, "ldxi requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_ldxi_c (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_uc:
        jit_ldxi_uc (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_s:
        jit_ldxi_s (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_us:
        jit_ldxi_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_i:
        jit_ldxi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_ldxi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_ldxi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_ldxi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_ldxi_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_ldxi_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_ldxi_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation ldxi, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_str(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "str requires 2 parameters.");
    if(!type)
        die(state, "str requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_str_c (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_uc:
        jit_str_uc (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_s:
        jit_str_s (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_us:
        jit_str_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_i:
        jit_str_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_str_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_l:
        jit_str_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ul:
        jit_str_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_p:
        jit_str_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_f:
        jit_str_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_d:
        jit_str_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation str, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_sti(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "sti requires 2 parameters.");
    if(!type)
        die(state, "sti requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_sti_c (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_uc:
        jit_sti_uc (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_s:
        jit_sti_s (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_us:
        jit_sti_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_i:
        jit_sti_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_sti_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_l:
        jit_sti_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ul:
        jit_sti_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_p:
        jit_sti_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_f:
        jit_sti_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_d:
        jit_sti_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation sti, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_stxr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "stxr requires 3 parameters.");
    if(!type)
        die(state, "stxr requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_stxr_c (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_uc:
        jit_stxr_uc (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_s:
        jit_stxr_s (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_us:
        jit_stxr_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_i:
        jit_stxr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_stxr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_stxr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_stxr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_stxr_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_stxr_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_stxr_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation stxr, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_stxi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "stxi requires 3 parameters.");
    if(!type)
        die(state, "stxi requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_stxi_c (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_uc:
        jit_stxi_uc (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_s:
        jit_stxi_s (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_us:
        jit_stxi_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_i:
        jit_stxi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_stxi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_stxi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_stxi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_stxi_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_f:
        jit_stxi_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_d:
        jit_stxi_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation stxi, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_prepare(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 1)
        die(state, "prepare requires 1 parameters.");
    if(!type)
        die(state, "prepare requires type of: ['i', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_i:
        jit_prepare_i (array_of(Token, params, 0)->value); break; 

    case OpType_f:
        jit_prepare_f (array_of(Token, params, 0)->value); break; 

    case OpType_d:
        jit_prepare_d (array_of(Token, params, 0)->value); break; 

        default:
            die(state, "Invalid type given for operation prepare, only ['i', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_pusharg(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 1)
        die(state, "pusharg requires 1 parameters.");
    if(!type)
        die(state, "pusharg requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_pusharg_c (array_of(Token, params, 0)->value); break; 

    case OpType_uc:
        jit_pusharg_uc (array_of(Token, params, 0)->value); break; 

    case OpType_s:
        jit_pusharg_s (array_of(Token, params, 0)->value); break; 

    case OpType_us:
        jit_pusharg_us (array_of(Token, params, 0)->value); break; 

    case OpType_i:
        jit_pusharg_i (array_of(Token, params, 0)->value); break; 

    case OpType_ui:
        jit_pusharg_ui (array_of(Token, params, 0)->value); break; 

    case OpType_l:
        jit_pusharg_l (array_of(Token, params, 0)->value); break; 

    case OpType_ul:
        jit_pusharg_ul (array_of(Token, params, 0)->value); break; 

    case OpType_p:
        jit_pusharg_p (array_of(Token, params, 0)->value); break; 

    case OpType_f:
        jit_pusharg_f (array_of(Token, params, 0)->value); break; 

    case OpType_d:
        jit_pusharg_d (array_of(Token, params, 0)->value); break; 

        default:
            die(state, "Invalid type given for operation pusharg, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_getarg(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 2)
        die(state, "getarg requires 2 parameters.");
    if(!type)
        die(state, "getarg requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_getarg_c (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_uc:
        jit_getarg_uc (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_s:
        jit_getarg_s (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_us:
        jit_getarg_us (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_i:
        jit_getarg_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ui:
        jit_getarg_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_l:
        jit_getarg_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_ul:
        jit_getarg_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_p:
        jit_getarg_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_f:
        jit_getarg_f (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

    case OpType_d:
        jit_getarg_d (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value); break; 

        default:
            die(state, "Invalid type given for operation getarg, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}

int inst_blti(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "blti requires 3 parameters.");
    if(!type)
        die(state, "blti requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_blti_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_blti_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_blti_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_blti_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_blti_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation blti, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_blei(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "blei requires 3 parameters.");
    if(!type)
        die(state, "blei requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_blei_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_blei_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_blei_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_blei_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_blei_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation blei, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_bgti(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "bgti requires 3 parameters.");
    if(!type)
        die(state, "bgti requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_bgti_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_bgti_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_bgti_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_bgti_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_bgti_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation bgti, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_bgei(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "bgei requires 3 parameters.");
    if(!type)
        die(state, "bgei requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_bgei_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_bgei_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_bgei_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_bgei_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_bgei_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation bgei, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_beqi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "beqi requires 3 parameters.");
    if(!type)
        die(state, "beqi requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_beqi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_beqi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_beqi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_beqi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_beqi_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation beqi, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_bnei(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "bnei requires 3 parameters.");
    if(!type)
        die(state, "bnei requires type of: ['i', 'ui', 'l', 'ul', 'p'].");

    switch(type->value) {
        
    case OpType_i:
        jit_bnei_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_bnei_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_bnei_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_bnei_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_p:
        jit_bnei_p (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation bnei, only ['i', 'ui', 'l', 'ul', 'p'] allowed.");
    }
    return 1;
}

int inst_bmsr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "bmsr requires 3 parameters.");
    if(!type)
        die(state, "bmsr requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_bmsr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_bmsr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_bmsr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_bmsr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation bmsr, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_bmsi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "bmsi requires 3 parameters.");
    if(!type)
        die(state, "bmsi requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_bmsi_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_bmsi_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_bmsi_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_bmsi_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation bmsi, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_bmcr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "bmcr requires 3 parameters.");
    if(!type)
        die(state, "bmcr requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_bmcr_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_bmcr_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_bmcr_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_bmcr_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation bmcr, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_bmci(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 3)
        die(state, "bmci requires 3 parameters.");
    if(!type)
        die(state, "bmci requires type of: ['i', 'ui', 'l', 'ul'].");

    switch(type->value) {
        
    case OpType_i:
        jit_bmci_i (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ui:
        jit_bmci_ui (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_l:
        jit_bmci_l (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

    case OpType_ul:
        jit_bmci_ul (array_of(Token, params, 0)->value, array_of(Token, params, 1)->value, array_of(Token, params, 2)->value); break; 

        default:
            die(state, "Invalid type given for operation bmci, only ['i', 'ui', 'l', 'ul'] allowed.");
    }
    return 1;
}

int inst_calli(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 1)
        die(state, "calli requires 1 parameters.");
    if(type) die(state, "Operation calli does not take a type.");

    jit_calli (array_of(Token, params, 0)->value);

    return 1;
}

int inst_callr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 1)
        die(state, "callr requires 1 parameters.");
    if(type) die(state, "Operation callr does not take a type.");

    jit_callr (array_of(Token, params, 0)->value);

    return 1;
}

int inst_finish(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 1)
        die(state, "finish requires 1 parameters.");
    if(type) die(state, "Operation finish does not take a type.");

    jit_finish (array_of(Token, params, 0)->value);

    return 1;
}

int inst_finishr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 1)
        die(state, "finishr requires 1 parameters.");
    if(type) die(state, "Operation finishr does not take a type.");

    jit_finishr (array_of(Token, params, 0)->value);

    return 1;
}

int inst_jmpi(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 1)
        die(state, "jmpi requires 1 parameters.");
    if(type) die(state, "Operation jmpi does not take a type.");

    jit_jmpi (array_of(Token, params, 0)->value);

    return 1;
}

int inst_jmpr(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 1)
        die(state, "jmpr requires 1 parameters.");
    if(type) die(state, "Operation jmpr does not take a type.");

    jit_jmpr (array_of(Token, params, 0)->value);

    return 1;
}

int inst_ret(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 0)
        die(state, "ret requires 0 parameters.");
    if(type) die(state, "Operation ret does not take a type.");

    jit_ret ();

    return 1;
}

int inst_retval(Module *state, Token *type, array_t *params) {
    if(array_length(params) != 1)
        die(state, "retval requires 1 parameters.");
    if(!type)
        die(state, "retval requires type of: ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'].");

    switch(type->value) {
        
    case OpType_c:
        jit_retval_c (array_of(Token, params, 0)->value); break; 

    case OpType_uc:
        jit_retval_uc (array_of(Token, params, 0)->value); break; 

    case OpType_s:
        jit_retval_s (array_of(Token, params, 0)->value); break; 

    case OpType_us:
        jit_retval_us (array_of(Token, params, 0)->value); break; 

    case OpType_i:
        jit_retval_i (array_of(Token, params, 0)->value); break; 

    case OpType_ui:
        jit_retval_ui (array_of(Token, params, 0)->value); break; 

    case OpType_l:
        jit_retval_l (array_of(Token, params, 0)->value); break; 

    case OpType_ul:
        jit_retval_ul (array_of(Token, params, 0)->value); break; 

    case OpType_p:
        jit_retval_p (array_of(Token, params, 0)->value); break; 

    case OpType_f:
        jit_retval_f (array_of(Token, params, 0)->value); break; 

    case OpType_d:
        jit_retval_d (array_of(Token, params, 0)->value); break; 

        default:
            die(state, "Invalid type given for operation retval, only ['c', 'uc', 's', 'us', 'i', 'ui', 'l', 'ul', 'p', 'f', 'd'] allowed.");
    }
    return 1;
}
