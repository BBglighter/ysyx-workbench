package RV32I

import chisel3._
import chisel3.util._

class ctrlFlowIO extends Bundle{
  val pc = Output(UInt(32.W))
  val instr = Output(UInt(32.W))
  val wen = Output(Bool())
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
  val csraddr = Input(UInt(12.W))
  val csrdata = Output(UInt(32.W))
}

class RegWrite extends Bundle{
  val wen = Input(Bool())
  val waddr = Input(UInt(5.W))
  val wdata = Input(UInt(32.W))
  val csraddr = Input(UInt(12.W))
  val csrdata = Input(UInt(32.W))
}

class DataSrcIO extends Bundle {
  val src1 = Output(UInt(32.W))
  val src2 = Output(UInt(32.W))
  val imm  = Output(UInt(32.W))
  val csr  = Output(UInt(32.W))
}

class ID2EX extends Bundle{
  val cf = new ctrlFlowIO
  val idCtrl = new decodeCtrl
  val data = new DataSrcIO
}

class EXUdata extends Bundle{
  val dnpc = Output(UInt(32.W))
  val wdata = Output(UInt(32.W))
  val csr = Output(UInt(32.W))
}

class EX2LS extends Bundle{
  val cf = new ctrlFlowIO
  val idCtrl = new decodeCtrl
  val data = new DataSrcIO
  val exuData = new EXUdata
}

class LS2WB extends Bundle{
  val cf = new ctrlFlowIO
  val idCtrl = new decodeCtrl
  val wbData = new EXUdata
  val load = Output(Bool())
}

class regCSR extends Bundle{
  val mcycle  = Input(UInt(32.W))
  val mcycleh = Input(UInt(32.W))
  val mvendorid = Input(UInt(32.W))
  val marchid = Input(UInt(32.W))
  val mepc = Input(UInt(32.W))
  val mtvec = Input(UInt(32.W))
  val mcause = Input(UInt(32.W))
  val mstatus = Input(UInt(32.W))
}

class axi4bus extends Bundle{
  val araddr  = Input(UInt(32.W))
  val arvalid = Input(Bool())
  val arready = Output(Bool())
  val arid    = Input(UInt(4.W))
  val arlen   = Input(UInt(8.W))
  val arsize  = Input(UInt(3.W))
  val arburst = Input(UInt(2.W))

  val rdata   = Output(UInt(32.W))
  val rresp   = Output(UInt(2.W))
  val rvalid  = Output(Bool())
  val rready  = Input(Bool())
  val rlast   = Output(Bool())
  val rid     = Output(UInt(4.W))

  val awaddr  = Input(UInt(32.W))
  val awvalid = Input(Bool())
  val awready = Output(Bool())
  val awid    = Input(UInt(4.W))
  val awlen   = Input(UInt(8.W))
  val awsize  = Input(UInt(3.W))
  val awburst = Input(UInt(2.W))
  
  val wdata   = Input(UInt(32.W))
  val wstrb   = Input(UInt(4.W))
  val wvalid  = Input(Bool())
  val wready  = Output(Bool())
  val wlast   = Input(Bool())
  
  val bresp   = Output(UInt(2.W))
  val bvalid  = Output(Bool())
  val bready  = Input(Bool())
  val bid     = Output(UInt(4.W))
}






