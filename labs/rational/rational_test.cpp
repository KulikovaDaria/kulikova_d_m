#include "rational.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

int main() {
  Rational a_def;
  std::cout << "Let's create default rational number. Rational number is "
            << a_def << std::endl;
  Rational a(3);
  std::cout << "Let's create rational number1 where num = 3. "
               "Rational number1 is " << a << std::endl;
  Rational b(3, 2);
  std::cout << "Let's create rational number2 where num = 3, den = 2. "
            << "Rational number2 is " << b << std::endl;
  std::cout << "Let's try to create rational number where num = 3, den = 0 -> "
            << std::endl;
  try {
    Rational a0(3, 0);
  }
  catch(const std::invalid_argument& except) {
    std::cout << except.what() << std::endl;
  }
  Rational c(b);
  std::cout << "Let's create copy of rational number2. Rational number3 is "
    << c << std::endl;
  Rational d;
  std::cout << "Rational number4 is " << d << std::endl;
  d = b;
  std::cout << "Let's do rational number4 = number2. Rational number4 is "
    << d << std::endl;
  std::cout << std::endl;

  std::cout << "Let's check reduction:" << std::endl;
  a = Rational(2, 4);
  std::cout << "Rational(2, 4) -> " << a << std::endl;
  a = Rational(-2, 4);
  std::cout << "Rational(-2, 4) -> " << a << std::endl;
  a = Rational(2, -4);
  std::cout << "Rational(2, -4) -> " << a << std::endl;
  a = Rational(-2, -4);
  std::cout << "Rational(-2, -4) -> " << a << std::endl;
  std::cout << std::endl;

  a = Rational(2, 3);
  b = Rational(5, 7);
  c = Rational(3, 2);
  std::cout << "A = " << a << std::endl;
  std::cout << "B = " << b << std::endl;
  std::cout << "C = " << c << std::endl;
  std::cout << "Let's try to do A = A -> " << std::endl;
  a = a;
  std::cout << "A = " << a << std::endl;
  std::cout << "Let's try to do A = B = C -> " << std::endl;
  a = b = c;
  std::cout << "A = " << a << std::endl;
  std::cout << "B = " << b << std::endl;
  std::cout << "C = " << c << std::endl;
  std::cout << std::endl;

  a = Rational(2, 3);
  b = Rational(2, 3);
  c = Rational(5, 3);
  std::cout << "Let's check operators == and != :" << std::endl;
  std::cout << a << " == " << b << " -> " << (a == b) << "; "
            << a << " == " << c << " -> " << (a == c) << std::endl;
  std::cout << a << " != " << b << " -> " << (a != b) << "; "
            << a << " != " << c << " -> " << (a != c) << std::endl;
  std::cout << std::endl;

  c = Rational(3, 4);
  std::cout << "Let's check operators <, <=, > and >= :" << std::endl;
  std::cout << a << " < " << b << " -> " << (a < b) << ";   "
            << a << " < " << c << " -> " << (a < c) << ";   "
            << c << " < " << a << " -> " << (c < a) << std::endl;
  std::cout << a << " <= " << b << " -> " << (a <= b) << ";   "
            << a << " <= " << c << " -> " << (a <= c) << ";   "
            << c << " <= " << a << " -> " << (c <= a) << std::endl;
  std::cout << a << " > " << b << " -> " << (a > b) << ";   "
            << a << " > " << c << " -> " << (a > c) << ";   "
            << c << " > " << a << " -> " << (c > a) << std::endl;
  std::cout << a << " >= " << b << " -> " << (a >= b) << ";   "
            << a << " >= " << c << " -> " << (a >= c) << ";   "
            << c << " >= " << a << " -> " << (c >= a) << std::endl;
  std::cout << std::endl;

  std::cout << "Let's check operators + and += :" << std::endl;
  a = Rational(2, 3);
  b = Rational(1, 2);
  std::cout << "A = " << a << std::endl;
  std::cout << "A += " << b << " -> " << (a += b) << std::endl;
  std::cout << "A += 1 -> " << (a += 1) << std::endl;
  a = Rational(2, 3);
  std::cout << a << " + " << b << " = " << (a + b) << std::endl;
  std::cout << a << " + 1 = " << (a + 1) << std::endl;
  std::cout << "1 + " << a << " = " << (1 + a) << std::endl;
  std::cout << std::endl;

  std::cout << "Let's check operators - and -= :" << std::endl;
  a = Rational(2, 3);
  b = Rational(1, 2);
  std::cout << "A = " << a << std::endl;
  std::cout << "A -= " << b << " -> " << (a -= b) << std::endl;
  std::cout << "A -= 1 -> " << (a -= 1) << std::endl;
  a = Rational(2, 3);
  std::cout << a << " - " << b << " = " << (a - b) << std::endl;
  std::cout << a << " - 1 = " << (a - 1) << std::endl;
  std::cout << "2 - " << a << " = " << (2 - a) << std::endl;
  std::cout << std::endl;

  std::cout << "Let's check operators * and *= :" << std::endl;
  a = Rational(2, 3);
  b = Rational(3, 5);
  std::cout << "A = " << a << std::endl;
  std::cout << "A *= " << b << " -> " << (a *= b) << std::endl;
  std::cout << "A *= 2 -> " << (a *= 2) << std::endl;
  a = Rational(2, 3);
  std::cout << a << " * " << b << " = " << (a * b) << std::endl;
  std::cout << a << " * 2 = " << (a * 2) << std::endl;
  std::cout << "2 * " << a << " = " << (2 * a) << std::endl;
  std::cout << std::endl;

  std::cout << "Let's check operators / and /= :" << std::endl;
  a = Rational(2, 3);
  b = Rational(5, 3);
  std::cout << "A = " << a << std::endl;
  std::cout << "A /= " << b << " -> " << (a /= b) << std::endl;
  std::cout << "A /= 2 -> " << (a /= 2) << std::endl;
  a = Rational(2, 3);
  std::cout << a << " / " << b << " = " << (a / b) << std::endl;
  std::cout << a << " / 2 = " << (a / 2) << std::endl;
  std::cout << "4 / " << a << " = " << (4 / a) << std::endl;
  std::cout << "Let's try to divided by 0 :" << std::endl;
  std::cout << "A /= 0 -> ";
  try {
    a /= 0;
  }
  catch(const std::invalid_argument& except) {
    std::cout << except.what() << std::endl;
  }
  std::cout << a << " / 0 -> ";
  try {
    b = a / 0;
  }
  catch(const std::invalid_argument& except) {
    std::cout << except.what() << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
