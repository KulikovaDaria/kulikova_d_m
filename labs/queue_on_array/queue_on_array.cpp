#include "queue_on_array.h"
#include <iostream>
#include <exception>

QueueOnArray::QueueOnArray(const QueueOnArray& obj)
  :i_first_(0) {
  size_ = obj.RealSize() + 1;
  i_last_ = size_ - 1;
  data_ = new int[size_];
  for (ptrdiff_t i = 0; i < size_- 1; ++i) {
    *(data_ + i) = *(obj.data_ + (i + i_first_) % obj.size_);
  }
}



QueueOnArray& QueueOnArray::operator=(const QueueOnArray& obj) {
  if (this != &obj) {
    ptrdiff_t size = obj.RealSize();
    if (size_ <= size) {
      Resize(size + 1);
    }
    i_first_ = 0;
    i_last_ = size;
    for (ptrdiff_t i = 0; i < size; ++i) {
      *(data_ + i) = *(obj.data_ + (i + i_first_) % obj.size_);
    }
  }
  return *this;
}



QueueOnArray::~QueueOnArray() {
  delete[] data_;
  data_ = nullptr;
}



void QueueOnArray::Resize(const ptrdiff_t new_size) {
  int* new_data(new int[new_size]);
  ptrdiff_t size = RealSize();
  for (ptrdiff_t i = 0; i < size; ++i) {
    *(new_data + i) = *(data_ + (i + i_first_) % size_);
  }
  delete[] data_;
  data_ = new_data;
  size_ = new_size;
  i_first_ = 0;
  i_last_ = size;
}



ptrdiff_t QueueOnArray::RealSize() const {
  ptrdiff_t size = i_last_ - i_first_;
  if (size < 0) {
    size = size_ - size;
  }
  return size;
}



void QueueOnArray::Push(const int value) {
  if (0 == size_) {
    Resize(1);
  }
  if ((i_last_ + 1) % size_ == i_first_) {
    Resize(size_ * 2);
  }
  *(data_ + i_last_) = value;
  i_last_ = (i_last_ + 1) % size_;
}



void QueueOnArray::Pop() noexcept {
  i_first_ = (i_first_ + 1) % size_;
}



int QueueOnArray::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("Try to get top from empty queue.");
  }
  return *(data_ + i_first_);
}



bool QueueOnArray::IsEmpty() const noexcept {
  return i_first_ == i_last_;
}



std::ostream& QueueOnArray::WriteTo(std::ostream& ostrm) const {
  ostrm << '{';
  for (ptrdiff_t i = 0; i < RealSize(); ++i) {
    ostrm << *(data_ + (i_first_ + i) % size_);
    if (i + 1 < RealSize()) {
      ostrm << ", ";
    }
  }
  ostrm << '}';
  return ostrm;
}
