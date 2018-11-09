
#include "dynamic_array.h"
#include <iostream>
#include <sstream>

int main()
{
	using namespace std;

	DynamicArray a1;
	cout << "DynamicArray a1 -> a1.size() = " << a1.size() << endl;
	DynamicArray a(3);
	cout << "DynamicArray a(3) -> a.size() = " << a.size() << endl;
	a[0] = 1; a[1] = 2; a[2] = 3;
	cout << "a = { ";
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << ' ';
	cout << "}" << endl;
	DynamicArray b(a);
	cout << "DynamicArray b(a) -> b  = { ";
	for (int i = 0; i < b.size(); ++i)
		cout << b[i] << ' ';
	cout << "}; b.size() = " << b.size() << endl;
	DynamicArray c = a;
	cout << "DynamicArray c = a -> c  = { ";
	for (int i = 0; i < c.size(); ++i)
		cout << c[i] << ' ';
	cout << "}; c.size() = " << c.size() << endl;
	for (int i = 0; i < c.size(); ++i)
	{
		++c[i];
	}
	cout << "c = { ";
	for (int i = 0; i < c.size(); ++i)
		cout << c[i] << ' ';
	cout << "}" << endl;
	cout << "a == b -> " << (a == b) << "; a == c -> " << (a == c) << endl;
	cout << "a != b -> " << (a != b) << "; a != c -> " << (a != c) << endl;
	c.push_back(10);
	cout << "c.push_back(10) -> c = { ";
	for (int i = 0; i < c.size(); ++i)
		cout << c[i] << ' ';
	cout << "}" << endl;
	c.pop_back();
	cout << "c.pop_back() -> c = { ";
	for (int i = 0; i < c.size(); ++i)
		cout << c[i] << ' ';
	cout << "}" << endl;
	c.resize(10);
	cout << "c.resize(10) -> c.size = " << c.size() << endl;

	return 0;
}