#include "dynamic_array_t.h"
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

template<typename T>
void Test(const DynamicArrayT<T>& val) {
  DynamicArrayT<T> a_def;
  std::cout << "Let's create default array. Array is " << a_def << std::endl;
  std::cout << "Size is " << a_def.Size() << std::endl;
  std::cout << "Let's try to create array0 where size = -2. -> " << std::endl;
  try {
    DynamicArrayT<T> a0(-2);
  }
  catch(const std::length_error& exp) {
    std::cout << exp.what() << std::endl;
  }
  DynamicArrayT<T> a1(2);
  std::cout << "Let's create array1 where size = 2. Array1 is " << a1
    << std::endl;
  a1[0] = val[0];
  a1[1] = val[1];
  std::cout << "Let's do a1[0] = " << val[0] << ", a1[1] = " << val[1]
    << ". Array1 is " << a1 << std::endl;
  a1.PushBack(val[2]);
  std::cout << "Let's push " << val[2] << ". " << "Array is " << a1
      << std::endl;
  std::cout << "Size is " << a1.Size() << std::endl;
  std::cout << std::endl;

  DynamicArrayT<T> a2(a1);
  std::cout << "Let's create copy of array1. Array2 is " << a2 << std::endl;
  std::cout << "Size is " << a2.Size() << std::endl;
  a2.PopBack();
  std::cout << "Let's pop. Array is " << a2 << std::endl;
  std::cout << "Size is " << a2.Size() << std::endl;
  std::cout << "a2[0] is " << a2[0] << std::endl;
  try {
    std::cout << "Let's try to get a2[4] -> ";
    std::cout << a2[4] << std::endl;
  }
  catch(const std::out_of_range& exp) {
    std::cout << exp.what() << std::endl;
  }
  std::cout << std::endl;

  DynamicArrayT<T> a3;
  a3 = a1;
  std::cout << "Let's create array3 = array1. Array3 is " << a3 << std::endl;
  std::cout << "Size is " << a3.Size() << std::endl;
  a3.Resize(2);
  std::cout << "Let's do Resize(2) to array3. Array3 is " << a3 << std::endl;
  std::cout << "Size is " << a3.Size() << std::endl;
  std::cout << std::endl;

  a3.PushBack(val[3]);
  a2.PushBack(val[2]);
  std::cout << "Let's check operators ==, != :" << std::endl;
  std::cout << a2 << " == " << a1 << " -> " << (a2 == a1) << "; "
    << a2 << " == " << a3 << " -> " << (a2 == a3) << std::endl;
  std::cout << a2 << " != " << a1 << " -> " << (a2 != a1) << "; "
    << a2 << " != " << a3 << " -> " << (a2 != a3) << std::endl;
  std::cout << std::endl;

  a2[2] = val[4];
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
}

int main() {
  std::cout << "Let's check DinamicArrayT for INT" << std::endl;
  std::cout << std::endl;
  DynamicArrayT<int> test_int(5);
  test_int[0] = 1;
  test_int[1] = 2;
  test_int[2] = 3;
  test_int[3] = 4;
  test_int[4] = 5;
  Test<int>(test_int);
  std::cout << std::endl;

  std::cout << "Let's check DinamicArrayT for DOUBLE" << std::endl;
  std::cout << std::endl;
  DynamicArrayT<double> test_double(5);
  test_double[0] = 1.1;
  test_double[1] = 2.3;
  test_double[2] = 3.0;
  test_double[3] = 4.1;
  test_double[4] = 5.7;
  Test<double>(test_double);
  std::cout << std::endl;

  std::cout << "Let's check DinamicArrayT for STRING" << std::endl;
  std::cout << std::endl;
  DynamicArrayT<std::string> test_string(5);
  test_string[0] = "aaa";
  test_string[1] = "abc";
  test_string[2] = "bq";
  test_string[3] = "cv";
  test_string[4] = "fg";
  Test<std::string>(test_string);
  std::cout << std::endl;

  return 0;
}
