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
    MemOpType.sb -> ((1.U) << (in.bits.exuData.wdata(1,0))),
    MemOpType.sh -> ((3.U) << (in.bits.exuData.wdata(1,0)))
  ))


  val lbdata = Wire(UInt(32.W))
  lbdata := 0.U
  switch(in.bits.exuData.wdata(1,0)){
    is(0.U) {lbdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lbu,0.U,lsDPI.io.rdata(7))),lsDPI.io.rdata(7,0))}
    is(1.U) {lbdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lbu,0.U,lsDPI.io.rdata(15))),lsDPI.io.rdata(15,8))}
    is(2.U) {lbdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lbu,0.U,lsDPI.io.rdata(23))),lsDPI.io.rdata(23,16))}
    is(3.U) {lbdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lbu,0.U,lsDPI.io.rdata(31))),lsDPI.io.rdata(31,24))}
  }

  val lhdata = Wire(UInt(32.W))
  lhdata := 0.U
  switch(in.bits.exuData.wdata(1,0)){
    is(0.U) {lhdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lhu,0.U,lsDPI.io.rdata(15))),lsDPI.io.rdata(15,0))}
    is(2.U) {lhdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lhu,0.U,lsDPI.io.rdata(31))),lsDPI.io.rdata(31,16))}
  }

  out.bits.wbData.wdata := MuxLookup(in.bits.idCtrl.memType,in.bits.exuData.wdata)(Seq(
    MemOpType.lw -> lsDPI.io.rdata,
    MemOpType.lbu -> lbdata,
    MemOpType.lb  -> lbdata,
    MemOpType.lh  -> lhdata,
    MemOpType.lhu -> lhdata
  ))

  out.bits.cf <> in.bits.cf
  out.bits.idCtrl <> in.bits.idCtrl
  out.bits.wbData.dnpc := in.bits.exuData.dnpc
  out.bits.wbData.csr := in.bits.exuData.csr
  
  in.ready := out.ready
  out.valid := in.valid
}
