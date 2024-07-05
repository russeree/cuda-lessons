# CUDA Hello World Example - 001

## Introduction

This project demonstrates a basic CUDA application that prints "Hello" messages from multiple GPU threads. It serves as an introductory example for those learning CUDA programming and parallel computing on NVIDIA GPUs.

## Prerequisites

- NVIDIA GPU with CUDA support
- CUDA Toolkit (version 8.0 or later recommended)
- A C++ compiler compatible with your CUDA version

## Files

- `hello_world.cu`: The main CUDA source file containing the kernel and host code.

## Compilation

To compile the program, use the NVIDIA CUDA Compiler (nvcc):

```
nvcc hello_world.cu -o hello_world
```


## Execution

After successful compilation, run the program:

```
./hello_world
```

## Expected Output

The program will output 10,000 lines in the following format:

```
Hello from block X, thread Y
```

Where X ranges from 0 to 99 (representing the block index) and Y ranges from 0 to 99 (representing the thread index within each block).

## Code Explanation

- The program defines a CUDA kernel function `print_kernel()` that prints a hello message.
- In the `main()` function, this kernel is launched with a grid of 100 blocks, each containing 100 threads.
- `cudaDeviceSynchronize()` is called to ensure all GPU operations are complete before the program exits.

## Key Concepts

- CUDA Kernel: A function that runs on the GPU, defined with the `__global__` keyword.
- Thread Hierarchy: CUDA organizes threads into blocks, and blocks into a grid.
- Kernel Launch: The `<<<>>>` syntax is used to specify the number of blocks and threads per block.

## Notes

- The actual order of the output lines may vary due to the parallel nature of GPU execution.
- This example demonstrates basic CUDA concepts and should not be considered a performance-oriented application.

## Further Learning

- Experiment with different grid and block sizes to see how it affects the output.
- Try adding more complex computations within the kernel.
- Explore CUDA's memory hierarchy and data transfer between CPU and GPU.

## Troubleshooting

If you encounter any issues:
1. Ensure your CUDA toolkit is properly installed.
2. Check that your GPU supports the CUDA version you're using.
3. Verify that your GPU drivers are up to date.

## License

This code is provided under the MIT License. Feel free to use and modify it for educational purposes.

