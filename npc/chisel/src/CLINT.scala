
package RV32I

import chisel3._
import chisel3.util._
import chisel3.experimental._

class CLINT extends Module {
  val io = IO(new Bundle {
    val axi4io = new axi4bus
  })

  val mtime = RegInit(0.U(64.W))
  mtime := mtime + 1.U
  val mtime_l = mtime(31, 0)
  val mtime_h = mtime(63, 32)

  io.axi4io.arready := true.B 

  val reg_rvalid = RegInit(false.B)
  val reg_rdata  = RegInit(0.U(32.W))

  when(io.axi4io.arvalid && io.axi4io.arready) {
    reg_rvalid := true.B
    reg_rdata := MuxLookup(io.axi4io.araddr, 0.U)(Seq(
      0x10000008.U -> mtime_l,
      0x1000000C.U -> mtime_h
    ))
  } .elsewhen(io.axi4io.rready && io.axi4io.rvalid) {
    reg_rvalid := false.B
  }

  io.axi4io.rvalid := reg_rvalid
  io.axi4io.rdata  := reg_rdata
  io.axi4io.rresp  := 0.U

  io.axi4io.awready := false.B 
  io.axi4io.wready  := false.B
  io.axi4io.bvalid  := false.B
  io.axi4io.bresp   := 0.U
  io.axi4io.rid    := 0.U
  io.axi4io.bid    := 0.U
  io.axi4io.rlast  := 0.U
}
