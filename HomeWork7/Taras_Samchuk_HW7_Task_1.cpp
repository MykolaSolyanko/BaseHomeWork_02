// #include <iostream>

#include <string>

#include "Classic_TS_HW7.hpp"
int main(int argc, char const *argv[]) {
  Stack<short> Demo(11);
  Demo.push(1);
  Demo.push(2);
  Demo.push(3);
  Demo.push(4);
  Demo.push(5);
  Demo.push(6);
  Demo.push(7);
  Demo.push(8);
  Demo.push(9);
  Demo.push(10);
  Demo.push(11);
  Demo.printAll();
  Demo.swap();
  Demo.printAll();
  Demo.clear();

  Equeue<double> Demo2;
  Demo2.printAllBackward();
  Demo2.printAllForward();
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
  Demo2.printAllBackward();
  Demo2.printAllForward();
  Demo2.swap();
  Demo2.printAllBackward();
  Demo2.clear();
  Demo2.printAllForward();

  return 0;
}
