import chisel3._
import chisel3.util._

class shifter extends Module {
    val io = IO(new Bundle{
    	val en = Input(Bool())
        val ctrl = Input(UInt(3.W))
        val bit_in = Input(UInt(1.W))
        val shift = Input(UInt(3.W))
        val reg_in = Input(UInt(8.W))
        val out = Output(UInt(8.W))
    })

    val reg = RegInit(1.U(8.W))
    val temp = Wire(UInt(8.W))
    temp := reg

    val empty = 0.U(8.W)
    val reg_n = io.reg_in
    val logicr = (temp >> io.shift)
    val logicl = (temp << io.shift)(7, 0)
    val mathr  = (temp.asSInt >> io.shift).asUInt
    val move   = Cat(io.bit_in, temp(7, 1)) 
    val roundr = (temp >> io.shift) | ((temp << (8.U - io.shift))(7, 0))
    val roundl = ((temp << io.shift)(7, 0)) | (temp >> (8.U - io.shift))
    
    val outs = Seq(empty,reg_n,logicl,logicr,mathr,move,roundl,roundr)
    val oh = UIntToOH(io.ctrl,8)
    val out = Mux1H(oh.asBools, outs)
    when(io.en){
    	reg := out
    	}
    io.out := reg
}

class shifter_test extends Module{
  val io = IO(new Bundle{
    val seg0 = Output(UInt(8.W))
    val seg1 = Output(UInt(8.W))
    val seg2 = Output(UInt(8.W))
    val seg3 = Output(UInt(8.W))
    val seg4 = Output(UInt(8.W))
    val seg5 = Output(UInt(8.W))
    val seg6 = Output(UInt(8.W))
    val seg7 = Output(UInt(8.W))
  })

  val shift = Module(new shifter())
  shift.io.ctrl := 5.U
  shift.io.shift := 1.U
  shift.io.reg_in := 1.U

  val out = RegInit(1.U(8.W))
 
  val (count,wrap) = Counter(true.B,10000000)
  shift.io.en := wrap
  out := shift.io.out
  
  shift.io.bit_in := out(4)^out(3)^out(2)^out(0)

  val segs = VecInit(
    "b00000011".U,  // 0
    "b10011111".U,  // 1
    )
  io.seg0 := segs(out(0))
  io.seg1 := segs(out(1))
  io.seg2 := segs(out(2))
  io.seg3 := segs(out(3))
  io.seg4 := segs(out(4))
  io.seg5 := segs(out(5))
  io.seg6 := segs(out(6))
  io.seg7 := segs(out(7))
}
