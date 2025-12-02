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
  val bne = Wire(UInt(32.W))
  val beq = Wire(UInt(32.W))
  val bge = Wire(UInt(32.W))
  val bgeu= Wire(UInt(32.W))
  val blt = Wire(UInt(32.W))
  val bltu= Wire(UInt(32.W))

  jal := io.pc + io.imm
  jalr := io.src1 + io.imm
  bne := Mux(io.src1 =/= io.src2, io.pc + io.imm, io.pc + 4.U)
  beq := Mux(io.src1 === io.src2, io.pc + io.imm, io.pc + 4.U)
  bge := Mux(io.src1.asSInt >= io.src2.asSInt, io.pc + io.imm, io.pc + 4.U)
  bgeu:= Mux(io.src1 >= io.src2, io.pc + io.imm, io.pc + 4.U)
  blt := Mux(io.src1.asSInt < io.src2.asSInt, io.pc + io.imm, io.pc + 4.U)
  bltu:= Mux(io.src1 < io.src2, io.pc + io.imm, io.pc + 4.U)


  io.d_pc := MuxLookup(io.BranchType,io.pc + 4.U)(Seq(
      BranchType.jalr -> jalr,
      BranchType.jal -> jal,
      BranchType.bne -> bne,
      BranchType.beq -> beq,
      BranchType.bge -> bge,
      BranchType.bgeu-> bgeu,
      BranchType.blt -> blt,
      BranchType.bltu-> bltu,
  ))
  io.rlt := io.pc + 4.U
} 
