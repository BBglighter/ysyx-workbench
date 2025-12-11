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
 

  val s_load :: s_over :: Nil = Enum(2)
  val state = RegInit(s_load)
  state := MuxLookup(state,s_load)(List(
    s_load       -> Mux(in.bits.load, s_over, s_load),
    s_over -> s_load
    ))
  
  val loadover = Wire(Bool())
  loadover := (!in.bits.load || state === s_over)
  //Default
  io_reg.waddr := rd
  io_reg.wdata := Mux(in.bits.idCtrl.immType === ImmType.iCSR, in.bits.wbData.csr, in.bits.wbData.wdata)
  io_reg.wen   := false.B
  halt := false.B

  when(in.bits.idCtrl.fuType === fuType.ebreak && in.bits.cf.wen){
    halt := true.B
  }.elsewhen(!(in.bits.idCtrl.immType === ImmType.immS||in.bits.idCtrl.immType === ImmType.immB||in.bits.idCtrl.immType === ImmType.none) 
                &&((in.bits.cf.wen&&loadover)||(loadover&&in.bits.load))){
    io_reg.wen := true.B    
  }
  
  out := Mux((in.bits.cf.wen&&loadover)||(loadover&&in.bits.load),in.bits.wbData.dnpc,in.bits.cf.pc)

  in.ready := true.B

  val ftraceDPI = Module(new ftrace())
  ftraceDPI.io.call := false.B
  ftraceDPI.io.ret := false.B
  ftraceDPI.io.addr := in.bits.wbData.dnpc
  ftraceDPI.io.pc := in.bits.cf.pc

  when(in.bits.idCtrl.brType === BranchType.jalr && in.bits.cf.wen){
    when(in.bits.cf.instr === "h00008067".U){
      ftraceDPI.io.ret := true.B
    }.otherwise{
      ftraceDPI.io.call := true.B
    }
  }.elsewhen(in.bits.idCtrl.brType === BranchType.jal&& in.bits.cf.wen){
    ftraceDPI.io.call := true.B 
  }
  
  io_reg.csraddr := Mux(in.bits.idCtrl.immType === ImmType.iCSR,in.bits.cf.instr(31,20),0.U(12.W))
  io_reg.csrdata := in.bits.wbData.wdata
  
  when(in.bits.idCtrl.fuType === fuType.ecall){
    io_reg.csraddr := "h341".U(12.W)
    io_reg.csrdata := in.bits.cf.pc 
    out := in.bits.wbData.csr 
  }.elsewhen(in.bits.idCtrl.fuType === fuType.mret){
    out := in.bits.wbData.csr
  } 
}
