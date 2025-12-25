package RV32I

import chisel3._
import chisel3.util._

class LSU extends Module{
  val in = IO(Flipped(Decoupled(new EX2LS)))
  val out = IO(Decoupled(new LS2WB))
  val axibus = IO(Flipped(new axi4bus))
  val axisel = IO(Output(UInt(3.W)))
    
  val reg_pc = RegInit(0.U(32.W))
  reg_pc := in.bits.cf.pc

  out.bits.load := false.B
 
  axibus.araddr := 0.U
  axibus.arvalid := 0.U
  axibus.arid   := 0.U
  axibus.arlen  := 0.U
  axibus.arsize := 0.U
  axibus.arburst:= 0.U

  axibus.awaddr := 0.U
  axibus.awvalid := 0.U
  axibus.awid   := 0.U
  axibus.awlen  := 0.U
  axibus.awsize := 0.U
  axibus.awburst:= 0.U

  axibus.wdata := 0.U
  axibus.wstrb := 0.U
  axibus.wvalid := 0.U
  axibus.wlast := 0.U
  
  val reg_bready = RegInit(false.B)
  val reg_rready = RegInit(false.B)
  axibus.rready := reg_rready
  axibus.bready  := reg_bready
  reg_bready := false.B
  when(in.bits.idCtrl.fuType === fuType.lsu){
    when(in.bits.idCtrl.immType === ImmType.immS){
      axibus.awvalid := true.B
      axibus.wvalid := true.B
      axibus.awaddr := in.bits.data.src1 + in.bits.data.imm
      axibus.wdata := (in.bits.data.src2 << (axibus.awaddr(1,0) * 8.U))
      reg_bready := true.B
      axibus.wlast := true.B
      // axibus.bready := RegNext(true.B)
    }.otherwise{
    axibus.araddr := in.bits.exuData.wdata
    axibus.arvalid := true.B
    reg_rready := true.B
    out.bits.load := true.B
    }
  }


  axibus.wstrb := MuxLookup(in.bits.idCtrl.memType,0.U(32.W))(Seq(
    MemOpType.sw -> 15.U(32.W),
    MemOpType.sb -> ((1.U) << (in.bits.exuData.wdata(1,0))),
    MemOpType.sh -> ((3.U) << (in.bits.exuData.wdata(1,0)))
  ))


  val lbdata = Wire(UInt(32.W))
  lbdata := 0.U
  switch(in.bits.exuData.wdata(1,0)){
    is(0.U) {lbdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lbu,0.U,axibus.rdata(7))),axibus.rdata(7,0))}
    is(1.U) {lbdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lbu,0.U,axibus.rdata(15))),axibus.rdata(15,8))}
    is(2.U) {lbdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lbu,0.U,axibus.rdata(23))),axibus.rdata(23,16))}
    is(3.U) {lbdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lbu,0.U,axibus.rdata(31))),axibus.rdata(31,24))}
  }

  val lhdata = Wire(UInt(32.W))
  lhdata := 0.U
  switch(in.bits.exuData.wdata(1,0)){
    is(0.U) {lhdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lhu,0.U,axibus.rdata(15))),axibus.rdata(15,0))}
    is(2.U) {lhdata := Cat(Fill(24,Mux(in.bits.idCtrl.memType === MemOpType.lhu,0.U,axibus.rdata(31))),axibus.rdata(31,16))}
  }


  val notload :: p1 ::  Nil = Enum(2)
  val state = RegInit(notload)
  state := MuxLookup(state,notload)(List(
    notload -> Mux(out.bits.load, p1, notload),
    p1      -> Mux(out.bits.load, p1, notload)
    ))
  when(axibus.rready && axibus.rvalid && state =/= notload){
    out.bits.load := false.B
  }
  when(state === p1){
    axibus.arvalid := false.B
  }

  val stop :: run :: skip :: Nil = Enum(3)
  val sel = RegInit(stop)
  sel := MuxLookup(sel,stop)(List(
    stop -> run,
    run  -> Mux(out.bits.load, skip, stop),
    skip -> Mux(out.bits.load, skip, stop)
    ))
  axisel := Mux((sel === skip), 3.U, Mux((in.bits.idCtrl.fuType === fuType.lsu), 2.U, 0.U))

  out.bits.wbData.wdata := Mux(state =/= p1,in.bits.exuData.wdata,MuxLookup(in.bits.idCtrl.memType,in.bits.exuData.wdata)(Seq(
    MemOpType.lw -> axibus.rdata,
    MemOpType.lbu -> lbdata,
    MemOpType.lb  -> lbdata,
    MemOpType.lh  -> lhdata,
    MemOpType.lhu -> lhdata
  )))

  out.bits.cf <> in.bits.cf
  out.bits.idCtrl <> in.bits.idCtrl
  out.bits.wbData.dnpc := in.bits.exuData.dnpc
  out.bits.wbData.csr := in.bits.exuData.csr
  
  in.ready := out.ready
  out.valid := in.valid
}
