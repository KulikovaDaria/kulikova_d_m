#include "complex.h"

#include <iostream>

Complex::Complex(const double real)
	: Complex(real, 0.0) {
}



Complex::Complex(const double real, const double imaginary)
	: re(real), im(imaginary) {
}



bool Complex::operator==(const Complex& rhs) const {
	double eps(0.000001);
	return (abs(re - rhs.re) < eps) && (abs(im - rhs.im) < eps);
}



Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}



Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex sum(lhs);
	sum += rhs;
	return sum;
}



Complex operator+(const Complex& lhs, const double rhs) {
	Complex sum(lhs + Complex(rhs));
	return sum;
}



Complex operator+(const double lhs, const Complex& rhs) {
	Complex sum(Complex(lhs) + rhs);
	return sum;
}



Complex& Complex::operator-=(const Complex& rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}



Complex operator-(const Complex& lhs, const Complex& rhs) {
	Complex sum(lhs);
	sum -= rhs;
	return sum;
}



Complex operator-(const Complex& lhs, const double rhs) {
	Complex sum(lhs - Complex(rhs));
	return sum;
}



Complex operator-(const double lhs, const Complex& rhs) {
	Complex sum(Complex(lhs) - rhs);
	return sum;
}



Complex& Complex::operator*=(const Complex& rhs) {
	Complex sum;
	sum.re = re * rhs.re - im * rhs.im;
	sum.im = re * rhs.im + rhs.re * im;
	*this = sum;
	return *this;
}



Complex operator*(const Complex& lhs, const Complex& rhs) {
	Complex sum(lhs);
	sum *= rhs;
	return sum;
}



Complex operator*(const Complex& lhs, const double rhs) {
	Complex sum(lhs * Complex(rhs));
	return sum;
}



Complex operator*(const double lhs, const Complex& rhs) {
	Complex sum(Complex(lhs) * rhs);
	return sum;
}



Complex& Complex::operator/=(const Complex& rhs) {
	Complex sum;
	sum.re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	sum.im = (rhs.re * im - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	*this = sum;
	return *this;
}



Complex operator/(const Complex& lhs, const Complex& rhs) {
	Complex sum(lhs);
	sum /= rhs;
	return sum;
}



Complex operator/(const Complex& lhs, const double rhs) {
	Complex sum(lhs / Complex(rhs));
	return sum;
}



Complex operator/(const double lhs, const Complex& rhs) {
	Complex sum(Complex(lhs) / rhs);
	return sum;
}



std::ostream& Complex::writeTo(std::ostream& ostrm) const {
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}



std::istream& Complex::readFrom(std::istream& istrm) {
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaginary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}