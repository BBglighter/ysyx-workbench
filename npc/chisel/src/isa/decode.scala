package RV32I

import chisel3._
import chisel3.util._
import RV32I.isa._

object DecodeTable{
  //fuType,src1Type,src2Type,brType
  val default: List[UInt] = List(
    fuType.alu,
    srcType.reg,
    srcType.reg,
    ImmType.immR,
    BranchType.none,
    MemOpType.none
  )
  val table: Array[(BitPat,List[UInt])] = Array(
    addi -> List(fuType.alu,srcType.reg,srcType.null,ImmType.immI,BranchType.none,MemOpType.none),
    jalr -> List(fuType.bru,srcType.reg,srcType.null,ImmType.immI,BranchType.jalr,MemOpType.none)
  )
}


