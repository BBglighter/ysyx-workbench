package RV32I

import chisel3._
import chisel3.util._

class IFU extends Module{
  val pc = IO(Input(UInt(32.W)))
  val out = IO(Decoupled(new ctrlFlowIO))

  out.valid := true.B
  
  val lsDPI = Module(new loadstore())
  lsDPI.io.valid := true.B
  lsDPI.io.wdata := 0.U
  lsDPI.io.waddr := 0.U
  lsDPI.io.wen   := false.B
  lsDPI.io.wmask := 0.U(32.W)
  
  lsDPI.io.raddr := pc
  out.bits.pc := pc
  out.bits.instr := lsDPI.io.rdata
}
