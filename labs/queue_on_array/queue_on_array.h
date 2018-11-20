#ifndef QUEUE_ON_ARRAY_H
#define QUEUE_ON_ARRAY_H
#include <iosfwd>

class QueueOnArray {
public:
  QueueOnArray();
  QueueOnArray(const QueueOnArray& obj);
  ~QueueOnArray();
  QueueOnArray& operator=(const QueueOnArray& obj);
  void Push(const int value);
  void Pop();
  int Top() const;

private:
  void Swap(QueueOnArray& rhs);
  void Resize();
  void Copy(const QueueOnArray& obj);

  int size_{0};
  int i_first_{-1};
  int i_last_{0};
  int* data_{nullptr};
};

#endif