package RV32I

import chisel3._
import chisel3.util._

class EXU extends Module{
  val in = IO(Flipped(Decoupled(new ID2EX)))
  val out = IO(Decoupled(new EX2LS))

  val alu = Module(new RV32I.ALU())
  val bru = Module(new RV32I.BRU())
  
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
  
  out.bits.exuData.wdata := MuxLookup(in.bits.idCtrl.fuType, 0.U(32.W))(Seq(
    fuType.alu -> alu.io.rlt,
    fuType.bru -> bru.io.rlt,
    fuType.lsu -> alu.io.rlt
    ))

  out.bits.cf <> in.bits.cf
  out.bits.idCtrl <> in.bits.idCtrl
  out.bits.data <> in.bits.data
  out.bits.exuData.dnpc := bru.io.d_pc
 
  in.ready := out.ready
  out.valid := in.valid
}
