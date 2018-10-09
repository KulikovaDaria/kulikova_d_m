#include <iostream>
#include <sstream>



int main()
{

}

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