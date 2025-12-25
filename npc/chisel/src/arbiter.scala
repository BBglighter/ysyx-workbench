package RV32I

import chisel3._
import chisel3.util._

class axi4Arbiter extends Module{
  val io = IO(new Bundle{
    val bus1 = new axi4bus
    val bus1sel = Input(UInt(3.W))
    val bus2 = new axi4bus
    val bus2sel = Input(UInt(3.W))
    val master = Flipped(new axi4bus)
  })

  io.master.araddr := 0.U
  io.master.arvalid := 0.U
  io.master.arid   := 0.U
  io.master.arlen  := 0.U
  io.master.arsize := 0.U
  io.master.arburst:= 0.U
  

  io.master.awaddr := 0.U
  io.master.awvalid := 0.U
  io.master.awid   := 0.U
  io.master.awlen  := 0.U
  io.master.awsize := 0.U
  io.master.awburst:= 0.U

  io.master.wdata := 0.U
  io.master.wstrb := 0.U
  io.master.wvalid := 0.U
  io.master.wlast := 0.U

  io.master.bready := 0.U


  io.bus1.arready := 0.U
  io.bus1.rdata   := 0.U
  io.bus1.rresp   := 0.U
  io.bus1.rvalid  := 0.U
  io.bus1.rid     := 0.U 
  io.bus1.rlast   := 0.U 
  io.bus1.awready := 0.U
  io.bus1.wready  := 0.U
  io.bus1.bid     := 0.U 
  io.bus1.bresp   := 0.U
  io.bus1.bvalid  := 0.U
  io.master.bready := io.bus1.bready

  io.bus2.arready := 0.U
  io.bus2.rdata   := 0.U
  io.bus2.rresp   := 0.U
  io.bus2.rvalid  := 0.U
  io.bus2.rid     := 0.U 
  io.bus2.rlast   := 0.U 
  io.bus2.awready := 0.U
  io.bus2.wready  := 0.U
  io.bus2.bresp   := 0.U
  io.bus2.bid     := 0.U 
  io.bus2.bvalid  := 0.U
  io.bus2.rdata   := io.master.rdata
  io.bus2.rvalid  := io.master.rvalid
  io.master.rready := io.bus2.rready

  
  
  val sel = Wire(UInt(3.W))
  sel := Mux(io.bus1sel > io.bus2sel,io.bus1sel,io.bus2sel)
  when(sel(1)){
    io.master.araddr := io.bus1.araddr
    io.master.arvalid := io.bus1.arvalid
    io.master.awaddr := io.bus1.awaddr
    io.master.awvalid := io.bus1.awvalid
    io.master.wdata := io.bus1.wdata
    io.master.wstrb := io.bus1.wstrb
    io.master.wvalid := io.bus1.wvalid
    io.master.wlast := io.bus1.wlast
    io.bus1.arready := io.master.arready 
    io.bus1.awready := io.master.awready
    io.bus1.wready  := io.master.wready
    io.bus1.bresp   := io.master.bresp 
    io.bus1.bvalid  := io.master.bvalid
  }
  when(sel(0)){
    io.master.araddr := io.bus2.araddr
    io.master.arvalid := io.bus2.arvalid
    io.bus2.arready := io.master.arready 
    io.bus2.rresp   := io.master.rresp 
  }
  when(sel === 3.U){
    io.master.rready := io.bus1.rready
    io.bus1.rdata   := io.master.rdata
    io.bus1.rresp   := io.master.rresp 
    io.bus1.rvalid  := io.master.rvalid
  }
}
