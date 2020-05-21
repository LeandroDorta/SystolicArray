// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XSYSARRAY_H
#define XSYSARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xsysarray_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XSysarray_Config;
#endif

typedef struct {
    u32 Control_BaseAddress;
    u32 IsReady;
} XSysarray;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XSysarray_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XSysarray_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XSysarray_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XSysarray_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XSysarray_Initialize(XSysarray *InstancePtr, u16 DeviceId);
XSysarray_Config* XSysarray_LookupConfig(u16 DeviceId);
int XSysarray_CfgInitialize(XSysarray *InstancePtr, XSysarray_Config *ConfigPtr);
#else
int XSysarray_Initialize(XSysarray *InstancePtr, const char* InstanceName);
int XSysarray_Release(XSysarray *InstancePtr);
#endif

void XSysarray_Start(XSysarray *InstancePtr);
u32 XSysarray_IsDone(XSysarray *InstancePtr);
u32 XSysarray_IsIdle(XSysarray *InstancePtr);
u32 XSysarray_IsReady(XSysarray *InstancePtr);
void XSysarray_EnableAutoRestart(XSysarray *InstancePtr);
void XSysarray_DisableAutoRestart(XSysarray *InstancePtr);

void XSysarray_Set_scalar00(XSysarray *InstancePtr, u32 Data);
u32 XSysarray_Get_scalar00(XSysarray *InstancePtr);
void XSysarray_Set_scalar01(XSysarray *InstancePtr, u32 Data);
u32 XSysarray_Get_scalar01(XSysarray *InstancePtr);
void XSysarray_Set_input_matrix(XSysarray *InstancePtr, u64 Data);
u64 XSysarray_Get_input_matrix(XSysarray *InstancePtr);
void XSysarray_Set_weight_matrix(XSysarray *InstancePtr, u64 Data);
u64 XSysarray_Get_weight_matrix(XSysarray *InstancePtr);
void XSysarray_Set_output_matrix(XSysarray *InstancePtr, u64 Data);
u64 XSysarray_Get_output_matrix(XSysarray *InstancePtr);

void XSysarray_InterruptGlobalEnable(XSysarray *InstancePtr);
void XSysarray_InterruptGlobalDisable(XSysarray *InstancePtr);
void XSysarray_InterruptEnable(XSysarray *InstancePtr, u32 Mask);
void XSysarray_InterruptDisable(XSysarray *InstancePtr, u32 Mask);
void XSysarray_InterruptClear(XSysarray *InstancePtr, u32 Mask);
u32 XSysarray_InterruptGetEnabled(XSysarray *InstancePtr);
u32 XSysarray_InterruptGetStatus(XSysarray *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
