#pragma once
#include <iostream>
#include <utility>

template <typename T1, typename T2> class Stack {
public:
  Stack() = default;
  Stack(size_t size);
  ~Stack();
  T2 push(T1 value);
  std::pair<T1, T2> pop();
  void clear();
  T2 empty() const;
  size_t GetStackSize() const;
  std::pair<T1, T2> top();
  std::pair<T1, T2> GetStackLength() const;
  void print() const;
  T1 find(T1 value);

private:
  const size_t kSize{100};
  size_t index{};
  T1 *array{nullptr};
};

template <typename T1, typename T2>
Stack<T1, T2>::Stack(size_t size) : kSize(size) {
  array = new T1[kSize]{};
}

template <typename T1, typename T2> Stack<T1, T2>::~Stack() { delete[] array; }

template <typename T1, typename T2> T2 Stack<T1, T2>::push(T1 value) {
  if (index == 100) {
    return false;
  }
  array[index++] = value;
  return true;
}

template <typename T1, typename T2> std::pair<T1, T2> Stack<T1, T2>::pop() {
  if (index == 0) {
    return {0, false};
  }
  return {array[--index], true};
}

template <typename T1, typename T2> void Stack<T1, T2>::clear() {
  if (index == 0) {
    return;
  }
  index = 0;
}

template <typename T1, typename T2> T2 Stack<T1, T2>::empty() const {
  return index == 0;
}

template <typename T1, typename T2> size_t Stack<T1, T2>::GetStackSize() const {
  return kSize;
}

template <typename T1, typename T2> std::pair<T1, T2> Stack<T1, T2>::top() {
  if (index == 0) {
    return {0, false};
  }
  return {array[index - 1], true};
}

template <typename T1, typename T2>
std::pair<T1, T2> Stack<T1, T2>::GetStackLength() const {
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

template <typename T1, typename T2> T1 Stack<T1, T2>::find(T1 value) {
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
