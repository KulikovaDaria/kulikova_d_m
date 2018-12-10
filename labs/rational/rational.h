#ifndef RATIONAL_H
#define RATIONAL_H
#include <iosfwd>

class Rational {
public:
  Rational() = default;
  explicit Rational(const int numerator);
  Rational(const int numerator, const int denominator);
  ~Rational() = default;
  void Reduction();
  Rational& operator=(const Rational& rhs) = default;
  bool operator==(const Rational& rhs) const;
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
  std::ostream& WriteTo(std::ostream& ostrm) const;
  std::istream& ReadFrom(std::istream& istrm);

private:
  int num {0};
  int den {1};
  static const char separator {'/'};
};

int Gcd(int a, int b);
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

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
  return rhs.WriteTo(ostrm);
}



inline std::istream& operator>>(std::istream& istrm, Rational rhs) {
  return rhs.ReadFrom(istrm);
}

#endif
