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
    lsDPI.io.raddr := in.bits.data.src1 + in.bits.data.imm
    }
  }

  lsDPI.io.rbyte := MuxLookup(in.bits.idCtrl.memType,0.U(32.W))(Seq(
    MemOpType.lw -> 4.U(32.W),
    MemOpType.lbu -> 1.U(32.W)
  ))

  lsDPI.io.wmask := MuxLookup(in.bits.idCtrl.memType,0.U(32.W))(Seq(
    MemOpType.sw -> 4.U(32.W),
    MemOpType.sb -> 1.U(32.W)
  ))

  out.bits.wbData.wdata := MuxLookup(in.bits.idCtrl.memType,in.bits.exuData.wdata)(Seq(
    MemOpType.lw -> lsDPI.io.rdata,
    MemOpType.lbu -> lsDPI.io.rdata
  ))

  out.bits.cf <> in.bits.cf
  out.bits.idCtrl <> in.bits.idCtrl
  out.bits.wbData.dnpc := in.bits.exuData.dnpc
  
  in.ready := out.ready
  out.valid := in.valid
}
