package RV32I

import chisel3._
import chisel3.util._
import chisel3.experimental._

class halt() extends BlackBox with HasBlackBoxPath {
  val io = IO(new Bundle{
    val halt = Input(Bool())
    val h_return = Input(UInt(32.W))
  })
  addPath("chisel/src/resources/halt.sv")
}

class loadstore extends BlackBox with HasBlackBoxPath{
  val io = IO(new Bundle{
    val araddr  = Input(UInt(32.W))
    val arvalid = Input(Bool())
    val arready = Output(Bool())

    val rdata   = Output(UInt(32.W))
    val rresp   = Output(UInt(2.W))
    val rvalid  = Output(Bool())
    val rready  = Input(Bool())

    val awaddr  = Input(UInt(32.W))
    val awvalid = Input(Bool())
    val awready = Output(Bool())
    
    val wdata   = Input(UInt(32.W))
    val wstrb   = Input(UInt(4.W))
    val wvalid  = Input(Bool())
    val wready  = Output(Bool())
    
    val bresp   = Output(UInt(2.W))
    val bvalid  = Output(Bool())
    val bready  = Input(Bool())

    val clock   = Input(Clock())
    val reset   = Input(Bool())
  })
  addPath("chisel/src/resources/DPI-C.sv")
}

class ifu_inst extends BlackBox with HasBlackBoxPath{
  val io = IO(new Bundle{
    val clock = Input(Clock())
    val reqValid = Input(Bool())
    val respValid = Output(Bool())
    val raddr = Input(UInt(32.W))
    val rdata = Output(UInt(32.W))
  })
  addPath("chisel/src/resources/DPI-C.sv")
}

class regRead extends BlackBox with HasBlackBoxPath{
  val io = IO(new Bundle{
    val pc = Input(UInt(32.W))
    val valid = Input(Bool())
    val regs_flat = Input(UInt((32*32).W))
  })
  addPath("chisel/src/resources/DPI-C.sv")
}

class itrace extends BlackBox with HasBlackBoxPath{
  val io = IO(new Bundle{
    val pc = Input(UInt(32.W))
    val inst = Input(UInt(32.W))
    val valid = Input(Bool())
  })
  addPath("chisel/src/resources/DPI-C.sv")
}

class ftrace extends BlackBox with HasBlackBoxPath{
  val io = IO(new Bundle{
    val call = Input(Bool())
    val ret = Input(Bool())
    val addr = Input(UInt(32.W))
    val pc = Input(UInt(32.W))
  })
  addPath("chisel/src/resources/DPI-C.sv")
}
