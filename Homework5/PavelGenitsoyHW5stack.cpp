#include "Stack.hpp"
#include <iostream>

static const auto kMax_Size_of_stack{100};

bool push(Stack &s, int value) {
  if (s.index == kMax_Size_of_stack) {
    return false;
  }
  s.array[s.index++] = value;
  return true;
}

bool pop(Stack &s) {
  if (s.index == 0) {
    return false;
  }
  --s.index;
  std::cout << __FUNCTION__ << std::endl;
  return true;
}

void clear(Stack &s) {
  s.index = 0;
  std::cout << __FUNCTION__ << std::endl;
}

bool empty(Stack &s) { return s.index == 0; }

int top(Stack &s) {
  if (s.index == 0) {
    return 0;
  }
  return s.array[s.index - 1];
}

size_t GetStackLength(Stack &s) {
  if (s.index == 0) {
    return 0;
  }
  int count{0};
  size_t virt_index{s.index};
  while (virt_index-- != 0) {
    count++;
  }
  return count;
}

void print(Stack &s) {
  if (empty(s)) {
    return;
  }
  size_t virt_index{s.index};
  while (virt_index != 0) {
    std::cout << s.array[--virt_index] << " ";
  }
  std::cout << std::endl;
}
