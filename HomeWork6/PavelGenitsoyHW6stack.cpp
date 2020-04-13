#include "Stack.hpp"
#include <iostream>

static const auto kMax_Size_of_stack{100};

bool Stack::push(int value) {
  if (index == kMax_Size_of_stack) {
    return false;
  }
  array[index++] = value;
  return true;
}

bool Stack::pop() {
  if (index == 0) {
    return false;
  }
  --index;
  std::cout << __FUNCTION__ << std::endl;
  return true;
}

void Stack::clear() {
  index = 0;
  std::cout << __FUNCTION__ << std::endl;
}

bool Stack::empty() const { return index == 0; }

int Stack::top() {
  if (index == 0) {
    return 0;
  }
  return array[index - 1];
}

size_t Stack::GetStackLength() {
  if (index == 0) {
    return 0;
  }
  int count{0};
  size_t virt_index{index};
  while (virt_index-- != 0) {
    count++;
  }
  return count;
}

void Stack::print() const {
  if (empty()) {
    return;
  }
  size_t virt_index{index};
  while (virt_index != 0) {
    std::cout << array[--virt_index] << " ";
  }
  std::cout << std::endl;
}
