#include "Stack.hpp"
#include <iostream>

int main() {
  Stack s(50);
  if (s.empty()) {
    std::cout << "\nStack is empty\n";
  }

  std::cout << "\nSize (constant) of stack: " << s.GetStackSize() << std::endl;

  if (auto [value, status] = s.top(); status == true) {
    std::cout << value << std::endl;
  } else {
    std::cout << "\nerror top\n" << std::endl;
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
  if (auto [value, status] = s.GetStackLength(); status == true) {
    std::cout << "Length of stack: " << value << std::endl;
  }
  std::cout << "\nContent of stack: ";
  s.print();
  if (auto [value, status] = s.top(); status == true) {
    std::cout << "\nValue from top: " << value << std::endl;
  }
  if (auto [value, status] = s.pop(); status == true) {
    std::cout << "\nValue which we deleted from stack: " << value << std::endl;
  }
  std::cout << "\nContent of stack: ";
  s.print();
  if (auto [value, status] = s.top(); status == true) {
    std::cout << "\nValue from top: " << value << std::endl;
  }
  std::cout << "\nWe want to find the element [10] int the stack: ";
  s.find(10);
  std::cout << "\nWe want to find the element [15] int the stack: ";
  s.find(15);

  system("pause");
  return 0;
}
