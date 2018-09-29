#include "Complex.h"
#include <iostream>
#include <sstream>

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error: " << str << " -> " << z << endl;
	}
	return istrm.good();
}

int main()
{
	using namespace std;

	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	cout << endl;
	cout << "Complex() = " << Complex() << ";		Complex(8.9) = " <<
		Complex(8.9) << ";		Complex(8.9, -9.1) = " << Complex(8.9, -9.1) << endl;
	Complex a(-8.9, 9.1);
	Complex b(-8.9, 9.1);
	Complex c(-8.9, 5.2);
	cout << a << "==" << b << " -> " << (a == b) << ";		" << a << "==" << c << " -> " << (a == c) << endl;
	cout << a << "!=" << b << " -> " << (a != b) << ";		" << a << "!=" << c << " -> " << (a != c) << endl;
	cout << endl;
	a = Complex(1.0, 1.1);
	b = Complex(1.2, -2.2);
	cout << "A = " << a << endl;
	cout << "A += " << b << " -> " << (a += b) << endl;
	cout << "A += 1.1 -> " << (a += 1.1) << endl;
	cout << a << " + " << b << " = " << (a + b) << endl;
	cout << a << " + 1.1 = " << (a + 1.1) << endl;
	cout << "1.1 + " << a << " = " << (1.1 + a) << endl;
	cout << endl;
	a = Complex(5.8, 4.4);
	b = Complex(1.4, 1.1);
	cout << "A = " << a << endl;
	cout << "A -= " << b << " -> " << (a -= b) << endl;
	cout << "A -= 1.1 -> " << (a -= 1.1) << endl;
	cout << a << " - " << b << " = " << (a - b) << endl;
	cout << a << " - 1.1 = " << (a - 1.1) << endl;
	cout << "8.8 - " << a << " = " << (8.8 - a) << endl;
	cout << endl;
	a = Complex(1.1, 2.0);
	b = Complex(5.0, 3.0);
	cout << "A = " << a << endl;
	cout << "A *= " << b << " -> " << (a *= b) << endl;
	cout << "A *= 2 -> " << (a *= 2) << endl;
	cout << a << " * " << b << " = " << (a*b) << endl;
	cout << a << " * 5 = " << (a * 5) << endl;
	cout << "5 * " << a << " = " << (5 * a) << endl;
	cout << endl;
	a = Complex(32, 8);
	b = Complex(1, 2);
	cout << "A = " << a << endl;
	cout << "A /= " << b << " -> " << (a /= b) << endl;
	cout << "A /= 2 -> " << (a /= 2) << endl;
	cout << a << " / " << b << " = " << (a / b) << endl;
	cout << a << " / 2 = " << (a / 2) << endl;
	cout << "64 / " << a << " = " << (64 / a) << endl;
	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}
