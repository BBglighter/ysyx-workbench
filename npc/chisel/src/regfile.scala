package sCPU
import chisel3._

class regfile extends Module{
    val io = IO(new Bundle{
        val in = Input(UInt(8.W))
        val out1 = Output(UInt(8.W))
        val out2 = Output(UInt(8.W))
        val raddr1 = Input(UInt(2.W))
        val raddr2 = Input(UInt(2.W))
        val waddr = Input(UInt(2.W))
        val wen = Input(Bool())
    })

    val reg = RegInit(VecInit(Seq.fill(4)(0.U(8.W))))
    reg(io.waddr) := Mux(io.wen,io.in,reg(io.waddr))
    io.out1 := reg(io.raddr1)
    io.out2 := reg(io.raddr2)
}