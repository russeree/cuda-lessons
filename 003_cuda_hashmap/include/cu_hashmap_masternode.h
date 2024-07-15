/**
 * @file cu_hashmap.h
 * @brief NVidia CUDA Parallel Hashmap Library
 * @author Portland.HODL
 * @date 2024-07-14
 *
 * @details
 * Master Node class for the parallel Nvidia cuda lookup process.
 *
 * @copyright Copyright (c) 2024 QR Snap LLC. All rights reserved.
 * This software is released under the MIT license.
 */

#include "cu_hashmap_slavenode.h"
#include <cstdint>

template <typename Key, typename Value> class MasterNode {
private:
  uint64_t hash;
  SlaveNode<Key, Value> *children;
  uint64_t nchildren;
  bool occupied;

public:
  // Empty Cuda Hashmap Creation
  MasterNode();
  // Single key cuda hashmap creation
  MasterNode(uint64_t hash, SlaveNode<Key, Value> *node);
  // Multi/Copy cuda hashmap entry creation
  MasterNode(uint64_t hash, SlaveNode<Key, Value> *node, uint64_t nchildren,
             bool occupied);
  // Copy Constructor
  MasterNode(const MasterNode &other);
  // Move constructor
  MasterNode(MasterNode &&other) noexcept;
  // Destructor
  ~MasterNode();
  // Assignment operator
  MasterNode &operator=(const MasterNode &other);
  // Move assignment operator
  MasterNode &operator=(MasterNode &&other) noexcept;
};
