package RV32I

import chisel3._
import chisel3.util._

class ctrlFlowIO extends Bundle{
  val pc = Output(UInt(32.W))
  val instr = Output(UInt(32.W))
}

class decodeCtrl extends Bundle{
  val fuType = Output(UInt(4.W))
  val aluOp = Output(UInt(4.W))
  val src1Type = Output(UInt(2.W))
  val src2Type = Output(UInt(2.W))
  val immType = Output(UInt(3.W))
  val brType = Output(UInt(4.W))
  val memType = Output(UInt(4.W))
}

class RegRead extends Bundle{
  val rdata1 = Output(UInt(32.W))
  val rdata2 = Output(UInt(32.W))
  val raddr1 = Input(UInt(5.W))
  val raddr2 = Input(UInt(5.W))
}

class RegWrite extends Bundle{
  val wen = Input(Bool())
  val waddr = Input(UInt(5.W))
  val wdata = Input(UInt(32.W))
}

class DataSrcIO extends Bundle {
  val src1 = Output(UInt(32.W))
  val src2 = Output(UInt(32.W))
  val imm  = Output(UInt(32.W)) 
}

class ID2EX extends Bundle{
  val cf = new ctrlFlowIO
  val idCtrl = new decodeCtrl
  val data = new DataSrcIO
}

// class EX2LS extends Bundle{
// }
