package RV32I

import chisel3._
import chisel3.util._

class ALU extends Module{
  val io = IO(new Bundle{
    val val1 = Input(UInt(32.W))
    val val2 = Input(UInt(32.W))
    val aluOp = Input(UInt(4.W))
    val rlt = Output(UInt(32.W))
  })

  io.rlt := MuxLookup(io.aluOp, 0.U(4.W))(Seq(
    aluOp.ADD -> (io.val1 + io.val2),
    aluOp.SUB -> (io.val1 + io.val2)
  ))

}
