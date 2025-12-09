package RV32I

import chisel3._
import chisel3.util._

object fuType{
  val alu = "b0000".U(4.W)
  val bru = "b0001".U(4.W)
  val lsu = "b0010".U(4.W)
  val ebreak = "b0011".U(4.W)
  val ecall = "b0100".U(4.W)
  val mret = "b0101".U(4.W)
}

object aluOp{
  val ADD = "b0000".U(4.W)
  val SUB = "b0001".U(4.W)
  val SRA = "b0010".U(4.W)
  val SRL = "b0011".U(4.W)
  val SLL = "b0100".U(4.W)
  val AND = "b0101".U(4.W)
  val SLT = "b0110".U(4.W)
  val SLTU= "b0111".U(4.W)
  val XOR = "b1000".U(4.W)
  val OR  = "b1001".U(4.W)
  val CSR = "b1010".U(4.W)
  val none = "b1111".U(4.W)
}

object srcType{
  val reg = "b000".U(3.W)
  val imm = "b001".U(3.W)
  val pc  = "b010".U(3.W)
  val none = "b011".U(3.W)
  val csr = "b100".U(3.W)
}

object BranchType{
  val none = "b0000".U(4.W)
  val jalr = "b0001".U(4.W)
  val jal  = "b0010".U(4.W)
  val bne  = "b0011".U(4.W)
  val beq  = "b0100".U(4.W)
  val bge  = "b0101".U(4.W)
  val bgeu = "b0110".U(4.W)
  val blt  = "b0111".U(4.W)
  val bltu = "b1000".U(4.W)
}

object ImmType{
  val immR = "b000".U(3.W)
  val immI = "b001".U(3.W)
  val immS = "b010".U(3.W)
  val immB = "b011".U(3.W)
  val immU = "b100".U(3.W)
  val immJ = "b101".U(3.W)
  val iCSR = "b110".U(3.W)
  val none = "b111".U(3.W)
}

object MemOpType{
  val none = 0.U(4.W)
  val lw = 1.U(4.W)
  val sw = 2.U(4.W)
  val lbu= 3.U(4.W)
  val sb = 4.U(4.W)
  val sh = 5.U(4.W)
  val lb = 6.U(4.W)
  val lh = 7.U(4.W)
  val lhu= 8.U(4.W)
}

object CSR{
  val mcycle = "hb00".U(12.W)
  val mcycleh= "hb80".U(12.W)
  val mvendorid = "hf11".U(12.W)
  val marchid= "hf12".U(12.W)
  val mstatus = "h300".U(12.W)
  val mepc = "h341".U(12.W)
  val mtvec = "h305".U(12.W)
  val mcause = "h342".U(12.W)
}
