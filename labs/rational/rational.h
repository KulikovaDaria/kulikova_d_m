#ifndef RATIONAL_H
#define RATIONAL_H
#include <iosfwd>

class Rational
{
public:
	Rational() = default;
	explicit Rational(const int numerator);
	Rational(const int numerator, const int denominator);
	~Rational() = default;
	void reduction();
	Rational& operator=(const Rational& rhs) = default;
	bool operator== (const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	bool operator>(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const { return !operator>=(rhs); }
	bool operator<=(const Rational& rhs) const { return !operator>(rhs); }
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs) { return operator*=(Rational(rhs)); }
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

private:
	int num{ 0 };
	int den{ 1 };

	static const char separator{ '/' };
};

int GCD(int a, int b);
Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const int rhs);
Rational operator+(const int lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const int rhs);
Rational operator-(const int lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const int rhs);
Rational operator*(const int lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int rhs);
Rational operator/(const int lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational rhs)
{
	return rhs.readFrom(istrm);
}

#endif