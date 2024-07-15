cmake_minimum_required(VERSION 3.10)

# Specify Clang as both C++ and CUDA compiler
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CUDA_COMPILER clang++)

# The Cuda Hashmap Project - Parallel Hashmap Lookups and Insertions
project(cuda_hashmap LANGUAGES CXX CUDA)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set CUDA-specific flags
set(CUDA_FLAGS "--cuda-gpu-arch=sm_61 --cuda-path=/usr/local/cuda-12.5")

# Add the include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/murmur3)
include_directories(/usr/local/cuda-12.5/include)

# Add CUDA library directory
link_directories(/usr/local/cuda-12.5/lib64)

# Gather source files separately
file(GLOB_RECURSE CPP_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE CUDA_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cu")

# Our primary example code that utilizes the cuda_hashmap library
add_executable(main ${CPP_SOURCES} ${CUDA_SOURCES})

# Set compile flags for CUDA files only
foreach(CUDA_SOURCE ${CUDA_SOURCES})
  set_source_files_properties(${CUDA_SOURCE} PROPERTIES COMPILE_FLAGS "-x cuda ${CUDA_FLAGS}")
endforeach()

# Link against CUDA libraries
target_link_libraries(main cudart_static dl rt pthread)
