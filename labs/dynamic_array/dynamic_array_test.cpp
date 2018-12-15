#include "dynamic_array.h"
#include <exception>
#include <iostream>
#include <sstream>

int main() {
  DynamicArray a_def;
  std::cout << "Let's create default array. Array is " << a_def << std::endl;
  std::cout << "Size is " << a_def.Size() << std::endl;
  std::cout << "Let's try to create array0 where size = -2. -> " << std::endl;
  try {
    DynamicArray a0(-2);
  }
  catch(const std::length_error& exp) {
    std::cout << exp.what() << std::endl;
  }
  DynamicArray a1(2);
  std::cout << "Let's create array1 where size = 2. Array1 is " << a1
            << std::endl;
  int val1(1);
  int val2(2);
  int val3(3);
  a1[0] = val1;
  a1[1] = val2;
  std::cout << "Let's do a1[0] = " << val1 << ", a1[1] = " << val2
            << ". Array1 is " << a1 << std::endl;
  a1.PushBack(val3);
  std::cout << "Let's push " << val3 << ". " << "Array is " << a1 << std::endl;
  std::cout << "Size is " << a1.Size() << std::endl;
  std::cout << std::endl;

  DynamicArray a2(a1);
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

  DynamicArray a3;
  a3 = a1;
  std::cout << "Let's create array3 = array1. Array3 is " << a3 << std::endl;
  std::cout << "Size is " << a3.Size() << std::endl;
  a3.Resize(2);
  std::cout << "Let's do Resize(2) to array3. Array3 is " << a3 << std::endl;
  std::cout << "Size is " << a3.Size() << std::endl;
  std::cout << std::endl;

  a3.PushBack(5);
  a2.PushBack(3);
  std::cout << "Let's check operators ==, != :" << std::endl;
  std::cout << a2 << " == " << a1 << " -> " << (a2 == a1) << "; "
            << a2 << " == " << a3 << " -> " << (a2 == a3) << std::endl;
  std::cout << a2 << " != " << a1 << " -> " << (a2 != a1) << "; "
            << a2 << " != " << a3 << " -> " << (a2 != a3) << std::endl;
  std::cout << std::endl;

  a2[2] = 4;
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
  return 0;
}
