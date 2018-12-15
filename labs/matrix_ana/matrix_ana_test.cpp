#include "matrix_ana.h"
#include <exception>
#include <iostream>
#include <sstream>

int main() {
  MatrixAnA a_def;
  std::cout << "Let's create default matrix. Matrix is " << a_def << std::endl;
  std::cout << "Let's try to create array0 where row_size = -2. -> "
      << std::endl;
  try {
    MatrixAnA a0(-2, 3);
  }
  catch(const std::length_error& exp) {
    std::cout << exp.what() << std::endl;
  }
  MatrixAnA a1(2, 3);
  std::cout << "Let's create matix1 2x3. Matrix1 is " << a1
    << std::endl;
  int val1(1);
  int val2(2);
  int val3(3);
  a1.Element(0, 0) = val1;
  a1.Element(0, 1) = val2;
  a1.Element(1, 0) = val3;
  std::cout << "Let's do a1[0][0] = " << val1 << ", a1[0][1] = " << val2
      << ", a1[1][0] = " << val3 << ". Array1 is " << a1 << std::endl;
  std::cout << "a1[1][1] = " << a1.Element(1, 1) << std::endl;
  try {
    std::cout << "Let's try to get a1[3][1] -> ";
    std::cout << a1.Element(3, 2) << std::endl;
  }
  catch(const std::out_of_range& exp) {
    std::cout << exp.what() << std::endl;
  }
  std::cout << std::endl;

  MatrixAnA a2(a1);
  std::cout << "Let's create copy of matrix1. Matrix2 is " << a2 << std::endl;
  std::cout << "RowSize is " << a2.RowSize() << std::endl;
  std::cout << "ColumnSize is " << a2.ColumnSize() << std::endl;
  a2.Resize(2, 2);
  std::cout << "Let's do Resize(2, 2) to matrix2. Matrix2 is " << a2
      << std::endl;
  std::cout << "RowSize is " << a2.RowSize() << std::endl;
  std::cout << "ColumnSize is " << a2.ColumnSize() << std::endl;
  MatrixAnA a3;
  a3 = a1;
  std::cout << "Let's create matrix3 = matrix1. Matrix3 is " << a1 << std::endl;
  std::cout << std::endl;

  a2.Resize(2, 3);
  int val4 = 5;
  a3.Element(0, 2) = val4;
  std::cout << "Let's check operators ==, != :" << std::endl;
  std::cout << a1 << " == " << a2 << " -> " << (a1 == a2) << "; "
    << a1 << " == " << a3 << " -> " << (a1 == a3) << std::endl;
  std::cout << a1 << " != " << a2 << " -> " << (a1 != a2) << "; "
    << a1 << " != " << a3 << " -> " << (a1 != a3) << std::endl;
  std::cout << std::endl;

  a2.Element(1, 2) = val1;
  std::cout << "A1 = " << a1 << std::endl;
  std::cout << "A2 = " << a2 << std::endl;
  std::cout << "A3 = " << a3 << std::endl;
  std::cout << "Let's try to do A1 = A1 -> " << std::endl;
  a1 = a1;
  std::cout << "A1 = " << a1 << std::endl;
  std::cout << "Let's try to do A1 = A2 = A3 -> " << std::endl;
  a1 = a2 = a3;
  std::cout << "A1 = " << a1 << std::endl;
  std::cout << "A2 = " << a2 << std::endl;
  std::cout << "A3 = " << a3 << std::endl;
  std::cout << std::endl;
  return 0;
}
