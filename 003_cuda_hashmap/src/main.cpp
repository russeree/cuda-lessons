/**
 * @auth: Portland.HODL
 * @desc: Cuda Accelerated Hashmaps in C++
 */

#include "axpy.cuh"
#include <iostream>

int main() {
  std::cout << "Starting CUDA test...\n";
  int result = cuda_test();
  std::cout << "CUDA test completed with result: " << result << "\n";
  return 0;
}
