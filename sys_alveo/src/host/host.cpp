// This is a generated file. Use and modify at your own risk.
////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
Vendor: Xilinx
Associated Filename: main.c
#Purpose: This example shows a basic vector add +1 (constant) by manipulating
#         memory inplace.
*******************************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <CL/opencl.h>
#include <CL/cl_ext.h>
#include "xclhal2.h"
//#include <iostream>
////////////////////////////////////////////////////////////////////////////////

#define NUM_WORKGROUPS (1)
#define WORKGROUP_SIZE (256)
#define MAX_LENGTH 8192

#if defined(SDX_PLATFORM) && !defined(TARGET_DEVICE)
#define STR_VALUE(arg)      #arg
#define GET_STRING(name) STR_VALUE(name)
#define TARGET_DEVICE GET_STRING(SDX_PLATFORM)
#endif

////////////////////////////////////////////////////////////////////////////////

//------------------alloc aligned memory---------------------
void *allocate_aligned(size_t size, size_t alignment)
{
   const size_t mask = alignment - 1;
   const uintptr_t mem = (uintptr_t) calloc(size + alignment, 1);
    return (void *) ((mem + mask) & ~mask);
}

int load_file_to_memory(const char *filename, char **result)
{
    uint size = 0;
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        *result = NULL;
        return -1; // -1 means file opening fail
    }
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);
    *result = (char *)malloc(size+1);
    if (size != fread(*result, sizeof(char), size, f)) {
        free(*result);
        return -2; // -2 means file reading fail
    }
    fclose(f);
    (*result)[size] = 0;
    return size;
}

int main(int argc, char* argv[])
{

    cl_int err;                            // error code returned from api calls
    int check_status = 0;
    const uint number_of_words = 4096; // 16KB of data


    cl_platform_id platform_id;         // platform id
    cl_device_id device_id;             // compute device id
    cl_context context;                 // compute context
    cl_command_queue commands;          // compute command queue
    cl_program program;                 // compute programs
    cl_kernel kernel;                   // compute kernel

    int h_input[MAX_LENGTH];                    // host memory for input vector
    int h_weight[MAX_LENGTH];
    int h_output[MAX_LENGTH];
    int h_data[MAX_LENGTH];
    char cl_platform_vendor[1001];
    const char* target_device_name =  argv[2];
    int h_input_matrix[MAX_LENGTH];                   // host memory for output vector
    cl_mem d_input_matrix;                         // device memory used for a vector

    int h_weight_matrix[MAX_LENGTH];                   // host memory for output vector
    cl_mem d_weight_matrix;                         // device memory used for a vector
    
    int h_output_matrix[MAX_LENGTH];
    cl_mem d_output_matrix;
    
    if (argc != 3) {
        printf("Usage: %s xclbin\n", argv[0]);
        return EXIT_FAILURE;
    }


    // Fill our data sets with pattern
    int i = 0;
    for(i = 0; i < MAX_LENGTH; i++) {
        h_data[i]  = 0;
        h_input[i] = 0;
        h_weight[i] = 0;
        h_output[i] = 0; 
        h_input_matrix[i] = 0;
        h_weight_matrix[i] = 0;
       // h_output_matrix[i] = 0;
    }

    h_input[0] = 1;
    h_input[1] = 2;
    h_input[2] = 3;
    h_input[3] = 4;
    h_input[4] = 5;
    h_input[5] = 6;
    h_input[6] = 7;
    h_input[7] = 8;
    h_input[8] = 9;
    h_input[9] = 10;
    h_input[10] = 11;
    h_input[11] = 12;
    h_input[12] = 13;
    h_input[13] = 14;
    h_input[14] = 15;
    h_input[15] = 16;
    
    h_weight[0] = 1;
    h_weight[1] = 1;
    h_weight[2] = 1;
    h_weight[3] = 1;
    h_weight[4] = 1;
    h_weight[5] = 1;
    h_weight[6] = 1;
    h_weight[7] = 1;
    h_weight[8] = 1;
    h_weight[9] = 1;
    h_weight[10] = 1;
    h_weight[11] = 1;
    h_weight[12] = 1;
    h_weight[13] = 1;
    h_weight[14] = 1;
    h_weight[15] = 1;
    
    h_data[0] = 10;
    h_data[1] = 10;
    h_data[2] = 10;
    h_data[3] = 10;
    h_data[4] = 26;
    h_data[5] = 26;
    h_data[6] = 26;
    h_data[7] = 26;
    h_data[8] = 42;
    h_data[9] = 42;
    h_data[10] = 42;
    h_data[11] = 42;
    h_data[12] = 58;
    h_data[13] = 58;
    h_data[14] = 58;
    h_data[15] = 58;
    
    for(int row=0; row < 4; row++){
      for(int col=0; col < 4; col++){
        h_input_matrix[4 * (row + col) + col] = h_input[4 * row + col];
      }
    }

   // Get all platforms and then select Xilinx platform
    cl_platform_id platforms[16];       // platform id
    cl_uint platform_count;
    int platform_found = 0;
    err = clGetPlatformIDs(16, platforms, &platform_count);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to find an OpenCL platform!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }
    printf("INFO: Found %d platforms\n", platform_count);

    // Find Xilinx Plaftorm
    for (unsigned int iplat=0; iplat<platform_count; iplat++) {
        err = clGetPlatformInfo(platforms[iplat], CL_PLATFORM_VENDOR, 1000, (void *)cl_platform_vendor,NULL);
        if (err != CL_SUCCESS) {
	    printf(  "%s", platforms[iplat]);	
            printf("Error: clGetPlatformInfo(CL_PLATFORM_VENDOR) failed!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }
        if (strcmp(cl_platform_vendor, "Xilinx") == 0) {
            printf("INFO: Selected platform %d from %s\n", iplat, cl_platform_vendor);
            platform_id = platforms[iplat];
            platform_found = 1;
        }
    }
    if (!platform_found) {
        printf("ERROR: Platform Xilinx not found. Exit.\n");
        return EXIT_FAILURE;
    }

   // Get Accelerator compute device
    cl_uint num_devices;
    unsigned int device_found = 0;
    cl_device_id devices[16];  // compute device id
    char cl_device_name[1001];
    err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ACCELERATOR, 16, devices, &num_devices);
    printf("INFO: Found %d devices\n", num_devices);
    if (err != CL_SUCCESS) {
        printf("ERROR: Failed to create a device group!\n");
        printf("ERROR: Test failed\n");
        return -1;
    }

    //iterate all devices to select the target device.
    for (uint i=0; i<num_devices; i++) {
       err = clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 1024, cl_device_name, 0);
       if (err != CL_SUCCESS) {
            printf("Error: Failed to get device name for device %d!\n", i);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

       printf("CL_DEVICE_NAME %s\n", cl_device_name);
       if(strstr(target_device_name, cl_device_name) != NULL) {
            device_id = devices[i];
            device_found = 1;
            printf("Selected %s as the target device\n", cl_device_name);
       
       }
    }
   if (!device_found) {
        printf("Target device %s not found. Exit.\n", target_device_name);
        return EXIT_FAILURE;
    }

    // Create a compute context
    //
   context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if (!context) {
        printf("Error: Failed to create a compute context!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Create a command commands
    commands = clCreateCommandQueue(context, device_id, 0, &err);
    if (!commands) {
        printf("Error: Failed to create a command commands!\n");
        printf("Error: code %i\n",err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

   int status;

    // Create Program Objects
    // Load binary from disk
    unsigned char *kernelbinary;
    char *xclbin = argv[1];

    //------------------------------------------------------------------------------
    // xclbin
    //------------------------------------------------------------------------------
    printf("INFO: loading xclbin %s\n", xclbin);
    int n_i0 = load_file_to_memory(xclbin, (char **) &kernelbinary);
    if (n_i0 < 0) {
        printf("failed to load kernel from xclbin: %s\n", xclbin);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    size_t n0 = n_i0;

   // Create the compute program from offline
    program = clCreateProgramWithBinary(context, 1, &device_id, &n0,
                                        (const unsigned char **) &kernelbinary, &status, &err);

    if ((!program) || (err!=CL_SUCCESS)) {
        printf("Error: Failed to create compute program from binary %d!\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    printf("INFO: Context created\n");

    // Build the program executable
    //
   err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
        size_t len;
        char buffer[2048];

        printf("Error: Failed to build program executable!\n");
        clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    printf("INFO: Program built\n");

    // Create the compute kernel in the program we wish to run
    //
     kernel = clCreateKernel(program, "SysArray", &err);
    if (!kernel || err != CL_SUCCESS) {
        printf("Error: Failed to create compute kernel!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Create structs to define memory bank mapping
    cl_mem_ext_ptr_t mem_ext;
    mem_ext.obj = NULL;
    mem_ext.param = kernel;


     mem_ext.flags = 2;
    d_input_matrix = clCreateBuffer(context,  CL_MEM_READ_WRITE | CL_MEM_EXT_PTR_XILINX,  sizeof(int) * number_of_words, &mem_ext, NULL);

     mem_ext.flags = 3;
    d_weight_matrix = clCreateBuffer(context,  CL_MEM_READ_WRITE | CL_MEM_EXT_PTR_XILINX,  sizeof(int) * number_of_words, &mem_ext, NULL);
    
     mem_ext.flags = 4;
    d_output_matrix = clCreateBuffer(context,  CL_MEM_READ_WRITE | CL_MEM_EXT_PTR_XILINX,  sizeof(int) * number_of_words, &mem_ext, NULL);

    if (!(d_input_matrix&&d_weight_matrix&&d_output_matrix)) {
        printf("Error: Failed to allocate device memory!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    printf("INFO: Buffers created\n");    

    err = clEnqueueWriteBuffer(commands, d_input_matrix, CL_TRUE, 0, sizeof(int) * number_of_words, h_input_matrix, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to write to source array h_data!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    printf("INFO: Input matrix written\n");    

    err = clEnqueueWriteBuffer(commands, d_weight_matrix, CL_TRUE, 0, sizeof(int) * number_of_words, h_weight_matrix, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to write to source array h_data!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    printf("INFO: Weight matrix written\n");
    
    // Set the arguments to our compute kernel
    // int vector_length = MAX_LENGTH;
    err = 0;
    cl_uint d_scalar00 = 0;
    cl_uint d_scalar01 = 0;
    err |= clSetKernelArg(kernel, 0, sizeof(cl_uint), &d_scalar00); // Not used in example RTL logic.
    err |= clSetKernelArg(kernel, 1, sizeof(cl_uint), &d_scalar01);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &d_input_matrix); 
    err |= clSetKernelArg(kernel, 3, sizeof(cl_mem), &d_weight_matrix);
    err |= clSetKernelArg(kernel, 4, sizeof(cl_mem), &d_output_matrix); 

    if (err != CL_SUCCESS) {
        printf("Error: Failed to set kernel arguments! %d\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    printf("INFO: Kernel arguments set\n");

    // Execute the kernel over the entire range of our 1d input data set
    // using the maximum number of work group items for this device

    err = clEnqueueTask(commands, kernel, 0, NULL, NULL);
    if (err) {
            printf("Error: Failed to execute kernel! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    printf("INFO: Task enqueued\n");

    // Read back the results from the device to verify the output
    //
    cl_event readevent;
    clFinish(commands);

    printf("Finish event\n");

    err = 0;
    err |= clEnqueueReadBuffer( commands, d_output_matrix, CL_TRUE, 0, sizeof(int) * number_of_words, h_output_matrix, 0, NULL, &readevent );

    for (int i=0; i < number_of_words; i++){
      printf("h_output_matrix[%d] = %d\n", i, h_output_matrix[i] );
    }
      
    if (err != CL_SUCCESS) {
            printf("Error: Failed to read output array! %d\n", err);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    printf("INFO: Buffer read (output_matrix)\n");
 
    clWaitForEvents(1, &readevent);
    // Check Results

    for (int row = 0; row < 4; row++) {
      for (int col = 0; col < 4; col++) {
        if ((h_data[4 * row + col]) != h_output_matrix[4 * (row + col) + col]) {
            printf("ERROR in SysArray - row: %d col: %d -input=%d, output=%d \n", row, col, h_data[4 * row + col], h_output_matrix[4 * (row + col) + col]);
            check_status = 1;
        }
      //  printf("i=%d, input=%d, output=%d\n", i,  h_B_input[i], h_B_output[i]);
      }
    }
 

    //--------------------------------------------------------------------------
    // Shutdown and cleanup
    //-------------------------------------------------------------------------- 
    clReleaseMemObject(d_input_matrix);

    clReleaseMemObject(d_weight_matrix);
    
    clReleaseMemObject(d_output_matrix);


    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(commands);
    clReleaseContext(context);

    if (check_status) {
        printf("INFO: Test failed\n");
        return EXIT_FAILURE;
    } else {
        printf("INFO: Test completed successfully.\n");
        return EXIT_SUCCESS;
    }


} // end of main
