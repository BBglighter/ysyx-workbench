package RV32I

import chisel3._
import chisel3.util._
import chisel3.experimental._

class Xbar extends Module{
  val io = IO(new Bundle{
    val in = new axi4bus
  })
  val uart = Module(new uart())
  val memory = Module(new loadstore())
  val clint = Module(new CLINT())
  memory.io.clock := clock
  memory.io.reset := reset
  
  val uartBase = 0x10000000L.U
  val uartEnd  = 0x10000FFFL.U
  val clintBase= 0x10000008L.U
  val clintEnd = 0x1000000CL.U
  val memBase  = 0x80000000L.U
  
  val is_uart  = (io.in.awaddr >= uartBase)&&(io.in.awaddr <= uartEnd)
  val is_mem   = (io.in.awaddr >= memBase)||(io.in.araddr >= memBase)
  val is_clint = (io.in.araddr >= clintBase)&&(io.in.araddr <= clintEnd)
  
  val state = Wire(UInt(4.W))
  val read_state = RegInit(0.U(4.W))
  state := 0.U
  when(is_uart && !is_clint){
    read_state := 1.U
  }
  when(is_mem){
    read_state := 2.U
  }
  when(is_clint){
    read_state := 3.U
  }
  when(read_state === 3.U){
    read_state := 2.U
  }

  clint.io.axi4io.araddr := Mux(is_clint,io.in.araddr,0.U)
  clint.io.axi4io.arvalid:= Mux(is_clint,io.in.arvalid,0.U)
  clint.io.axi4io.rready := Mux(is_clint,io.in.rready,0.U)
  clint.io.axi4io.awaddr := 0.U
  clint.io.axi4io.awvalid:= 0.U
  clint.io.axi4io.wdata  := 0.U
  clint.io.axi4io.wstrb  := 0.U
  clint.io.axi4io.wvalid := 0.U
  clint.io.axi4io.bready := 0.U
  
  uart.io.axi4io.araddr := 0.U
  uart.io.axi4io.arvalid:= 0.U
  uart.io.axi4io.rready := false.B
  uart.io.axi4io.awaddr := Mux(is_uart,io.in.awaddr,0.U)
  uart.io.axi4io.awvalid:= Mux(is_uart,io.in.awvalid,0.U)
  uart.io.axi4io.wdata  := Mux(is_uart,io.in.wdata,0.U)
  uart.io.axi4io.wstrb  := Mux(is_uart,io.in.wstrb,0.U)
  uart.io.axi4io.wvalid := Mux(is_uart,io.in.wvalid,0.U)
  uart.io.axi4io.bready := Mux(is_uart,io.in.bready,0.U)
  
  memory.io.araddr := io.in.araddr
  memory.io.arvalid:= Mux(is_mem,io.in.arvalid,0.U)
  memory.io.rready := Mux(is_mem,io.in.rready,0.U)
  memory.io.awaddr := Mux(is_mem,io.in.awaddr,0.U)
  memory.io.awvalid:= Mux(is_mem,io.in.awvalid,0.U)
  memory.io.wdata  := Mux(is_mem,io.in.wdata,0.U)
  memory.io.wstrb  := Mux(is_mem,io.in.wstrb,0.U)
  memory.io.wvalid := Mux(is_mem,io.in.wvalid,0.U)
  memory.io.bready := Mux(is_mem,io.in.bready,0.U)

  io.in.arready := MuxLookup(read_state,0.U)(List(
    3.U -> clint.io.axi4io.awready,
    2.U -> memory.io.awready
  ))
  io.in.rdata   := MuxLookup(read_state,0.U)(List(
    3.U -> clint.io.axi4io.rdata,
    2.U -> memory.io.rdata
  ))
  io.in.rresp   := MuxLookup(read_state,0.U)(List(
    3.U -> clint.io.axi4io.rresp,
    2.U -> memory.io.rresp
  ))
  io.in.rvalid :=  MuxLookup(read_state,0.U)(List(
    3.U -> clint.io.axi4io.rvalid,
    2.U -> memory.io.rvalid
  ))
  
  io.in.awready := MuxLookup(read_state,0.U)(List(
    1.U -> uart.io.axi4io.awready,
    2.U -> memory.io.awready
  ))
  io.in.wready  := MuxLookup(read_state,0.U)(List(
    1.U -> uart.io.axi4io.wready,
    2.U -> memory.io.wready
  ))
  io.in.bresp   := MuxLookup(read_state,0.U)(List(
    1.U -> uart.io.axi4io.bresp,
    2.U -> memory.io.bresp
  ))
  io.in.bvalid  := MuxLookup(read_state,0.U)(List(
    1.U -> uart.io.axi4io.bvalid,
    2.U -> memory.io.bvalid
  ))
}
