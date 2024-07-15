/**
 * @file cu_hashmap.h
 * @brief NVidia CUDA Parallel Hashmap Library
 * @author Portland.HODL
 * @date 2024-07-14
 *
 * @details
 * A Basic murur3 linked list hashmap library accelerated with LLVM Clang CUDA
 *
 * @copyright Copyright (c) 2024 QR Snap LLC. All rights reserved.
 * This software is released under the MIT license.
 */
#include <cstddef>
#include <cu_hashmap_masternode.h>
#include <memory>

template <typename Key, typename Value> class cu_unordered_map {
private:
  static const size_t DEFAULT_BUCKETS = 16;
  size_t num_buckets;
  size_t size;
};
