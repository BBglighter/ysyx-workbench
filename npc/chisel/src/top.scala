package RV32I

import chisel3._
import chisel3.util._

class Top extends Module{
  val io = IO(new Bundle{
    val regValid = Input(Bool())
    val debugPc = Output(UInt(32.W))
    val difftest = Output(Bool())
  })

  val reg_pc = RegInit(0x80000000L.U(32.W))
  val reg_inst = RegInit(0x00000413.U(32.W))

  // io.pc := reg_pc
  val IFU = Module(new IFU())
  val IDU = Module(new IDU())
  val EXU = Module(new EXU())
  val LSU = Module(new LSU())
  val WBU = Module(new WBU())
  val RF = Module(new Regfile())

  reg_inst := IFU.io.out.bits.instr
  io.debugPc := WBU.out
  reg_pc := WBU.out
  io.difftest := Mux((reg_inst === IFU.io.out.bits.instr)&&(!WBU.in.bits.load),true.B,false.B)
  IFU.io.pc := reg_pc
  IFU.io.out <> IDU.io.in
  IDU.io.out <> EXU.in
  EXU.out <> LSU.in
  LSU.out <> WBU.in
  RF.io.pc := reg_pc
  RF.io.read <> IDU.io.io_reg
  RF.io.write <> WBU.io_reg
  RF.io.valid := io.regValid

  
  val halt = Module(new halt())
  halt.io.h_return := RF.io.halt_d
  halt.io.halt := WBU.halt
}
