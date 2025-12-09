package RV32I

import chisel3._
import chisel3.util._

class IDU extends Module{
  val io = IO(new Bundle{
    val in = Flipped(Decoupled(new ctrlFlowIO))
    val out = Decoupled(new ID2EX)
    val io_reg = Flipped(new RegRead)
  })
  val instr = io.in.bits.instr
  val rs1 = instr(19,15)
  val rs2 = instr(24,20)
  val decodeList = ListLookup(instr,DecodeTable.default,DecodeTable.table)

  val fuType :: aluOp :: src1Type :: src2Type :: immType :: brType :: memType :: Nil = decodeList

  val decodeCtrl = Wire(new decodeCtrl)
  decodeCtrl.fuType := fuType
  decodeCtrl.aluOp := aluOp
  decodeCtrl.src1Type := src1Type
  decodeCtrl.src2Type := src2Type
  decodeCtrl.immType := immType
  decodeCtrl.brType := brType
  decodeCtrl.memType := memType

  io.out.bits.idCtrl := decodeCtrl
  io.io_reg.raddr1 := rs1
  io.io_reg.raddr2 := rs2


  io.io_reg.csraddr := instr(31,20)
  when(decodeCtrl.fuType === "b0100".U(4.W)){
    io.io_reg.csraddr := "h305".U(12.W)
  }.elsewhen(decodeCtrl.fuType === "b0101".U(4.W)){
    io.io_reg.csraddr := "h341".U(12.W)
  }

  val data = Wire(new DataSrcIO)
  data.csr := io.io_reg.csrdata
  data.src1 := MuxLookup(src1Type, 0.U(32.W))(Seq(
    srcType.reg -> io.io_reg.rdata1,
    srcType.pc  -> io.in.bits.pc
    //todo
  ))
  data.src2 := MuxLookup(src2Type, 0.U(32.W))(Seq(
    srcType.reg -> io.io_reg.rdata2,
    srcType.pc  -> io.in.bits.pc,
    srcType.csr -> io.io_reg.csrdata
    //todo
  ))
  data.imm := MuxLookup(immType, 0.U(32.W))(Seq(
    ImmType.immR -> 0.U(32.W),
    ImmType.immI -> Cat(Fill(20, instr(31)), instr(31,20)),
    ImmType.iCSR -> Cat(Fill(20, instr(31)), instr(31,20)),
    ImmType.immS -> Cat(Fill(20, instr(31)), instr(31,25),instr(11,7)),
    ImmType.immU -> Cat(instr(31,12), Fill(12, 0.U)),
    ImmType.immJ -> Cat(Fill(12, instr(31)), instr(19,12), instr(20), instr(30,21), 0.U),
    ImmType.immB -> Cat(Fill(20, instr(31)), instr(7), instr(30,25), instr(11,8), 0.U)
    //todo
  ))
  io.out.bits.data <> data
  io.out.bits.cf := io.in.bits
  
  io.in.ready := true.B
  io.out.valid := true.B
}
