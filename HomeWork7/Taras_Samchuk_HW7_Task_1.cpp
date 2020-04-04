#include <iostream>

#include "Queue_TS_HW7Template.hpp"
#include "StackOnArray_TS_HW7.hpp"
// #include "Stack_TS_HW7.hpp" //Such a stack is also entitled to life
int main(int argc, char const *argv[]) {
  Stack<float> Demo;
  std::cout << Demo.top().first << std::endl;
  Demo.push(1);
  std::cout << Demo.pop().first << std::endl;
  Demo.push(2);
  Demo.push(3);
  Demo.push(4);
  Demo.push(5);
  Demo.push(6);
  Demo.push(7);
  Demo.push(8);
  std::cout << Demo.pop().first << std::endl;
  Demo.push(9);
  Demo.push(10);
  Demo.push(11);
  Demo.pop();
  Demo.pop();
  Demo.pop();
  Demo.clear();

  Queue<int> Demo2;
  Demo2.enqueue(1.1);
  Demo2.enqueue(2.2);
  Demo2.enqueue(3.3);
  Demo2.enqueue(4.4);
  Demo2.enqueue(5.5);
  Demo2.enqueue(6.6);
  Demo2.enqueue(7.7);
  Demo2.enqueue(8.8);
  Demo2.enqueue(9.9);
  Demo2.enqueue(10.01);
  Demo2.enqueue(11.11);
  Demo2.dequeue();
  Demo2.dequeue();
  Demo2.dequeue();
  Demo2.clear();
  return 0;
}
return 0;
}
