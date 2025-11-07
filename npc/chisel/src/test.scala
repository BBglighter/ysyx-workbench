package sCPU

import chisel3._

class Decoder extends Module{
    val io = IO(new Bundle{
        val inst = Input(UInt(8.W))
        val liOp = Output(Bool())
        val addOp = Output(Bool())
        val bner0 = Output(Bool())
        val out_rs= Output(Bool())
    })
    val opcode = io.inst(7,6)
    io.liOp   := (opcode === "b10".U)
    io.addOp  := (opcode === "b00".U)
    io.bner0  := (opcode === "b11".U)
    io.out_rs := (opcode === "b01".U)
}

class display extends Module{
  val io = IO(new Bundle{
    val rs = Input(UInt(8.W))
    val seg1 = Output(UInt(8.W))
    val seg2 = Output(UInt(8.W))
    val seg3 = Output(UInt(8.W))
  })
  val numh = io.rs/100.U
  val numt = (io.rs - numh*100.U)/10.U
  val num  = io.rs%10.U
  
  val play = VecInit(
    "b00000010".U,
    "b10011111".U,
    "b00100101".U,
    "b00001101".U,
    "b10011001".U,
    "b01001001".U,
    "b01000001".U,
    "b00011111".U,
    )

  io.seg1 := play(numh)
  io.seg2 := play(numt)
  io.seg3 := play(num)
}


class test extends Module{
   val io = IO(new Bundle{
        val seg0 = Output(UInt(8.W))
        val seg1 = Output(UInt(8.W))
        val seg2 = Output(UInt(8.W))
    })
  
    
    io.seg0 := 0.U
    io.seg1 := 0.U
    io.seg2 := 0.U

    val play = Module(new sCPU.display())
    val pc = Module(new sCPU.PC())
    val decoder = Module(new Decoder())
    val rom = Module(new sCPU.PCrom())
    val gpr = Module(new sCPU.regfile())

    play.io.rs := 0.U

    rom.io.addr := pc.io.pcaddr
    decoder.io.inst := rom.io.out
    
    gpr.io.wen    := false.B
    gpr.io.waddr  := 0.U(gpr.io.waddr.getWidth.W)
    gpr.io.raddr1 := 0.U(gpr.io.raddr1.getWidth.W)
    gpr.io.raddr2 := 0.U(gpr.io.raddr2.getWidth.W)
    gpr.io.in     := 0.U(gpr.io.in.getWidth.W)
    
    pc.io.jmp  := false.B
    pc.io.addr := 0.U(pc.io.addr.getWidth.W)

    when(decoder.io.liOp){
        gpr.io.wen := true.B
        gpr.io.waddr := rom.io.out(5,4)
        gpr.io.in := rom.io.out(3,0)
    }.elsewhen(decoder.io.addOp){
        gpr.io.raddr1 := rom.io.out(1,0)
        gpr.io.raddr2 := rom.io.out(3,2)
        gpr.io.waddr  := rom.io.out(5,4)
        gpr.io.in := gpr.io.out1 + gpr.io.out2
        gpr.io.wen := true.B
    }.elsewhen(decoder.io.bner0){
        gpr.io.raddr1 := 0.U
        gpr.io.raddr2 := rom.io.out(1,0)
        pc.io.jmp := Mux(gpr.io.out1 =/= gpr.io.out2,true.B,false.B)
        pc.io.addr := rom.io.out(5,2)
    }.otherwise{
        gpr.io.raddr1 := rom.io.out(1,0)
        play.io.rs := gpr.io.out1
        pc.io.jmp := true.B
        pc.io.addr := pc.io.pcaddr
        io.seg2 := play.io.seg1
        io.seg1 := play.io.seg2
        io.seg0 := play.io.seg3
    }
}
