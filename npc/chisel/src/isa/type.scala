package RV32I

import chisel3._
import chisel3.util._

object fuType{
  val alu = "b0000".U
  val bru = "b0001".U
}

object srcType{
  val reg = "b00".U
  val imm = "b01".U
  val pc  = "b10".U
  val null = "b11".U
}

object BranchType{
  val none = 0.U
  val jalr = 1.U
}

object ImmType{
  val immR = "b000.U"
  val immI = "b001.U"
  val immS = "b010.U"
  val immB = "b011.U"
  val immU = "b100.U"
  val immJ = "b001.U"
}

object MemOpType{
  val none = 0.U
  val lw = 1.U
  val sw = 2.U
}
