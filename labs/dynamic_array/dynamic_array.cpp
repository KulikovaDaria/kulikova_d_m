
#include "dynamic_array.h"
#include <iostream>

DynamicArray::DynamicArray()
{
	data_ = new int[0];
}

DynamicArray::DynamicArray(const int size)
	:size_(size)
{
	data_ = new int[size];
}

DynamicArray::DynamicArray(const DynamicArray& obj)
{
	*this = obj;
}

DynamicArray::~DynamicArray()
{
	size_ = 0;
	data_ = nullptr;
	delete[] data_;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& obj)
{	
	size_ = obj.size_;
	data_ = obj.data_;
	return *this;
}

int& DynamicArray::operator[](const int i) const
{
	return data_[i];
}

int DynamicArray::size() const
{
	return size_;
}