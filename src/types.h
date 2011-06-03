#ifndef types_h
#define types_h

/**
 * These are used to determine the types of both operations and function returns.
 * For an operation it follows a '.' as in movi.ui(...).  For functions it follows
 * the function's name after a ':' as in function adder : int.  The lexer will actually
 * allow shorthand (i,ui,s,v) or long hand forms (int, uint, short, void) for
 * both functions and operations.
 */
typedef enum OpType {
    OpType_i,
    OpType_ui,
    OpType_l,
    OpType_ul,
    OpType_p,
    OpType_f,
    OpType_d,
    OpType_v,
    OpType_c,
    OpType_uc,
    OpType_s,
    OpType_us
} OpType;

const char *OpType_to_str(OpType type);

#endif
