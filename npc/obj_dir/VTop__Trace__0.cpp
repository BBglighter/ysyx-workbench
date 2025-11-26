// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VTop__Syms.h"


void VTop___024root__trace_chg_0_sub_0(VTop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VTop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_0\n"); );
    // Body
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VTop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VTop___024root__trace_chg_0_sub_0(VTop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_0_sub_0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.Top__DOT__reg_pc),32);
        bufp->chgIData(oldp+1,(vlSelfRef.Top__DOT___IFU_out_bits_instr),32);
        bufp->chgCData(oldp+2,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType),4);
        bufp->chgCData(oldp+3,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_aluOp),4);
        bufp->chgCData(oldp+4,(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType),3);
        bufp->chgCData(oldp+5,(((0x0013U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))
                                 ? 0U : (0x0067U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN)))),4);
        bufp->chgCData(oldp+6,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType),4);
        bufp->chgIData(oldp+7,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src1),32);
        bufp->chgIData(oldp+8,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src2),32);
        bufp->chgIData(oldp+9,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_imm),32);
        bufp->chgIData(oldp+10,(((1U == ((0x0013U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))
                                          ? 0U : (0x0067U 
                                                  == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))))
                                  ? vlSelfRef.__VdfgRegularize_he50b618e_0_0
                                  : ((IData)(4U) + vlSelfRef.Top__DOT__reg_pc))),32);
        bufp->chgIData(oldp+11,(vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata),32);
        bufp->chgIData(oldp+12,(((1U & ((~ ((2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                            | ((1U 
                                                == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                               | (0U 
                                                  == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))))) 
                                        | (4U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))))
                                  ? 0U : vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src1)),32);
        bufp->chgIData(oldp+13,((((4U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                  | ((2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                     | (1U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))))
                                  ? vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_imm
                                  : ((0U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))
                                      ? vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src2
                                      : 0U))),32);
        bufp->chgIData(oldp+14,(vlSelfRef.Top__DOT__EXU__DOT__alu__DOT__io_rlt),32);
        bufp->chgIData(oldp+15,(((IData)(4U) + vlSelfRef.Top__DOT__reg_pc)),32);
        bufp->chgIData(oldp+16,(((0U == (0x0000001fU 
                                         & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                            >> 0x0000000fU)))
                                  ? 0U : vlSelfRef.Top__DOT__RF__DOT__casez_tmp)),32);
        bufp->chgIData(oldp+17,(((0U == (0x0000001fU 
                                         & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                            >> 0x00000014U)))
                                  ? 0U : vlSelfRef.Top__DOT__RF__DOT__casez_tmp_0)),32);
        bufp->chgCData(oldp+18,((0x0000001fU & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+19,((0x0000001fU & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                                >> 0x00000014U))),5);
        bufp->chgIData(oldp+20,(vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata),32);
        bufp->chgIData(oldp+21,(((0U == (3U & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata))
                                  ? (0x000000ffU & vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata)
                                  : ((1U == (3U & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata))
                                      ? (0x000000ffU 
                                         & (vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata 
                                            >> 8U))
                                      : ((2U == (3U 
                                                 & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata))
                                          ? (0x000000ffU 
                                             & (vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata 
                                                >> 0x00000010U))
                                          : VL_SHIFTR_III(32,32,32, vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata, 0x00000018U))))),32);
        bufp->chgIData(oldp+22,((((2U != (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType)) 
                                  | (2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)))
                                  ? 0U : vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata)),32);
        bufp->chgIData(oldp+23,(((IData)(vlSelfRef.Top__DOT__LSU__DOT___GEN_1)
                                  ? vlSelfRef.__VdfgRegularize_he50b618e_0_0
                                  : 0U)),32);
        bufp->chgIData(oldp+24,(((IData)(vlSelfRef.Top__DOT__LSU__DOT___GEN_1)
                                  ? vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src2
                                  : 0U)),32);
        bufp->chgBit(oldp+25,(vlSelfRef.Top__DOT__LSU__DOT___GEN_1));
        bufp->chgBit(oldp+26,((2U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType))));
        bufp->chgIData(oldp+27,(((4U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType))
                                  ? (0x0000000fU & 
                                     ((IData)(1U) << 
                                      (3U & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata)))
                                  : ((2U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType))
                                      ? 0x0000000fU
                                      : 0U))),32);
        bufp->chgIData(oldp+28,(vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata),32);
        bufp->chgBit(oldp+29,((1U & (~ ((3U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType)) 
                                        | ((2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                           | ((3U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                              | (6U 
                                                 == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)))))))));
        bufp->chgCData(oldp+30,((0x0000001fU & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                                >> 7U))),5);
        bufp->chgIData(oldp+31,(vlSelfRef.Top__DOT__RF__DOT__regs_0),32);
        bufp->chgIData(oldp+32,(vlSelfRef.Top__DOT__RF__DOT__regs_1),32);
        bufp->chgIData(oldp+33,(vlSelfRef.Top__DOT__RF__DOT__regs_2),32);
        bufp->chgIData(oldp+34,(vlSelfRef.Top__DOT__RF__DOT__regs_3),32);
        bufp->chgIData(oldp+35,(vlSelfRef.Top__DOT__RF__DOT__regs_4),32);
        bufp->chgIData(oldp+36,(vlSelfRef.Top__DOT__RF__DOT__regs_5),32);
        bufp->chgIData(oldp+37,(vlSelfRef.Top__DOT__RF__DOT__regs_6),32);
        bufp->chgIData(oldp+38,(vlSelfRef.Top__DOT__RF__DOT__regs_7),32);
        bufp->chgIData(oldp+39,(vlSelfRef.Top__DOT__RF__DOT__regs_8),32);
        bufp->chgIData(oldp+40,(vlSelfRef.Top__DOT__RF__DOT__regs_9),32);
        bufp->chgIData(oldp+41,(vlSelfRef.Top__DOT__RF__DOT__regs_10),32);
        bufp->chgIData(oldp+42,(vlSelfRef.Top__DOT__RF__DOT__regs_11),32);
        bufp->chgIData(oldp+43,(vlSelfRef.Top__DOT__RF__DOT__regs_12),32);
        bufp->chgIData(oldp+44,(vlSelfRef.Top__DOT__RF__DOT__regs_13),32);
        bufp->chgIData(oldp+45,(vlSelfRef.Top__DOT__RF__DOT__regs_14),32);
        bufp->chgIData(oldp+46,(vlSelfRef.Top__DOT__RF__DOT__regs_15),32);
        bufp->chgIData(oldp+47,(vlSelfRef.Top__DOT__RF__DOT__regs_16),32);
        bufp->chgIData(oldp+48,(vlSelfRef.Top__DOT__RF__DOT__regs_17),32);
        bufp->chgIData(oldp+49,(vlSelfRef.Top__DOT__RF__DOT__regs_18),32);
        bufp->chgIData(oldp+50,(vlSelfRef.Top__DOT__RF__DOT__regs_19),32);
        bufp->chgIData(oldp+51,(vlSelfRef.Top__DOT__RF__DOT__regs_20),32);
        bufp->chgIData(oldp+52,(vlSelfRef.Top__DOT__RF__DOT__regs_21),32);
        bufp->chgIData(oldp+53,(vlSelfRef.Top__DOT__RF__DOT__regs_22),32);
        bufp->chgIData(oldp+54,(vlSelfRef.Top__DOT__RF__DOT__regs_23),32);
        bufp->chgIData(oldp+55,(vlSelfRef.Top__DOT__RF__DOT__regs_24),32);
        bufp->chgIData(oldp+56,(vlSelfRef.Top__DOT__RF__DOT__regs_25),32);
        bufp->chgIData(oldp+57,(vlSelfRef.Top__DOT__RF__DOT__regs_26),32);
        bufp->chgIData(oldp+58,(vlSelfRef.Top__DOT__RF__DOT__regs_27),32);
        bufp->chgIData(oldp+59,(vlSelfRef.Top__DOT__RF__DOT__regs_28),32);
        bufp->chgIData(oldp+60,(vlSelfRef.Top__DOT__RF__DOT__regs_29),32);
        bufp->chgIData(oldp+61,(vlSelfRef.Top__DOT__RF__DOT__regs_30),32);
        bufp->chgIData(oldp+62,(vlSelfRef.Top__DOT__RF__DOT__regs_31),32);
        bufp->chgIData(oldp+63,(vlSelfRef.Top__DOT__RF__DOT__casez_tmp),32);
        bufp->chgIData(oldp+64,(vlSelfRef.Top__DOT__RF__DOT__casez_tmp_0),32);
        bufp->chgBit(oldp+65,((3U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType))));
    }
    bufp->chgBit(oldp+66,(vlSelfRef.clock));
    bufp->chgBit(oldp+67,(vlSelfRef.reset));
}

void VTop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_cleanup\n"); );
    // Body
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
