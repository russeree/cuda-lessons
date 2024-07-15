#ifndef CUDA_AXPY_CUH
#define CUDA_AXPY_CUH

#include <cuda_runtime.h>

// Declare the CUDA kernel
__global__ void axpy(float a, float *x, float *y);

// Declare the function that will be called from main.cpp
int cuda_test();

#endif // CUDA_AXPY_CUH
