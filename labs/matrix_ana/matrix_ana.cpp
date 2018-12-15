#include "matrix_ana.h"
#include <exception>
#include <iostream>
#include <sstream>

MatrixAnA::MatrixAnA(const ptrdiff_t i_size, const ptrdiff_t j_size)
  : i_size_(i_size), j_size_(j_size), i_capacity_(i_size),
      j_capacity_(j_size) {
  if (i_size < 0 || j_size < 0) {
    throw std::length_error("Size cant't be < 0");
  }
  data_ = new int[i_size * j_size];
  for (ptrdiff_t i = 0; i < i_size * j_size; ++i) {
    *(data_ + i) = 0;
  }
}



MatrixAnA::MatrixAnA(const MatrixAnA& obj)
  : i_size_(obj.i_size_), j_size_(obj.j_size_), i_capacity_(obj.i_size_),
      j_capacity_(obj.j_size_), data_(new int[obj.i_size_ * obj.j_size_]) {
  Copy(obj, data_, j_capacity_);
}



MatrixAnA::~MatrixAnA() noexcept {
  delete[] data_;
  data_ = nullptr;
}



MatrixAnA& MatrixAnA::operator=(const MatrixAnA& obj) {
  if (this != &obj) {
    if (i_capacity_ < obj.i_size_ || j_capacity_ < obj.j_size_) {
      Resize(obj.i_size_, obj.j_size_);
    }
    Copy(obj, data_, j_capacity_);
    i_size_ = obj.i_size_;
    j_size_ = obj.j_size_;
  }
  return *this;
}



bool MatrixAnA::operator==(const MatrixAnA& obj) const {
  if (this == &obj) {
    return true;
  }
  bool check = false;
  if (i_size_ == obj.i_size_ && j_size_ == obj.j_size_) {
    check = true;
    for (ptrdiff_t i = 0; i < i_size_ && check == true; ++i) {
      for (ptrdiff_t j = 0; j < j_size_ && check == true; ++j) {
        if (*(data_ + i * j_capacity_ + j)
            != *(obj.data_ + i * obj.j_capacity_ + j)) {
          check = false;
        }
      }
    }
  }
  return check;
}



bool MatrixAnA::operator!=(const MatrixAnA& obj) const {
  return !operator==(obj);
}



int& MatrixAnA::Element(const ptrdiff_t i, const ptrdiff_t j) {
  if ((i < 0) || (j < 0) || (i >= i_size_) || (j >= j_size_)) {
    throw std::out_of_range("Invalid index");
  }
  return *(data_ + i * j_size_ + j);
}



ptrdiff_t MatrixAnA::RowSize() const noexcept {
  return i_size_;
}



ptrdiff_t MatrixAnA::ColumnSize() const noexcept {
  return j_size_;
}



void MatrixAnA::Resize(const ptrdiff_t i_new, const ptrdiff_t j_new) {
  if (i_new < 0 || j_new < 0) {
    throw std::length_error("Size cant't be < 0");
  }
  if (i_capacity_ < i_new || j_capacity_ < j_new) {
    Reserve(i_new, j_new);
  }
  for (ptrdiff_t i = 0; i < i_size_; ++i) {
    for (ptrdiff_t j = j_size_; j < j_new; ++j) {
      *(data_ + i * j_capacity_ + j) = 0;
    }
  }
  for (ptrdiff_t i = i_size_; i < i_new; ++i) {
    for (ptrdiff_t j = 0; j < j_new; ++j) {
      *(data_ + i * j_capacity_ + j) = 0;
    }
  }
  i_size_ = i_new;
  j_size_ = j_new;
}



void MatrixAnA::Reserve(const ptrdiff_t i_new, const ptrdiff_t j_new) {
  if (i_new < 0 || j_new < 0) {
    throw std::length_error("Size cant't be < 0");
  }
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
    Copy(*this, new_data_, j_new_cap);
    delete[] data_;
    data_ = new_data_;
    i_capacity_ = i_new_cap;
    j_capacity_ = j_new_cap;
  }
}



void MatrixAnA::Copy(const MatrixAnA& from, int* const data,
    const ptrdiff_t j_cap) {
  for (ptrdiff_t i = 0; i < from.i_size_; ++i) {
    for (ptrdiff_t j = 0; j < from.j_size_; ++j) {
      *(data + i * j_cap + j) = *(from.data_ + i * from.j_capacity_ + j);
    }
  }
}



std::ostream& MatrixAnA::WriteTo(std::ostream& ostrm) const {
  ostrm << '{';
  for (ptrdiff_t i = 0; i < i_size_; ++i) {
    ostrm << '{';
    for (ptrdiff_t j = 0; j < j_size_; ++j) {
      ostrm << *(data_ + i * j_capacity_ + j);
      if (j < j_size_ - 1) {
        ostrm << ", ";
      }
    }
    ostrm << '}';
    if (i < i_size_ - 1) {
      ostrm << ", ";
    }
  }
  ostrm << '}';
  return ostrm;
}
