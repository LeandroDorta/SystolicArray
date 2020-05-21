// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of scalar00
//        bit 31~0 - scalar00[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of scalar01
//        bit 31~0 - scalar01[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of input_matrix
//        bit 31~0 - input_matrix[31:0] (Read/Write)
// 0x24 : Data signal of input_matrix
//        bit 31~0 - input_matrix[63:32] (Read/Write)
// 0x28 : reserved
// 0x2c : Data signal of weight_matrix
//        bit 31~0 - weight_matrix[31:0] (Read/Write)
// 0x30 : Data signal of weight_matrix
//        bit 31~0 - weight_matrix[63:32] (Read/Write)
// 0x34 : reserved
// 0x38 : Data signal of output_matrix
//        bit 31~0 - output_matrix[31:0] (Read/Write)
// 0x3c : Data signal of output_matrix
//        bit 31~0 - output_matrix[63:32] (Read/Write)
// 0x40 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XSYSARRAY_CONTROL_ADDR_AP_CTRL            0x00
#define XSYSARRAY_CONTROL_ADDR_GIE                0x04
#define XSYSARRAY_CONTROL_ADDR_IER                0x08
#define XSYSARRAY_CONTROL_ADDR_ISR                0x0c
#define XSYSARRAY_CONTROL_ADDR_SCALAR00_DATA      0x10
#define XSYSARRAY_CONTROL_BITS_SCALAR00_DATA      32
#define XSYSARRAY_CONTROL_ADDR_SCALAR01_DATA      0x18
#define XSYSARRAY_CONTROL_BITS_SCALAR01_DATA      32
#define XSYSARRAY_CONTROL_ADDR_INPUT_MATRIX_DATA  0x20
#define XSYSARRAY_CONTROL_BITS_INPUT_MATRIX_DATA  64
#define XSYSARRAY_CONTROL_ADDR_WEIGHT_MATRIX_DATA 0x2c
#define XSYSARRAY_CONTROL_BITS_WEIGHT_MATRIX_DATA 64
#define XSYSARRAY_CONTROL_ADDR_OUTPUT_MATRIX_DATA 0x38
#define XSYSARRAY_CONTROL_BITS_OUTPUT_MATRIX_DATA 64

