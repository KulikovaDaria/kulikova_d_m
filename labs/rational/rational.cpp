#include "rational.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

Rational::Rational(const int numerator)
  : num(numerator) {
}



Rational::Rational(const int numerator, const int denominator) {
  if (0 == denominator) {
    throw std::invalid_argument("Denominator can't be zero");
  }
  num = numerator;
  den = denominator;
  Reduction();
}



void Rational::Reduction() {
  if (den < 0) {
    num *= (-1);
    den *= (-1);
  }
  int gcd = Gcd(num, den);
  num /= gcd;
  den /= gcd;
}



int Gcd(int a, int b) {
  return (0 == b) ? abs(a) : Gcd(b, a%b);
}



bool Rational::operator==(const Rational& rhs) const {
  return (num == rhs.num) && (den == rhs.den);
}



bool Rational::operator>(const Rational& rhs) const {
  return (num * rhs.den) > (rhs.num * den);
}



bool Rational::operator>=(const Rational& rhs) const {
  return (*this > rhs) || (*this == rhs);
}



Rational& Rational::operator+=(const Rational& rhs) {
  num = num * rhs.den + rhs.num * den;
  den *= rhs.den;
  Reduction();
  return *this;
}



Rational operator+(const Rational& lhs, const Rational& rhs) {
  Rational sum(lhs);
  sum += rhs;
  return sum;
}



Rational operator+(const Rational& lhs, const int rhs) {
  return (lhs + Rational(rhs));
}



Rational operator+(const int lhs, const Rational& rhs) {
  return (Rational(lhs) + rhs);
}



Rational& Rational::operator-=(const Rational& rhs) {
  num = num * rhs.den - rhs.num * den;
  den *= rhs.den;
  Reduction();
  return *this;
}



Rational operator-(const Rational& lhs, const Rational& rhs) {
  Rational sum(lhs);
  sum -= rhs;
  return sum;
}



Rational operator-(const Rational& lhs, const int rhs) {
  return (lhs - Rational(rhs));
}



Rational operator-(const int lhs, const Rational& rhs) {
  return (Rational(lhs) - rhs);
}



Rational& Rational::operator*=(const Rational& rhs) {
  num *= rhs.num;
  den *= rhs.den;
  Reduction();
  return *this;
}



Rational operator*(const Rational& lhs, const Rational& rhs) {
  Rational sum(lhs);
  sum *= rhs;
  return sum;
}



Rational operator*(const Rational& lhs, const int rhs) {
  return (lhs * Rational(rhs));
}



Rational operator*(const int lhs, const Rational& rhs) {
  return(Rational(lhs) * rhs);
}



Rational& Rational::operator/=(const Rational& rhs) {
  if (0 == rhs.num) {
    throw std::invalid_argument("Can't be divided by 0");
  }
  num *= rhs.den;
  den *= rhs.num;
  Reduction();
  return *this;
}



Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational sum(lhs);
  sum /= rhs;
  return sum;
}



Rational operator/(const Rational& lhs, const int rhs) {
  return (lhs / Rational(rhs));
}



Rational operator/(const int lhs, const Rational& rhs) {
  return(Rational(lhs) / rhs);
}



std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
  ostrm << num << separator << den;
  return ostrm;
}



std::istream& Rational::ReadFrom(std::istream& istrm) {
  int numerator(0);
  char separator(0);
  int denominator(0);
  istrm >> numerator >> separator >> denominator;
  if (istrm.good()) {
    if (Rational::separator == separator) {
      num = numerator;
      den = denominator;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}
