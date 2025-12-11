package RV32I

import chisel3._
import chisel3.util._

class LSU extends Module{
  val in = IO(Flipped(Decoupled(new EX2LS)))
  val out = IO(Decoupled(new LS2WB))

  val lsDPI = Module(new loadstore())
  lsDPI.io.clock := clock
  lsDPI.io.addr := 0.U
  lsDPI.io.wdata := 0.U
  lsDPI.io.wen   := false.B
  when(in.bits.idCtrl.fuType === fuType.lsu && in.bits.cf.wen){
    when(in.bits.idCtrl.immType === ImmType.immS){
      lsDPI.io.wen := true.B
      lsDPI.io.addr := in.bits.data.src1 + in.bits.data.imm
      lsDPI.io.wdata := in.bits.data.src2
    }.otherwise{
    lsDPI.io.addr := in.bits.exuData.wdata
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

  out.bits.load := MuxLookup(in.bits.idCtrl.memType,false.B)(Seq(
    MemOpType.lw  -> true.B,
    MemOpType.lbu -> true.B,
    MemOpType.lb  -> true.B,
    MemOpType.lh  -> true.B,
    MemOpType.lhu -> true.B
  ))
  val notload :: p1 :: p2 :: Nil = Enum(3)
  val state = RegInit(notload)
  state := MuxLookup(state,notload)(List(
    notload -> Mux(out.bits.load, p1, notload),
    p1      -> p2,
    p2      -> notload
    ))
  when(state === p2){
    out.bits.load := false.B
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
