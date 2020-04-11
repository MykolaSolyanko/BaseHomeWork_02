#include "Stack.hpp"
#include <iostream>

Stack::Stack(size_t size) : kSize(size) { array = new int[kSize]{}; }

Stack::~Stack() { delete[] array; }

bool Stack::push(int value) {
  if (index == 100) {
    return false;
  }
  array[index++] = value;
  return true;
}

std::pair<int, bool> Stack::pop() {
  if (index == 0) {
    return {0, false};
  }
  return {array[--index], true};
}

void Stack::clear() {
  if (index == 0) {
    return;
  }
  index = 0;
}

bool Stack::empty() const { return index == 0; }

size_t Stack::GetStackSize() { return kSize; }

std::pair<int, bool> Stack::top() {
  if (index == 0) {
    return {0, false};
  }
  return {array[index - 1], true};
}

std::pair<int, bool> Stack::GetStackLength() {
  if (index == 0) {
    return {0, false};
  }
  int count{0};
  size_t virt_index{index};
  while (virt_index-- != 0) {
    count++;
  }
  return {count, true};
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

int Stack::find(int value) {
  if (empty()) {
    return 0;
  }
  size_t virt_index{index};
  while (virt_index != 0) {
    --virt_index;
    if (virt_index == 0 && array[virt_index] != value) {
      std::cout << "\nNot found\n";
      return virt_index;
    }
    if (array[virt_index] == value) {
      std::cout << "\nFound. The index of this element in stack is "
                << virt_index << std::endl;
      return array[virt_index];
    }
  }
  return virt_index;
}
