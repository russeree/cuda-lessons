// master_node.tpp
#include <cstdint>
#include <cu_hashmap_masternode.h>
#include <cu_hashmap_slavenode.h>

template <typename Key, typename Value>
MasterNode<Key, Value>::MasterNode()
    : hash(0), children(nullptr), nchildren(0), occupied(false) {}

template <typename Key, typename Value>
MasterNode<Key, Value>::MasterNode(uint64_t hash, SlaveNode<Key, Value> *node)
    : hash(hash), children(node), nchildren(1), occupied(true) {}

template <typename Key, typename Value>
MasterNode<Key, Value>::MasterNode(uint64_t hash, SlaveNode<Key, Value> *node,
                                   uint64_t nchildren, bool occupied)
    : hash(hash), children(node), nchildren(nchildren), occupied(occupied) {}

template <typename Key, typename Value>
MasterNode<Key, Value>::MasterNode(const MasterNode &other)
    : hash(other.hash), nchildren(other.nchildren), occupied(other.occupied) {
  if (other.children) {
    children = new SlaveNode<Key, Value>[nchildren];
    for (uint64_t i = 0; i < nchildren; ++i) {
      children[i] = other.children[i];
    }
  } else {
    children = nullptr;
  }
}

template <typename Key, typename Value>
MasterNode<Key, Value>::MasterNode(MasterNode &&other) noexcept
    : hash(other.hash), children(other.children), nchildren(other.nchildren),
      occupied(other.occupied) {
  other.children = nullptr;
  other.nchildren = 0;
}

template <typename Key, typename Value> MasterNode<Key, Value>::~MasterNode() {
  delete[] children;
}

template <typename Key, typename Value>
MasterNode<Key, Value> &
MasterNode<Key, Value>::operator=(const MasterNode &other) {
  if (this != &other) {
    hash = other.hash;
    nchildren = other.nchildren;
    occupied = other.occupied;
    delete[] children;
    if (other.children) {
      children = new SlaveNode<Key, Value>[nchildren];
      for (uint64_t i = 0; i < nchildren; ++i) {
        children[i] = other.children[i];
      }
    } else {
      children = nullptr;
    }
  }
  return *this;
}

template <typename Key, typename Value>
MasterNode<Key, Value> &
MasterNode<Key, Value>::operator=(MasterNode &&other) noexcept {
  if (this != &other) {
    hash = other.hash;
    delete[] children;
    children = other.children;
    nchildren = other.nchildren;
    occupied = other.occupied;
    other.children = nullptr;
    other.nchildren = 0;
  }
  return *this;
}
