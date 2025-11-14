// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlight.h for the primary calling header

#include "Vlight__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlight___024root___dump_triggers__act(Vlight___024root* vlSelf);
#endif  // VL_DEBUG

void Vlight___024root___eval_triggers__act(Vlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root___eval_triggers__act\n"); );
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vlight___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vlight___024root___eval_act(Vlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root___eval_act\n"); );
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vlight___024root___nba_sequent__TOP__0(Vlight___024root* vlSelf);

void Vlight___024root___eval_nba(Vlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root___eval_nba\n"); );
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vlight___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vlight___024root___nba_sequent__TOP__0(Vlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root___nba_sequent__TOP__0\n"); );
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __Vdly__led;
    __Vdly__led = 0;
    IData/*31:0*/ __Vdly__light__DOT__count;
    __Vdly__light__DOT__count = 0;
    // Body
    __Vdly__led = vlSelfRef.led;
    __Vdly__light__DOT__count = vlSelfRef.light__DOT__count;
    if (vlSelfRef.rst) {
        __Vdly__led = 1U;
        __Vdly__light__DOT__count = 0U;
    } else {
        if ((0U == vlSelfRef.light__DOT__count)) {
            __Vdly__led = ((0x0000fffeU & ((IData)(vlSelfRef.led) 
                                           << 1U)) 
                           | (1U & ((IData)(vlSelfRef.led) 
                                    >> 0x0fU)));
        }
        __Vdly__light__DOT__count = ((0x004c4b40U <= vlSelfRef.light__DOT__count)
                                      ? 0U : ((IData)(1U) 
                                              + vlSelfRef.light__DOT__count));
    }
    vlSelfRef.led = __Vdly__led;
    vlSelfRef.light__DOT__count = __Vdly__light__DOT__count;
}

bool Vlight___024root___eval_phase__act(Vlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root___eval_phase__act\n"); );
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vlight___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vlight___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vlight___024root___eval_phase__nba(Vlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root___eval_phase__nba\n"); );
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vlight___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlight___024root___dump_triggers__nba(Vlight___024root* vlSelf);
#endif  // VL_DEBUG

void Vlight___024root___eval(Vlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root___eval\n"); );
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vlight___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("light.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vlight___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("light.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vlight___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vlight___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vlight___024root___eval_debug_assertions(Vlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root___eval_debug_assertions\n"); );
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
