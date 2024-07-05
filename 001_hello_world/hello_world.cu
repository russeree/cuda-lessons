#include <stdio.h>

__global__ void print_kernel() {
    printf("Hello from block %d, thread %d\n", blockIdx.x, threadIdx.x);
}

int main() {
    	print_kernel<<<100, 100>>>();
	cudaError_t cudaerr = cudaDeviceSynchronize();

}

