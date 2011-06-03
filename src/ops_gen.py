import re
import sys

header = """
#ifndef ops_h
#define ops_h

#include "module.h"
#include "array.h"

#include "allocator_ops.h"

%s

#endif
"""

function_decl = "int inst_%(op)s(Module *state, Token *type, array_t *params);\n"

typed_function = """
int inst_%(op)s(Module *state, Token *type, array_t *params) {
    if(array_length(params) != %(pcount)s)
        die(state, "%(op)s requires %(pcount)s parameters.");
    if(type) die(state, "Operation %(op)s does not take a type.");

    jit_%(op)s (%(args)s);

    return 1;
}
"""


type_case = """
    case OpType_%(type)s:
        jit_%(op)s_%(type)s (%(args)s); break; 
"""

untyped_function = """
int inst_%(op)s(Module *state, Token *type, array_t *params) {
    if(array_length(params) != %(pcount)s)
        die(state, "%(op)s requires %(pcount)s parameters.");
    if(!type)
        die(state, "%(op)s requires type of: %(types)s.");

    switch(type->value) {
        %(type_case)s
        default:
            die(state, "Invalid type given for operation %(op)s, only %(types)s allowed.");
    }
    return 1;
}
"""


instructions = open("src/instructions.txt").read().strip()

declarations = []

lines = instructions.split("\n")
commented = [x.split("|") for x in lines]
spaces = re.compile(" +")
ops_and_types = [(spaces.split(x[0].strip()), x[1].strip()) for x in commented]
ops_and_types = [(x[0][0], x[0][1:], x[1]) for x in ops_and_types]
counted = [(x[0], x[1], x[2], x[2].count("O")) for x in ops_and_types]
final = [{"op": x[0], "types": x[1], "comment": x[2], "pcount": x[3]} for x in
         counted]

defs = open("src/ops.c", "w")
decls = open("src/ops.h", "w")

defs.write('#include "module.h"\n#include "allocator_ops.c"\n')

for op in final:
    op["args"] = ", ".join(["array_of(Token, params, %d)->value" % x for x in range(0,op["pcount"])])
    op["type_case"] = "".join([type_case % {"op": op["op"], "type": type, "args":
                                 op["args"]} for type in op["types"]])

    declarations.append(function_decl % op)

    if len(op["types"]) > 0:
        defs.write(untyped_function % op)
    else:
        defs.write(typed_function % op)

decls.write(header % "".join(declarations))

defs.close()
decls.close()

