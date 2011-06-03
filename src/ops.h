
#ifndef ops_h
#define ops_h

#include "module.h"
#include "array.h"

#include "allocator_ops.h"

int inst_addr(Module *state, Token *type, array_t *params);
int inst_addi(Module *state, Token *type, array_t *params);
int inst_addxr(Module *state, Token *type, array_t *params);
int inst_addxi(Module *state, Token *type, array_t *params);
int inst_addcr(Module *state, Token *type, array_t *params);
int inst_addci(Module *state, Token *type, array_t *params);
int inst_subr(Module *state, Token *type, array_t *params);
int inst_subi(Module *state, Token *type, array_t *params);
int inst_subxr(Module *state, Token *type, array_t *params);
int inst_subxi(Module *state, Token *type, array_t *params);
int inst_subcr(Module *state, Token *type, array_t *params);
int inst_subci(Module *state, Token *type, array_t *params);
int inst_rsbr(Module *state, Token *type, array_t *params);
int inst_rsbi(Module *state, Token *type, array_t *params);
int inst_mulr(Module *state, Token *type, array_t *params);
int inst_muli(Module *state, Token *type, array_t *params);
int inst_hmulr(Module *state, Token *type, array_t *params);
int inst_hmuli(Module *state, Token *type, array_t *params);
int inst_divr(Module *state, Token *type, array_t *params);
int inst_divi(Module *state, Token *type, array_t *params);
int inst_modr(Module *state, Token *type, array_t *params);
int inst_modi(Module *state, Token *type, array_t *params);
int inst_andr(Module *state, Token *type, array_t *params);
int inst_andi(Module *state, Token *type, array_t *params);
int inst_orr(Module *state, Token *type, array_t *params);
int inst_ori(Module *state, Token *type, array_t *params);
int inst_xorr(Module *state, Token *type, array_t *params);
int inst_xori(Module *state, Token *type, array_t *params);
int inst_lshr(Module *state, Token *type, array_t *params);
int inst_lshi(Module *state, Token *type, array_t *params);
int inst_rshr(Module *state, Token *type, array_t *params);
int inst_rshi(Module *state, Token *type, array_t *params);
int inst_negr(Module *state, Token *type, array_t *params);
int inst_notr(Module *state, Token *type, array_t *params);
int inst_ltr(Module *state, Token *type, array_t *params);
int inst_lti(Module *state, Token *type, array_t *params);
int inst_ler(Module *state, Token *type, array_t *params);
int inst_lei(Module *state, Token *type, array_t *params);
int inst_gtr(Module *state, Token *type, array_t *params);
int inst_gti(Module *state, Token *type, array_t *params);
int inst_ger(Module *state, Token *type, array_t *params);
int inst_gei(Module *state, Token *type, array_t *params);
int inst_eqr(Module *state, Token *type, array_t *params);
int inst_eqi(Module *state, Token *type, array_t *params);
int inst_ner(Module *state, Token *type, array_t *params);
int inst_nei(Module *state, Token *type, array_t *params);
int inst_unltr(Module *state, Token *type, array_t *params);
int inst_unler(Module *state, Token *type, array_t *params);
int inst_ungtr(Module *state, Token *type, array_t *params);
int inst_unger(Module *state, Token *type, array_t *params);
int inst_uneqr(Module *state, Token *type, array_t *params);
int inst_ltgtr(Module *state, Token *type, array_t *params);
int inst_ordr(Module *state, Token *type, array_t *params);
int inst_unordr(Module *state, Token *type, array_t *params);
int inst_movr(Module *state, Token *type, array_t *params);
int inst_movi(Module *state, Token *type, array_t *params);
int inst_hton(Module *state, Token *type, array_t *params);
int inst_ntoh(Module *state, Token *type, array_t *params);
int inst_ldr(Module *state, Token *type, array_t *params);
int inst_ldi(Module *state, Token *type, array_t *params);
int inst_ldxr(Module *state, Token *type, array_t *params);
int inst_ldxi(Module *state, Token *type, array_t *params);
int inst_str(Module *state, Token *type, array_t *params);
int inst_sti(Module *state, Token *type, array_t *params);
int inst_stxr(Module *state, Token *type, array_t *params);
int inst_stxi(Module *state, Token *type, array_t *params);
int inst_prepare(Module *state, Token *type, array_t *params);
int inst_pusharg(Module *state, Token *type, array_t *params);
int inst_getarg(Module *state, Token *type, array_t *params);
int inst_blti(Module *state, Token *type, array_t *params);
int inst_blei(Module *state, Token *type, array_t *params);
int inst_bgti(Module *state, Token *type, array_t *params);
int inst_bgei(Module *state, Token *type, array_t *params);
int inst_beqi(Module *state, Token *type, array_t *params);
int inst_bnei(Module *state, Token *type, array_t *params);
int inst_bmsr(Module *state, Token *type, array_t *params);
int inst_bmsi(Module *state, Token *type, array_t *params);
int inst_bmcr(Module *state, Token *type, array_t *params);
int inst_bmci(Module *state, Token *type, array_t *params);
int inst_calli(Module *state, Token *type, array_t *params);
int inst_callr(Module *state, Token *type, array_t *params);
int inst_finish(Module *state, Token *type, array_t *params);
int inst_finishr(Module *state, Token *type, array_t *params);
int inst_jmpi(Module *state, Token *type, array_t *params);
int inst_jmpr(Module *state, Token *type, array_t *params);
int inst_ret(Module *state, Token *type, array_t *params);
int inst_retval(Module *state, Token *type, array_t *params);


#endif
