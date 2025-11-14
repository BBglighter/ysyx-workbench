package sCPU
import chisel3._

class PCrom extends Module{
    val io = IO(new Bundle{
        val out= Output(UInt(8.W))
        val addr=Input(UInt(4.W))
    })
    val rom = VecInit(
        "b10001010".U(8.W), 
        "b10010000".U(8.W),
        "b10100000".U(8.W),
        "b10110001".U(8.W),
        "b00010111".U(8.W), 
        "b00101001".U(8.W),
        "b11010001".U(8.W),
        "b01000010".U(8.W)
    )

    io.out := rom(io.addr)
}
