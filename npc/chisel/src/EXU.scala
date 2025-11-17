package RV32I

import chisel3._
import chisel3.util._

class EXU extends Module{
  val in = IO(Flipped(Decoupled(new ID2EX)))
  val out = IO(Output(UInt(32.W)))
  val io_reg = IO(Flipped(new RegWrite))

  in.ready := true.B
  
  val alu = Module(new RV32I.ALU())
  val bru = Module(new RV32I.BRU())

  val rd = Wire(UInt(32.W))
  
  alu.io.val1 := MuxLookup(in.bits.idCtrl.immType,0.U)(Seq(
    ImmType.immR -> in.bits.data.src1,
    ImmType.immI -> in.bits.data.src1
    ))
  alu.io.val2 := MuxLookup(in.bits.idCtrl.immType,0.U)(Seq(
    ImmType.immR -> in.bits.data.src2,
    ImmType.immI -> in.bits.data.imm
    ))
  alu.io.aluOp := in.bits.idCtrl.aluOp
  
  bru.io.src1 := in.bits.data.src1
  bru.io.src2 := in.bits.data.src2
  bru.io.imm := in.bits.data.imm
  bru.io.pc := in.bits.cf.pc
  bru.io.BranchType := in.bits.idCtrl.brType
  
  rd := in.bits.cf.instr(11,7) 
  when(in.bits.idCtrl.immType === ImmType.immS ||in.bits.idCtrl.immType === ImmType.immB){
    io_reg.wen := false.B
  }.otherwise{
    io_reg.wen := true.B
  }
  io_reg.waddr := rd
  io_reg.wdata := MuxLookup(in.bits.idCtrl.fuType, 0.U(32.W))(Seq(
    fuType.alu -> alu.io.rlt,
    fuType.bru -> bru.io.rlt
    ))
  out := bru.io.d_pc
}
