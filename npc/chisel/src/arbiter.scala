package RV32I

import chisel3._
import chisel3.util._

class axi4Arbiter extends Module{
  val io = IO(new Bundle{
    val bus1 = new axi4bus
    val bus1sel = Input(UInt(2.W))
    val bus2 = new axi4bus
    val bus2sel = Input(UInt(2.W))
    val out = Flipped(new axi4bus)
  })

  io.out.araddr := 0.U
  io.out.arvalid := 0.U
  io.out.rready := 0.U
  io.out.awaddr := 0.U
  io.out.awvalid := 0.U
  io.out.wdata := 0.U
  io.out.wstrb := 0.U
  io.out.wvalid := 0.U
  io.out.bready := 0.U


  io.bus1.arready := 0.U
  io.bus1.rdata   := 0.U
  io.bus1.rresp   := 0.U
  io.bus1.rvalid  := 0.U
  io.bus1.awready := 0.U
  io.bus1.wready  := 0.U
  io.bus1.bresp   := 0.U
  io.bus1.bvalid  := 0.U
  io.out.bready := io.bus1.bready

  io.bus2.arready := 0.U
  io.bus2.rdata   := 0.U
  io.bus2.rresp   := 0.U
  io.bus2.rvalid  := 0.U
  io.bus2.awready := 0.U
  io.bus2.wready  := 0.U
  io.bus2.bresp   := 0.U
  io.bus2.bvalid  := 0.U
  io.bus2.rdata   := io.out.rdata
  io.bus2.rvalid  := io.out.rvalid

  
  
  val sel = Wire(UInt(2.W))
  sel := Mux(io.bus1sel > io.bus2sel,io.bus1sel,io.bus2sel)
  when(sel(1)){
    io.out.araddr := io.bus1.araddr
    io.out.arvalid := io.bus1.arvalid
    io.out.rready := io.bus1.rready
    io.out.awaddr := io.bus1.awaddr
    io.out.awvalid := io.bus1.awvalid
    io.out.wdata := io.bus1.wdata
    io.out.wstrb := io.bus1.wstrb
    io.out.wvalid := io.bus1.wvalid
    io.bus1.arready := io.out.arready 
    io.bus1.rdata   := io.out.rdata
    io.bus1.rresp   := io.out.rresp 
    io.bus1.rvalid  := io.out.rvalid
    io.bus1.awready := io.out.awready
    io.bus1.wready  := io.out.wready
    io.bus1.bresp   := io.out.bresp 
    io.bus1.bvalid  := io.out.bvalid
  }
  when(sel(0)){
    io.out.araddr := io.bus2.araddr
    io.out.arvalid := io.bus2.arvalid
    io.out.rready := io.bus2.rready
    io.bus2.arready := io.out.arready 
    io.bus2.rresp   := io.out.rresp 
  }
}
