#include "queue_on_array.h"

#include <iostream>

QueueOnArray::QueueOnArray() {
  data_ = new int[0];
}



QueueOnArray::QueueOnArray(const QueueOnArray& obj)
  : size_(obj.size_), i_first_(0), i_last_(obj.size_) {
  data_ = new int[size_];
  Copy(obj);
}



QueueOnArray& QueueOnArray::operator=(const QueueOnArray& obj) {
  if (this != &obj) {
    std::swap(*this, QueueOnArray(obj));
  }
  return *this;
}




QueueOnArray::~QueueOnArray() {
  size_ = 0;
  i_first_ = 0;
  i_last_ = 0;
  delete[] data_;
  data_ = nullptr;
}



void QueueOnArray::Copy(const QueueOnArray& obj) {
  for (int i = 0; i < obj.size_; ++i) {
    int j = obj.i_first_ + i;
    if (j >= obj.size_) {
      j -= obj.size_;
    }
    *(data_ + i) = *(obj.data_ + j);
  }
}



void QueueOnArray::Resize() {
  int size = size_ * 2;
  int* data = new int[size];
  Copy();
}


void QueueOnArray::Push(const int value) {
  
}



void QueueOnArray::Pop() {
  --size_;
  if (i_last_ > 0) {
    --i_last_;
  }
  else {
    i_last_ = size_ - 1;
  }
}