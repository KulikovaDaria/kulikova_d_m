#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iosfwd>

class PriorityQueue {
public:
  PriorityQueue() = default;
  PriorityQueue(const PriorityQueue& obj);
  PriorityQueue& operator=(const PriorityQueue& obj);
  ~PriorityQueue();
  void Push(const int key, const int val);
  void Pop() noexcept;
  int Top() const;
  bool IsEmpty() const noexcept;
  std::ostream& WriteTo(std::ostream& ostrm) const;

private:
  struct Node {
    Node() = default;
    Node(const int k, const int v)
      :data(k, v) {
    }
    Node(const int k, const int v, Node*& next)
      :data(k, v), next(next) {
    }
    struct Pair {
      Pair(const int k, const int v)
        :key(k), val(v) {
      }
      Pair& operator=(const Pair& obj) {
        key = obj.key;
        val = obj.val;
        return *this;
      }
      int key {0};
      int val {0};
    };
    Pair data {0, 0};
    Node* next {nullptr};
  };
  Node* data_ {nullptr};
};

inline std::ostream& operator<<(std::ostream& ostrm, const PriorityQueue& obj) {
  return obj.WriteTo(ostrm);
}

#endif
