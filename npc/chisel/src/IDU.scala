package RV32I

import chisel3._
import chisel3.util._
import RV32I.isa._

class IDU extends Module{
  val io = IO(new Bundle{
    val in = Flipped(Decoupled(new ctrlFlowIO))
    val out = Decoupled(new ID2EX)
    val io_reg = Flipped(new RegFlow)
  })
  val instr = io.in.bits.instr
  val rs1 = instr(19,15)
  val rs2 = instr(24,20)
  val decodeList = ListLookup(instr,DecodeTable.default,DecodeTable.table)

  val fuType :: src1Type :: src2Type :: immType :: brType :: memType :: Nil = decodeList

  val decodeCtrl = Wire(new decodeCtrl)
  decodeCtrl.fuType := fuType
  decodeCtrl.src1Type := src1Type
  decodeCtrl.src2Type := src2Type
  decodeCtrl.immType := immType
  decodeCtrl.brType := brType
  decodeCtrl.memType := memType

  io.out.bits.idCtrl := decodeCtrl
  io_reg.raddr1 := rs1
  io_reg.raddr2 := rs2
  val data = Wire(new DataSrcIO)
  data.src1 := MuxLookup(src1Type, 0.U(32.W), Array(
    reg -> io_reg.rdata1
    //todo
  ))
  data.src2 := MuxLookup(src2Type, 0.U(32.W), Array(
    reg -> io_reg.rdata2
    //todo
  ))
  data.imm := MuxLookup(immType, 0.S(32.W), Array(
    immR -> 0.S(32.W),
    immI -> Cat(Fill(20, instr(31)), instr(31,20)).asSInt,
    immS -> Cat(Fill(20, instr(31)), instr(31,25),instr(11,7)).asSInt
    //todo
  ))
  io.out.bits.data := data
  io.out.bits.cf := io.in.bits

  io.out.valid := io.in.valid
  io.in.ready := io.out.ready
}
