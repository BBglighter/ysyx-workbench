package RV32I

import chisel3._
import chisel3.util._

class ysyx_25110271 extends Module{
  val io = IO(new Bundle{
    val master = Flipped(new axi4bus)
    val slave = new axi4bus
    val interrupt = Input(Bool())
    val regValid = Input(Bool())
    // val debugPc = Output(UInt(32.W))
    val difftest = Output(Bool())
  })

  val reg_pc = RegInit(0x20000000L.U(32.W))
  val reg_inst = RegInit(0x00000413.U(32.W))

  // io.pc := reg_pc
  val IFU = Module(new IFU())
  val IDU = Module(new IDU())
  val EXU = Module(new EXU())
  val LSU = Module(new LSU())
  val WBU = Module(new WBU())
  val RF = Module(new Regfile())

  val axi4bus = Module(new axi4Arbiter())
  val xbar    = Module(new Xbar())
  axi4bus.io.bus1 <> LSU.axibus 
  axi4bus.io.bus1sel := LSU.axisel
  axi4bus.io.bus2 <> IFU.io.axibus 
  axi4bus.io.bus2sel := IFU.io.axisel
  io.master <> axi4bus.io.master
  io.slave  <> xbar.io.slave 

  reg_inst := IFU.io.out.bits.instr
  // io.debugPc := WBU.out
  reg_pc := WBU.out
  IFU.io.pc := reg_pc
  IFU.io.loadinst := LSU.out.bits.load
  IFU.io.out <> IDU.io.in
  IDU.io.out <> EXU.in
  EXU.out <> LSU.in
  LSU.out <> WBU.in
  RF.io.pc := reg_pc
  RF.io.read <> IDU.io.io_reg
  RF.io.write <> WBU.io_reg
  RF.io.valid := io.regValid
  // RF.io.valid := false.B
  
  val difftest_reg = RegInit(false.B)
  difftest_reg := IFU.io.out.bits.wen 
  io.difftest := difftest_reg

  
  val halt = Module(new halt())
  halt.io.h_return := RF.io.halt_d
  halt.io.halt := WBU.halt
}
