// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"

void VTop___024root___ctor_var_reset(VTop___024root* vlSelf);

VTop___024root::VTop___024root(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop___024root___ctor_var_reset(this);
}

void VTop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop___024root::~VTop___024root() {
}
