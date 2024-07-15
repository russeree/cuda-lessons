#include "cu_hashmap_slavenode.h"

template <typename Key, typename Value>
SlaveNode<Key, Value>::SlaveNode(const Key &k, const Value &v)
    : key(k), value(std::make_unique<Value>(v)) {}

template <typename Key, typename Value>
const Key &SlaveNode<Key, Value>::getKey() const {
  return key;
}

template <typename Key, typename Value>
Value &SlaveNode<Key, Value>::getValue() {
  return *value;
}

template <typename Key, typename Value>
const Value &SlaveNode<Key, Value>::getValue() const {
  return *value;
}
