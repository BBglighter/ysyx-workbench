package RV32I

import chisel3._
import chisel3.util._

class IFU extends Module{
  val io = IO(new Bundle{
    val pc = Input(UInt(32.W))
    val out = Decoupled(new ctrlFlowIO)
  })
  
  val s_idle :: s_wait_ready :: Nil = Enum(2)
  val state = RegInit(s_idle)
  state := MuxLookup(state,s_idle)(List(
    s_idle       -> Mux(io.out.valid, s_wait_ready, s_idle),
    s_wait_ready -> Mux(io.out.ready, s_idle, s_wait_ready)
    ))

  
  val ifu_DPI = Module(new ifu_inst())

  ifu_DPI.io.raddr := io.pc
  ifu_DPI.io.clock := clock
  val inst_reg = RegInit(0.U(32.W))
  inst_reg := ifu_DPI.io.rdata
  io.out.valid := Mux(inst_reg === ifu_DPI.io.rdata,false.B,true.B)

  io.out.bits.pc := io.pc
  io.out.bits.instr := ifu_DPI.io.rdata
  io.out.bits.wen := Mux(io.out.ready && io.out.valid,true.B,false.B) 
  
  val traceDPI = Module(new itrace())
  traceDPI.io.valid := true.B
  traceDPI.io.pc := io.pc
  traceDPI.io.inst := ifu_DPI.io.rdata
}
