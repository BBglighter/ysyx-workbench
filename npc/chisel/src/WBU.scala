package RV32I

import chisel3._
import chisel3.util._

class WBU extends Module{
  val in = IO(Flipped(Decoupled(new LS2WB)))
  val out = IO(Output(UInt(32.W)))
  val halt = IO(Output(Bool()))
  val io_reg = IO(Flipped(new RegWrite))
  val rd = Wire(UInt(5.W))
  rd := in.bits.cf.instr(11,7)
 
  val wb = Wire(UInt(32.W))
  wb := in.bits.wbData.wdata

  //Default
  io_reg.waddr := rd
  io_reg.wdata := wb
  io_reg.wen   := false.B
  halt := false.B

  when(in.bits.idCtrl.fuType === fuType.ebreak){
    halt := true.B
  }.elsewhen(!(in.bits.idCtrl.immType === ImmType.immS||in.bits.idCtrl.immType === ImmType.immB||in.bits.idCtrl.immType === ImmType.none)){
    io_reg.wen := true.B    
  }
  
  out := in.bits.wbData.dnpc

  in.ready := true.B
}
