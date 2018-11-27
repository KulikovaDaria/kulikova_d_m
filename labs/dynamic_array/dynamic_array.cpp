#include "dynamic_array.h"
#include <exception>
#include <iostream>
#include <sstream>

DynamicArray::DynamicArray()
	:data_(new int[0]) {
}



DynamicArray::DynamicArray(const ptrdiff_t size)
	: size_(0), capacity_(size), data_(new int[size]) {
}



DynamicArray::DynamicArray(const DynamicArray& obj) 
  :size_(obj.size_), capacity_(obj.size_), data_(new int[obj.size_]) {
  Copy(obj.data_, obj.size_, data_);
}



DynamicArray::~DynamicArray() noexcept {
	size_ = 0;
  capacity_ = 0;
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



bool DynamicArray::operator==(const DynamicArray& obj) const noexcept {
	if (size_ == obj.size_) {
    for (ptrdiff_t i = 0; i < size_; ++i) {
      if (*(data_ + i) != *(obj.data_ + i)) {
        return false;
      }
    }
    return true;
	}
	return false;
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
  if (capacity_ < new_size) {
    Reserve(new_size);
  }
  size_ = new_size;
}



void DynamicArray::Reserve(const ptrdiff_t new_capacity) {
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



void Copy(const int* const first, const ptrdiff_t size, int* const data_) {
	for (ptrdiff_t i = 0; i < size; ++i) {
		*(data_ + i) = *(first + i);
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