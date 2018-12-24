#ifndef QUEUE_ON_ARRAY_H
#define QUEUE_ON_ARRAY_H
#include <iosfwd>

class QueueOnArray {
public:
  QueueOnArray() = default;
  QueueOnArray(const QueueOnArray& obj);
  ~QueueOnArray();
  QueueOnArray& operator=(const QueueOnArray& obj);
  void Push(const int value);
  void Pop() noexcept;
  int Top() const;
  bool IsEmpty() const noexcept;
  std::ostream& WriteTo(std::ostream& ostrm) const;

private:
  void Resize(const ptrdiff_t new_size);
  ptrdiff_t RealSize() const;
  ptrdiff_t size_{0};
  ptrdiff_t i_first_{0};
  ptrdiff_t i_last_{0};
  int* data_{nullptr};
};

inline std::ostream& operator<<(std::ostream& ostrm, const QueueOnArray& obj) {
  return obj.WriteTo(ostrm);
}

#endif
