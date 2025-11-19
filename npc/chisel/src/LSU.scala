package RV32I

import chisel3._
import chisel3.util._

class LSU extends Module{
  val in = IO(Flipped(Decoupled(new EX2LS)))
  val out = IO(Decoupled(new LS2WB))

  val lsDPI = Module(new loadstore())
  lsDPI.io.raddr := 0.U
  lsDPI.io.valid := false.B
  lsDPI.io.wdata := 0.U
  lsDPI.io.waddr := 0.U
  lsDPI.io.wen   := false.B
  when(in.bits.idCtrl.fuType === fuType.lsu){
    lsDPI.io.valid := true.B
    when(in.bits.idCtrl.immType === ImmType.immS){
      lsDPI.io.wen := true.B
      lsDPI.io.waddr := in.bits.data.src1 + in.bits.data.imm
      lsDPI.io.wdata := in.bits.data.src2
    }.otherwise{
    lsDPI.io.raddr := in.bits.exuData.wdata
    }
  }


  lsDPI.io.wmask := MuxLookup(in.bits.idCtrl.memType,0.U(32.W))(Seq(
    MemOpType.sw -> 15.U(32.W),
    MemOpType.sb -> ((1.U) << (in.bits.exuData.wdata(1,0)))
  ))


  val lbudata = Wire(UInt(32.W))
  lbudata := 0.U
  switch(in.bits.exuData.wdata(1,0)){
    is(0.U) {lbudata := Cat(Fill(24,0.U),lsDPI.io.rdata(7,0))}
    is(1.U) {lbudata := Cat(Fill(24,0.U),lsDPI.io.rdata(15,8))}
    is(2.U) {lbudata := Cat(Fill(24,0.U),lsDPI.io.rdata(23,16))}
    is(3.U) {lbudata := Cat(Fill(24,0.U),lsDPI.io.rdata(31,24))}
  }

  out.bits.wbData.wdata := MuxLookup(in.bits.idCtrl.memType,in.bits.exuData.wdata)(Seq(
    MemOpType.lw -> lsDPI.io.rdata,
    MemOpType.lbu -> lbudata
  ))

  out.bits.cf <> in.bits.cf
  out.bits.idCtrl <> in.bits.idCtrl
  out.bits.wbData.dnpc := in.bits.exuData.dnpc
  
  in.ready := out.ready
  out.valid := in.valid
}
