package RV32I

import chisel3._
import chisel3.util._

class Regfile extends Module{
  val io = IO(new Bundle{
    val pc = Input(UInt(32.W))
    val valid = Input(Bool())
    val read = new RegRead
    val write = new RegWrite
    val halt_d = Output(UInt(32.W))
  }) 
  val regs = Reg(Vec(32,UInt(32.W)))
  val mcycle = RegInit(0.U(32.W))
  val mcycleh = RegInit(0.U(32.W))
  val mvendorid = RegInit("h79737978".U(32.W))
  val marchid = RegInit("h17f26ff".U(32.W))
  val mepc = RegInit(0.U(32.W))
  val mtvec = RegInit(0.U(32.W))
  val mcause = RegInit(11.U(32.W)) 
  val mstatus = RegInit("h1800".U(32.W))
  
  switch(io.write.csraddr){
    is(CSR.mcycle){
      mcycle := io.write.csrdata
    }
    is(CSR.mcycleh){
      mcycleh := io.write.csrdata
    }
    is(CSR.mvendorid){
      mvendorid:= io.write.csrdata
    }
    is(CSR.marchid){
      marchid := io.write.csrdata
    }
    is(CSR.mepc){
      mepc := io.write.csrdata
    }
    is(CSR.mtvec){
      mtvec := io.write.csrdata
    }
    is(CSR.mcause){
      mcause := io.write.csrdata
    }
    is(CSR.mstatus){
      mstatus := io.write.csrdata
    }
  }
  
  io.read.csrdata := MuxLookup(io.read.csraddr,0.U(32.W))(Seq(
    CSR.mcycle -> mcycle,
    CSR.mcycleh-> mcycleh,
    CSR.mvendorid->mvendorid,
    CSR.marchid-> marchid,
    CSR.mepc -> mepc,
    CSR.mtvec -> mtvec,
    CSR.mcause->mcause,
    CSR.mstatus->mstatus
  ))

  val countReg = RegInit(0.U(64.W))
  countReg := countReg+1.U

  mcycle := countReg(31,0)
  mcycleh:= countReg(63,32)
  
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
  readDPI.io.pc := io.pc
}
