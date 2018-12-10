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



Complex Complex::operator++(int) {
  Complex tmp(*this);
  ++(*this);
  return tmp;
}



Complex operator+(const Complex& lhs, const Complex& rhs) {
  Complex res(lhs);
  res += rhs;
  return res;
}



Complex operator+(const Complex& lhs, const double rhs) {
  return lhs + Complex(rhs);
}



Complex operator+(const double lhs, const Complex& rhs) {
  return Complex(lhs) + rhs;
}



Complex& Complex::operator-=(const Complex& rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}



Complex Complex::operator--(int) {
  Complex tmp(*this);
  --(*this);
  return tmp;
}



Complex operator-(const Complex& lhs, const Complex& rhs) {
  Complex res(lhs);
  res -= rhs;
  return res;
}



Complex operator-(const Complex& lhs, const double rhs) {
  return lhs - Complex(rhs);
}



Complex operator-(const double lhs, const Complex& rhs) {
  return Complex(lhs) - rhs;
}



Complex& Complex::operator*=(const Complex& rhs) {
  Complex res;
  res.re = re * rhs.re - im * rhs.im;
  res.im = re * rhs.im + rhs.re * im;
  *this = res;
  return *this;
}



Complex operator*(const Complex& lhs, const Complex& rhs) {
  Complex res(lhs);
  res *= rhs;
  return res;
}



Complex operator*(const Complex& lhs, const double rhs) {
  return lhs * Complex(rhs);
}



Complex operator*(const double lhs, const Complex& rhs) {
  return Complex(lhs) * rhs;
}



Complex& Complex::operator/=(const Complex& rhs) {
  Complex res;
  res.re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
  res.im = (rhs.re * im - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
  *this = res;
  return *this;
}



Complex operator/(const Complex& lhs, const Complex& rhs) {
  Complex res(lhs);
  res /= rhs;
  return res;
}



Complex operator/(const Complex& lhs, const double rhs) {
  return lhs / Complex(rhs);
}



Complex operator/(const double lhs, const Complex& rhs) {
  return Complex(lhs) / rhs;
}



std::ostream& Complex::WriteTo(std::ostream& ostrm) const {
  ostrm << kLeftBrace << re << kSeparator << im << kRightBrace;
  return ostrm;
}



std::istream& Complex::ReadFrom(std::istream& istrm) {
  char left_brace(0);
  double real(0.0);
  char comma(0);
  double imaginary(0.0);
  char right_brace(0);
  istrm >> left_brace >> real >> comma >> imaginary >> right_brace;
  if (istrm.good()) {
    if ((Complex::kLeftBrace == left_brace) && (Complex::kSeparator == comma)
     && (Complex::kRightBrace == right_brace)) {
      re = real;
      im = imaginary;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}
