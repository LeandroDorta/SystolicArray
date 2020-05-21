// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xsysarray.h"

extern XSysarray_Config XSysarray_ConfigTable[];

XSysarray_Config *XSysarray_LookupConfig(u16 DeviceId) {
	XSysarray_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XSYSARRAY_NUM_INSTANCES; Index++) {
		if (XSysarray_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XSysarray_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSysarray_Initialize(XSysarray *InstancePtr, u16 DeviceId) {
	XSysarray_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSysarray_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSysarray_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

