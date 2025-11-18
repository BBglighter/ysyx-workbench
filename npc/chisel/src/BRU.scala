package RV32I

import chisel3._
import chisel3.util._

class BRU extends Module{
  val io = IO(new Bundle{
    val pc = Input(UInt(32.W))
    val src1 = Input(UInt(32.W))
    val src2 = Input(UInt(32.W))
    val imm = Input(UInt(32.W))
    val BranchType = Input(UInt(4.W))
    val d_pc = Output(UInt(32.W))
    val rlt = Output(UInt(32.W))
  })
  val jal = Wire(UInt(32.W))
  val jalr = Wire(UInt(32.W))

  jal := io.imm
  jalr := io.src1 + io.imm

  io.d_pc := MuxLookup(io.BranchType,io.pc + 4.U)(Seq(
      BranchType.jalr -> jalr
  ))
  io.rlt := io.pc + 4.U
} 
