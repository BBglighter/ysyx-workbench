// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VTop__Syms.h"


VL_ATTR_COLD void VTop___024root__trace_init_sub__TOP__0(VTop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_sub__TOP__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+67,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("Top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+67,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"reg_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("EXU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"in_bits_cf_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"in_bits_cf_instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"in_bits_idCtrl_fuType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"in_bits_idCtrl_aluOp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"in_bits_idCtrl_immType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+6,0,"in_bits_idCtrl_brType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+7,0,"in_bits_idCtrl_memType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+8,0,"in_bits_data_src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"in_bits_data_src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"in_bits_data_imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"out_bits_cf_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"out_bits_idCtrl_fuType",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"out_bits_idCtrl_immType",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+7,0,"out_bits_idCtrl_memType",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+8,0,"out_bits_data_src1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"out_bits_data_src2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"out_bits_data_imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"out_bits_exuData_dnpc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"out_bits_exuData_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+13,0,"io_val1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"io_val2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"io_aluOp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+15,0,"io_rlt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("bru", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"io_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"io_src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"io_imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"io_BranchType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+11,0,"io_d_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"io_rlt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("IDU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"io_in_bits_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"io_in_bits_instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"io_out_bits_cf_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"io_out_bits_cf_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_out_bits_idCtrl_fuType",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"io_out_bits_idCtrl_aluOp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"io_out_bits_idCtrl_immType",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+6,0,"io_out_bits_idCtrl_brType",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+7,0,"io_out_bits_idCtrl_memType",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+8,0,"io_out_bits_data_src1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"io_out_bits_data_src2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"io_out_bits_data_imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"io_io_reg_rdata1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"io_io_reg_rdata2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"io_io_reg_raddr1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+20,0,"io_io_reg_raddr2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+5,0,"decodeList_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("IFU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"out_bits_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"out_bits_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("lsDPI", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+70,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"wmask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("LSU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+2,0,"in_bits_cf_instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"in_bits_idCtrl_fuType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"in_bits_idCtrl_immType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+7,0,"in_bits_idCtrl_memType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+8,0,"in_bits_data_src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"in_bits_data_src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"in_bits_data_imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"in_bits_exuData_dnpc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"in_bits_exuData_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"out_bits_cf_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"out_bits_idCtrl_fuType",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"out_bits_idCtrl_immType",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+11,0,"out_bits_wbData_dnpc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"out_bits_wbData_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"casez_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("lsDPI", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+23,0,"raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"wmask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("RF", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+67,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"io_read_rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"io_read_rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"io_read_raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+20,0,"io_read_raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+30,0,"io_write_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"io_write_waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+21,0,"io_write_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"regs_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"regs_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"regs_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"regs_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"regs_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"regs_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"regs_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"regs_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"regs_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"regs_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"regs_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"regs_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"regs_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"regs_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"regs_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"regs_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"regs_16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"regs_17",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"regs_18",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"regs_19",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"regs_20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"regs_21",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"regs_22",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"regs_23",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"regs_24",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"regs_25",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"regs_26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"regs_27",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"regs_28",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"regs_29",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"regs_30",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"regs_31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"casez_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"casez_tmp_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("WBU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+2,0,"in_bits_cf_instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"in_bits_idCtrl_fuType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"in_bits_idCtrl_immType",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+11,0,"in_bits_wbData_dnpc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"in_bits_wbData_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+66,0,"halt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"io_reg_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"io_reg_waddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+21,0,"io_reg_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("halt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+66,0,"halt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VTop___024root__trace_init_top(VTop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_top\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VTop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VTop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VTop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VTop___024root__trace_register(VTop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_register\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VTop___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VTop___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VTop___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VTop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTop___024root__trace_const_0_sub_0(VTop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VTop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_const_0\n"); );
    // Body
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTop___024root__trace_const_0_sub_0(VTop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_const_0_sub_0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+69,(0U),32);
    bufp->fullBit(oldp+70,(0U));
    bufp->fullBit(oldp+71,(1U));
}

VL_ATTR_COLD void VTop___024root__trace_full_0_sub_0(VTop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VTop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_0\n"); );
    // Body
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTop___024root__trace_full_0_sub_0(VTop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_0_sub_0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+1,(vlSelfRef.Top__DOT__reg_pc),32);
    bufp->fullIData(oldp+2,(vlSelfRef.Top__DOT___IFU_out_bits_instr),32);
    bufp->fullCData(oldp+3,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType),4);
    bufp->fullCData(oldp+4,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_aluOp),4);
    bufp->fullCData(oldp+5,(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType),3);
    bufp->fullCData(oldp+6,(((0x0013U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))
                              ? 0U : (0x0067U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN)))),4);
    bufp->fullCData(oldp+7,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType),4);
    bufp->fullIData(oldp+8,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src1),32);
    bufp->fullIData(oldp+9,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src2),32);
    bufp->fullIData(oldp+10,(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_imm),32);
    bufp->fullIData(oldp+11,(((1U == ((0x0013U == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))
                                       ? 0U : (0x0067U 
                                               == (IData)(vlSelfRef.Top__DOT__IDU__DOT___GEN))))
                               ? vlSelfRef.__VdfgRegularize_he50b618e_0_0
                               : ((IData)(4U) + vlSelfRef.Top__DOT__reg_pc))),32);
    bufp->fullIData(oldp+12,(vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata),32);
    bufp->fullIData(oldp+13,(((1U & ((~ ((2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                         | ((1U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                            | (0U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))))) 
                                     | (4U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))))
                               ? 0U : vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src1)),32);
    bufp->fullIData(oldp+14,((((4U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                               | ((2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                  | (1U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))))
                               ? vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_imm
                               : ((0U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType))
                                   ? vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src2
                                   : 0U))),32);
    bufp->fullIData(oldp+15,(vlSelfRef.Top__DOT__EXU__DOT__alu__DOT__io_rlt),32);
    bufp->fullIData(oldp+16,(((IData)(4U) + vlSelfRef.Top__DOT__reg_pc)),32);
    bufp->fullIData(oldp+17,(((0U == (0x0000001fU & 
                                      (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                       >> 0x0000000fU)))
                               ? 0U : vlSelfRef.Top__DOT__RF__DOT__casez_tmp)),32);
    bufp->fullIData(oldp+18,(((0U == (0x0000001fU & 
                                      (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                       >> 0x00000014U)))
                               ? 0U : vlSelfRef.Top__DOT__RF__DOT__casez_tmp_0)),32);
    bufp->fullCData(oldp+19,((0x0000001fU & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                             >> 0x0000000fU))),5);
    bufp->fullCData(oldp+20,((0x0000001fU & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                             >> 0x00000014U))),5);
    bufp->fullIData(oldp+21,(vlSelfRef.Top__DOT__LSU__DOT__out_bits_wbData_wdata),32);
    bufp->fullIData(oldp+22,(((0U == (3U & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata))
                               ? (0x000000ffU & vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata)
                               : ((1U == (3U & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata))
                                   ? (0x000000ffU & 
                                      (vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata 
                                       >> 8U)) : ((2U 
                                                   == 
                                                   (3U 
                                                    & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata))
                                                   ? 
                                                  (0x000000ffU 
                                                   & (vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata 
                                                      >> 0x00000010U))
                                                   : 
                                                  VL_SHIFTR_III(32,32,32, vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata, 0x00000018U))))),32);
    bufp->fullIData(oldp+23,((((2U != (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType)) 
                               | (2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)))
                               ? 0U : vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata)),32);
    bufp->fullIData(oldp+24,(((IData)(vlSelfRef.Top__DOT__LSU__DOT___GEN_1)
                               ? vlSelfRef.__VdfgRegularize_he50b618e_0_0
                               : 0U)),32);
    bufp->fullIData(oldp+25,(((IData)(vlSelfRef.Top__DOT__LSU__DOT___GEN_1)
                               ? vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_data_src2
                               : 0U)),32);
    bufp->fullBit(oldp+26,(vlSelfRef.Top__DOT__LSU__DOT___GEN_1));
    bufp->fullBit(oldp+27,((2U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType))));
    bufp->fullIData(oldp+28,(((4U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType))
                               ? (0x0000000fU & ((IData)(1U) 
                                                 << 
                                                 (3U 
                                                  & vlSelfRef.Top__DOT__EXU__DOT__out_bits_exuData_wdata)))
                               : ((2U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_memType))
                                   ? 0x0000000fU : 0U))),32);
    bufp->fullIData(oldp+29,(vlSelfRef.Top__DOT__LSU__DOT___lsDPI_rdata),32);
    bufp->fullBit(oldp+30,((1U & (~ ((3U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType)) 
                                     | ((2U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                        | ((3U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)) 
                                           | (6U == (IData)(vlSelfRef.Top__DOT___LSU_out_bits_idCtrl_immType)))))))));
    bufp->fullCData(oldp+31,((0x0000001fU & (vlSelfRef.Top__DOT___IFU_out_bits_instr 
                                             >> 7U))),5);
    bufp->fullIData(oldp+32,(vlSelfRef.Top__DOT__RF__DOT__regs_0),32);
    bufp->fullIData(oldp+33,(vlSelfRef.Top__DOT__RF__DOT__regs_1),32);
    bufp->fullIData(oldp+34,(vlSelfRef.Top__DOT__RF__DOT__regs_2),32);
    bufp->fullIData(oldp+35,(vlSelfRef.Top__DOT__RF__DOT__regs_3),32);
    bufp->fullIData(oldp+36,(vlSelfRef.Top__DOT__RF__DOT__regs_4),32);
    bufp->fullIData(oldp+37,(vlSelfRef.Top__DOT__RF__DOT__regs_5),32);
    bufp->fullIData(oldp+38,(vlSelfRef.Top__DOT__RF__DOT__regs_6),32);
    bufp->fullIData(oldp+39,(vlSelfRef.Top__DOT__RF__DOT__regs_7),32);
    bufp->fullIData(oldp+40,(vlSelfRef.Top__DOT__RF__DOT__regs_8),32);
    bufp->fullIData(oldp+41,(vlSelfRef.Top__DOT__RF__DOT__regs_9),32);
    bufp->fullIData(oldp+42,(vlSelfRef.Top__DOT__RF__DOT__regs_10),32);
    bufp->fullIData(oldp+43,(vlSelfRef.Top__DOT__RF__DOT__regs_11),32);
    bufp->fullIData(oldp+44,(vlSelfRef.Top__DOT__RF__DOT__regs_12),32);
    bufp->fullIData(oldp+45,(vlSelfRef.Top__DOT__RF__DOT__regs_13),32);
    bufp->fullIData(oldp+46,(vlSelfRef.Top__DOT__RF__DOT__regs_14),32);
    bufp->fullIData(oldp+47,(vlSelfRef.Top__DOT__RF__DOT__regs_15),32);
    bufp->fullIData(oldp+48,(vlSelfRef.Top__DOT__RF__DOT__regs_16),32);
    bufp->fullIData(oldp+49,(vlSelfRef.Top__DOT__RF__DOT__regs_17),32);
    bufp->fullIData(oldp+50,(vlSelfRef.Top__DOT__RF__DOT__regs_18),32);
    bufp->fullIData(oldp+51,(vlSelfRef.Top__DOT__RF__DOT__regs_19),32);
    bufp->fullIData(oldp+52,(vlSelfRef.Top__DOT__RF__DOT__regs_20),32);
    bufp->fullIData(oldp+53,(vlSelfRef.Top__DOT__RF__DOT__regs_21),32);
    bufp->fullIData(oldp+54,(vlSelfRef.Top__DOT__RF__DOT__regs_22),32);
    bufp->fullIData(oldp+55,(vlSelfRef.Top__DOT__RF__DOT__regs_23),32);
    bufp->fullIData(oldp+56,(vlSelfRef.Top__DOT__RF__DOT__regs_24),32);
    bufp->fullIData(oldp+57,(vlSelfRef.Top__DOT__RF__DOT__regs_25),32);
    bufp->fullIData(oldp+58,(vlSelfRef.Top__DOT__RF__DOT__regs_26),32);
    bufp->fullIData(oldp+59,(vlSelfRef.Top__DOT__RF__DOT__regs_27),32);
    bufp->fullIData(oldp+60,(vlSelfRef.Top__DOT__RF__DOT__regs_28),32);
    bufp->fullIData(oldp+61,(vlSelfRef.Top__DOT__RF__DOT__regs_29),32);
    bufp->fullIData(oldp+62,(vlSelfRef.Top__DOT__RF__DOT__regs_30),32);
    bufp->fullIData(oldp+63,(vlSelfRef.Top__DOT__RF__DOT__regs_31),32);
    bufp->fullIData(oldp+64,(vlSelfRef.Top__DOT__RF__DOT__casez_tmp),32);
    bufp->fullIData(oldp+65,(vlSelfRef.Top__DOT__RF__DOT__casez_tmp_0),32);
    bufp->fullBit(oldp+66,((3U == (IData)(vlSelfRef.Top__DOT__IDU__DOT__io_out_bits_idCtrl_fuType))));
    bufp->fullBit(oldp+67,(vlSelfRef.clock));
    bufp->fullBit(oldp+68,(vlSelfRef.reset));
}
