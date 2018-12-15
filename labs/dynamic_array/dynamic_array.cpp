#include "dynamic_array.h"
#include <exception>
#include <iostream>
#include <sstream>

DynamicArray::DynamicArray(const ptrdiff_t size)
  : size_(size), capacity_(size) {
  if (size < 0) {
    throw std::length_error("Size can't be < 0");
  }
  data_ = new int[size];
  for (ptrdiff_t i = 0; i < size; ++i) {
    *(data_ + i) = 0;
  }
}



DynamicArray::DynamicArray(const DynamicArray& obj)
  :size_(obj.size_), capacity_(obj.size_), data_(new int[obj.size_]) {
  Copy(obj.data_, obj.size_, data_);
}



DynamicArray::~DynamicArray() noexcept {
  delete[] data_;
  data_ = nullptr;
}



DynamicArray& DynamicArray::operator=(const DynamicArray& obj) {
  if (this != &obj) {
    if (capacity_ < obj.size_) {
      Resize(obj.size_);
    }
    Copy(obj.data_, obj.size_, data_);
    size_ = obj.size_;
  }
  return *this;
}



bool DynamicArray::operator==(const DynamicArray& obj) const {
  if (this == &obj) {
    return true;
  }
  bool check = false;
  if (size_ == obj.size_) {
    for (ptrdiff_t i = 0; (i < size_) && (*(data_ + i) == *(obj.data_ + i) ?
        check = true : check = false); ++i) {
    }
  }
  return check;
}



bool DynamicArray::operator!=(const DynamicArray& obj) const {
  return !operator==(obj);
}



int& DynamicArray::operator[](const ptrdiff_t i) const {
  if ((i < 0) || (i >= size_)) {
    throw std::out_of_range("Invalid index");
  }
  return *(data_ + i);
}



ptrdiff_t DynamicArray::Size() const noexcept {
  return size_;
}



void DynamicArray::Resize(const ptrdiff_t new_size) {
  if (new_size < 0) {
    throw std::length_error("Size can't be < 0");
  }
  if (capacity_ < new_size) {
    Reserve(new_size);
  }
  size_ = new_size;
}



void DynamicArray::Reserve(const ptrdiff_t new_capacity) {
  if (new_capacity < 0) {
    throw std::length_error("Size can't be < 0");
  }
  if (capacity_ < new_capacity) {
    int* new_data(new int[new_capacity]);
    Copy(data_, size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }
}



void DynamicArray::PushBack(const int a) {
  if (capacity_ < size_ + 1) {
    Reserve(size_ + 1);
  }
  *(data_ + size_) = a;
  ++size_;
}



void DynamicArray::PopBack() noexcept {
  --size_;
}



void DynamicArray::Copy(const int* const first, const ptrdiff_t size,
      int* const data) {
  for (ptrdiff_t i = 0; i < size; ++i) {
    *(data + i) = *(first + i);
  }
}



std::ostream& DynamicArray::WriteTo(std::ostream& ostrm) const {
  ostrm << '{';
  for (ptrdiff_t i = 0; i < size_; ++i) {
    ostrm << *(data_ + i);
    if (i < size_ - 1) {
      ostrm << ", ";
    }
  }
  ostrm << '}';
  return ostrm;
}
