import chisel3._
import chisel3.util._

class encoder extends Module{
  val io = IO(new Bundle{
    val sw = Input(UInt(8.W))
    val seg0 = Output(UInt(8.W))
  })
  val encode = 7.U - PriorityEncoder(Reverse(io.sw))

  val segs = VecInit(
    "b00000011".U,  // 0
    "b10011111".U,  // 1
    "b00100101".U,  // 2
    "b00001101".U,  // 3
    "b10011001".U,  // 4
    "b01001001".U,  // 5
    "b01000001".U,  // 6
    "b00011111".U,  // 7
    "b00000001".U,  // 8
    "b00001001".U,  // 9
    )
  
  io.seg0 := segs(encode)

}

