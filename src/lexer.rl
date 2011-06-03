/** Zed A. Shaw -- A weird assembler.  Copyright 2008.  */

#include "module.h"
#include "grammar.h"
#include "tokenize.h"
#include "grammar.c"
#include "ops.h"
#include "error.h"
#include "allocator.h"

%%{
	machine lexer;

	newline = '\n' @{state->curline++; SYM(EOL)};
	any_count_line = any | newline;

	c_comment := any_count_line* :>> '*/' @{fgoto main;};

	main := |*

	alnum_u = alnum | '_';
	alpha_u = alpha | '_';

    # symbols used 
    "." { SYM(DOT) };
    "(" { SYM(LPAREN) };
    ")" { SYM(RPAREN) };
    "," { SYM(COMMA) };
    ":" { SYM(COLON) };
    "=" { SYM(EQ) };
    "%" { SYM(PERCENT) };
    ";" { SYM(EOL) };
    "[" { SYM(LBRACK) };
    "]" { SYM(RBRACK) };

    # keywords for structures
    "function" { KW(FUNCTION) };
    "end" { KW(END) };

    # registers start with a % like in gas
    "NOREG" {REG(NOREG) };
    "R0" {REG(R0) };
    "R1" {REG(R1) };
    "R2" {REG(R2) };
    "V0" {REG(V0) };
    "V1" {REG(V1) };
    "V2" {REG(V2) };
    "FP" {REG(FP) }; 
    "RET" { REG(RET) };

    # types used for operations and for function returns
    ('i'|'int') { TYPE(i) };
    ('ui'|'uint') { TYPE(ui) };
    ('l'|'long') { TYPE(l) };
    ('ul'|'ulong') { TYPE(ul) };
    ('p'|'ptr') { TYPE(p) };
    ('f'|'float') { TYPE(f) };
    ('d'|'double') { TYPE(d) };
    ('v'|'void') { TYPE(v) };
    ('c'|'char') { TYPE(c) };
    ('uc'|'uchar') { TYPE(uc) };
    ('s'|'short') { TYPE(s) };
    ('us'|'ushort') { TYPE(us) };

    # operations that are available
    "addr" {OP(addr) }; 
    "addi" {OP(addi) }; 
    "addxr" {OP(addxr) }; 
    "addxi" {OP(addxi) }; 
    "addcret" {OP(addcr) }; 
    "addciet" {OP(addci) }; 
    "subr" {OP(subr) }; 
    "subi" {OP(subi) }; 
    "subxr" {OP(subxr) }; 
    "subxi" {OP(subxi) }; 
    "subcr" {OP(subcr) }; 
    "subci" {OP(subci) }; 
    "rsbr" {OP(rsbr) }; 
    "rsbi" {OP(rsbi) }; 
    "mulr" {OP(mulr) }; 
    "muli" {OP(muli) }; 
    "hmulr" {OP(hmulr) }; 
    "hmuli" {OP(hmuli) }; 
    "divr" {OP(divr) }; 
    "divi" {OP(divi) }; 
    "modr" {OP(modr) }; 
    "modi" {OP(modi) }; 
    "andr" {OP(andr) }; 
    "andi" {OP(andi) }; 
    "orr" {OP(orr) }; 
    "ori" {OP(ori) }; 
    "xorr" {OP(xorr) }; 
    "xori" {OP(xori) }; 
    "lshr" {OP(lshr) }; 
    "lshi" {OP(lshi) }; 
    "rshr" {OP(rshr) }; 
    "rshi" {OP(rshi) }; 
    "negr" {OP(negr) }; 
    "notr" {OP(notr) }; 
    "ltr" {OP(ltr) }; 
    "lti" {OP(lti) }; 
    "ler" {OP(ler) }; 
    "lei" {OP(lei) }; 
    "gtr" {OP(gtr) }; 
    "gti" {OP(gti) }; 
    "ger" {OP(ger) }; 
    "gei" {OP(gei) }; 
    "eqr" {OP(eqr) }; 
    "eqi" {OP(eqi) }; 
    "ner" {OP(ner) }; 
    "nei" {OP(nei) }; 
    "unltr" {OP(unltr) }; 
    "unler" {OP(unler) }; 
    "ungtr" {OP(ungtr) }; 
    "unger" {OP(unger) }; 
    "uneqr" {OP(uneqr) }; 
    "ltgtr" {OP(ltgtr) }; 
    "ordr" {OP(ordr) }; 
    "unordr" {OP(unordr) }; 
    "movr" {OP(movr) }; 
    "movi" {OP(movi) }; 
    "hton" {OP(hton) }; 
    "ntoh" {OP(ntoh) }; 
    "ldr" {OP(ldr) }; 
    "ldi" {OP(ldi) }; 
    "ldxr" {OP(ldxr) }; 
    "ldxi" {OP(ldxi) }; 
    "str" {OP(str) }; 
    "sti" {OP(sti) }; 
    "stxr" {OP(stxr) }; 
    "stxi" {OP(stxi) }; 
    "prepare" {OP(prepare) }; 
    "pusharg" {OP(pusharg) }; 
    "getarg" {OP(getarg) }; 
    "retval" {OP(retval) }; 
    "blti" {OP(blti) }; 
    "blei" {OP(blei) }; 
    "bgti" {OP(bgti) }; 
    "bgei" {OP(bgei) }; 
    "beqi" {OP(beqi) }; 
    "bnei" {OP(bnei) }; 
    "bmsi" {OP(bmsi) }; 
    "bmci" {OP(bmci) }; 
    "jmpi" {OP(jmpi) }; 
    "jmpr" {OP(jmpr) }; 
    "ret" {OP(ret) }; 

    # these are psuedo ops for working the GC
    "sizeof" { OP(size_of) };
    "alloc" { OP(alloc) };
    "realloc" { OP(realloc) };
    "free" { OP(free) };
    "collect" { OP(collect) };

    # these are special in that we don't want to allow them in
    # leaf functions
    "calli" { OP(calli); NO_LEAF(calli); }; 
    "callr" {OP(callr); NO_LEAF(callr); }; 
    "finish" {OP(finish); NO_LEAF(finish); }; 
    "finishr" {OP(finishr); NO_LEAF(finishr); }; 

    # identifiers for things like variables and such
	alpha_u alnum_u* { IDENT() };
	alpha_u alnum_u* ':' { LABEL() };

	# single quoted string for single literal char
	sliteralChar = [^'\\] | newline | ( '\\' . any_count_line );
	'\'' . sliteralChar* . '\'' { CHR() };

	# double quoted string
	dliteralChar = [^"\\] | newline | ( '\\' any_count_line );
	'"' . dliteralChar* . '"' { STR() };

	# Whitespace is standard ws, newlines and control codes.
	any_count_line - 0x21..0x7e;

    # more sane EOL comments, and the only ones we need 
	'#' [^\n]* newline;
	'/*' { fgoto c_comment; };

    # integers, floats, and hex encoded values
	"-"? digit+ { INT() };
	"-"? digit+ '.' digit+ { FLOAT() };
	'0x' xdigit+ { HEX() };

	*|;
}%%

%% write data nofinal;

int Module_compile(Module *state, CORD source)
{
	int cs, act;
	const char *ts = 0, *te = 0;
    void *pParser = ParseAlloc(Allocator_malloc);
    Token *tk = NULL;
    const char *p = CORD_to_const_char_star(source);

	%% write init;

    const char *pe = p+CORD_len(source);
    const char *eof = pe;

    %% write exec;

    if(cs == lexer_error) {
        state->errors++;
        error(state, "invalid character '%c'\n", p[0]);
    } else {
        Parse(pParser, 0, NULL, state);
    }

    ParseFree(pParser, Allocator_free);

    return state->errors > 0 ? 0 : 1;
}


