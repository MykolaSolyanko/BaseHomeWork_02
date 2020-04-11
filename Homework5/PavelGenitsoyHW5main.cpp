#include "Stack.hpp"
#include <iostream>

int main() {
  Stack s;
  if (empty(s)) {
    std::cout << "Stack is empty\n";
  }

  std::cout << "\nSize (constant) of stack: " << GetStackSize(s) << std::endl;

  if (auto [value, status] = top(s); status == true) {
    std::cout << value << std::endl;
  } else {
    std::cout << "\nerror top\n" << std::endl;
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
  if (auto [value, status] = GetStackLength(s); status == true) {
    std::cout << "Length of stack: " << value << std::endl;
  }
  std::cout << "\nContent of stack: ";
  print(s);
  if (auto [value, status] = top(s); status == true) {
    std::cout << "\nValue from top: " << value << std::endl;
  }
  if (auto [value, status] = pop(s); status == true) {
    std::cout << "\nValue which we deleted from stack: " << value << std::endl;
  }
  std::cout << "\nContent of stack: ";
  print(s);
  if (auto [value, status] = top(s); status == true) {
    std::cout << "\nValue from top: " << value << std::endl;
  }
  std::cout << "\nWe want to find the element [10] int the stack: ";
  find(s, 10);
  std::cout << "\nWe want to find the element [15] int the stack: ";
  find(s, 15);

  system("pause");
  return 0;
}
