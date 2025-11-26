// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"

VL_ATTR_COLD void VTop___024root___eval_static(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_static\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
}

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VTop___024root___eval_final(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_final\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VTop___024root___eval_phase__stl(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/Top.sv", 636, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VTop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_triggers__stl\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__stl\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf);
VL_ATTR_COLD void VTop___024root____Vm_traceActivitySetAll(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
        VTop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

void VTop___024root____Vdpiimwrap_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
extern const VlUnpacked<CData/*2:0*/, 64> VTop__ConstPool__TABLE_h3256f443_0;
void VTop___024root____Vdpiimwrap_Top__DOT__halt__DOT__ebreak_TOP(IData/*31:0*/ exit_code);
void VTop___024root____Vdpiimwrap_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wmask, IData/*31:0*/ wdata);

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTop___024root____Vdpiimwrap_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_read_TOP(vlSelfRef.Top__DOT__reg_pc, vlSelfRef.__Vfunc_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_read__0__Vfuncout);
    vlSelfRef.Top__DOT___IFU_out_bits_instr = vlSelfRef.__Vfunc_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_read__0__Vfuncout;
    vlSelfRef.Top__DOT__RF__DOT__casez_tmp_0 = ((0x01000000U 
                                                 & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                 ? 
                                                ((0x00800000U 
                                                  & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                  ? 
                                                 ((0x00400000U 
                                                   & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                   ? 
                                                  ((0x00200000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_31
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_30)
                                                    : 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_29
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_28))
                                                   : 
                                                  ((0x00200000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_27
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_26)
                                                    : 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_25
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_24)))
                                                  : 
                                                 ((0x00400000U 
                                                   & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                   ? 
                                                  ((0x00200000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_23
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_22)
                                                    : 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_21
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_20))
                                                   : 
                                                  ((0x00200000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_19
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_18)
                                                    : 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_17
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_16))))
                                                 : 
                                                ((0x00800000U 
                                                  & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                  ? 
                                                 ((0x00400000U 
                                                   & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                   ? 
                                                  ((0x00200000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_15
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_14)
                                                    : 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_13
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_12))
                                                   : 
                                                  ((0x00200000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_11
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_10)
                                                    : 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_9
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_8)))
                                                  : 
                                                 ((0x00400000U 
                                                   & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                   ? 
                                                  ((0x00200000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_7
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_6)
                                                    : 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_5
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_4))
                                                   : 
                                                  ((0x00200000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_3
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_2)
                                                    : 
                                                   ((0x00100000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? vlSelfRef.Top__DOT__RF__DOT__regs_1
                                                     : vlSelfRef.Top__DOT__RF__DOT__regs_0)))));
    vlSelfRef.Top__DOT__RF__DOT__casez_tmp = ((0x00080000U 
                                               & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                               ? ((0x00040000U 
                                                   & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                   ? 
                                                  ((0x00020000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00010000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_31
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_30)
                                                     : 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_29
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_28))
                                                    : 
                                                   ((0x00010000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_27
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_26)
                                                     : 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_25
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_24)))
                                                   : 
                                                  ((0x00020000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00010000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_23
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_22)
                                                     : 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_21
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_20))
                                                    : 
                                                   ((0x00010000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_19
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_18)
                                                     : 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_17
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_16))))
                                               : ((0x00040000U 
                                                   & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                   ? 
                                                  ((0x00020000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00010000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_15
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_14)
                                                     : 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_13
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_12))
                                                    : 
                                                   ((0x00010000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_11
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_10)
                                                     : 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_9
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_8)))
                                                   : 
                                                  ((0x00020000U 
                                                    & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                    ? 
                                                   ((0x00010000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_7
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_6)
                                                     : 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_5
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_4))
                                                    : 
                                                   ((0x00010000U 
                                                     & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                     ? 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_3
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_2)
                                                     : 
                                                    ((0x00008000U 
                                                      & vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                                      ? vlSelfRef.Top__DOT__RF__DOT__regs_1
                                                      : vlSelfRef.Top__DOT__RF__DOT__regs_0)))));
    vlSelfRef.Top__DOT__IDU__DOT___GEN = ((0x00000380U 
                                           & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                              >> 5U)) 
                                          | (0x0000007fU 
                                             & vlSelfRef.Top__DOT___IFU_out_bits_instr));
    vlSelfRef.Top__DOT__IDU__DOT___GEN_4 = ((0x0013U 
                                             == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN)) 
                                            | (0x0067U 
                                               == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN)));
    vlSelfRef.Top__DOT__IDU__DOT___GEN_0 = ((0x0103U 
                                             == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN)) 
                                            | (0x0203U 
                                               == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN)));
    vlSelfRef.Top__DOT__IDU__DOT___GEN_5 = ((0x0123U 
                                             == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN)) 
                                            | (0x0023U 
                                               == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN)));
    vlSelfRef.Top__DOT__IDU__DOT___decodeList_T_7 = 
        (0x00000033U == ((0x0001fc00U & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                         >> 0x0000000fU)) 
                         | (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN)));
    vlSelfRef.Top__DOT__IDU__DOT___GEN_1 = ((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_5) 
                                            | (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_0));
    vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src2 
        = ((0U == (((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_4) 
                    | (0x37U == (0x0000007fU & vlSelfRef.Top__DOT___IFU_out_bits_instr)))
                    ? 3U : (((IData)(vlSelfRef.Top__DOT__IDU__DOT___decodeList_T_7) 
                             | (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_5))
                             ? 0U : (3U & (- (IData)(
                                                     ((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_0) 
                                                      | (0x00100073U 
                                                         == vlSelfRef.Top__DOT___IFU_out_bits_instr))))))))
            ? ((0U == (0x0000001fU & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                      >> 0x00000014U)))
                ? 0U : vlSelfRef.Top__DOT__RF__DOT__casez_tmp_0)
            : 0U);
    vlSelfRef.Top__DOT__IDU__DOT___GEN_2 = ((0x37U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.Top__DOT___IFU_out_bits_instr)) 
                                            | (IData)(vlSelfRef.Top__DOT__IDU__DOT___decodeList_T_7));
    vlSelfRef.__Vtableidx1 = ((((0x00100073U == vlSelfRef.Top__DOT___IFU_out_bits_instr) 
                                << 5U) | (((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_0) 
                                           << 4U) | 
                                          ((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_5) 
                                           << 3U))) 
                              | (((IData)(vlSelfRef.Top__DOT__IDU__DOT___decodeList_T_7) 
                                  << 2U) | (((0x37U 
                                              == (0x0000007fU 
                                                  & vlSelfRef.Top__DOT___IFU_out_bits_instr)) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_4))));
    vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType 
        = VTop__ConstPool__TABLE_h3256f443_0[vlSelfRef.__Vtableidx1];
    vlSelfRef.Top__DOT__IDU__DOT___GEN_3 = ((IData)(vlSelfRef.Top__DOT__IDU__DOT___decodeList_T_7) 
                                            | (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_1));
    vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType 
        = (((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_4) 
            | (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_2))
            ? 0U : ((0x0123U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))
                     ? 2U : ((0x0023U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))
                              ? 4U : ((0x0103U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))
                                       ? 1U : ((0x0203U 
                                                == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))
                                                ? 3U
                                                : 0U)))));
    if ((0x0013U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))) {
        vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType = 0U;
        vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_aluOp = 0U;
    } else if ((0x0067U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))) {
        vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType = 1U;
        vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_aluOp = 0x0000000fU;
    } else {
        vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType 
            = ((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_2)
                ? 0U : ((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_1)
                         ? 2U : ((0x00100073U == vlSelfRef.Top__DOT___IFU_out_bits_instr)
                                  ? 3U : 0U)));
        vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_aluOp 
            = (((0x37U == (0x0000007fU & vlSelfRef.Top__DOT___IFU_out_bits_instr)) 
                | (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_3))
                ? 0U : (0x0000000fU & (- (IData)((0x00100073U 
                                                  == vlSelfRef.Top__DOT___IFU_out_bits_instr)))));
    }
    vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_imm 
        = ((4U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))
            ? (0xfffff000U & vlSelfRef.Top__DOT___IFU_out_bits_instr)
            : ((2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))
                ? (((- (IData)((vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                >> 0x0000001fU))) << 0x0000000cU) 
                   | ((0x00000fe0U & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                      >> 0x00000014U)) 
                      | (0x0000001fU & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                        >> 7U)))) : 
               ((1U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))
                 ? (((- (IData)((vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                 >> 0x0000001fU))) 
                     << 0x0000000cU) | (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                        >> 0x00000014U))
                 : 0U)));
    vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src1 
        = ((0U == ((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_4)
                    ? 0U : ((0x37U == (0x0000007fU 
                                       & vlSelfRef.Top__DOT___IFU_out_bits_instr))
                             ? 3U : ((IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN_3)
                                      ? 0U : (3U & 
                                              (- (IData)(
                                                         (0x00100073U 
                                                          == vlSelfRef.Top__DOT___IFU_out_bits_instr))))))))
            ? ((0U == (0x0000001fU & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                      >> 0x0000000fU)))
                ? 0U : vlSelfRef.Top__DOT__RF__DOT__casez_tmp)
            : 0U);
    if ((3U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType))) {
        VTop___024root____Vdpiimwrap_Top__DOT__halt__DOT__ebreak_TOP(0U);
    }
    vlSelfRef.Top__DOT__RF__DOT___GEN = ((~ ((3U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType)) 
                                             | ((2U 
                                                 == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                                | ((3U 
                                                    == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                                   | (6U 
                                                      == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)))))) 
                                         & (0U != (0x0000001fU 
                                                   & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                                      >> 7U))));
    vlSelfRef.Top__DOT__LSU__DOT___GEN_1 = ((2U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType)) 
                                            & (2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)));
    vlSelfRef.__VdfgRegularize_he50b618e_0_0 = (vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_imm 
                                                + vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src1);
    vlSelfRef.Top__DOT__EXU__DOT__alu__DOT__io_rlt 
        = (((1U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_aluOp)) 
            | (0U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_aluOp)))
            ? (((1U & ((~ ((2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                           | ((1U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                              | (0U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))))) 
                       | (4U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))))
                 ? 0U : vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src1) 
               + (((4U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                   | ((2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                      | (1U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))))
                   ? vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_imm
                   : ((0U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))
                       ? vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src2
                       : 0U))) : 0U);
    vlSelfRef.Top__DOT__EXU__DOT__bru__DOT__io_d_pc 
        = ((1U == ((0x0013U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))
                    ? 0U : (0x0067U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))))
            ? vlSelfRef.__VdfgRegularize_he50b618e_0_0
            : ((IData)(4U) + vlSelfRef.Top__DOT__reg_pc));
    vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata 
        = ((2U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType))
            ? vlSelfRef.Top__DOT__EXU__DOT__alu__DOT__io_rlt
            : ((1U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType))
                ? ((IData)(4U) + vlSelfRef.Top__DOT__reg_pc)
                : ((0U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType))
                    ? vlSelfRef.Top__DOT__EXU__DOT__alu__DOT__io_rlt
                    : 0U)));
    if ((2U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType))) {
        VTop___024root____Vdpiimwrap_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_read_TOP(
                                                                                (((2U 
                                                                                != (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType)) 
                                                                                | (2U 
                                                                                == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)))
                                                                                 ? 0U
                                                                                 : vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata), vlSelfRef.__Vfunc_Top__DOT__LSU__DOT__lsDPI__DOT__pmem_read__1__Vfuncout);
        vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata 
            = vlSelfRef.__Vfunc_Top__DOT__LSU__DOT__lsDPI__DOT__pmem_read__1__Vfuncout;
        if (vlSelfRef.Top__DOT__LSU__DOT___GEN_1) {
            VTop___024root____Vdpiimwrap_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_write_TOP(
                                                                                ((IData)(vlSelfRef.Top__DOT__LSU__DOT___GEN_1)
                                                                                 ? vlSelfRef.__VdfgRegularize_he50b618e_0_0
                                                                                 : 0U), 
                                                                                ((4U 
                                                                                == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType))
                                                                                 ? 
                                                                                (0x0000000fU 
                                                                                & ((IData)(1U) 
                                                                                << 
                                                                                (3U 
                                                                                & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata)))
                                                                                 : 
                                                                                ((2U 
                                                                                == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType))
                                                                                 ? 0x0000000fU
                                                                                 : 0U)), 
                                                                                ((IData)(vlSelfRef.Top__DOT__LSU__DOT___GEN_1)
                                                                                 ? vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src2
                                                                                 : 0U));
        }
    } else {
        vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata = 0U;
    }
    vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata 
        = ((3U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType))
            ? ((0U == (3U & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata))
                ? (0x000000ffU & vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata)
                : ((1U == (3U & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata))
                    ? (0x000000ffU & (vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata 
                                      >> 8U)) : ((2U 
                                                  == 
                                                  (3U 
                                                   & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata))
                                                  ? 
                                                 (0x000000ffU 
                                                  & (vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata 
                                                     >> 0x00000010U))
                                                  : 
                                                 VL_SHIFTR_III(32,32,32, vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata, 0x00000018U))))
            : ((1U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType))
                ? vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata
                : vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata));
}

VL_ATTR_COLD bool VTop___024root___eval_phase__stl(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__stl\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VTop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VTop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__act\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__nba\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root____Vm_traceActivitySetAll(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vm_traceActivitySetAll\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5452235342940299466ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->Top__DOT___LSU_out_bits_idCtrl_immType = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2839134430624689833ull);
    vlSelf->Top__DOT___IFU_out_bits_instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4436614504555161795ull);
    vlSelf->Top__DOT__reg_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12624611384344592462ull);
    vlSelf->Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3615404703615501398ull);
    vlSelf->Top__DOT__IDU__DOT__io_out_bits_idCtrl_aluOp = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4770390112350346283ull);
    vlSelf->Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12522707957482201301ull);
    vlSelf->Top__DOT__IDU__DOT__io_out_bits_data_src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3050063603005740829ull);
    vlSelf->Top__DOT__IDU__DOT__io_out_bits_data_src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15683556420630513575ull);
    vlSelf->Top__DOT__IDU__DOT__io_out_bits_data_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6682869627240925225ull);
    vlSelf->Top__DOT__IDU__DOT___GEN = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 16073526487545279144ull);
    vlSelf->Top__DOT__IDU__DOT___decodeList_T_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14773759897337673142ull);
    vlSelf->Top__DOT__IDU__DOT___GEN_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17015771411163056848ull);
    vlSelf->Top__DOT__IDU__DOT___GEN_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2810991907129277342ull);
    vlSelf->Top__DOT__IDU__DOT___GEN_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17885157499298056679ull);
    vlSelf->Top__DOT__IDU__DOT___GEN_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7311657024508981017ull);
    vlSelf->Top__DOT__IDU__DOT___GEN_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9542904295560794597ull);
    vlSelf->Top__DOT__IDU__DOT___GEN_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9295263423561736884ull);
    vlSelf->Top__DOT__EXU__DOT__out_bits_exuData_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6832249541039747810ull);
    vlSelf->Top__DOT__EXU__DOT__alu__DOT__io_rlt = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13701532313110482932ull);
    vlSelf->Top__DOT__EXU__DOT__bru__DOT__io_d_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8004208209848981836ull);
    vlSelf->Top__DOT__LSU__DOT__out_bits_wbData_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3160627047580351586ull);
    vlSelf->Top__DOT__LSU__DOT___lsDPI_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13879992517695590098ull);
    vlSelf->Top__DOT__LSU__DOT___GEN_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17216677048314670425ull);
    vlSelf->Top__DOT__RF__DOT__regs_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7515936505394768184ull);
    vlSelf->Top__DOT__RF__DOT__regs_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8036166544951198923ull);
    vlSelf->Top__DOT__RF__DOT__regs_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4350850206613650169ull);
    vlSelf->Top__DOT__RF__DOT__regs_3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6284131815740396491ull);
    vlSelf->Top__DOT__RF__DOT__regs_4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15896826866319057319ull);
    vlSelf->Top__DOT__RF__DOT__regs_5 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17620651033746333456ull);
    vlSelf->Top__DOT__RF__DOT__regs_6 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9802340388731901466ull);
    vlSelf->Top__DOT__RF__DOT__regs_7 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10322570428288235181ull);
    vlSelf->Top__DOT__RF__DOT__regs_8 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15918981081421039955ull);
    vlSelf->Top__DOT__RF__DOT__regs_9 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13184899229744597705ull);
    vlSelf->Top__DOT__RF__DOT__regs_10 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10769593942985450595ull);
    vlSelf->Top__DOT__RF__DOT__regs_11 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16550171464662501778ull);
    vlSelf->Top__DOT__RF__DOT__regs_12 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10368417640174933252ull);
    vlSelf->Top__DOT__RF__DOT__regs_13 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15829702418221688044ull);
    vlSelf->Top__DOT__RF__DOT__regs_14 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9647948593734127718ull);
    vlSelf->Top__DOT__RF__DOT__regs_15 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17668204674840489187ull);
    vlSelf->Top__DOT__RF__DOT__regs_16 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15738468845689607876ull);
    vlSelf->Top__DOT__RF__DOT__regs_17 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5311980853086232454ull);
    vlSelf->Top__DOT__RF__DOT__regs_18 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3402827111848777470ull);
    vlSelf->Top__DOT__RF__DOT__regs_19 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13660853412632808751ull);
    vlSelf->Top__DOT__RF__DOT__regs_20 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15206498557479718493ull);
    vlSelf->Top__DOT__RF__DOT__regs_21 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5884017713632644994ull);
    vlSelf->Top__DOT__RF__DOT__regs_22 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2621415745135029485ull);
    vlSelf->Top__DOT__RF__DOT__regs_23 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2144774671433106995ull);
    vlSelf->Top__DOT__RF__DOT__regs_24 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5029555996383807976ull);
    vlSelf->Top__DOT__RF__DOT__regs_25 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10810133518060706492ull);
    vlSelf->Top__DOT__RF__DOT__regs_26 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5072315094659776732ull);
    vlSelf->Top__DOT__RF__DOT__regs_27 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6835352580387283349ull);
    vlSelf->Top__DOT__RF__DOT__regs_28 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11083795294759555660ull);
    vlSelf->Top__DOT__RF__DOT__regs_29 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4108919972520903807ull);
    vlSelf->Top__DOT__RF__DOT__regs_30 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4265416129383295138ull);
    vlSelf->Top__DOT__RF__DOT__regs_31 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10370905363486932127ull);
    vlSelf->Top__DOT__RF__DOT__casez_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11220654913079622649ull);
    vlSelf->Top__DOT__RF__DOT__casez_tmp_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2171119126422987677ull);
    vlSelf->Top__DOT__RF__DOT___GEN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5298382960374382632ull);
    vlSelf->__VdfgRegularize_he50b618e_0_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 777431380022455576ull);
    vlSelf->__Vfunc_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_Top__DOT__LSU__DOT__lsDPI__DOT__pmem_read__1__Vfuncout = 0;
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13272892335938733197ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
