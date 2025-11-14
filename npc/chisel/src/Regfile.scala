package RV32I

import chisel3._
import chisel3.util._

class Regfile extends Module{
  val io = IO(new RegFlow)
  val regs = Reg(Vec(32,UInt(32.W)))

  regs(0) := 0.U
  io.rdata1 := Mux(io.raddr1 === 0.U,0.U,regs(io.raddr1))
  io.rdata2 := Mux(io.raddr2 === 0.U,0.U,regs(io.raddr2))

  when(io.wen && (io.waddr =/= 0.U)){
    res(io.waddr) := io.wdata
  }
}
