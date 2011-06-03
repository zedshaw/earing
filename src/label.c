#include "function.h"
#include "label.h"
#include <assert.h>

Label *Label_find(Function *func, Token *tk)
{
    hnode_t *hn = hash_lookup(func->labels, tk->data);
    return hn ? hnode_get(hn) : NULL;
}


Token *Label_expression(Function *func, Token *tk)
{
    Label *label = Label_find(func, tk);

    if(!label) {
        // forward label expression, create but not realized
        // label = Label_create_and_add(func, tk, 0);
        assert(label && "You must fix this Zed.");
    } else {
        if(label->realized) {
            // backward label expression
            tk->value = (unsigned long)label->ref;
        } else {
            // forward label expression that's being used again
            // do nothing with it, Call_operation will handle the gore
        }
    }

    return tk;
}

