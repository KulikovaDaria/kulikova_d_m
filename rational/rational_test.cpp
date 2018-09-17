#include "rational.h"
#include <iostream>
#include <sstream>

int main()
{
	using namespace std;	

	cout << "Rational() = " << Rational() << "; Rational(5) = " << Rational(5) << endl;
	cout << "Rational(2, -8) = " << Rational(2, -8) << "; Rational(8, 2) = " << Rational(8, 2) << endl;

	system("pause");
	return 0;
}