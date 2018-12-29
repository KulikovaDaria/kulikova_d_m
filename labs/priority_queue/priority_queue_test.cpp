#include "priority_queue.h"
#include <iostream>
#include <sstream>
#include <exception>

int main() {
  PriorityQueue q_def;
  std::cout << "Let's create default queue. Queue is " << q_def << std::endl;
  std::cout << "Is def queue empty? -> " << q_def.IsEmpty() << std::endl;
  try {
    std::cout << "Let's try to get top from def queue -> " << std::endl;
    q_def.Top();
  }
  catch(const std::logic_error& except) {
    std::cout << except.what() << std::endl;
  }
  std::cout << std::endl;

  PriorityQueue q1;
  int v1(1);
  int v2(5);
  int v3(2);
  std::cout << "let's push " << v1 << " with key " << v1 << ", " << v2
      << " with key " << v2 << ", " << v3 << " with key " << v3 << std::endl;
  q1.Push(v1, v1);
  q1.Push(v2, v2);
  q1.Push(v3, v3);
  std::cout << "Queue1 is " << q1 << std::endl;
  std::cout << "Is queue1 empty? -> " << q1.IsEmpty() << std::endl;
  std::cout << "Top value is " << q1.Top() << std::endl;
  std::cout << std::endl;

  PriorityQueue q2(q1);
  std::cout << "Let's create copy of queue1. Queue2 is " << q2 << std::endl;
  q2.Pop();
  std::cout << "Let's pop. Queue2 is " << q2 << std::endl;
  std::cout << "Top value is " << q2.Top() << std::endl;
  std::cout << std::endl;

  PriorityQueue q3;
  std::cout << "Queue3 is " << q3 << std::endl;
  q3 = q1;
  std::cout << "Let's do queue3 = queue1. Queue3 is " << q3 << std::endl;
  q3.Push(v2, v2);
  std::cout << "Let's push " << v2 << " with key " << v2 << "Queue3 is " << q3
      << std::endl;
  std::cout << std::endl;

  std::cout << "Queue1 is " << q1 << std::endl;
  std::cout << "Queue2 is " << q2 << std::endl;
  std::cout << "Queue3 is " << q3 << std::endl;
  q1 = q1;
  std::cout << "Let's do queue1 = queue1. Queue1 is " << q1 << std::endl;
  std::cout << "Let's do queue1 = queue2 = queue3." << std::endl;
  q1 = q2 = q3;
  std::cout << "Queue1 is " << q1 << std::endl;
  std::cout << "Queue2 is " << q2 << std::endl;
  std::cout << "Queue3 is " << q3 << std::endl;
  std::cout << std::endl;

  return 0;
}
