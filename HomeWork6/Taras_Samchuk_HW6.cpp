#include <iostream>

#include "Classic_TS_HW6.hpp"
int main(int argc, char const *argv[]) {
  /* code */
  // Demo.printQueueFront();
  // {
  //   Stack Demo(11);
  //   Demo.push(1);
  //   Demo.push(2);
  //   Demo.push(3);
  //   Demo.push(4);
  //   Demo.push(5);
  //   Demo.push(6);
  //   Demo.push(7);
  //   Demo.push(8);
  //   Demo.push(9);
  //   Demo.push(10);
  //   Demo.push(11);
  //   Demo.printAll();
  //   Demo.swap();
  //   Demo.printAll();
  // }
  {
    Equeue Demo(6);
    Demo.printAllBackward();
    Demo.printAllForward();
    Demo.enqueue(1);
    Demo.enqueue(2);
    Demo.enqueue(3);
    Demo.enqueue(4);
    Demo.enqueue(5);
    Demo.enqueue(6);
    Demo.enqueue(7);
    Demo.enqueue(8);
    Demo.enqueue(9);
    Demo.enqueue(10);
    Demo.enqueue(11);
    Demo.printAllBackward();
    Demo.printAllForward();
    Demo.swap();

    Demo.printAllBackward();
    Demo.printAllForward();
  }
  // Stack Demo2(Demo);
  // Demo2.printAll();
  // std::cout << Demo.getCount() << std::endl
  //           << Demo.top().first << std::endl;
  return 0;
}
