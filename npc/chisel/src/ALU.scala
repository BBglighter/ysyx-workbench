import chisel3._
import chisel3.util._ 

class ALU(w : Int) extends Module{
    val io = IO(new Bundle{
        val a = Input(UInt(w.W))
        val b = Input(UInt(w.W))
        val cin = Input(UInt(1.W))
        val ctrl = Input(UInt(3.W))
        val cout = Output(UInt(1.W))
        val of = Output(Bool())
        val zero = Output(Bool())
        val result = Output(UInt(w.W))
    })

    io.result := 0.U

    val add = io.a +& io.b + io.cin
    val add_w = add(w-1,0)
    val add_c = add(w)

    val sub = io.a +& (~io.b) + (~io.cin)
    val sub_w = sub(w-1,0)
    val sub_c = sub(w)

    val not = ~io.a
    val and = io.a & io.b
    val or  = io.a | io.b
    val xor = io.a ^ io.b
    val max = Mux(io.a > io.b, 1.U(w.W), 0.U(w.W))
    val eq  = Mux(io.a === io.b, 1.U(w.W), 0.U(w.W))

    val outs = Seq(add_w,sub_w,not,and,or,xor,max,eq)
    val oh = UIntToOH(io.ctrl,8)
    io.result := Mux1H(oh.asBools, outs)

    when(io.ctrl === 0.U){
        io.zero := io.result === 0.U
        io.of := (io.a(w-1)===io.b(w-1)) && (io.a(w-1) =/= io.result(w-1))
        io.cout := add_c
    }.elsewhen(io.ctrl === 1.U){
        io.zero := io.result === 0.U
        io.of := (io.a(w-1)=/=io.b(w-1)) && (io.a(w-1) =/= io.result(w-1))
        io.cout := sub_c
    }.otherwise{
        io.zero := false.B
        io.of := false.B
        io.cout := 0.U
    }
}