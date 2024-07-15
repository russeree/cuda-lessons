
#ifndef SLAVE_NODE_H
#define SLAVE_NODE_H

#include <memory>

template <typename Key, typename Value> class SlaveNode {
public:
  SlaveNode(const Key &k, const Value &v);

  const Key &getKey() const;
  Value &getValue();
  const Value &getValue() const;

private:
  Key key;
  std::unique_ptr<Value> value;
};

#endif // SLAVE_NODE_H
