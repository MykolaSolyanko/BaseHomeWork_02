#include <iostream>

using str = char[25];

#include "Classic_TS_HW7.hpp"
int main(int argc, char const *argv[]) {
  /* code */
  // Demo.printQueueFront();
  Stack<str> DemoStack(11);
  DemoStack.push("'1'");
  DemoStack.push("'2'");
  DemoStack.push("'3'");
  DemoStack.push("'4'");
  DemoStack.push("'5'");
  DemoStack.push("'6'");
  DemoStack.push("'7'");
  DemoStack.push("'8'");
  DemoStack.push("'9'");
  // DemoStack.push(10);
  // DemoStack.push(11);
  DemoStack.printAll();
  DemoStack.swap();
  DemoStack.printAll();
  // Stack Demo2(DemoStack);
  // Demo2.printAll();
  // std::cout << DemoStack.getCount() << std::endl
  //           << DemoStack.top().first << std::endl;
  return 0;
}
