#include "dynamic_array.h"
#include <iostream>

DynamicArray::DynamicArray()
{
	data_ = new int[0];
}

DynamicArray::DynamicArray(int size)
	:size_(size)
{
	data_ = new int[size];
}



DynamicArray::~DynamicArray()
{
	delete(data_);
	size_ = 0;
	data_ = nullptr;
}