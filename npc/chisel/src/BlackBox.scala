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
    val wen = Input(Bool())
    val valid = Input(Bool())
    val raddr = Input(UInt(32.W))
    val wdata = Input(UInt(32.W))
    val waddr = Input(UInt(32.W))
    val wmask = Input(UInt(32.W))
    val rdata = Output(UInt(32.W))
  })
  addPath("chisel/src/resources/DPI-C.sv")
}

class regRead extends BlackBox with HasBlackBoxPath{
  val io = IO(new Bundle{
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
