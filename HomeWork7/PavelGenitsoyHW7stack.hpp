#pragma once
#include <iostream>

template <typename T1, typename T2> class Stack {
public:
  T2 push(T1 value);
  T2 pop();
  void clear();
  T2 empty() const;
  T1 top();
  size_t GetStackLength() const;
  void print() const;

private:
  static const auto kMax_Size_of_stack{100};
  size_t index{};
  T1 array[kMax_Size_of_stack]{};
};

template <typename T1, typename T2> T2 Stack<T1, T2>::push(T1 value) {
  if (index == kMax_Size_of_stack) {
    return false;
  }
  array[index++] = value;
  return true;
}

template <typename T1, typename T2> T2 Stack<T1, T2>::pop() {
  if (index == 0) {
    return false;
  }
  --index;
  std::cout << __FUNCTION__ << std::endl;
  return true;
}

template <typename T1, typename T2> void Stack<T1, T2>::clear() {
  index = 0;
  std::cout << __FUNCTION__ << std::endl;
}

template <typename T1, typename T2> T2 Stack<T1, T2>::empty() const {
  return index == 0;
}

template <typename T1, typename T2> T1 Stack<T1, T2>::top() {
  if (index == 0) {
    return 0;
  }
  return array[index - 1];
}

template <typename T1, typename T2>
size_t Stack<T1, T2>::GetStackLength() const {
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

template <typename T1, typename T2> void Stack<T1, T2>::print() const {
  if (empty()) {
    return;
  }
  size_t virt_index{index};
  while (virt_index != 0) {
    std::cout << array[--virt_index] << " ";
  }
  std::cout << std::endl;
}
