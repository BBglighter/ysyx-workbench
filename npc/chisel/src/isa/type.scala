package RV32I

import chisel3._
import chisel3.util._

object fuType{
  val alu = "b0000".U(4.W)
  val bru = "b0001".U(4.W)
}

object aluOp{
  val ADD = "b0000".U(4.W)
  val SUB = "b0001".U(4.W)
}

object srcType{
  val reg = "b00".U(2.W)
  val imm = "b01".U(2.W)
  val pc  = "b10".U(2.W)
  val _null = "b11".U(2.W)
}

object BranchType{
  val none = "b0000".U(4.W)
  val jalr = "b0001".U(4.W)
}

object ImmType{
  val immR = "b000".U(3.W)
  val immI = "b001".U(3.W)
  val immS = "b010".U(3.W)
  val immB = "b011".U(3.W)
  val immU = "b100".U(3.W)
  val immJ = "b101".U(3.W)
}

object MemOpType{
  val none = 0.U(4.W)
  val lw = 1.U(4.W)
  val sw = 2.U(4.W)
}
