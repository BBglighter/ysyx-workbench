package RV32I

import chisel3._
import chisel3.util._

object DecodeTable{
  //fuType,src1Type,src2Type,brType
  val default: List[UInt] = List(
    fuType.alu,
    aluOp.ADD,
    srcType.reg,
    srcType.reg,
    ImmType.immR,
    BranchType.none,
    MemOpType.none
  )
  val table: Array[(BitPat,List[UInt])] = Array(
    inst.addi -> List(fuType.alu,aluOp.ADD,srcType.reg,srcType._null,ImmType.immI,BranchType.none,MemOpType.none),
    inst.jalr -> List(fuType.bru,aluOp.ADD,srcType.reg,srcType._null,ImmType.immI,BranchType.jalr,MemOpType.none)
  )
}


