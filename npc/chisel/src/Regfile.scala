package RV32I

import chisel3._
import chisel3.util._

class Regfile extends Module{
  val io = IO(new Bundle{
    val valid = Input(Bool())
    val read = new RegRead
    val write = new RegWrite
    val halt_d = Output(UInt(32.W))
  })
  val regs = Reg(Vec(32,UInt(32.W)))
  
  val readDPI = Module(new regRead())
  regs(0) := 0.U
  io.read.rdata1 := Mux(io.read.raddr1 === 0.U,0.U,regs(io.read.raddr1))
  io.read.rdata2 := Mux(io.read.raddr2 === 0.U,0.U,regs(io.read.raddr2))

  when(io.write.wen && (io.write.waddr =/= 0.U)){
    regs(io.write.waddr) := io.write.wdata
  }
  io.halt_d := regs(10.U)
  readDPI.io.valid := io.valid
  readDPI.io.regs_flat := regs.asUInt
}
