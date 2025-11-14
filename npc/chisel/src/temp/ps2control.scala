import chisel3._
import chisel3.util._

class Ps2control extends Module{
  val io = IO(new Bundle{
    val ps2_clk = Input(Bool())
    val ps2_data = Input(UInt(1.W))
    val ps2_nextdata = Input(Bool())
    val data = Output(UInt(8.W))
    val ready = Output(Bool())
    val of = Output(Bool())
  })
  val buffer = RegInit(0.U(10.W))
  val fifo = Reg(Vec(8,UInt(8.W)))
  val w_ptr = RegInit(0.U(3.W))
  val r_ptr = RegInit(0.U(3.W))
  val count = RegInit(0.U(4.W))
  val ps2_clk_sync = RegInit(VecInit(Seq.fill(3)(false.B)))
  val reg_ready = RegInit(false.B)
  val reg_of = RegInit(false.B)
  ps2_clk_sync(0) := io.ps2_clk
  ps2_clk_sync(1) := ps2_clk_sync(0)
  ps2_clk_sync(2) := ps2_clk_sync(1)
  val sampling = Wire(Bool())
  sampling := ps2_clk_sync(2) && !ps2_clk_sync(1)
  when(reg_ready){
    when(!io.ps2_nextdata){
      r_ptr := r_ptr + 1.U
      when(w_ptr === (r_ptr + 1.U)){
        reg_ready := 0.U
      }
    }
  }
  when(sampling){
    when(count === 10.U){
      when(!buffer(0) && io.ps2_data.asBool && buffer(9,1).xorR){
        printf(p"recieve ${buffer(8,1)}\n")
        fifo(w_ptr) := buffer(8,1)
        w_ptr := w_ptr + 1.U
        reg_ready := true.B
        reg_of := reg_of || (w_ptr + 1.U === r_ptr)
        count := 0.U
      }
    }.otherwise{
      buffer := Cat(io.ps2_data,buffer(9,1)) 
      count := count + 1.U
    }
  }

  io.data := fifo(r_ptr)
  io.ready := reg_ready
  io.of := reg_of
}
class detectkey extends Module{
  val io = IO(new Bundle{
    val keyclk = Input(Bool())
    val keydata = Input(UInt(1.W))
    val seg0 = Output(UInt(8.W))
    val seg1 = Output(UInt(8.W))
    val seg2 = Output(UInt(8.W))
    val seg3 = Output(UInt(8.W))
    val seg4 = Output(UInt(8.W))
    val seg5 = Output(UInt(8.W))
  })
  val ps2 = Module(new Ps2control())
  ps2.io.ps2_clk := io.keyclk
  ps2.io.ps2_data := io.keydata
  val count = RegInit(0.U(8.W))

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
    "b00010001".U,  // A
    "b11000001".U,  // b
    "b01100011".U,  // C
    "b10000101".U,  // d
    "b01100001".U,  // E
    "b01110001".U   // F
    )
  

  val key = RegInit(0.U(8.W))
  val key_pressed = RegInit(false.B)
  val break_code_flag = RegInit(false.B)


  when(ps2.io.ready) {
    val scan_code = ps2.io.data
    when(scan_code === 0xF0.U) {
      break_code_flag := true.B
    }.elsewhen(break_code_flag) {
      key_pressed := false.B
      break_code_flag := false.B
      count := count + 1.U
    }.otherwise {
      key := scan_code
      key_pressed := true.B
      //break_code_flag := false.B
    }
  }

  val ready_reg = RegNext(ps2.io.ready, false.B)
  ps2.io.ps2_nextdata := ready_reg
  
  val ascii = RegInit(0.U(8.W))
  val Table = VecInit(Seq.fill(256)(0.U(8.W)))
  Table(0x1C) := 'a'.U
  ascii := Table(key)

  when(key_pressed) {
    io.seg0 := segs(key(3,0))
    io.seg1 := segs(key(7,4))
    io.seg2 := segs(ascii(3,0))
    io.seg3 := segs(ascii(7,4))
  }.otherwise {
    io.seg0 := "b11111111".U
    io.seg1 := "b11111111".U
    io.seg2 := "b11111111".U
    io.seg3 := "b11111111".U
  }

  io.seg4 := segs(count(3,0))
  io.seg5 := segs(count(7,4))
}
