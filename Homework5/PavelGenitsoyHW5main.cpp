#include "Stack.hpp"
#include <iostream>

int main() {
  Stack s;
  if (empty(s)) {
    std::cout << "Stack is empty\n" << std::endl;
    ;
  }
  if (push(s, 5)) {
    std::cout << "push(5) was success\n" << std::endl;
  }
  if (push(s, 10)) {
    std::cout << "push(10) was success\n" << std::endl;
  }
  if (push(s, 20)) {
    std::cout << "push(10) was success\n" << std::endl;
  }

  std::cout << "Length of stack: " << GetStackLength(s) << std::endl;

  std::cout << "\nContent of stack: ";
  print(s);

  std::cout << "\nValue from top: " << top(s) << std::endl;

  pop(s);
  std::cout << "\nContent of stack: ";
  print(s);

  clear(s);

  system("pause");
  return 0;
}
