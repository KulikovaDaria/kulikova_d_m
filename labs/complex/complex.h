#ifndef COMPLEX_H
#define COMPLEX_H

#include <iosfwd>

struct Complex {
	Complex() = default;
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
  Complex(const Complex& obj) = default;
	~Complex() = default;
	Complex& operator=(const Complex& rhs) = default;
	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
  Complex& operator++() { return operator+=(Complex(1)); }
  Complex operator++(int);
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator--() { return operator-=(Complex(1)); }
  Complex operator--(int);
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); }
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }
	std::ostream& WriteTo(std::ostream& ostrm) const;
	std::istream& ReadFrom(std::istream& istrm);

	double re{0.0};
	double im{0.0};
	static const char kLeftBrace{'{'};
	static const char kSeparator{','};
	static const char kRightBrace{'}'};
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator+(const double lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator*(const double lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);
Complex operator/(const double lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.WriteTo(ostrm);
}



inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.ReadFrom(istrm);
}

#endif