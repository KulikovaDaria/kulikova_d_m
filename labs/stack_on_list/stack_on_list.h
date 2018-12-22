#ifndef STACK_ON_LIST_H
#define STACK_ON_LIST_H
#include <iosfwd>

class StackOnList {
public:
  StackOnList() = default;
  StackOnList(const StackOnList& obj);
  StackOnList& operator=(const StackOnList& obj);
  ~StackOnList() noexcept;
  void Push(const int value);
  void Pop() noexcept;
  int Top() const;
  bool IsEmpty() const noexcept;
  std::ostream& WriteTo(std::ostream& ostrm) const;
private:
  struct Node {
    Node() = default;
    Node(const int v, Node* p)
      :data(v), next(p) {
    }
    int data {0};
    Node* next {nullptr};
  };
  Node* data_ {nullptr};
};

inline std::ostream& operator<<(std::ostream& ostrm, const StackOnList& obj) {
  return obj.WriteTo(ostrm);
}

#endif
