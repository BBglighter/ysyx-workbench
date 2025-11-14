package sCPU
import chisel3._

class PC extends Module {
    val io = IO(new Bundle{
        val jmp = Input(Bool())
        val addr = Input(UInt(4.W))
        val pcaddr = Output(UInt(4.W))
    })

    val reg = RegInit(0.U(4.W))
    val nextPC = Wire(UInt(4.W))
    nextPC := Mux(io.jmp,io.addr,io.pcaddr+1.U)
    reg := nextPC
    io.pcaddr := reg
}