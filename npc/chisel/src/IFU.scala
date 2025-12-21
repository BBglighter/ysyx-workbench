package RV32I

import chisel3._
import chisel3.util._

class IFU extends Module{
  val io = IO(new Bundle{
    val pc = Input(UInt(32.W))
    val loadinst = Input(Bool())
    val out = Decoupled(new ctrlFlowIO)
    val axibus = Flipped(new axi4bus)
    val axisel = Output(UInt(2.W))
  })
  
  val s_idle :: s_wait_ready :: Nil = Enum(2)
  val state = RegInit(s_idle)
  state := MuxLookup(state,s_idle)(List(
    s_idle       -> Mux(io.out.valid, s_wait_ready, s_idle),
    s_wait_ready -> Mux(io.out.ready, s_idle, s_wait_ready)
    ))

  val nul :: load :: Nil = Enum(2)
  val load_s = RegInit(nul)
  load_s := MuxLookup(load_s,nul)(List(
    nul  -> Mux(io.loadinst,load,nul),
    load -> nul
    ))

  
  io.axibus.awaddr := 0.U
  io.axibus.awvalid := false.B
  io.axibus.wdata  := 0.U 
  io.axibus.wstrb  := 0.U 
  io.axibus.wvalid  := false.B
  io.axibus.bready  := false.B

  io.axibus.araddr := io.pc

  val inst_reg = RegInit(0.U(32.W))
  inst_reg := io.axibus.rdata
  val pc_reg = RegInit(0.U(32.W))
  pc_reg := io.pc
  io.out.valid := io.axibus.rvalid 
  val getinst = Wire(Bool())
  getinst := (pc_reg =/= io.pc)||(io.loadinst && (load_s === nul))
  io.axisel     := 1.U 
  io.axibus.rready  := getinst 
  io.axibus.arvalid := getinst

  io.out.bits.pc := io.pc
  io.out.bits.instr := Mux((pc_reg===io.pc)&&(inst_reg=/=0.U),inst_reg,io.axibus.rdata)
  io.out.bits.wen := Mux(io.out.ready && io.out.valid,true.B,false.B) 
  
  val traceDPI = Module(new itrace())
  traceDPI.io.valid := true.B
  traceDPI.io.pc := io.pc
  traceDPI.io.inst := io.axibus.rdata
}
