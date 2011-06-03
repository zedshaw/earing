/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 3 "grammar.y"

  #include <assert.h>
  #include <stdio.h> 
  #include <gc/gc.h>
  #include "allocator.h"
#line 16 "grammar.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    ParseTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is ParseTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    ParseARG_SDECL     A static variable declaration for the %extra_argument
**    ParseARG_PDECL     A parameter declaration for the %extra_argument
**    ParseARG_STORE     Code to store %extra_argument into yypParser
**    ParseARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 41
#define YYACTIONTYPE unsigned char
#define ParseTOKENTYPE  Token* 
typedef union {
  ParseTOKENTYPE yy0;
  Function * yy13;
  Label * yy27;
  FunctionParam * yy62;
  Parameters * yy67;
  Token * yy68;
  int yy81;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL  Module *state ;
#define ParseARG_PDECL , Module *state 
#define ParseARG_FETCH  Module *state  = yypParser->state 
#define ParseARG_STORE yypParser->state  = state 
#define YYNSTATE 75
#define YYNRULE 42
#define YYERRORSYMBOL 23
#define YYERRSYMDT yy81
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor;

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    17,   52,   70,    6,   51,    5,   31,   16,   42,   41,
 /*    10 */    74,   71,   69,   68,   60,   14,   20,    3,   47,   21,
 /*    20 */    20,  118,    1,   54,   18,   19,   30,   59,   18,   19,
 /*    30 */    30,    9,   75,   47,   21,    9,   27,   11,   33,   35,
 /*    40 */    53,   20,    4,   27,   53,   48,   28,   27,   43,   18,
 /*    50 */    19,   27,   11,   52,   15,   23,   51,   23,   29,   23,
 /*    60 */    23,   44,   26,   72,   36,   73,   56,   32,   37,    2,
 /*    70 */    66,    4,   25,   39,   40,   57,   45,   61,   24,   22,
 /*    80 */    55,   64,   65,   67,   12,   62,   13,   63,   50,    8,
 /*    90 */    58,    7,   46,   38,   10,   34,  119,  119,  119,  119,
 /*   100 */   119,   49,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     2,   34,    5,    6,   37,   38,   39,   28,   10,   11,
 /*    10 */    12,   13,   14,   15,   16,   17,   26,   23,    1,    2,
 /*    20 */    26,   31,   32,   33,   34,   35,    2,   33,   34,   35,
 /*    30 */     2,    7,    0,    1,    2,    7,   19,   20,    5,    6,
 /*    40 */    16,   26,    4,   19,   16,   21,    8,   19,   33,   34,
 /*    50 */    35,   19,   20,   34,   25,   30,   37,   30,   39,   30,
 /*    60 */    30,   36,    2,   36,    2,   36,   36,    2,   22,   27,
 /*    70 */     9,    4,   12,   22,   24,    9,   24,    2,    8,    8,
 /*    80 */     1,    1,   18,    2,    2,    1,    9,   18,    1,    3,
 /*    90 */     1,    3,   24,    2,    4,   22,   40,   40,   40,   40,
 /*   100 */    40,    9,
};
#define YY_SHIFT_USE_DFLT (-4)
#define YY_SHIFT_MAX 39
static const signed char yy_shift_ofst[] = {
 /*     0 */    17,   32,   28,   17,   -2,   24,   -2,   -2,   -2,   38,
 /*    10 */    91,   65,   67,   67,   60,   -3,   33,   71,   80,   84,
 /*    20 */    79,   86,   81,   70,   75,   69,   64,   82,   77,   87,
 /*    30 */    88,   89,   90,   73,   92,   62,   46,   61,   51,   66,
};
#define YY_REDUCE_USE_DFLT (-34)
#define YY_REDUCE_MAX 13
static const signed char yy_reduce_ofst[] = {
 /*     0 */   -10,   -6,  -33,   15,   29,   19,   27,   30,   25,   68,
 /*    10 */   -21,   42,   50,   52,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   117,  117,  115,  117,   87,  115,  117,  117,  117,   84,
 /*    10 */   108,  117,   84,   84,  117,  117,  117,   96,  117,  117,
 /*    20 */   117,  117,  117,   97,  117,  117,  117,  117,  117,  117,
 /*    30 */   117,  117,  117,  117,  117,  117,  117,  117,  117,  117,
 /*    40 */   103,   91,   90,  116,   82,   88,   89,   81,  104,  105,
 /*    50 */   110,  111,  112,  113,   76,   80,  114,  106,  109,   77,
 /*    60 */    99,   98,   79,  100,   78,  101,  107,  102,   95,   94,
 /*    70 */    83,   93,   85,   86,   92,
};
#define YY_SZ_ACTTAB (int)(sizeof(yy_action)/sizeof(yy_action[0]))

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammer, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  YYMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
  int yyerrcnt;                 /* Shifts left before out of the error */
  ParseARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "EOL",           "IDENT",         "EQ",          
  "LPAREN",        "RPAREN",        "COMMA",         "OP",          
  "DOT",           "TYPE",          "HEX",           "FLOAT",       
  "INT",           "STR",           "CHR",           "REG",         
  "LABEL",         "LBRACK",        "RBRACK",        "PERCENT",     
  "FUNCTION",      "END",           "COLON",         "error",       
  "parameters",    "args",          "function",      "function_decl",
  "function_params",  "label",         "function_reference",  "module",      
  "statements",    "statement",     "directive",     "constant",    
  "expr",          "operation",     "block",         "element",     
};

/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "module ::= statements",
 /*   1 */ "statements ::= statement",
 /*   2 */ "statements ::= statements statement",
 /*   3 */ "statement ::= directive EOL",
 /*   4 */ "statement ::= constant EOL",
 /*   5 */ "statement ::= function EOL",
 /*   6 */ "statement ::= EOL",
 /*   7 */ "constant ::= IDENT EQ expr",
 /*   8 */ "parameters ::= LPAREN args RPAREN",
 /*   9 */ "parameters ::=",
 /*  10 */ "args ::= args COMMA expr",
 /*  11 */ "args ::= expr",
 /*  12 */ "args ::=",
 /*  13 */ "operation ::= OP DOT TYPE parameters",
 /*  14 */ "operation ::= OP parameters",
 /*  15 */ "expr ::= HEX",
 /*  16 */ "expr ::= FLOAT",
 /*  17 */ "expr ::= INT",
 /*  18 */ "expr ::= STR",
 /*  19 */ "expr ::= CHR",
 /*  20 */ "expr ::= REG",
 /*  21 */ "expr ::= IDENT",
 /*  22 */ "expr ::= function_reference",
 /*  23 */ "expr ::= function_reference DOT IDENT",
 /*  24 */ "expr ::= LABEL",
 /*  25 */ "expr ::= LBRACK INT RBRACK",
 /*  26 */ "expr ::= LBRACK IDENT RBRACK",
 /*  27 */ "function_reference ::= IDENT DOT IDENT",
 /*  28 */ "directive ::= PERCENT IDENT parameters",
 /*  29 */ "function ::= FUNCTION function_decl block END",
 /*  30 */ "function_decl ::= IDENT LPAREN function_params RPAREN COLON TYPE",
 /*  31 */ "function_params ::= IDENT COLON TYPE",
 /*  32 */ "function_params ::= function_params COMMA IDENT COLON TYPE",
 /*  33 */ "function_params ::=",
 /*  34 */ "block ::= element EOL",
 /*  35 */ "block ::= block element EOL",
 /*  36 */ "element ::= operation",
 /*  37 */ "element ::= directive",
 /*  38 */ "element ::= LABEL",
 /*  39 */ "element ::= IDENT EQ expr",
 /*  40 */ "element ::=",
 /*  41 */ "statements ::= statements error statement",
};


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to Parse and ParseFree.
*/
void *ParseAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#if YYSTACKDEPTH<=0
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(YYCODETYPE yymajor, YYMINORTYPE *yypminor){
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    case 1: /* EOL */
    case 2: /* IDENT */
    case 3: /* EQ */
    case 4: /* LPAREN */
    case 5: /* RPAREN */
    case 6: /* COMMA */
    case 7: /* OP */
    case 8: /* DOT */
    case 9: /* TYPE */
    case 10: /* HEX */
    case 11: /* FLOAT */
    case 12: /* INT */
    case 13: /* STR */
    case 14: /* CHR */
    case 15: /* REG */
    case 16: /* LABEL */
    case 17: /* LBRACK */
    case 18: /* RBRACK */
    case 19: /* PERCENT */
    case 20: /* FUNCTION */
    case 21: /* END */
    case 22: /* COLON */
{
#line 9 "grammar.y"
 GC_FREE((yypminor->yy0)); 
#line 433 "grammar.c"
}
      break;
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor( yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from ParseAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void ParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  GC_FREE(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_MAX || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      int iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( j>=0 && j<YY_SZ_ACTTAB && yy_lookahead[j]==YYWILDCARD ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_MAX ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_MAX );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_SZ_ACTTAB );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   ParseARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
#line 36 "grammar.y"

    printf("Stack overflowed, you suck after line: %u.\n", state->curline);
#line 600 "grammar.c"
   ParseARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer ot the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = yyNewState;
  yytos->major = yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 31, 1 },
  { 32, 1 },
  { 32, 2 },
  { 33, 2 },
  { 33, 2 },
  { 33, 2 },
  { 33, 1 },
  { 35, 3 },
  { 24, 3 },
  { 24, 0 },
  { 25, 3 },
  { 25, 1 },
  { 25, 0 },
  { 37, 4 },
  { 37, 2 },
  { 36, 1 },
  { 36, 1 },
  { 36, 1 },
  { 36, 1 },
  { 36, 1 },
  { 36, 1 },
  { 36, 1 },
  { 36, 1 },
  { 36, 3 },
  { 36, 1 },
  { 36, 3 },
  { 36, 3 },
  { 30, 3 },
  { 34, 3 },
  { 26, 4 },
  { 27, 6 },
  { 28, 3 },
  { 28, 5 },
  { 28, 0 },
  { 38, 2 },
  { 38, 3 },
  { 39, 1 },
  { 39, 1 },
  { 39, 1 },
  { 39, 3 },
  { 39, 0 },
  { 32, 3 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  ParseARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* module ::= statements */
      case 1: /* statements ::= statement */
      case 2: /* statements ::= statements statement */
      case 36: /* element ::= operation */
      case 37: /* element ::= directive */
      case 40: /* element ::= */
      case 41: /* statements ::= statements error statement */
#line 58 "grammar.y"
{
}
#line 758 "grammar.c"
        break;
      case 3: /* statement ::= directive EOL */
      case 4: /* statement ::= constant EOL */
      case 5: /* statement ::= function EOL */
      case 6: /* statement ::= EOL */
      case 34: /* block ::= element EOL */
      case 35: /* block ::= block element EOL */
#line 63 "grammar.y"
{
  yy_destructor(1,&yymsp[0].minor);
}
#line 770 "grammar.c"
        break;
      case 7: /* constant ::= IDENT EQ expr */
#line 68 "grammar.y"
{
     Module_create_constant(state, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(3,&yymsp[-1].minor);
}
#line 778 "grammar.c"
        break;
      case 8: /* parameters ::= LPAREN args RPAREN */
#line 72 "grammar.y"
{ yygotominor.yy67 = yymsp[-1].minor.yy67;   yy_destructor(4,&yymsp[-2].minor);
  yy_destructor(5,&yymsp[0].minor);
}
#line 785 "grammar.c"
        break;
      case 9: /* parameters ::= */
      case 12: /* args ::= */
#line 73 "grammar.y"
{ yygotominor.yy67 = GC_MALLOC(sizeof(Parameters)); }
#line 791 "grammar.c"
        break;
      case 10: /* args ::= args COMMA expr */
#line 75 "grammar.y"
{ yymsp[-2].minor.yy67->args[yymsp[-2].minor.yy67->i++] = yymsp[0].minor.yy0; yygotominor.yy67=yymsp[-2].minor.yy67;   yy_destructor(6,&yymsp[-1].minor);
}
#line 797 "grammar.c"
        break;
      case 11: /* args ::= expr */
#line 76 "grammar.y"
{ yygotominor.yy67 = GC_MALLOC(sizeof(Parameters)); yygotominor.yy67->args[yygotominor.yy67->i++] = yymsp[0].minor.yy0;}
#line 802 "grammar.c"
        break;
      case 13: /* operation ::= OP DOT TYPE parameters */
#line 80 "grammar.y"
{ Call_operation(state, state->current, yymsp[-3].minor.yy0, yymsp[-1].minor.yy0, yymsp[0].minor.yy67);   yy_destructor(8,&yymsp[-2].minor);
}
#line 808 "grammar.c"
        break;
      case 14: /* operation ::= OP parameters */
#line 82 "grammar.y"
{ Call_operation(state, state->current, yymsp[-1].minor.yy0, NULL, yymsp[0].minor.yy67); }
#line 813 "grammar.c"
        break;
      case 15: /* expr ::= HEX */
      case 16: /* expr ::= FLOAT */
      case 17: /* expr ::= INT */
      case 18: /* expr ::= STR */
      case 19: /* expr ::= CHR */
      case 20: /* expr ::= REG */
#line 84 "grammar.y"
{ yygotominor.yy0 = yymsp[0].minor.yy0; }
#line 823 "grammar.c"
        break;
      case 21: /* expr ::= IDENT */
#line 90 "grammar.y"
{ yygotominor.yy0 = Module_resolve_data(state, yymsp[0].minor.yy0); }
#line 828 "grammar.c"
        break;
      case 22: /* expr ::= function_reference */
#line 91 "grammar.y"
{ yygotominor.yy0 = yymsp[0].minor.yy68; }
#line 833 "grammar.c"
        break;
      case 23: /* expr ::= function_reference DOT IDENT */
#line 92 "grammar.y"
{ yygotominor.yy0 = Module_outside_function_data(state, yymsp[-2].minor.yy68, yymsp[0].minor.yy0);   yy_destructor(8,&yymsp[-1].minor);
}
#line 839 "grammar.c"
        break;
      case 24: /* expr ::= LABEL */
#line 93 "grammar.y"
{ yygotominor.yy0 = Label_expression(state->current, yymsp[0].minor.yy0); }
#line 844 "grammar.c"
        break;
      case 25: /* expr ::= LBRACK INT RBRACK */
#line 94 "grammar.y"
{ yygotominor.yy0 = Allocator_expression(state, yymsp[-1].minor.yy0);   yy_destructor(17,&yymsp[-2].minor);
  yy_destructor(18,&yymsp[0].minor);
}
#line 851 "grammar.c"
        break;
      case 26: /* expr ::= LBRACK IDENT RBRACK */
#line 96 "grammar.y"
{ yygotominor.yy0 = Allocator_expression(state, Module_resolve_data(state, yymsp[-1].minor.yy0));   yy_destructor(17,&yymsp[-2].minor);
  yy_destructor(18,&yymsp[0].minor);
}
#line 858 "grammar.c"
        break;
      case 27: /* function_reference ::= IDENT DOT IDENT */
#line 99 "grammar.y"
{ yygotominor.yy68 = Module_resolve_function(state, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);   yy_destructor(8,&yymsp[-1].minor);
}
#line 864 "grammar.c"
        break;
      case 28: /* directive ::= PERCENT IDENT parameters */
#line 102 "grammar.y"
{ Module_call_directive(state, yymsp[-1].minor.yy0, yymsp[0].minor.yy67);   yy_destructor(19,&yymsp[-2].minor);
}
#line 870 "grammar.c"
        break;
      case 29: /* function ::= FUNCTION function_decl block END */
#line 105 "grammar.y"
{ yygotominor.yy13 = Function_finalize(state, yymsp[-2].minor.yy13, yymsp[0].minor.yy0);   yy_destructor(20,&yymsp[-3].minor);
}
#line 876 "grammar.c"
        break;
      case 30: /* function_decl ::= IDENT LPAREN function_params RPAREN COLON TYPE */
#line 108 "grammar.y"
{ yygotominor.yy13 = Function_create(state, yymsp[0].minor.yy0->value, yymsp[-5].minor.yy0->start, yymsp[-5].minor.yy0->len, yymsp[-3].minor.yy62);   yy_destructor(4,&yymsp[-4].minor);
  yy_destructor(5,&yymsp[-2].minor);
  yy_destructor(22,&yymsp[-1].minor);
}
#line 884 "grammar.c"
        break;
      case 31: /* function_params ::= IDENT COLON TYPE */
#line 111 "grammar.y"
{ yygotominor.yy62 = FunctionParam_create(NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);   yy_destructor(22,&yymsp[-1].minor);
}
#line 890 "grammar.c"
        break;
      case 32: /* function_params ::= function_params COMMA IDENT COLON TYPE */
#line 113 "grammar.y"
{ yygotominor.yy62 = FunctionParam_create(yymsp[-4].minor.yy62, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);   yy_destructor(6,&yymsp[-3].minor);
  yy_destructor(22,&yymsp[-1].minor);
}
#line 897 "grammar.c"
        break;
      case 33: /* function_params ::= */
#line 114 "grammar.y"
{ yygotominor.yy62 = NULL; }
#line 902 "grammar.c"
        break;
      case 38: /* element ::= LABEL */
#line 121 "grammar.y"
{ Label_statement(state->current, yymsp[0].minor.yy0); }
#line 907 "grammar.c"
        break;
      case 39: /* element ::= IDENT EQ expr */
#line 122 "grammar.y"
{
 Module_create_function_constant(state, yymsp[-2].minor.yy0, yymsp[0].minor.yy0);
  yy_destructor(3,&yymsp[-1].minor);
}
#line 915 "grammar.c"
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = yyact;
      yymsp->major = yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  ParseARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 14 "grammar.y"

    state->errors++;

    if(state->current) {
        printf("%s: In function '%.*s':\n", state->module_name, 
            state->current->len, state->current->name);
        state->current = NULL;
    }

    printf("%s:%d: error at %s token in [",
            state->module_name, state->curline, yyTokenName[yymajor]);
   
    int i;
    for(i=1; i<=yypParser->yyidx; i++)
      printf(" %s",yyTokenName[yypParser->yystack[i].major]);

    printf(" | %s ] unexpected '%.*s'\n",
            yyTokenName[yymajor],
            yymajor != 0 ? TOKEN->len : 7, 
            yymajor != 0 ? TOKEN->start : "$ (EOF)");
#line 996 "grammar.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
#line 11 "grammar.y"

#line 1019 "grammar.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "ParseAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void Parse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  ParseTOKENTYPE yyminor       /* The value for the token */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  ParseARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
