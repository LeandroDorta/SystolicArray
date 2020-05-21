// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xsysarray.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XSysarray_CfgInitialize(XSysarray *InstancePtr, XSysarray_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XSysarray_Start(XSysarray *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_AP_CTRL) & 0x80;
    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XSysarray_IsDone(XSysarray *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XSysarray_IsIdle(XSysarray *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XSysarray_IsReady(XSysarray *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XSysarray_EnableAutoRestart(XSysarray *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XSysarray_DisableAutoRestart(XSysarray *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_AP_CTRL, 0);
}

void XSysarray_Set_scalar00(XSysarray *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_SCALAR00_DATA, Data);
}

u32 XSysarray_Get_scalar00(XSysarray *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_SCALAR00_DATA);
    return Data;
}

void XSysarray_Set_scalar01(XSysarray *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_SCALAR01_DATA, Data);
}

u32 XSysarray_Get_scalar01(XSysarray *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_SCALAR01_DATA);
    return Data;
}

void XSysarray_Set_input_matrix(XSysarray *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_INPUT_MATRIX_DATA, (u32)(Data));
    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_INPUT_MATRIX_DATA + 4, (u32)(Data >> 32));
}

u64 XSysarray_Get_input_matrix(XSysarray *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_INPUT_MATRIX_DATA);
    Data += (u64)XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_INPUT_MATRIX_DATA + 4) << 32;
    return Data;
}

void XSysarray_Set_weight_matrix(XSysarray *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_WEIGHT_MATRIX_DATA, (u32)(Data));
    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_WEIGHT_MATRIX_DATA + 4, (u32)(Data >> 32));
}

u64 XSysarray_Get_weight_matrix(XSysarray *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_WEIGHT_MATRIX_DATA);
    Data += (u64)XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_WEIGHT_MATRIX_DATA + 4) << 32;
    return Data;
}

void XSysarray_Set_output_matrix(XSysarray *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_OUTPUT_MATRIX_DATA, (u32)(Data));
    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_OUTPUT_MATRIX_DATA + 4, (u32)(Data >> 32));
}

u64 XSysarray_Get_output_matrix(XSysarray *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_OUTPUT_MATRIX_DATA);
    Data += (u64)XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_OUTPUT_MATRIX_DATA + 4) << 32;
    return Data;
}

void XSysarray_InterruptGlobalEnable(XSysarray *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_GIE, 1);
}

void XSysarray_InterruptGlobalDisable(XSysarray *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_GIE, 0);
}

void XSysarray_InterruptEnable(XSysarray *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_IER);
    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_IER, Register | Mask);
}

void XSysarray_InterruptDisable(XSysarray *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_IER);
    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_IER, Register & (~Mask));
}

void XSysarray_InterruptClear(XSysarray *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSysarray_WriteReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_ISR, Mask);
}

u32 XSysarray_InterruptGetEnabled(XSysarray *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_IER);
}

u32 XSysarray_InterruptGetStatus(XSysarray *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSysarray_ReadReg(InstancePtr->Control_BaseAddress, XSYSARRAY_CONTROL_ADDR_ISR);
}

