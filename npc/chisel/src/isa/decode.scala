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
    inst.addi -> List(fuType.alu,aluOp.ADD,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.none),
    inst.xori -> List(fuType.alu,aluOp.XOR,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.none),
    inst.andi -> List(fuType.alu,aluOp.AND,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.none),
    inst.ori  -> List(fuType.alu,aluOp.OR,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.none),
    inst.jalr -> List(fuType.bru,aluOp.none,srcType.reg,srcType.none,ImmType.immI,BranchType.jalr,MemOpType.none),
    inst.lw   -> List(fuType.lsu,aluOp.ADD,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.lw),
    inst.lbu  -> List(fuType.lsu,aluOp.ADD,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.lbu),
    inst.lb   -> List(fuType.lsu,aluOp.ADD,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.lb),
    inst.lh   -> List(fuType.lsu,aluOp.ADD,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.lh),
    inst.lhu  -> List(fuType.lsu,aluOp.ADD,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.lhu),
    inst.sltiu-> List(fuType.alu,aluOp.SLTU,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.none),
    inst.slti -> List(fuType.alu,aluOp.SLT,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.none),
    inst.srai -> List(fuType.alu,aluOp.SRA,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.none),
    inst.srli -> List(fuType.alu,aluOp.SRL,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.none),
    inst.slli -> List(fuType.alu,aluOp.SLL,srcType.reg,srcType.none,ImmType.immI,BranchType.none,MemOpType.none),

    inst.lui  -> List(fuType.alu,aluOp.ADD,srcType.none,srcType.none,ImmType.immU,BranchType.none,MemOpType.none),
    //R-type
    inst.add  -> List(fuType.alu,aluOp.ADD,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),
    inst.sub  -> List(fuType.alu,aluOp.SUB,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),
    inst.or   -> List(fuType.alu,aluOp.OR,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),
    inst.xor  -> List(fuType.alu,aluOp.XOR,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),
    inst.sll  -> List(fuType.alu,aluOp.SLL,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),
    inst.sra  -> List(fuType.alu,aluOp.SRA,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),
    inst.srl  -> List(fuType.alu,aluOp.SRL,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),
    inst.and  -> List(fuType.alu,aluOp.AND,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),
    inst.sltu -> List(fuType.alu,aluOp.SLTU,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),
    inst.slt  -> List(fuType.alu,aluOp.SLT,srcType.reg,srcType.reg,ImmType.immR,BranchType.none,MemOpType.none),

    inst.sw   -> List(fuType.lsu,aluOp.ADD,srcType.reg,srcType.reg,ImmType.immS,BranchType.none,MemOpType.sw),
    inst.sb   -> List(fuType.lsu,aluOp.ADD,srcType.reg,srcType.reg,ImmType.immS,BranchType.none,MemOpType.sb),
    inst.sh   -> List(fuType.lsu,aluOp.ADD,srcType.reg,srcType.reg,ImmType.immS,BranchType.none,MemOpType.sh),

    inst.ebreak -> List(fuType.ebreak,aluOp.none,srcType.none,srcType.none,ImmType.none,BranchType.none,MemOpType.none),
    inst.ecall  -> List(fuType.ecall,aluOp.none,srcType.none,srcType.none,ImmType.none,BranchType.none,MemOpType.none),
    inst.mret  -> List(fuType.mret,aluOp.none,srcType.none,srcType.none,ImmType.none,BranchType.none,MemOpType.none),
    inst.jal  -> List(fuType.bru,aluOp.none,srcType.none,srcType.none,ImmType.immJ,BranchType.jal,MemOpType.none),
    inst.auipc ->List(fuType.alu,aluOp.ADD,srcType.pc,srcType.none,ImmType.immU,BranchType.none,MemOpType.none),
    //B-type
    inst.bne ->List(fuType.bru,aluOp.none,srcType.reg,srcType.reg,ImmType.immB,BranchType.bne,MemOpType.none),
    inst.beq ->List(fuType.bru,aluOp.none,srcType.reg,srcType.reg,ImmType.immB,BranchType.beq,MemOpType.none),
    inst.bge ->List(fuType.bru,aluOp.none,srcType.reg,srcType.reg,ImmType.immB,BranchType.bge,MemOpType.none),
    inst.bgeu->List(fuType.bru,aluOp.none,srcType.reg,srcType.reg,ImmType.immB,BranchType.bgeu,MemOpType.none),
    inst.blt ->List(fuType.bru,aluOp.none,srcType.reg,srcType.reg,ImmType.immB,BranchType.blt,MemOpType.none),
    inst.bltu->List(fuType.bru,aluOp.none,srcType.reg,srcType.reg,ImmType.immB,BranchType.bltu,MemOpType.none),
    
    inst.csrrs->List(fuType.alu,aluOp.OR,srcType.reg,srcType.csr,ImmType.iCSR,BranchType.none,MemOpType.none),
    inst.csrrw->List(fuType.alu,aluOp.CSR,srcType.reg,srcType.csr,ImmType.iCSR,BranchType.none,MemOpType.none)
  )
}


