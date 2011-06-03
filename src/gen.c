#include "module.h"
#include "label.h"
#include "function.h"
#include "grammar.h"
#include "error.h"
#include "hash.h"
#include <gc/gc.h>
#include <assert.h>

// because of the way GNU lightning is designed we have to keep ALL of the
// code generation tasks in the same file.  Since the function management is
// here we also have to include the code ops.c here.
#include "ops.c"

void Function_synthesize_param(FunctionParam *p)
{
    switch(p->type) {
        case OpType_i:
            p->index = jit_arg_i(); break;
        case OpType_ui:
            p->index = jit_arg_ui(); break;
        case OpType_l:
            p->index = jit_arg_l(); break;
        case OpType_ul:
            p->index = jit_arg_ul(); break;
        case OpType_p:
            p->index = jit_arg_p(); break;
        case OpType_f:
            p->index = jit_arg_f(); break;
        case OpType_d:
            p->index = jit_arg_d(); break;
        case OpType_c:
            p->index = jit_arg_c(); break;
        case OpType_uc:
            p->index = jit_arg_uc(); break;
        case OpType_s:
            p->index = jit_arg_s(); break;
        case OpType_us:
            p->index = jit_arg_us(); break;
        default:
            assert(!"Invalid type given for function parameter.");
    }
}

Function *Function_create(struct Module *state, OpType type, CORD name, array_t *params)
{
    size_t i = 0;

    if(Function_find(state, name)) {
        die(state, "%r is already defined, what you think this is Ruby?.", name);
    }

    Function *func = GC_MALLOC(sizeof(Function));
    assert(func && "Failed to allocate the function.");
    func->code = GC_MALLOC(state->max_code_size * sizeof(jit_insn));
    func->code_len = state->max_code_size;
    func->name = name;
    func->type = type;
    func->params = params;

    func->fp = jit_set_ip(func->code);

    if(state->current_is_leaf) {
        jit_leaf(func->nparams);
    } else {
        jit_prolog(func->nparams);
    }

    if(func->params) {
        for(i = 0; i < array_length(func->params); i++) {
                Function_synthesize_param(array_at(func->params, i));
        }
    }

    // now we just record ourselves in the state for further processing
    hash_alloc_insert(state->functions, func->name, func);
    state->current = func;

    return func;
}

Function *Function_finalize(Module *state, Function *func, Token *end)
{
    jit_ret();

    func->code_len = jit_get_ip().ptr - (char *)func->code;
    jit_flush_code(func->code, jit_get_ip().ptr);

    state->current = NULL;
    state->current_is_leaf = 0;

    return func;
}

void Label_patch_back_refs(Label *label)
{
    int i = 0;
    jit_insn *ref = NULL;

    for(i = 0; i < array_length(label->back_refs); i++) {
        ref = array_at(label->back_refs, i);
        assert(ref && "back_ref was NULL and shouldn't be.");

        jit_patch(ref);
        array_set(label->back_refs, i, NULL);
    }
}

Label *Label_create_and_add(Function *func, Token *tk, int realized)
{
    assert(tk && "Must give a tk.");
    assert(func && "Must have an active function.");

    Label *result = GC_MALLOC(sizeof(Label));
    result->name = tk->data;
    result->ref = jit_get_label();
    result->realized = realized;
    hash_alloc_insert(func->labels, result->name, result);

    return result;
}

void Label_statement(Function *func, Token *tk)
{
    Label *label = Label_find(func, tk);
    if(!label) {
        // forward label statement, create realized
        label = Label_create_and_add(func, tk, 1);
    } else {
        // backward label statement
        assert(!label->realized && "You've already used this label.");

        // patch the back references
        label->realized = 1;
        Label_patch_back_refs(label);
        label->ref = jit_get_label();
    }
}

static int Call_param_is(array_t *params, int i, int tk) {
    assert(array_length(params) <= i && "array bounds error.");
    Token *param = array_at(params, i);

    return param->id == tk;
}

void Label_add_back_ref(Label *label, jit_insn *ref)
{
    array_add(label->back_refs, ref);
}

void Call_operation(Module *state, Function *func, Token *op, Token *type, array_t *params)
{
    // TODO: adapt this to handle any parameter as a label
    Label *label = NULL;
    Token *label_tk = NULL;

    if(Call_param_is(params, 0, TK_LABEL)) {
        label = Label_find(func, array_at(params, 0));
        assert(label && "Label should be found.");

        if(!label->realized) {
            // adjust the value of this parameter to the jit_forward for the call
            label_tk = array_at(params, 0);

            label_tk->value = (unsigned long)jit_forward();
        } // otherwise value was set by Label_expression
    }

    // TODO: expand this
    assert(jit_get_ip().ptr - (char *)func->code < func->code_len && "You exceeded the space specified for function code blocks.");

    op->call(state, type, params);

    if(Call_param_is(params, 0, TK_LABEL) && !label->realized) {
        // we have to update backrefs here, and not in the label code
        // since the label is created outside the opcode run
        Label_add_back_ref(label, jit_get_label());
    }
}

