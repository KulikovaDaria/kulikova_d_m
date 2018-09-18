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

bool Rational::operator==(const Rational& rhs) const
{
	return (num == rhs.num) && (den == rhs.den);
}

bool Rational::operator>(const Rational& rhs) const
{
	return (num*rhs.den) > (rhs.num*den);
}

bool Rational::operator>=(const Rational& rhs) const
{
	return (*this > rhs) || (*this == rhs);
}

Rational& Rational::operator+=(const Rational& rhs)
{
	num = num * rhs.den + rhs.num*den;
	den *= rhs.den;
	reduction();
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator+(const Rational& lhs, const int rhs) 
{ 
	return (lhs + Rational(rhs)); 
}

Rational operator+(const int lhs, const Rational& rhs) 
{ 
	return (Rational(lhs) + rhs); 
}

Rational& Rational::operator-=(const Rational& rhs)
{
	num = num * rhs.den - rhs.num*den;
	den *= rhs.den;
	reduction();
	return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum -= rhs;
	return sum;
}

Rational operator-(const Rational& lhs, const int rhs)
{
	return (lhs - Rational(rhs));
}

Rational operator-(const int lhs, const Rational& rhs)
{
	return (Rational(lhs) - rhs);
}

Rational& Rational::operator*=(const Rational& rhs)
{
	num *= rhs.num;
	den *= rhs.den;
	reduction();
	return *this;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum *= rhs;
	return sum;
}

Rational operator*(const Rational& lhs, const int rhs)
{
	return (lhs*Rational(rhs));
}

Rational operator*(const int lhs, const Rational& rhs)
{
	return(Rational(lhs)*rhs);
}

Rational& Rational::operator/=(const Rational& rhs)
{
	num *= rhs.den;
	den *= rhs.num;
	reduction();
	return *this;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum /= rhs;
	return sum;
}

Rational operator/(const Rational& lhs, const int rhs)
{
	return (lhs / Rational(rhs));
}

Rational operator/(const int lhs, const Rational& rhs)
{
	return(Rational(lhs) / rhs);
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