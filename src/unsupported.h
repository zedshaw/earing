/** This file contains combinations of macros and types that do not exist in lightning.
 * They should not exist, and instead act as error markers so that the code generation
 * for the ops.c file can be consistent and raise errors for any given type.
 *
 * It was obtained by trying to compile ops.c, and then any jit_*_* macros that were
 * missing were created here.  Takes about two seconds in vim.
 */

#define jit_addci_d(...) assert(!"Type d not supported for addci.") 
#define jit_addci_f(...) assert(!"Type f not supported for addci.") 

#ifndef jit_addci_l
#define jit_addci_l(...) assert(!"Type l not supported for addci.") 
#endif

#define jit_addci_p(...) assert(!"Type p not supported for addci.") 
#define jit_addcr_d(...) assert(!"Type d not supported for addcr.") 
#define jit_addcr_f(...) assert(!"Type f not supported for addcr.") 

#ifndef jit_addcr_l
#define jit_addcr_l(...) assert(!"Type l not supported for addcr.") 
#endif

#define jit_addcr_p(...) assert(!"Type p not supported for addcr.") 
#define jit_addi_d(...) assert(!"Type d not supported for addi.") 
#define jit_addi_f(...) assert(!"Type f not supported for addi.") 
#define jit_addxi_d(...) assert(!"Type d not supported for addxi.") 
#define jit_addxi_f(...) assert(!"Type f not supported for addxi.") 

#ifndef jit_addxi_l
#define jit_addxi_l(...) assert(!"Type l not supported for addxi.") 
#endif

#define jit_addxi_p(...) assert(!"Type p not supported for addxi.") 
#define jit_addxr_d(...) assert(!"Type d not supported for addxr.") 
#define jit_addxr_f(...) assert(!"Type f not supported for addxr.") 

#ifndef jit_addxr_l
#define jit_addxr_l(...) assert(!"Type l not supported for addxr.") 
#endif

#define jit_addxr_p(...) assert(!"Type p not supported for addxr.") 
#define jit_andi_d(...) assert(!"Type d not supported for andi.") 
#define jit_andi_f(...) assert(!"Type f not supported for andi.") 
#define jit_andi_p(...) assert(!"Type p not supported for andi.") 
#define jit_andr_d(...) assert(!"Type d not supported for andr.") 
#define jit_andr_f(...) assert(!"Type f not supported for andr.") 
#define jit_andr_p(...) assert(!"Type p not supported for andr.") 
#define jit_beqi_d(...) assert(!"Type d not supported for beqi.") 
#define jit_beqi_f(...) assert(!"Type f not supported for beqi.") 
#define jit_bgei_d(...) assert(!"Type d not supported for bgei.") 
#define jit_bgei_f(...) assert(!"Type f not supported for bgei.") 
#define jit_bgti_d(...) assert(!"Type d not supported for bgti.") 
#define jit_bgti_f(...) assert(!"Type f not supported for bgti.") 
#define jit_blei_d(...) assert(!"Type d not supported for blei.") 
#define jit_blei_f(...) assert(!"Type f not supported for blei.") 
#define jit_bltgtr_i(...) assert(!"Type i not supported for bltgtr.") 
#define jit_bltgtr_l(...) assert(!"Type l not supported for bltgtr.") 
#define jit_bltgtr_p(...) assert(!"Type p not supported for bltgtr.") 
#define jit_bltgtr_ui(...) assert(!"Type ui not supported for bltgtr.") 
#define jit_blti_d(...) assert(!"Type d not supported for blti.") 
#define jit_blti_f(...) assert(!"Type f not supported for blti.") 
#define jit_bmci_d(...) assert(!"Type d not supported for bmci.") 
#define jit_bmci_f(...) assert(!"Type f not supported for bmci.") 
#define jit_bmci_p(...) assert(!"Type p not supported for bmci.") 
#define jit_bmcr_d(...) assert(!"Type d not supported for bmcr.") 
#define jit_bmcr_f(...) assert(!"Type f not supported for bmcr.") 
#define jit_bmcr_p(...) assert(!"Type p not supported for bmcr.") 
#define jit_bmsi_d(...) assert(!"Type d not supported for bmsi.") 
#define jit_bmsi_f(...) assert(!"Type f not supported for bmsi.") 
#define jit_bmsi_p(...) assert(!"Type p not supported for bmsi.") 
#define jit_bmsr_d(...) assert(!"Type d not supported for bmsr.") 
#define jit_bmsr_uc(...) assert(!"Type uc not supported for bmsr.") 
#define jit_bmsr_f(...) assert(!"Type f not supported for bmsr.") 
#define jit_bmsr_p(...) assert(!"Type p not supported for bmsr.") 
#define jit_bnei_d(...) assert(!"Type d not supported for bnei.") 
#define jit_bnei_f(...) assert(!"Type f not supported for bnei.") 
#define jit_boaddi_d(...) assert(!"Type d not supported for boaddi.") 
#define jit_boaddi_f(...) assert(!"Type f not supported for boaddi.") 
#define jit_boaddi_p(...) assert(!"Type p not supported for boaddi.") 
#define jit_boaddr_d(...) assert(!"Type d not supported for boaddr.") 
#define jit_boaddr_f(...) assert(!"Type f not supported for boaddr.") 
#define jit_boaddr_p(...) assert(!"Type p not supported for boaddr.") 
#define jit_bordr_i(...) assert(!"Type i not supported for bordr.") 
#define jit_bordr_l(...) assert(!"Type l not supported for bordr.") 
#define jit_bordr_p(...) assert(!"Type p not supported for bordr.") 
#define jit_bordr_ui(...) assert(!"Type ui not supported for bordr.") 
#define jit_bosubi_d(...) assert(!"Type d not supported for bosubi.") 
#define jit_bosubi_f(...) assert(!"Type f not supported for bosubi.") 
#define jit_bosubi_p(...) assert(!"Type p not supported for bosubi.") 
#define jit_bosubr_d(...) assert(!"Type d not supported for bosubr.") 
#define jit_bosubr_f(...) assert(!"Type f not supported for bosubr.") 
#define jit_bosubr_p(...) assert(!"Type p not supported for bosubr.") 
#define jit_buneqr_i(...) assert(!"Type i not supported for buneqr.") 
#define jit_buneqr_l(...) assert(!"Type l not supported for buneqr.") 
#define jit_buneqr_p(...) assert(!"Type p not supported for buneqr.") 
#define jit_buneqr_ui(...) assert(!"Type ui not supported for buneqr.") 
#define jit_bunger_i(...) assert(!"Type i not supported for bunger.") 
#define jit_bunger_l(...) assert(!"Type l not supported for bunger.") 
#define jit_bunger_p(...) assert(!"Type p not supported for bunger.") 
#define jit_bunger_ui(...) assert(!"Type ui not supported for bunger.") 
#define jit_bungtr_i(...) assert(!"Type i not supported for bungtr.") 
#define jit_bungtr_l(...) assert(!"Type l not supported for bungtr.") 
#define jit_bungtr_p(...) assert(!"Type p not supported for bungtr.") 
#define jit_bungtr_ui(...) assert(!"Type ui not supported for bungtr.") 
#define jit_bunler_i(...) assert(!"Type i not supported for bunler.") 
#define jit_bunler_l(...) assert(!"Type l not supported for bunler.") 
#define jit_bunler_p(...) assert(!"Type p not supported for bunler.") 
#define jit_bunler_ui(...) assert(!"Type ui not supported for bunler.") 
#define jit_bunltr_i(...) assert(!"Type i not supported for bunltr.") 
#define jit_bunltr_l(...) assert(!"Type l not supported for bunltr.") 
#define jit_bunltr_p(...) assert(!"Type p not supported for bunltr.") 
#define jit_bunltr_ui(...) assert(!"Type ui not supported for bunltr.") 
#define jit_bunordr_i(...) assert(!"Type i not supported for bunordr.") 
#define jit_bunordr_l(...) assert(!"Type l not supported for bunordr.") 
#define jit_bunordr_p(...) assert(!"Type p not supported for bunordr.") 
#define jit_bunordr_ui(...) assert(!"Type ui not supported for bunordr.") 
#define jit_ceilr_d(...) assert(!"Type d not supported for ceilr.") 
#define jit_ceilr_f(...) assert(!"Type f not supported for ceilr.") 
#define jit_ceilr_i(...) assert(!"Type i not supported for ceilr.") 
#define jit_ceilr_l(...) assert(!"Type l not supported for ceilr.") 
#define jit_ceilr_p(...) assert(!"Type p not supported for ceilr.") 
#define jit_ceilr_ui(...) assert(!"Type ui not supported for ceilr.") 
#define jit_divi_d(...) assert(!"Type d not supported for divi.") 
#define jit_divi_f(...) assert(!"Type f not supported for divi.") 
#define jit_divi_p(...) assert(!"Type p not supported for divi.") 
#define jit_divr_p(...) assert(!"Type p not supported for divr.") 
#define jit_eqi_d(...) assert(!"Type d not supported for eqi.") 
#define jit_eqi_f(...) assert(!"Type f not supported for eqi.") 
#define jit_extr_d(...) assert(!"Type d not supported for extr.") 
#define jit_extr_f(...) assert(!"Type f not supported for extr.") 
#define jit_extr_i(...) assert(!"Type i not supported for extr.") 
#define jit_extr_l(...) assert(!"Type l not supported for extr.") 
#define jit_extr_p(...) assert(!"Type p not supported for extr.") 
#define jit_extr_ui(...) assert(!"Type ui not supported for extr.") 
#define jit_floorr_d(...) assert(!"Type d not supported for floorr.") 
#define jit_floorr_f(...) assert(!"Type f not supported for floorr.") 
#define jit_floorr_i(...) assert(!"Type i not supported for floorr.") 
#define jit_floorr_l(...) assert(!"Type l not supported for floorr.") 
#define jit_floorr_p(...) assert(!"Type p not supported for floorr.") 
#define jit_floorr_ui(...) assert(!"Type ui not supported for floorr.") 
#define jit_gei_d(...) assert(!"Type d not supported for gei.") 
#define jit_gei_f(...) assert(!"Type f not supported for gei.") 
#define jit_gti_d(...) assert(!"Type d not supported for gti.") 
#define jit_gti_f(...) assert(!"Type f not supported for gti.") 
#define jit_hmuli_d(...) assert(!"Type d not supported for hmuli.") 
#define jit_hmuli_f(...) assert(!"Type f not supported for hmuli.") 
#define jit_hmuli_p(...) assert(!"Type p not supported for hmuli.") 
#define jit_hmulr_d(...) assert(!"Type d not supported for hmulr.") 
#define jit_hmulr_f(...) assert(!"Type f not supported for hmulr.") 
#define jit_hmulr_p(...) assert(!"Type p not supported for hmulr.") 
#define jit_hton_d(...) assert(!"Type d not supported for hton.") 
#define jit_hton_f(...) assert(!"Type f not supported for hton.") 
#define jit_hton_i(...) assert(!"Type i not supported for hton.") 
#define jit_hton_l(...) assert(!"Type l not supported for hton.") 
#define jit_hton_p(...) assert(!"Type p not supported for hton.") 
#define jit_lei_d(...) assert(!"Type d not supported for lei.") 
#define jit_lei_f(...) assert(!"Type f not supported for lei.") 
#define jit_lshi_d(...) assert(!"Type d not supported for lshi.") 
#define jit_lshi_f(...) assert(!"Type f not supported for lshi.") 
#define jit_lshi_p(...) assert(!"Type p not supported for lshi.") 
#define jit_lshr_d(...) assert(!"Type d not supported for lshr.") 
#define jit_lshr_f(...) assert(!"Type f not supported for lshr.") 
#define jit_lshr_p(...) assert(!"Type p not supported for lshr.") 
#define jit_ltgtr_i(...) assert(!"Type i not supported for ltgtr.") 
#define jit_ltgtr_l(...) assert(!"Type l not supported for ltgtr.") 
#define jit_ltgtr_p(...) assert(!"Type p not supported for ltgtr.") 
#define jit_ltgtr_ui(...) assert(!"Type ui not supported for ltgtr.") 
#define jit_lti_d(...) assert(!"Type d not supported for lti.") 
#define jit_lti_f(...) assert(!"Type f not supported for lti.") 
#define jit_modi_d(...) assert(!"Type d not supported for modi.") 
#define jit_modi_f(...) assert(!"Type f not supported for modi.") 
#define jit_modi_p(...) assert(!"Type p not supported for modi.") 
#define jit_modr_d(...) assert(!"Type d not supported for modr.") 
#define jit_modr_f(...) assert(!"Type f not supported for modr.") 
#define jit_modr_p(...) assert(!"Type p not supported for modr.") 
#define jit_muli_d(...) assert(!"Type d not supported for muli.") 
#define jit_muli_f(...) assert(!"Type f not supported for muli.") 
#define jit_muli_p(...) assert(!"Type p not supported for muli.") 
#define jit_mulr_l_(...) assert(!"Type l_ not supported for mulr.") 
#define jit_mulr_p(...) assert(!"Type p not supported for mulr.") 

#ifndef jit_negr_d
#define jit_negr_d(...) assert(!"Type d not supported for negr.") 
#endif

#ifndef jit_negr_f
#define jit_negr_f(...) assert(!"Type f not supported for negr.") 
#endif

#define jit_negr_p(...) assert(!"Type p not supported for negr.") 
#define jit_negr_ui(...) assert(!"Type ui not supported for negr.") 
#define jit_nei_d(...) assert(!"Type d not supported for nei.") 
#define jit_nei_f(...) assert(!"Type f not supported for nei.") 
#define jit_notr_d(...) assert(!"Type d not supported for notr.") 
#define jit_notr_f(...) assert(!"Type f not supported for notr.") 
#define jit_notr_p(...) assert(!"Type p not supported for notr.") 
#define jit_ntoh_d(...) assert(!"Type d not supported for ntoh.") 
#define jit_ntoh_f(...) assert(!"Type f not supported for ntoh.") 
#define jit_ntoh_i(...) assert(!"Type i not supported for ntoh.") 
#define jit_ntoh_l(...) assert(!"Type l not supported for ntoh.") 
#define jit_ntoh_p(...) assert(!"Type p not supported for ntoh.") 
#define jit_ordr_i(...) assert(!"Type i not supported for ordr.") 
#define jit_ordr_l(...) assert(!"Type l not supported for ordr.") 
#define jit_ordr_p(...) assert(!"Type p not supported for ordr.") 
#define jit_ordr_ui(...) assert(!"Type ui not supported for ordr.") 
#define jit_ori_d(...) assert(!"Type d not supported for ori.") 
#define jit_ori_f(...) assert(!"Type f not supported for ori.") 
#define jit_ori_p(...) assert(!"Type p not supported for ori.") 
#define jit_orr_d(...) assert(!"Type d not supported for orr.") 
#define jit_orr_f(...) assert(!"Type f not supported for orr.") 
#define jit_orr_p(...) assert(!"Type p not supported for orr.") 
#define jit_prepare_l(...) assert(!"Type l not supported for prepare.") 
#define jit_prepare_p(...) assert(!"Type p not supported for prepare.") 
#define jit_prepare_ui(...) assert(!"Type ui not supported for prepare.") 
#define jit_roundr_d(...) assert(!"Type d not supported for roundr.") 
#define jit_roundr_f(...) assert(!"Type f not supported for roundr.") 
#define jit_roundr_i(...) assert(!"Type i not supported for roundr.") 
#define jit_roundr_l(...) assert(!"Type l not supported for roundr.") 
#define jit_roundr_p(...) assert(!"Type p not supported for roundr.") 
#define jit_roundr_ui(...) assert(!"Type ui not supported for roundr.") 
#define jit_rsbi_d(...) assert(!"Type d not supported for rsbi.") 
#define jit_rsbi_f(...) assert(!"Type f not supported for rsbi.") 
#define jit_rshi_d(...) assert(!"Type d not supported for rshi.") 
#define jit_rshi_f(...) assert(!"Type f not supported for rshi.") 
#define jit_rshi_p(...) assert(!"Type p not supported for rshi.") 
#define jit_rshr_d(...) assert(!"Type d not supported for rshr.") 
#define jit_rshr_f(...) assert(!"Type f not supported for rshr.") 
#define jit_rshr_p(...) assert(!"Type p not supported for rshr.") 
#define jit_subci_d(...) assert(!"Type d not supported for subci.") 
#define jit_subci_f(...) assert(!"Type f not supported for subci.") 
#define jit_subci_p(...) assert(!"Type p not supported for subci.") 
#define jit_subcr_d(...) assert(!"Type d not supported for subcr.") 
#define jit_subcr_f(...) assert(!"Type f not supported for subcr.") 

#ifndef jit_subcr_l
#define jit_subcr_l(...) assert(!"Type l not supported for subcr.") 
#endif

#define jit_subcr_p(...) assert(!"Type p not supported for subcr.") 
#define jit_subi_d(...) assert(!"Type d not supported for subi.") 
#define jit_subi_f(...) assert(!"Type f not supported for subi.") 
#define jit_subxi_d(...) assert(!"Type d not supported for subxi.") 
#define jit_subxi_f(...) assert(!"Type f not supported for subxi.") 

#ifndef jit_subxi_l
#define jit_subxi_l(...) assert(!"Type l not supported for subxi.") 
#endif

#define jit_subxi_p(...) assert(!"Type p not supported for subxi.") 
#define jit_subxr_d(...) assert(!"Type d not supported for subxr.") 
#define jit_subxr_f(...) assert(!"Type f not supported for subxr.") 

#ifndef jit_subxr_l
#define jit_subxr_l(...) assert(!"Type l not supported for subxr.") 
#endif

#define jit_subxr_p(...) assert(!"Type p not supported for subxr.") 
#define jit_truncr_d(...) assert(!"Type d not supported for truncr.") 
#define jit_truncr_f(...) assert(!"Type f not supported for truncr.") 
#define jit_truncr_i(...) assert(!"Type i not supported for truncr.") 
#define jit_truncr_l(...) assert(!"Type l not supported for truncr.") 
#define jit_truncr_p(...) assert(!"Type p not supported for truncr.") 
#define jit_truncr_ui(...) assert(!"Type ui not supported for truncr.") 
#define jit_uneqr_i(...) assert(!"Type i not supported for uneqr.") 
#define jit_uneqr_l(...) assert(!"Type l not supported for uneqr.") 
#define jit_uneqr_p(...) assert(!"Type p not supported for uneqr.") 
#define jit_uneqr_ui(...) assert(!"Type ui not supported for uneqr.") 
#define jit_unger_i(...) assert(!"Type i not supported for unger.") 
#define jit_unger_l(...) assert(!"Type l not supported for unger.") 
#define jit_unger_p(...) assert(!"Type p not supported for unger.") 
#define jit_unger_ui(...) assert(!"Type ui not supported for unger.") 
#define jit_ungtr_i(...) assert(!"Type i not supported for ungtr.") 
#define jit_ungtr_l(...) assert(!"Type l not supported for ungtr.") 
#define jit_ungtr_p(...) assert(!"Type p not supported for ungtr.") 
#define jit_ungtr_ui(...) assert(!"Type ui not supported for ungtr.") 
#define jit_unler_i(...) assert(!"Type i not supported for unler.") 
#define jit_unler_l(...) assert(!"Type l not supported for unler.") 
#define jit_unler_p(...) assert(!"Type p not supported for unler.") 
#define jit_unler_ui(...) assert(!"Type ui not supported for unler.") 
#define jit_unltr_i(...) assert(!"Type i not supported for unltr.") 
#define jit_unltr_l(...) assert(!"Type l not supported for unltr.") 
#define jit_unltr_p(...) assert(!"Type p not supported for unltr.") 
#define jit_unltr_ui(...) assert(!"Type ui not supported for unltr.") 
#define jit_unordr_i(...) assert(!"Type i not supported for unordr.") 
#define jit_unordr_l(...) assert(!"Type l not supported for unordr.") 
#define jit_unordr_p(...) assert(!"Type p not supported for unordr.") 
#define jit_unordr_ui(...) assert(!"Type ui not supported for unordr.") 
#define jit_xori_d(...) assert(!"Type d not supported for xori.") 
#define jit_xori_f(...) assert(!"Type f not supported for xori.") 
#define jit_xori_p(...) assert(!"Type p not supported for xori.") 
#define jit_xorr_d(...) assert(!"Type d not supported for xorr.") 
#define jit_xorr_f(...) assert(!"Type f not supported for xorr.") 
#define jit_xorr_p(...) assert(!"Type p not supported for xorr.") 



#ifndef jit_allocai
#define jit_allocai(...) assert(!"You are using lightning 1.2 so no jit_allocai.")
#endif


#ifndef jit_beqr_f
#define jit_beqr_f(...) assert(!"Type f not supported for beqr.");
#endif


#ifndef jit_bger_f
#define jit_bger_f(...) assert(!"Type f not supported for bger.");
#endif


#ifndef jit_bgtr_f
#define jit_bgtr_f(...) assert(!"Type f not supported for bgtr.");
#endif


#ifndef jit_bler_f
#define jit_bler_f(...) assert(!"Type f not supported for bler.");
#endif


#ifndef jit_bltgtr_f
#define jit_bltgtr_f(...) assert(!"Type f not supported for bltgtr.");
#endif


#ifndef jit_bltr_f
#define jit_bltr_f(...) assert(!"Type f not supported for bltr.");
#endif


#ifndef jit_bner_f
#define jit_bner_f(...) assert(!"Type f not supported for bner.");
#endif


#ifndef jit_bordr_f
#define jit_bordr_f(...) assert(!"Type f not supported for bordr.");
#endif


#ifndef jit_buneqr_f
#define jit_buneqr_f(...) assert(!"Type f not supported for buneqr.");
#endif


#ifndef jit_bunger_f
#define jit_bunger_f(...) assert(!"Type f not supported for bunger.");
#endif


#ifndef jit_bungtr_f
#define jit_bungtr_f(...) assert(!"Type f not supported for bungtr.");
#endif


#ifndef jit_bunler_f
#define jit_bunler_f(...) assert(!"Type f not supported for bunler.");
#endif


#ifndef jit_bunltr_f
#define jit_bunltr_f(...) assert(!"Type f not supported for bunltr.");
#endif


#ifndef jit_bunordr_f
#define jit_bunordr_f(...) assert(!"Type f not supported for bunordr.");

// these aren't in lightning 1.2 we use the fact that bunordr_f isn't as well
// to then clean up some dumbassery in lightning
#define JCm(...) (1)
#define JNCm(...) (2)
#undef jit_bger_d
#undef jit_bger_d
#undef jit_bler_d
#undef jit_bltgtr_d
#undef jit_bordr_d

#define jit_bger_d(...) assert(!"Type d not supported for bger.");
#define jit_bler_d(...) assert(!"Type d not supported for bler.");
#define jit_bltgtr_d(...) assert(!"Type d not supported for bltgtr.");
#define jit_bordr_d(...) assert(!"Type d not supported for bordr.");
#endif



#define jit_addr_c(...) assert("Unsupported type c for instruction addr.")
#define jit_addr_c(...) assert("Unsupported type c for instruction addr.")
#define jit_addr_s(...) assert("Unsupported type s for instruction addr.")
#define jit_addr_us(...) assert("Unsupported type us for instruction addr.")

#define jit_addi_c(...) assert("Unsupported type c for instruction addi.")
#define jit_addi_c(...) assert("Unsupported type c for instruction addi.")
#define jit_addi_s(...) assert("Unsupported type s for instruction addi.")
#define jit_addi_us(...) assert("Unsupported type us for instruction addi.")

#define jit_addxr_c(...) assert("Unsupported type c for instruction addxr.")
#define jit_addxr_c(...) assert("Unsupported type c for instruction addxr.")
#define jit_addxr_s(...) assert("Unsupported type s for instruction addxr.")
#define jit_addxr_us(...) assert("Unsupported type us for instruction addxr.")

#define jit_addxi_c(...) assert("Unsupported type c for instruction addxi.")
#define jit_addxi_c(...) assert("Unsupported type c for instruction addxi.")
#define jit_addxi_s(...) assert("Unsupported type s for instruction addxi.")
#define jit_addxi_us(...) assert("Unsupported type us for instruction addxi.")

#define jit_addcr_c(...) assert("Unsupported type c for instruction addcr.")
#define jit_addcr_c(...) assert("Unsupported type c for instruction addcr.")
#define jit_addcr_s(...) assert("Unsupported type s for instruction addcr.")
#define jit_addcr_us(...) assert("Unsupported type us for instruction addcr.")

#define jit_addci_c(...) assert("Unsupported type c for instruction addci.")
#define jit_addci_c(...) assert("Unsupported type c for instruction addci.")
#define jit_addci_s(...) assert("Unsupported type s for instruction addci.")
#define jit_addci_us(...) assert("Unsupported type us for instruction addci.")

#define jit_subr_c(...) assert("Unsupported type c for instruction subr.")
#define jit_subr_c(...) assert("Unsupported type c for instruction subr.")
#define jit_subr_s(...) assert("Unsupported type s for instruction subr.")
#define jit_subr_us(...) assert("Unsupported type us for instruction subr.")

#define jit_subi_c(...) assert("Unsupported type c for instruction subi.")
#define jit_subi_c(...) assert("Unsupported type c for instruction subi.")
#define jit_subi_s(...) assert("Unsupported type s for instruction subi.")
#define jit_subi_us(...) assert("Unsupported type us for instruction subi.")

#define jit_subxr_c(...) assert("Unsupported type c for instruction subxr.")
#define jit_subxr_c(...) assert("Unsupported type c for instruction subxr.")
#define jit_subxr_s(...) assert("Unsupported type s for instruction subxr.")
#define jit_subxr_us(...) assert("Unsupported type us for instruction subxr.")

#define jit_subxi_c(...) assert("Unsupported type c for instruction subxi.")
#define jit_subxi_c(...) assert("Unsupported type c for instruction subxi.")
#define jit_subxi_s(...) assert("Unsupported type s for instruction subxi.")
#define jit_subxi_us(...) assert("Unsupported type us for instruction subxi.")

#define jit_subcr_c(...) assert("Unsupported type c for instruction subcr.")
#define jit_subcr_c(...) assert("Unsupported type c for instruction subcr.")
#define jit_subcr_s(...) assert("Unsupported type s for instruction subcr.")
#define jit_subcr_us(...) assert("Unsupported type us for instruction subcr.")

#define jit_subci_c(...) assert("Unsupported type c for instruction subci.")
#define jit_subci_c(...) assert("Unsupported type c for instruction subci.")
#define jit_subci_s(...) assert("Unsupported type s for instruction subci.")
#define jit_subci_us(...) assert("Unsupported type us for instruction subci.")

#define jit_rsbr_c(...) assert("Unsupported type c for instruction rsbr.")
#define jit_rsbr_c(...) assert("Unsupported type c for instruction rsbr.")
#define jit_rsbr_s(...) assert("Unsupported type s for instruction rsbr.")
#define jit_rsbr_us(...) assert("Unsupported type us for instruction rsbr.")

#define jit_rsbi_c(...) assert("Unsupported type c for instruction rsbi.")
#define jit_rsbi_c(...) assert("Unsupported type c for instruction rsbi.")
#define jit_rsbi_s(...) assert("Unsupported type s for instruction rsbi.")
#define jit_rsbi_us(...) assert("Unsupported type us for instruction rsbi.")

#define jit_mulr_c(...) assert("Unsupported type c for instruction mulr.")
#define jit_mulr_c(...) assert("Unsupported type c for instruction mulr.")
#define jit_mulr_s(...) assert("Unsupported type s for instruction mulr.")
#define jit_mulr_us(...) assert("Unsupported type us for instruction mulr.")

#define jit_muli_c(...) assert("Unsupported type c for instruction muli.")
#define jit_muli_c(...) assert("Unsupported type c for instruction muli.")
#define jit_muli_s(...) assert("Unsupported type s for instruction muli.")
#define jit_muli_us(...) assert("Unsupported type us for instruction muli.")

#define jit_hmulr_c(...) assert("Unsupported type c for instruction hmulr.")
#define jit_hmulr_c(...) assert("Unsupported type c for instruction hmulr.")
#define jit_hmulr_s(...) assert("Unsupported type s for instruction hmulr.")
#define jit_hmulr_us(...) assert("Unsupported type us for instruction hmulr.")

#define jit_hmuli_c(...) assert("Unsupported type c for instruction hmuli.")
#define jit_hmuli_c(...) assert("Unsupported type c for instruction hmuli.")
#define jit_hmuli_s(...) assert("Unsupported type s for instruction hmuli.")
#define jit_hmuli_us(...) assert("Unsupported type us for instruction hmuli.")

#define jit_divr_c(...) assert("Unsupported type c for instruction divr.")
#define jit_divr_c(...) assert("Unsupported type c for instruction divr.")
#define jit_divr_s(...) assert("Unsupported type s for instruction divr.")
#define jit_divr_us(...) assert("Unsupported type us for instruction divr.")

#define jit_divi_c(...) assert("Unsupported type c for instruction divi.")
#define jit_divi_c(...) assert("Unsupported type c for instruction divi.")
#define jit_divi_s(...) assert("Unsupported type s for instruction divi.")
#define jit_divi_us(...) assert("Unsupported type us for instruction divi.")

#define jit_modr_c(...) assert("Unsupported type c for instruction modr.")
#define jit_modr_c(...) assert("Unsupported type c for instruction modr.")
#define jit_modr_s(...) assert("Unsupported type s for instruction modr.")
#define jit_modr_us(...) assert("Unsupported type us for instruction modr.")

#define jit_modi_c(...) assert("Unsupported type c for instruction modi.")
#define jit_modi_c(...) assert("Unsupported type c for instruction modi.")
#define jit_modi_s(...) assert("Unsupported type s for instruction modi.")
#define jit_modi_us(...) assert("Unsupported type us for instruction modi.")

#define jit_andr_c(...) assert("Unsupported type c for instruction andr.")
#define jit_andr_c(...) assert("Unsupported type c for instruction andr.")
#define jit_andr_s(...) assert("Unsupported type s for instruction andr.")
#define jit_andr_us(...) assert("Unsupported type us for instruction andr.")

#define jit_andi_c(...) assert("Unsupported type c for instruction andi.")
#define jit_andi_c(...) assert("Unsupported type c for instruction andi.")
#define jit_andi_s(...) assert("Unsupported type s for instruction andi.")
#define jit_andi_us(...) assert("Unsupported type us for instruction andi.")

#define jit_orr_c(...) assert("Unsupported type c for instruction orr.")
#define jit_orr_c(...) assert("Unsupported type c for instruction orr.")
#define jit_orr_s(...) assert("Unsupported type s for instruction orr.")
#define jit_orr_us(...) assert("Unsupported type us for instruction orr.")

#define jit_ori_c(...) assert("Unsupported type c for instruction ori.")
#define jit_ori_c(...) assert("Unsupported type c for instruction ori.")
#define jit_ori_s(...) assert("Unsupported type s for instruction ori.")
#define jit_ori_us(...) assert("Unsupported type us for instruction ori.")

#define jit_xorr_c(...) assert("Unsupported type c for instruction xorr.")
#define jit_xorr_c(...) assert("Unsupported type c for instruction xorr.")
#define jit_xorr_s(...) assert("Unsupported type s for instruction xorr.")
#define jit_xorr_us(...) assert("Unsupported type us for instruction xorr.")

#define jit_xori_c(...) assert("Unsupported type c for instruction xori.")
#define jit_xori_c(...) assert("Unsupported type c for instruction xori.")
#define jit_xori_s(...) assert("Unsupported type s for instruction xori.")
#define jit_xori_us(...) assert("Unsupported type us for instruction xori.")

#define jit_lshr_c(...) assert("Unsupported type c for instruction lshr.")
#define jit_lshr_c(...) assert("Unsupported type c for instruction lshr.")
#define jit_lshr_s(...) assert("Unsupported type s for instruction lshr.")
#define jit_lshr_us(...) assert("Unsupported type us for instruction lshr.")

#define jit_lshi_c(...) assert("Unsupported type c for instruction lshi.")
#define jit_lshi_c(...) assert("Unsupported type c for instruction lshi.")
#define jit_lshi_s(...) assert("Unsupported type s for instruction lshi.")
#define jit_lshi_us(...) assert("Unsupported type us for instruction lshi.")

#define jit_rshr_c(...) assert("Unsupported type c for instruction rshr.")
#define jit_rshr_c(...) assert("Unsupported type c for instruction rshr.")
#define jit_rshr_s(...) assert("Unsupported type s for instruction rshr.")
#define jit_rshr_us(...) assert("Unsupported type us for instruction rshr.")

#define jit_rshi_c(...) assert("Unsupported type c for instruction rshi.")
#define jit_rshi_c(...) assert("Unsupported type c for instruction rshi.")
#define jit_rshi_s(...) assert("Unsupported type s for instruction rshi.")
#define jit_rshi_us(...) assert("Unsupported type us for instruction rshi.")

#define jit_negr_c(...) assert("Unsupported type c for instruction negr.")
#define jit_negr_c(...) assert("Unsupported type c for instruction negr.")
#define jit_negr_s(...) assert("Unsupported type s for instruction negr.")
#define jit_negr_us(...) assert("Unsupported type us for instruction negr.")

#define jit_xori_c(...) assert("Unsupported type c for instruction xori.")
#define jit_xori_c(...) assert("Unsupported type c for instruction xori.")
#define jit_xori_s(...) assert("Unsupported type s for instruction xori.")
#define jit_xori_s(...) assert("Unsupported type s for instruction xori.")

#define jit_ltr_c(...) assert("Unsupported type c for instruction ltr.")
#define jit_ltr_c(...) assert("Unsupported type c for instruction ltr.")
#define jit_ltr_s(...) assert("Unsupported type s for instruction ltr.")
#define jit_ltr_us(...) assert("Unsupported type us for instruction ltr.")

#define jit_lti_c(...) assert("Unsupported type c for instruction lti.")
#define jit_lti_c(...) assert("Unsupported type c for instruction lti.")
#define jit_lti_s(...) assert("Unsupported type s for instruction lti.")
#define jit_lti_us(...) assert("Unsupported type us for instruction lti.")

#define jit_ler_c(...) assert("Unsupported type c for instruction ler.")
#define jit_ler_c(...) assert("Unsupported type c for instruction ler.")
#define jit_ler_s(...) assert("Unsupported type s for instruction ler.")
#define jit_ler_us(...) assert("Unsupported type us for instruction ler.")

#define jit_lei_c(...) assert("Unsupported type c for instruction lei.")
#define jit_lei_c(...) assert("Unsupported type c for instruction lei.")
#define jit_lei_s(...) assert("Unsupported type s for instruction lei.")
#define jit_lei_us(...) assert("Unsupported type us for instruction lei.")

#define jit_gtr_c(...) assert("Unsupported type c for instruction gtr.")
#define jit_gtr_c(...) assert("Unsupported type c for instruction gtr.")
#define jit_gtr_s(...) assert("Unsupported type s for instruction gtr.")
#define jit_gtr_us(...) assert("Unsupported type us for instruction gtr.")

#define jit_gti_c(...) assert("Unsupported type c for instruction gti.")
#define jit_gti_c(...) assert("Unsupported type c for instruction gti.")
#define jit_gti_s(...) assert("Unsupported type s for instruction gti.")
#define jit_gti_us(...) assert("Unsupported type us for instruction gti.")

#define jit_ger_c(...) assert("Unsupported type c for instruction ger.")
#define jit_ger_c(...) assert("Unsupported type c for instruction ger.")
#define jit_ger_s(...) assert("Unsupported type s for instruction ger.")
#define jit_ger_us(...) assert("Unsupported type us for instruction ger.")

#define jit_gei_c(...) assert("Unsupported type c for instruction gei.")
#define jit_gei_c(...) assert("Unsupported type c for instruction gei.")
#define jit_gei_s(...) assert("Unsupported type s for instruction gei.")
#define jit_gei_us(...) assert("Unsupported type us for instruction gei.")

#define jit_eqr_c(...) assert("Unsupported type c for instruction eqr.")
#define jit_eqr_c(...) assert("Unsupported type c for instruction eqr.")
#define jit_eqr_s(...) assert("Unsupported type s for instruction eqr.")
#define jit_eqr_us(...) assert("Unsupported type us for instruction eqr.")

#define jit_eqi_c(...) assert("Unsupported type c for instruction eqi.")
#define jit_eqi_c(...) assert("Unsupported type c for instruction eqi.")
#define jit_eqi_s(...) assert("Unsupported type s for instruction eqi.")
#define jit_eqi_us(...) assert("Unsupported type us for instruction eqi.")

#define jit_ner_c(...) assert("Unsupported type c for instruction ner.")
#define jit_ner_c(...) assert("Unsupported type c for instruction ner.")
#define jit_ner_s(...) assert("Unsupported type s for instruction ner.")
#define jit_ner_us(...) assert("Unsupported type us for instruction ner.")

#define jit_nei_c(...) assert("Unsupported type c for instruction nei.")
#define jit_nei_c(...) assert("Unsupported type c for instruction nei.")
#define jit_nei_s(...) assert("Unsupported type s for instruction nei.")
#define jit_nei_us(...) assert("Unsupported type us for instruction nei.")

#define jit_unltr_c(...) assert("Unsupported type c for instruction unltr.")
#define jit_unltr_c(...) assert("Unsupported type c for instruction unltr.")
#define jit_unltr_s(...) assert("Unsupported type s for instruction unltr.")
#define jit_unltr_us(...) assert("Unsupported type us for instruction unltr.")

#define jit_unler_c(...) assert("Unsupported type c for instruction unler.")
#define jit_unler_c(...) assert("Unsupported type c for instruction unler.")
#define jit_unler_s(...) assert("Unsupported type s for instruction unler.")
#define jit_unler_us(...) assert("Unsupported type us for instruction unler.")

#define jit_ungtr_c(...) assert("Unsupported type c for instruction ungtr.")
#define jit_ungtr_c(...) assert("Unsupported type c for instruction ungtr.")
#define jit_ungtr_s(...) assert("Unsupported type s for instruction ungtr.")
#define jit_ungtr_us(...) assert("Unsupported type us for instruction ungtr.")

#define jit_unger_c(...) assert("Unsupported type c for instruction unger.")
#define jit_unger_c(...) assert("Unsupported type c for instruction unger.")
#define jit_unger_s(...) assert("Unsupported type s for instruction unger.")
#define jit_unger_us(...) assert("Unsupported type us for instruction unger.")

#define jit_uneqr_c(...) assert("Unsupported type c for instruction uneqr.")
#define jit_uneqr_c(...) assert("Unsupported type c for instruction uneqr.")
#define jit_uneqr_s(...) assert("Unsupported type s for instruction uneqr.")
#define jit_uneqr_us(...) assert("Unsupported type us for instruction uneqr.")

#define jit_ltgtr_c(...) assert("Unsupported type c for instruction ltgtr.")
#define jit_ltgtr_c(...) assert("Unsupported type c for instruction ltgtr.")
#define jit_ltgtr_s(...) assert("Unsupported type s for instruction ltgtr.")
#define jit_ltgtr_us(...) assert("Unsupported type us for instruction ltgtr.")

#define jit_ordr_c(...) assert("Unsupported type c for instruction ordr.")
#define jit_ordr_c(...) assert("Unsupported type c for instruction ordr.")
#define jit_ordr_s(...) assert("Unsupported type s for instruction ordr.")
#define jit_ordr_us(...) assert("Unsupported type us for instruction ordr.")

#define jit_unordr_c(...) assert("Unsupported type c for instruction unordr.")
#define jit_unordr_c(...) assert("Unsupported type c for instruction unordr.")
#define jit_unordr_s(...) assert("Unsupported type s for instruction unordr.")
#define jit_unordr_us(...) assert("Unsupported type us for instruction unordr.")

#define jit_movr_c(...) assert("Unsupported type c for instruction movr.")
#define jit_movr_c(...) assert("Unsupported type c for instruction movr.")
#define jit_movr_s(...) assert("Unsupported type s for instruction movr.")
#define jit_movr_us(...) assert("Unsupported type us for instruction movr.")

#define jit_movi_c(...) assert("Unsupported type c for instruction movi.")
#define jit_movi_c(...) assert("Unsupported type c for instruction movi.")
#define jit_movi_s(...) assert("Unsupported type s for instruction movi.")
#define jit_movi_us(...) assert("Unsupported type us for instruction movi.")

#define jit_extr_c(...) assert("Unsupported type c for instruction extr.")
#define jit_extr_c(...) assert("Unsupported type c for instruction extr.")
#define jit_extr_s(...) assert("Unsupported type s for instruction extr.")
#define jit_extr_us(...) assert("Unsupported type us for instruction extr.")

#define jit_roundr_c(...) assert("Unsupported type c for instruction roundr.")
#define jit_roundr_c(...) assert("Unsupported type c for instruction roundr.")
#define jit_roundr_s(...) assert("Unsupported type s for instruction roundr.")
#define jit_roundr_us(...) assert("Unsupported type us for instruction roundr.")

#define jit_truncr_c(...) assert("Unsupported type c for instruction truncr.")
#define jit_truncr_c(...) assert("Unsupported type c for instruction truncr.")
#define jit_truncr_s(...) assert("Unsupported type s for instruction truncr.")
#define jit_truncr_us(...) assert("Unsupported type us for instruction truncr.")

#define jit_floorr_c(...) assert("Unsupported type c for instruction floorr.")
#define jit_floorr_c(...) assert("Unsupported type c for instruction floorr.")
#define jit_floorr_s(...) assert("Unsupported type s for instruction floorr.")
#define jit_floorr_us(...) assert("Unsupported type us for instruction floorr.")

#define jit_ceilr_c(...) assert("Unsupported type c for instruction ceilr.")
#define jit_ceilr_c(...) assert("Unsupported type c for instruction ceilr.")
#define jit_ceilr_s(...) assert("Unsupported type s for instruction ceilr.")
#define jit_ceilr_us(...) assert("Unsupported type us for instruction ceilr.")

#define jit_hton_c(...) assert("Unsupported type c for instruction hton.")
#define jit_hton_c(...) assert("Unsupported type c for instruction hton.")
#define jit_hton_s(...) assert("Unsupported type s for instruction hton.")

#define jit_ntoh_c(...) assert("Unsupported type c for instruction ntoh.")
#define jit_ntoh_c(...) assert("Unsupported type c for instruction ntoh.")
#define jit_ntoh_s(...) assert("Unsupported type s for instruction ntoh.")

#define jit_bltr_c(...) assert("Unsupported type c for instruction bltr.")
#define jit_bltr_c(...) assert("Unsupported type c for instruction bltr.")
#define jit_bltr_s(...) assert("Unsupported type s for instruction bltr.")
#define jit_bltr_us(...) assert("Unsupported type us for instruction bltr.")

#define jit_blti_c(...) assert("Unsupported type c for instruction blti.")
#define jit_blti_c(...) assert("Unsupported type c for instruction blti.")
#define jit_blti_s(...) assert("Unsupported type s for instruction blti.")
#define jit_blti_us(...) assert("Unsupported type us for instruction blti.")

#define jit_bler_c(...) assert("Unsupported type c for instruction bler.")
#define jit_bler_c(...) assert("Unsupported type c for instruction bler.")
#define jit_bler_s(...) assert("Unsupported type s for instruction bler.")
#define jit_bler_us(...) assert("Unsupported type us for instruction bler.")

#define jit_blei_c(...) assert("Unsupported type c for instruction blei.")
#define jit_blei_c(...) assert("Unsupported type c for instruction blei.")
#define jit_blei_s(...) assert("Unsupported type s for instruction blei.")
#define jit_blei_us(...) assert("Unsupported type us for instruction blei.")

#define jit_bgtr_c(...) assert("Unsupported type c for instruction bgtr.")
#define jit_bgtr_c(...) assert("Unsupported type c for instruction bgtr.")
#define jit_bgtr_s(...) assert("Unsupported type s for instruction bgtr.")
#define jit_bgtr_us(...) assert("Unsupported type us for instruction bgtr.")

#define jit_bgti_c(...) assert("Unsupported type c for instruction bgti.")
#define jit_bgti_c(...) assert("Unsupported type c for instruction bgti.")
#define jit_bgti_s(...) assert("Unsupported type s for instruction bgti.")
#define jit_bgti_us(...) assert("Unsupported type us for instruction bgti.")

#define jit_bger_c(...) assert("Unsupported type c for instruction bger.")
#define jit_bger_c(...) assert("Unsupported type c for instruction bger.")
#define jit_bger_s(...) assert("Unsupported type s for instruction bger.")
#define jit_bger_us(...) assert("Unsupported type us for instruction bger.")

#define jit_bgei_c(...) assert("Unsupported type c for instruction bgei.")
#define jit_bgei_c(...) assert("Unsupported type c for instruction bgei.")
#define jit_bgei_s(...) assert("Unsupported type s for instruction bgei.")
#define jit_bgei_us(...) assert("Unsupported type us for instruction bgei.")

#define jit_beqr_c(...) assert("Unsupported type c for instruction beqr.")
#define jit_beqr_c(...) assert("Unsupported type c for instruction beqr.")
#define jit_beqr_s(...) assert("Unsupported type s for instruction beqr.")
#define jit_beqr_us(...) assert("Unsupported type us for instruction beqr.")

#define jit_beqi_c(...) assert("Unsupported type c for instruction beqi.")
#define jit_beqi_c(...) assert("Unsupported type c for instruction beqi.")
#define jit_beqi_s(...) assert("Unsupported type s for instruction beqi.")
#define jit_beqi_us(...) assert("Unsupported type us for instruction beqi.")

#define jit_bner_c(...) assert("Unsupported type c for instruction bner.")
#define jit_bner_c(...) assert("Unsupported type c for instruction bner.")
#define jit_bner_s(...) assert("Unsupported type s for instruction bner.")
#define jit_bner_us(...) assert("Unsupported type us for instruction bner.")

#define jit_bnei_c(...) assert("Unsupported type c for instruction bnei.")
#define jit_bnei_c(...) assert("Unsupported type c for instruction bnei.")
#define jit_bnei_s(...) assert("Unsupported type s for instruction bnei.")
#define jit_bnei_us(...) assert("Unsupported type us for instruction bnei.")

#define jit_bunltr_c(...) assert("Unsupported type c for instruction bunltr.")
#define jit_bunltr_c(...) assert("Unsupported type c for instruction bunltr.")
#define jit_bunltr_s(...) assert("Unsupported type s for instruction bunltr.")
#define jit_bunltr_us(...) assert("Unsupported type us for instruction bunltr.")

#define jit_bunler_c(...) assert("Unsupported type c for instruction bunler.")
#define jit_bunler_c(...) assert("Unsupported type c for instruction bunler.")
#define jit_bunler_s(...) assert("Unsupported type s for instruction bunler.")
#define jit_bunler_us(...) assert("Unsupported type us for instruction bunler.")

#define jit_bungtr_c(...) assert("Unsupported type c for instruction bungtr.")
#define jit_bungtr_c(...) assert("Unsupported type c for instruction bungtr.")
#define jit_bungtr_s(...) assert("Unsupported type s for instruction bungtr.")
#define jit_bungtr_us(...) assert("Unsupported type us for instruction bungtr.")

#define jit_bunger_c(...) assert("Unsupported type c for instruction bunger.")
#define jit_bunger_c(...) assert("Unsupported type c for instruction bunger.")
#define jit_bunger_s(...) assert("Unsupported type s for instruction bunger.")
#define jit_bunger_us(...) assert("Unsupported type us for instruction bunger.")

#define jit_buneqr_c(...) assert("Unsupported type c for instruction buneqr.")
#define jit_buneqr_c(...) assert("Unsupported type c for instruction buneqr.")
#define jit_buneqr_s(...) assert("Unsupported type s for instruction buneqr.")
#define jit_buneqr_us(...) assert("Unsupported type us for instruction buneqr.")

#define jit_bltgtr_c(...) assert("Unsupported type c for instruction bltgtr.")
#define jit_bltgtr_c(...) assert("Unsupported type c for instruction bltgtr.")
#define jit_bltgtr_s(...) assert("Unsupported type s for instruction bltgtr.")
#define jit_bltgtr_us(...) assert("Unsupported type us for instruction bltgtr.")

#define jit_bordr_c(...) assert("Unsupported type c for instruction bordr.")
#define jit_bordr_c(...) assert("Unsupported type c for instruction bordr.")
#define jit_bordr_s(...) assert("Unsupported type s for instruction bordr.")
#define jit_bordr_us(...) assert("Unsupported type us for instruction bordr.")

#define jit_bunordr_c(...) assert("Unsupported type c for instruction bunordr.")
#define jit_bunordr_c(...) assert("Unsupported type c for instruction bunordr.")
#define jit_bunordr_s(...) assert("Unsupported type s for instruction bunordr.")
#define jit_bunordr_us(...) assert("Unsupported type us for instruction bunordr.")

#define jit_bmsr_c(...) assert("Unsupported type c for instruction bmsr.")
#define jit_bmsr_c(...) assert("Unsupported type c for instruction bmsr.")
#define jit_bmsr_s(...) assert("Unsupported type s for instruction bmsr.")
#define jit_bmsr_us(...) assert("Unsupported type us for instruction bmsr.")

#define jit_bmsi_c(...) assert("Unsupported type c for instruction bmsi.")
#define jit_bmsi_c(...) assert("Unsupported type c for instruction bmsi.")
#define jit_bmsi_s(...) assert("Unsupported type s for instruction bmsi.")
#define jit_bmsi_us(...) assert("Unsupported type us for instruction bmsi.")

#define jit_bmcr_c(...) assert("Unsupported type c for instruction bmcr.")
#define jit_bmcr_c(...) assert("Unsupported type c for instruction bmcr.")
#define jit_bmcr_s(...) assert("Unsupported type s for instruction bmcr.")
#define jit_bmcr_us(...) assert("Unsupported type us for instruction bmcr.")

#define jit_bmci_c(...) assert("Unsupported type c for instruction bmci.")
#define jit_bmci_c(...) assert("Unsupported type c for instruction bmci.")
#define jit_bmci_s(...) assert("Unsupported type s for instruction bmci.")
#define jit_bmci_us(...) assert("Unsupported type us for instruction bmci.")

#define jit_addr_uc(...) assert("Unsupported type uc for instruction addr.")
#define jit_addi_uc(...) assert("Unsupported type uc for instruction addi.")
#define jit_addxr_uc(...) assert("Unsupported type uc for instruction addxr.")
#define jit_addxi_uc(...) assert("Unsupported type uc for instruction addxi.")
#define jit_addcr_uc(...) assert("Unsupported type uc for instruction addcr.")
#define jit_addci_uc(...) assert("Unsupported type uc for instruction addci.")
#define jit_subr_uc(...) assert("Unsupported type uc for instruction subr.")
#define jit_subi_uc(...) assert("Unsupported type uc for instruction subi.")
#define jit_subxr_uc(...) assert("Unsupported type uc for instruction subxr.")
#define jit_subxi_uc(...) assert("Unsupported type uc for instruction subxi.")
#define jit_subcr_uc(...) assert("Unsupported type uc for instruction subcr.")
#define jit_subci_uc(...) assert("Unsupported type uc for instruction subci.")
#define jit_rsbr_uc(...) assert("Unsupported type uc for instruction rsbr.")
#define jit_rsbi_uc(...) assert("Unsupported type uc for instruction rsbi.")
#define jit_mulr_uc(...) assert("Unsupported type uc for instruction mulr.")
#define jit_muli_uc(...) assert("Unsupported type uc for instruction muli.")
#define jit_mulr_ul_(...) assert("Unsupported type ul for instruction mulr.")
#define jit_hmulr_uc(...) assert("Unsupported type uc for instruction hmulr.")
#define jit_hmuli_uc(...) assert("Unsupported type uc for instruction hmuli.")
#define jit_divr_uc(...) assert("Unsupported type uc for instruction divr.")
#define jit_divi_uc(...) assert("Unsupported type uc for instruction divi.")
#define jit_modr_uc(...) assert("Unsupported type uc for instruction modr.")
#define jit_modi_uc(...) assert("Unsupported type uc for instruction modi.")
#define jit_andr_uc(...) assert("Unsupported type uc for instruction andr.")
#define jit_andi_uc(...) assert("Unsupported type uc for instruction andi.")
#define jit_orr_uc(...) assert("Unsupported type uc for instruction orr.")
#define jit_ori_uc(...) assert("Unsupported type uc for instruction ori.")
#define jit_xorr_uc(...) assert("Unsupported type uc for instruction xorr.")
#define jit_xori_uc(...) assert("Unsupported type uc for instruction xori.")
#define jit_lshr_uc(...) assert("Unsupported type uc for instruction lshr.")
#define jit_lshi_uc(...) assert("Unsupported type uc for instruction lshi.")
#define jit_rshr_uc(...) assert("Unsupported type uc for instruction rshr.")
#define jit_rshi_uc(...) assert("Unsupported type uc for instruction rshi.")
#define jit_negr_ul(...) assert("Unsupported type ul for instruction negr.")
#define jit_negr_uc(...) assert("Unsupported type uc for instruction negr.")
#define jit_ltr_uc(...) assert("Unsupported type uc for instruction ltr.")
#define jit_lti_uc(...) assert("Unsupported type uc for instruction lti.")
#define jit_ler_uc(...) assert("Unsupported type uc for instruction ler.")
#define jit_lei_uc(...) assert("Unsupported type uc for instruction lei.")
#define jit_gtr_uc(...) assert("Unsupported type uc for instruction gtr.")
#define jit_gti_uc(...) assert("Unsupported type uc for instruction gti.")
#define jit_ger_uc(...) assert("Unsupported type uc for instruction ger.")
#define jit_gei_uc(...) assert("Unsupported type uc for instruction gei.")
#define jit_eqr_uc(...) assert("Unsupported type uc for instruction eqr.")
#define jit_eqi_uc(...) assert("Unsupported type uc for instruction eqi.")
#define jit_ner_uc(...) assert("Unsupported type uc for instruction ner.")
#define jit_nei_uc(...) assert("Unsupported type uc for instruction nei.")
#define jit_unltr_ul(...) assert("Unsupported type ul for instruction unltr.")
#define jit_unltr_uc(...) assert("Unsupported type uc for instruction unltr.")
#define jit_unler_ul(...) assert("Unsupported type ul for instruction unler.")
#define jit_unler_uc(...) assert("Unsupported type uc for instruction unler.")
#define jit_ungtr_ul(...) assert("Unsupported type ul for instruction ungtr.")
#define jit_ungtr_uc(...) assert("Unsupported type uc for instruction ungtr.")
#define jit_unger_ul(...) assert("Unsupported type ul for instruction unger.")
#define jit_unger_uc(...) assert("Unsupported type uc for instruction unger.")
#define jit_uneqr_ul(...) assert("Unsupported type ul for instruction uneqr.")
#define jit_uneqr_uc(...) assert("Unsupported type uc for instruction uneqr.")
#define jit_ltgtr_ul(...) assert("Unsupported type ul for instruction ltgtr.")
#define jit_ltgtr_uc(...) assert("Unsupported type uc for instruction ltgtr.")
#define jit_ordr_ul(...) assert("Unsupported type ul for instruction ordr.")
#define jit_ordr_uc(...) assert("Unsupported type uc for instruction ordr.")
#define jit_unordr_ul(...) assert("Unsupported type ul for instruction unordr.")
#define jit_unordr_uc(...) assert("Unsupported type uc for instruction unordr.")
#define jit_movr_uc(...) assert("Unsupported type uc for instruction movr.")
#define jit_movi_uc(...) assert("Unsupported type uc for instruction movi.")
#define jit_extr_ul(...) assert("Unsupported type ul for instruction extr.")
#define jit_extr_uc(...) assert("Unsupported type uc for instruction extr.")
#define jit_roundr_ul(...) assert("Unsupported type ul for instruction roundr.")
#define jit_roundr_uc(...) assert("Unsupported type uc for instruction roundr.")
#define jit_truncr_ul(...) assert("Unsupported type ul for instruction truncr.")
#define jit_truncr_uc(...) assert("Unsupported type uc for instruction truncr.")
#define jit_floorr_ul(...) assert("Unsupported type ul for instruction floorr.")
#define jit_floorr_uc(...) assert("Unsupported type uc for instruction floorr.")
#define jit_ceilr_ul(...) assert("Unsupported type ul for instruction ceilr.")
#define jit_ceilr_uc(...) assert("Unsupported type uc for instruction ceilr.")
#define jit_hton_ul(...) assert("Unsupported type ul for instruction hton.")
#define jit_hton_uc(...) assert("Unsupported type uc for instruction hton.")
#define jit_ntoh_ul(...) assert("Unsupported type ul for instruction ntoh.")
#define jit_ntoh_uc(...) assert("Unsupported type uc for instruction ntoh.")
#define jit_bltr_uc(...) assert("Unsupported type uc for instruction bltr.")
#define jit_blti_uc(...) assert("Unsupported type uc for instruction blti.")
#define jit_bler_uc(...) assert("Unsupported type uc for instruction bler.")
#define jit_blei_uc(...) assert("Unsupported type uc for instruction blei.")
#define jit_bgtr_uc(...) assert("Unsupported type uc for instruction bgtr.")
#define jit_bgti_uc(...) assert("Unsupported type uc for instruction bgti.")
#define jit_bger_uc(...) assert("Unsupported type uc for instruction bger.")
#define jit_bgei_uc(...) assert("Unsupported type uc for instruction bgei.")
#define jit_beqr_uc(...) assert("Unsupported type uc for instruction beqr.")
#define jit_beqi_uc(...) assert("Unsupported type uc for instruction beqi.")
#define jit_bner_uc(...) assert("Unsupported type uc for instruction bner.")
#define jit_bnei_uc(...) assert("Unsupported type uc for instruction bnei.")
#define jit_bunltr_ul(...) assert("Unsupported type ul for instruction bunltr.")
#define jit_bunltr_uc(...) assert("Unsupported type uc for instruction bunltr.")
#define jit_bunler_ul(...) assert("Unsupported type ul for instruction bunler.")
#define jit_bunler_uc(...) assert("Unsupported type uc for instruction bunler.")
#define jit_bungtr_ul(...) assert("Unsupported type ul for instruction bungtr.")
#define jit_bungtr_uc(...) assert("Unsupported type uc for instruction bungtr.")
#define jit_bunger_ul(...) assert("Unsupported type ul for instruction bunger.")
#define jit_bunger_uc(...) assert("Unsupported type uc for instruction bunger.")
#define jit_buneqr_ul(...) assert("Unsupported type ul for instruction buneqr.")
#define jit_buneqr_uc(...) assert("Unsupported type uc for instruction buneqr.")
#define jit_bltgtr_ul(...) assert("Unsupported type ul for instruction bltgtr.")
#define jit_bltgtr_uc(...) assert("Unsupported type uc for instruction bltgtr.")
#define jit_bordr_ul(...) assert("Unsupported type ul for instruction bordr.")
#define jit_bordr_uc(...) assert("Unsupported type uc for instruction bordr.")
#define jit_bunordr_ul(...) assert("Unsupported type ul for instruction bunordr.")
#define jit_bunordr_uc(...) assert("Unsupported type uc for instruction bunordr.")
#define jit_bmsi_uc(...) assert("Unsupported type uc for instruction bmsi.")
#define jit_bmcr_uc(...) assert("Unsupported type uc for instruction bmcr.")
#define jit_bmci_uc(...) assert("Unsupported type uc for instruction bmci.")
