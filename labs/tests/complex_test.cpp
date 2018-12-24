#include "complex.h"
#include <iostream>
#include <sstream>

int main() {
  Complex c_def;
  std::cout << "Let's create default complex number. Complex number is "
            << c_def << std::endl;
  Complex a(1.1);
  std::cout << "Let's create complex number1 where re = 1,1. "
               "Complex number1 is " << a << std::endl;
  Complex b(1.1, 2.2);
  std::cout << "Let's create complex number2 where re = 1,1, im = 2,2. "
               "Complex number2 is " << b << std::endl;
  Complex c(b);
  std::cout << "Let's create copy of complex number2. Complex number3 is "
            << c << std::endl;
  Complex d = b;
  std::cout << "Let's create complex number4 = number2. Complex number4 is "
            << d << std::endl;
  std::cout << std::endl;

  a = Complex(3, 1);
  b = Complex(-2, 4);
  c = Complex(10, 11);
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

  a = Complex(-8.9, 9.1);
  b = Complex(-8.9, 9.1);
  c = Complex(-8.9, 5.2);
  std::cout << "Let's check operators == and != :" << std::endl;
  std::cout << a << " == " << b << " -> " << (a == b) << "; "
            << a << " == " << c << " -> " << (a == c) << std::endl;
  std::cout << a << " != " << b << " -> " << (a != b) << "; "
            << a << " != " << c << " -> " << (a != c) << std::endl;
  std::cout << std::endl;

  std::cout << "Let's check operators +, ++ and += :" << std::endl;
  a = Complex(1.1, 2.2);
  b = Complex(2.3, -2.2);
  std::cout << "A = " << a << std::endl;
  std::cout << "A += " << b << " -> " << (a += b) << std::endl;
  std::cout << "A += 1.1 -> " << (a += 1.1) << std::endl;
  a = Complex(1.1, 2.2);
  std::cout << a << " + " << b << " = " << (a + b) << std::endl;
  std::cout << a << " + 2.3 = " << (a + 2.3) << std::endl;
  std::cout << "2.3 + " << a << " = " << (2.3 + a) << std::endl;
  std::cout << "++" << a << " -> ";
  std::cout << ++a << std::endl;
  std::cout << a << "++ -> ";
  std::cout << a++ << std::endl;
  std::cout << "Complex number is " << a << std::endl;
  std::cout << std::endl;

  std::cout << "Let's check operators -, -- and -= :" << std::endl;
  a = Complex(5.8, 4.4);
  b = Complex(1.4, 1.1);
  std::cout << "A = " << a << std::endl;
  std::cout << "A -= " << b << " -> " << (a -= b) << std::endl;
  std::cout << "A -= 1.1 -> " << (a -= 1.1) << std::endl;
  a = Complex(5.8, 4.4);
  std::cout << a << " - " << b << " = " << (a - b) << std::endl;
  std::cout << a << " - 1.1 = " << (a - 1.1) << std::endl;
  std::cout << "8.8 - " << a << " = " << (8.8 - a) << std::endl;
  std::cout << "--" << a << " -> ";
  std::cout << --a << std::endl;
  std::cout << a << "-- -> ";
  std::cout << a-- << std::endl;
  std::cout << "Complex number is " << a << std::endl;
  std::cout << std::endl;

  std::cout << "Let's check operators * and *= :" << std::endl;
  a = Complex(1, 2);
  b = Complex(2, 3);
  std::cout << "A = " << a << std::endl;
  std::cout << "A *= " << b << " -> " << (a *= b) << std::endl;
  std::cout << "A *= 2 -> " << (a *= 2) << std::endl;
  a = Complex(1, 2);
  std::cout << a << " * " << b << " = " << (a*b) << std::endl;
  std::cout << a << " * 2 = " << (a * 2) << std::endl;
  std::cout << "2 * " << a << " = " << (2 * a) << std::endl;
  std::cout << std::endl;

  std::cout << "Let's check operators / and /= :" << std::endl;
  a = Complex(16, 8);
  b = Complex(1, 2);
  std::cout << "A = " << a << std::endl;
  std::cout << "A /= " << b << " -> " << (a /= b) << std::endl;
  std::cout << "A /= 2 -> " << (a /= 2) << std::endl;
  a = Complex(16, 8);
  std::cout << a << " / " << b << " = " << (a / b) << std::endl;
  std::cout << a << " / 2 = " << (a / 2) << std::endl;
  std::cout << "64 / " << a << " = " << (64 / a) << std::endl;
  std::cout << std::endl;

  return 0;
}
