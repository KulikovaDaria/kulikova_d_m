#include "rational.h"
#include <iostream>

Rational::Rational(const int numerator)
	:num(numerator)
{
}

Rational::Rational(const int numerator, const int denominator)
	: num(numerator)
	, den(denominator)
{
	reduction();
}

void Rational::reduction()
{
	if (den < 0)
	{
		num *= (-1);
		den *= (-1);
	}
	int gcd = GCD(num, den);
	num /= gcd;
	den /= gcd;
}

int GCD(int a, int b)
{
	return (0 == b) ? abs(a) : GCD(b, a%b);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << num << separator << den;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	int numerator(0);
	char separator(0);
	int denominator(0);
	istrm >> numerator >> separator >> denominator;
	if (istrm.good())
	{
		if (Rational::separator == separator)
		{
			num = numerator;
			den = denominator;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}