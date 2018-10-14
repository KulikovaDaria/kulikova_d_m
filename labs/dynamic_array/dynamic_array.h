
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iosfwd>

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const int size);
	DynamicArray(const DynamicArray& obj);
	~DynamicArray();
	DynamicArray& operator=(const DynamicArray& obj);
	int& operator[] (const int i) const;
	int size() const;

private:
	int size_{ 0 };
	int* data_{ nullptr };
};

#endif
