package RV32I

import chisel3._
import chisel3.util._

class Top extends Module{
  // val io = IO(new Bundle{
  //   val inst = Input(UInt(32.W))
  //   val pc = Output(UInt(32.W))
  // })

  val reg_pc = RegInit(0x80000000L.U(32.W))

  // io.pc := reg_pc
  val IFU = Module(new IFU())
  val IDU = Module(new IDU())
  val EXU = Module(new EXU())
  val LSU = Module(new LSU())
  val WBU = Module(new WBU())
  val RF = Module(new Regfile())

  

  reg_pc := WBU.out
  IFU.pc := reg_pc
  IFU.out <> IDU.io.in
  IDU.io.out <> EXU.in
  EXU.out <> LSU.in
  LSU.out <> WBU.in
  RF.io.read <> IDU.io.io_reg
  RF.io.write <> WBU.io_reg

  
  val halt = Module(new halt())
  halt.io.h_return := RF.io.halt_d
  halt.io.halt := WBU.halt
}
