
#include "dynamic_array.h"
#include <iostream>
#include <sstream>
using namespace std;
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
	delete[] data_;
	data_ = nullptr;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& obj)
{	
	size_ = obj.size_;
	data_ = new int[obj.size_];
	this->add(obj, 0, obj.size_);
	return *this;
}

bool DynamicArray::operator==(const DynamicArray& obj) const
{
	bool ans = false;
	if (size_ == obj.size_)
	{
		ans = true;
		for(int i=0; i<size_; ++i)
			if (*(data_ + i) != *(obj.data_ + i))
			{
				ans = false;
				break;
			}
	}
	return ans;
}

int& DynamicArray::operator[](const int i) const
{
	return *(data_ + i);
}

int DynamicArray::size() const
{
	return size_;
}

void DynamicArray::push_back(const int a)
{
	DynamicArray tmp(size_ + 1);
	tmp.add(*this, 0, size_);
	*(tmp.data_ + size_) = a;
	*this = tmp;
}

void DynamicArray::pop_back()
{
	DynamicArray tmp(size_ - 1);
	tmp.add(*this, 0, size_ - 1);
	*this = tmp;
}

void DynamicArray::add(const DynamicArray& obj, int l, int r)
{
	for (int i = l; i < r; ++i)
	{
		*(data_ + i) = *(obj.data_ + i);
	}
}