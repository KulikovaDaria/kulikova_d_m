#include "matrix_ana.h"
#include <iostream>
#include <sstream>

MatrixAnA::MatrixAnA()
  :data_(new int[0]) {
}



MatrixAnA::MatrixAnA(const ptrdiff_t i_size, const ptrdiff_t j_size)
  : i_size_(i_size), j_size_(j_size), i_capacity_(i_size), j_capacity_(j_size),
      data_(new int[i_size * j_size]) {
  for (ptrdiff_t i = 0; i < i_size*j_size; ++i) {
    *(data_ + i) = 0;
  }
}



MatrixAnA::MatrixAnA(const MatrixAnA& obj)
  : i_size_(obj.i_size_), j_size_(obj.j_size_), i_capacity_(obj.i_size_),
      j_capacity_(obj.j_size_), data_(new int[obj.i_size_ * obj.j_size_]) {
  Copy(obj.data_, i_size_, j_size_, data_, j_capacity_);
}



MatrixAnA::~MatrixAnA() {
  i_size_ = 0;
  j_size_ = 0;
  i_capacity_ = 0;
  j_capacity_ = 0;
  delete[] data_;
  data_ = nullptr;
}



MatrixAnA& MatrixAnA::operator=(const MatrixAnA& obj) {
  if (this != &obj) {
    if (i_capacity_ < obj.i_size_ || j_capacity_ < obj.j_size_) {
      Resize(obj.i_size_, obj.j_size_);
    }
    Copy(obj.data_, obj.i_size_, obj.j_size_, data_, j_capacity_);
    i_size_ = obj.i_size_;
    j_size_ = obj.j_size_;
  }
  return *this;
}



bool MatrixAnA::operator==(const MatrixAnA& obj) const {
  if (i_size_ == obj.i_size_ && j_size_ == obj.j_size_) {
    for (ptrdiff_t i = 0; i < i_size_ * j_size_; ++i) {
      if (*(data_ + i) != *(obj.data_ + i)) {
        return false;
      }
    }
    return true;
  }
  return false;
}



bool MatrixAnA::operator!=(const MatrixAnA& obj) const {
  return !operator==(obj);
}



int& MatrixAnA::GetEl(const ptrdiff_t i, const ptrdiff_t j) {
  return *(data_ + i * j_size_ + j);
}



ptrdiff_t MatrixAnA::RowSize() const {
  return i_size_;
}



ptrdiff_t MatrixAnA::ColumnSize() const {
  return j_size_;
}



void MatrixAnA::Resize(const ptrdiff_t i_new, const ptrdiff_t j_new) {
  if (i_capacity_ < i_new || j_capacity_ < j_new) {
    Reserve(i_new, j_new);
  }
  i_size_ = i_new;
  j_size_ = j_new;
}



void MatrixAnA::Reserve(const ptrdiff_t i_new, const ptrdiff_t j_new) {
  if (i_capacity_ < i_new || j_capacity_ < j_new) {
    ptrdiff_t i_new_cap(i_new);
    ptrdiff_t j_new_cap(j_new);
    if (i_new_cap < i_capacity_) {
      i_new_cap = i_capacity_;
    }
    if (j_new_cap < j_capacity_) {
      j_new_cap = j_capacity_;
    }
    int* new_data_ = new int[i_new_cap * j_new_cap];
    Copy(data_, i_size_, j_size_, new_data_, j_new_cap);
    delete[] data_;
    data_ = new_data_;
    i_capacity_ = i_new_cap;
    j_capacity_ = j_new_cap;
  }
}



void Copy(const int* const first, const ptrdiff_t i_size,
    const ptrdiff_t j_size, int* const data, const ptrdiff_t j_cap) {
  for (ptrdiff_t i = 0; i < i_size; ++i) {
    for (ptrdiff_t j = 0; j < j_size; ++j) {
      *(data + i * j_cap + j) = *(first + i * j_size + j);
    }
  }
}
