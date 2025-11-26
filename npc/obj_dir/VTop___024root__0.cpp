// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"

extern "C" int pmem_read(int raddr);

void VTop___024root____Vdpiimwrap_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = (pmem_read__Vfuncrtn__Vcvt);
}

extern "C" void pmem_write(int waddr, int wmask, int wdata);

void VTop___024root____Vdpiimwrap_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wmask, IData/*31:0*/ wdata) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    waddr__Vcvt = waddr;
    int wmask__Vcvt;
    wmask__Vcvt = wmask;
    int wdata__Vcvt;
    wdata__Vcvt = wdata;
    pmem_write(waddr__Vcvt, wmask__Vcvt, wdata__Vcvt);
}

extern "C" void ebreak(int exit_code);

void VTop___024root____Vdpiimwrap_Top__DOT__halt__DOT__ebreak_TOP(IData/*31:0*/ exit_code) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__halt__DOT__ebreak_TOP\n"); );
    // Body
    int exit_code__Vcvt;
    exit_code__Vcvt = exit_code;
    ebreak(exit_code__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_triggers__act\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clock) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf);

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

extern const VlUnpacked<CData/*2:0*/, 64> VTop__ConstPool__TABLE_h3256f443_0;

void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000e80U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_29 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000e00U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_28 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000d80U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_27 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000d00U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_26 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000c80U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_25 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000c00U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_24 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000b80U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_23 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000b00U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_22 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000a80U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_21 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000a00U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_20 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000980U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_19 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000900U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_18 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000880U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_17 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000800U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_16 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000780U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_15 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000600U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_12 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000580U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_11 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000180U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_3 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000300U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_6 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000500U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_10 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000100U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_2 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000280U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_5 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000480U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_9 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000080U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_1 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000200U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_4 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000400U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_8 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000680U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_13 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    vlSelfRef.Top__DOT__RF__DOT__regs_0 = (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
                                            & (~ (0U 
                                                  != 
                                                  (0x0000001fU 
                                                   & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                                      >> 7U)))))
                                            ? vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata
                                            : 0U);
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000f80U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_31 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000700U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_14 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000380U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_7 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    if (((IData)(vlSelfRef.Top__DOT__RF__DOT___GEN) 
         & (0x00000f00U == (0x00000f80U & vlSelfRef.Top__DOT___IFU_out_bits_instr)))) {
        vlSelfRef.Top__DOT__RF__DOT__regs_30 = vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata;
    }
    vlSelfRef.Top__DOT__reg_pc = ((IData)(vlSelfRef.reset)
                                   ? 0x00000010U : vlSelfRef.Top__DOT__EXU__DOT__bru__DOT__io_d_pc);
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

bool VTop___024root___eval_phase__act(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__act\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VTop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VTop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VTop___024root___eval_phase__nba(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__nba\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VTop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/Top.sv", 636, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vsrc/Top.sv", 636, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VTop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VTop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
}
#endif  // VL_DEBUG
