package RV32I

import chisel3._
import chisel3.util._
import chisel3.experimental._

class uart extends Module{
  val io = IO(new Bundle{
    val axi4io = new axi4bus
  })

  io.axi4io.awready := Mux(io.axi4io.awvalid,true.B,false.B)
  io.axi4io.wready  := false.B
  val reg_b  = RegInit(false.B)
  io.axi4io.bvalid  := reg_b
  io.axi4io.bresp   := 0.U
  when(io.axi4io.wvalid){
    io.axi4io.wready := true.B
    printf("%c",io.axi4io.wdata(7, 0))
    reg_b  := true.B
  }
  when(io.axi4io.bvalid && io.axi4io.bready){
    reg_b := false.B
  }
  io.axi4io.arready := false.B
  io.axi4io.rdata   := false.B
  io.axi4io.rresp   := 0.U
  io.axi4io.rvalid  := false.B
}
