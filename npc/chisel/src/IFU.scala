package RV32I

import chisel3._
import chisel3.util._

class IFU extends Module{
  val in = IO(Flipped(Decoupled(new ctrlFlowIO)))
  val out = IO(Decoupled(new ctrlFlowIO))

  in.ready := true.B
  out.valid := in.valid

  out.bits.pc := in.bits.pc
  out.bits.instr := in.bits.instr
}
