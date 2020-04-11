#include "Stack.hpp"
#include <iostream>

bool push(Stack &s, int value) {
  if (s.index == 100) {
    return false;
  }
  s.array[s.index++] = value;
  return true;
}

std::pair<int, bool> pop(Stack &s) {
  if (s.index == 0) {
    return {0, false};
  }
  return {s.array[--s.index], true};
}

void clear(Stack &s) {
  if (s.index == 0) {
    return;
  }
  s.index = 0;
}

bool empty(Stack &s) { return s.index == 0; }

size_t GetStackSize(Stack &s) { return s.kSize; }

std::pair<int, bool> top(Stack &s) {
  if (s.index == 0) {
    return {0, false};
  }
  return {s.array[s.index - 1], true};
}

std::pair<int, bool> GetStackLength(Stack &s) {
  if (s.index == 0) {
    return {0, false};
  }
  int count{0};
  size_t virt_index{s.index};
  while (virt_index-- != 0) {
    count++;
  }
  return {count, true};
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

int find(Stack &s, int value) {
  if (empty(s)) {
    return 0;
  }
  size_t virt_index{s.index};
  while (virt_index != 0) {
    --virt_index;
    if (virt_index == 0 && s.array[virt_index] != value) {
      std::cout << "\nNot found\n";
      return virt_index;
    }
    if (s.array[virt_index] == value) {
      std::cout << "\nFound. The index of this element in stack is "
                << virt_index << std::endl;
      return s.array[virt_index];
    }
  }
  return virt_index;
}
