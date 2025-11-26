// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        CData/*2:0*/ Top__DOT___LSU_out_bits_idCtrl_immType;
        CData/*3:0*/ Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType;
        CData/*3:0*/ Top__DOT__IDU__DOT__io_out_bits_idCtrl_aluOp;
        CData/*3:0*/ Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType;
        CData/*0:0*/ Top__DOT__IDU__DOT___decodeList_T_7;
        CData/*0:0*/ Top__DOT__IDU__DOT___GEN_0;
        CData/*0:0*/ Top__DOT__IDU__DOT___GEN_1;
        CData/*0:0*/ Top__DOT__IDU__DOT___GEN_2;
        CData/*0:0*/ Top__DOT__IDU__DOT___GEN_3;
        CData/*0:0*/ Top__DOT__IDU__DOT___GEN_4;
        CData/*0:0*/ Top__DOT__IDU__DOT___GEN_5;
        CData/*0:0*/ Top__DOT__LSU__DOT___GEN_1;
        CData/*0:0*/ Top__DOT__RF__DOT___GEN;
        CData/*5:0*/ __Vtableidx1;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactContinue;
        SData/*9:0*/ Top__DOT__IDU__DOT___GEN;
        IData/*31:0*/ Top__DOT___IFU_out_bits_instr;
        IData/*31:0*/ Top__DOT__reg_pc;
        IData/*31:0*/ Top__DOT__IDU__DOT__io_out_bits_data_src1;
        IData/*31:0*/ Top__DOT__IDU__DOT__io_out_bits_data_src2;
        IData/*31:0*/ Top__DOT__IDU__DOT__io_out_bits_data_imm;
        IData/*31:0*/ Top__DOT__EXU__DOT__out_bits_exuData_wdata;
        IData/*31:0*/ Top__DOT__EXU__DOT__alu__DOT__io_rlt;
        IData/*31:0*/ Top__DOT__EXU__DOT__bru__DOT__io_d_pc;
        IData/*31:0*/ Top__DOT__LSU__DOT__out_bits_wbData_wdata;
        IData/*31:0*/ Top__DOT__LSU__DOT___lsDPI_rdata;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_0;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_1;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_2;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_3;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_4;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_5;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_6;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_7;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_8;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_9;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_10;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_11;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_12;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_13;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_14;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_15;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_16;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_17;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_18;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_19;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_20;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_21;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_22;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_23;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_24;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_25;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_26;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_27;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_28;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_29;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_30;
        IData/*31:0*/ Top__DOT__RF__DOT__regs_31;
        IData/*31:0*/ Top__DOT__RF__DOT__casez_tmp;
        IData/*31:0*/ Top__DOT__RF__DOT__casez_tmp_0;
    };
    struct {
        IData/*31:0*/ __VdfgRegularize_he50b618e_0_0;
        IData/*31:0*/ __Vfunc_Top__DOT__IFU__DOT__lsDPI__DOT__pmem_read__0__Vfuncout;
        IData/*31:0*/ __Vfunc_Top__DOT__LSU__DOT__lsDPI__DOT__pmem_read__1__Vfuncout;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop___024root(VTop__Syms* symsp, const char* v__name);
    ~VTop___024root();
    VL_UNCOPYABLE(VTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
