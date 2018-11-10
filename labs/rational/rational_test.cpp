#include "rational.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>

int main() {

	using namespace std;	
	try { 
		Rational z(0, 0);
		cout << "Rational " << z << " -> ";
		throw invalid_argument("Denominator can't be zero");
	} 
  catch (const invalid_argument& except) {
		cout << except.what() << endl;
	}
	cout << endl;
	cout << "Rational() = " << Rational() << ";		Rational(5) = " << Rational(2) << endl;
	cout << "Rational(8, 6) = " << Rational(8, 6) << ";		Rational(8, -6) = " << Rational(8, -6) 
	     << ";		Rational(-8, 6) = " << Rational(-8, 6) << ";		Rational(-8, -2) = " << Rational(-8, -6) << endl;
	cout << endl;
	Rational a(1, 4);
	Rational b(1, 4);
	Rational c(-1, 4);
	cout << a << " == " << b << " -> " << (a == b) << ";	" << a << " == " << c << " -> " << (a == c) << endl;
	cout << a << " != " << b << " -> " << (a != b) << ";	" << a << " != " << c << " -> " << (a != c) << endl;
	c = Rational(1, 5);
	Rational d(2, 3);
	cout << a << " > " << b << " -> " << (a > b) << ";		" << a << " > " << c << " -> " << (a > c) << ";		" << a << " > " << d << " -> " << (a > d) << endl;
	cout << a << " >= " << b << " -> " << (a >= b) << ";	" << a << " >= " << c << " -> " << (a >= c) << ";	" << a << " >= " << d << " -> " << (a >= d) << endl;
	cout << a << " < " << b << " -> " << (a < b) << ";		" << a << " < " << c << " -> " << (a < c) << ";		" << a << " < " << d << " -> " << (a < d) << endl;
	cout << a << " <= " << b << " -> " << (a <= b) << ";	" << a << " <= " << c << " -> " << (a <= c) << ";	" << a << " <= " << d << " -> " << (a <= d) << endl;
	cout << endl;
	b = Rational(5, 2);
	cout << "A = " << a << endl;
	cout << "A += " << b << " -> " << (a += b) << endl;
	cout << "A += 3 -> " << (a += 3) << endl;
	a = Rational(1, 4);
	cout << a << " + " << b << " = " << (a + b) << ";	" << a << " + 3 = " << (a + 3) << ";		" << "3 + " << a << " = " << (3 + a) << endl;
	cout << endl;
	a = Rational(5, 6);
	b = Rational(10, 3);
	cout << "A = " << a << endl;
	cout << "A -= " << b << " -> " << (a -= b) << endl;
	cout << "A -= 1 -> " << (a -= 1) << endl;
	a = Rational(5, 6);
	cout << a << " - " << b << " = " << (a - b) << ";	" << a << " - 1 = " << (a - 1) << ";		" << "1 - " << a << " = " << (1 - a) << endl;
	cout << endl;
	a = Rational(5, 12);
	b = Rational(9, 5);
	cout << "A = " << a << endl;
	cout << "A *= " << b << " -> " << (a *= b) << endl;
	cout << "A *= -2 -> " << (a *= -2) << endl;
	a = Rational(5, 12);
	cout << a << " * " << b << " = " << (a * b) << ";	" << a << " * 6 = " << (a * 6) << ";		" << "6 * " << a << " = " << (6 * a) << endl;
	cout << endl;
	a = Rational(5, 12);
	b = Rational(5, 9);
	cout << "A = " << a << endl;
	cout << "A /= " << b << " -> " << (a /= b) << endl;
	cout << "A /= 3 -> " << (a /= 3) << endl;
	a = Rational(5, 12);
	cout << a << " / " << b << " = " << (a / b) << ";	" << a << " / -5 = " << (a / -5) << ";		" << "-5 / " << a << " = " << (-5 / a) << endl;
	cout << endl;
	
	return 0;
}