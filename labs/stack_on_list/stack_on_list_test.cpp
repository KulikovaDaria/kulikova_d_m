#include "stack_on_list.h"
#include <iostream>
#include <exception>

int main() {
  StackOnList st_def;
  std::cout << "Let's create default stack. Stack is " << st_def << std::endl;
  std::cout << "Is def stack empty -> " << st_def.IsEmpty() << std::endl;
  try {
    std::cout << "Let's try to get top -> ";
    st_def.Top();
  }
  catch(const std::logic_error& except) {
    std::cout << except.what() << std::endl;
  }
  std::cout << std::endl;

  StackOnList st1;
  int val1(10);
  std::cout << "Let's push " << val1 << std::endl;
  st1.Push(val1);
  std::cout << "Stack1 is " << st1 << std::endl;
  std::cout << "Is stack1 empty -> " << st1.IsEmpty() << std::endl;
  std::cout << "Top value is " << st1.Top() << std::endl;
  std::cout << std::endl;

  std::cout << "Let's pop" << std::endl;
  st1.Pop();
  std::cout << "Stack1 is " << st1 << std::endl;
  std::cout << "Is stack1 empty -> " << st1.IsEmpty() << std::endl;
  std::cout << std::endl;

  std::cout << "Let's push values from " << (val1 + 1)
                               << " to " << (val1 + 3) << std::endl;
  st1.Push(val1 + 1);
  st1.Push(val1 + 2);
  st1.Push(val1 + 3);
  std::cout << "Stack1 is " << st1 << std::endl;
  std::cout << "Top value is " << st1.Top() << std::endl;
  std::cout << std::endl;

  StackOnList st2(st1);
  std::cout << "Let's create copy of stack1. Stack2 is " << st2 << std::endl;
  std::cout << "Is stack2 empty -> " << st2.IsEmpty() << std::endl;
  std::cout << "Top value of stack2 is " << st2.Top() << std::endl;
  int val2(14);
  std::cout << "Let's push " << val2 << std::endl;
  st2.Push(val2);
  std::cout << "Stack2 is " << st2 << std::endl;
  std::cout << std::endl;

  StackOnList st3;
  std::cout << "Stack3 is " << st3 << std::endl;
  st3 = st1;
  std::cout << "Let's do stack3 = stack1. Stack3 is " << st3 << std::endl;
  std::cout << "Is stack3 empty -> " << st3.IsEmpty() << std::endl;
  std::cout << "Top value of stack3 is " << st3.Top() << std::endl;
  std::cout << "Let's pop" << std::endl;
  st3.Pop();
  std::cout << "Stack3 is " << st3 << std::endl;
  std::cout << std::endl;

  std::cout << "Let's do stack1 = stack2 = stack3 -> " << std::endl;
  st1 = st2 = st3;
  std::cout << "Stack1 is " << st1 << std::endl;
  std::cout << "Stack2 is " << st2 << std::endl;
  std::cout << "Stack3 is " << st3 << std::endl;

  return 0;
}
