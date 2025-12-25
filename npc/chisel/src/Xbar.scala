package RV32I

import chisel3._
import chisel3.util._
import chisel3.experimental._

class Xbar extends Module{
  val io = IO(new Bundle{
    val slave = new axi4bus
  })
  val clint = Module(new CLINT())
  
  val clintBase= 0x10000008L.U
  val clintEnd = 0x1000000CL.U
  
  val is_clint = (io.slave.araddr >= clintBase)&&(io.slave.araddr <= clintEnd)

  clint.io.axi4io.araddr := Mux(is_clint,io.slave.araddr,0.U)
  clint.io.axi4io.arvalid:= Mux(is_clint,io.slave.arvalid,0.U)
  clint.io.axi4io.rready := Mux(is_clint,io.slave.rready,0.U)
  clint.io.axi4io.arid   := 0.U
  clint.io.axi4io.arlen  := 0.U
  clint.io.axi4io.arsize := 0.U
  clint.io.axi4io.arburst:= 0.U
  clint.io.axi4io.awaddr := 0.U
  clint.io.axi4io.awvalid:= 0.U
  clint.io.axi4io.awid   := 0.U
  clint.io.axi4io.awlen  := 0.U
  clint.io.axi4io.awsize := 0.U
  clint.io.axi4io.awburst:= 0.U
  clint.io.axi4io.wdata  := 0.U
  clint.io.axi4io.wstrb  := 0.U
  clint.io.axi4io.wvalid := 0.U
  clint.io.axi4io.wlast  := 0.U
  clint.io.axi4io.bready := 0.U
 
  io.slave.arready:= 0.U

  io.slave.rdata  := 0.U
  io.slave.rresp  := 0.U
  io.slave.rvalid := 0.U
  io.slave.rlast  := 0.U
  io.slave.rid    := 0.U

  io.slave.awready:= 0.U
  
  io.slave.wready := 0.U

  io.slave.bresp  := 0.U
  io.slave.bvalid := 0.U
  io.slave.bid    := 0.U
}
