#ifndef RATIONAL_H
#define RATIONAL_H
#include <iosfwd>

struct Rational
{
	Rational() = default;
	explicit Rational(const int numerator);
	Rational(const int numerator, const int denominator);
	~Rational() = default;
	void reduction();
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	int num{ 0 };
	int den{ 1 };

	static const char separator{ '/' };
};

int GCD(int a, int b);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational rhs)
{
	return rhs.readFrom(istrm);
}

#endif