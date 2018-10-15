
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
	bool operator==(const DynamicArray& obj) const;
	bool operator!=(const DynamicArray& obj) const { return !operator==(obj);  };
	int& operator[] (const int i) const;
	int size() const;
	void push_back(const int a);
	void pop_back();

private:
	void add(const DynamicArray& obj, int l, int r);
	int size_{ 0 };
	int* data_{ nullptr };
};

#endif
