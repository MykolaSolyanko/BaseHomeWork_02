#include "Stack.hpp"
#include <iostream>

int main() {
  Stack<int, bool> s;
  if (s.empty()) {
    std::cout << "Stack is empty\n" << std::endl;
  }
  if (s.push(5)) {
    std::cout << "push(5) was success\n" << std::endl;
  }
  if (s.push(10)) {
    std::cout << "push(10) was success\n" << std::endl;
  }
  if (s.push(20)) {
    std::cout << "push(10) was success\n" << std::endl;
  }

  std::cout << "Length of stack: " << s.GetStackLength() << std::endl;

  std::cout << "\nContent of stack: ";
  s.print();

  std::cout << "\nValue from top: " << s.top() << std::endl;

  s.pop();
  std::cout << "\nContent of stack: ";
  s.print();

  s.clear();

  system("pause");
  return 0;
}
