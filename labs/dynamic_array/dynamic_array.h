#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iosfwd>

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(const DynamicArray& obj);
	~DynamicArray();

private:
	int size_{ 0 };
	int* data_{ nullptr };
};

#endif
