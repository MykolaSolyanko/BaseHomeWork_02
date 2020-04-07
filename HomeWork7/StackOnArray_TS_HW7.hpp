#pragma once
#include <iostream>

template <typename T>
using result = std::pair<T, bool>;

static const size_t k_defult_stack_max_size{100};

template <typename T>
struct layer {
  T inf{};
  layer<T> *next{nullptr};
};

template <typename T>
class Stack {
 public:
  Stack() = default;
  Stack(const size_t size) : k_max_size{size} {};
  ~Stack() { delete[] Layers; };

  bool push(const T value);
  result<T> top();
  result<T> pop();

  void clear() { count = 0; };

  bool isEmpty() const { return count == 0; };
  bool isFull() const { return count == k_max_size; };

  size_t getCount() const { return count; };
  size_t getMaxSize() const { return k_max_size; };

 private:
  const size_t k_max_size{k_defult_stack_max_size};
  size_t count{0};
  T *Layers = new T[k_max_size]{};
};

template <typename T>
bool Stack<T>::push(const T value) {
  if (count == k_max_size) {
    return false;
  }
  Layers[count++] = value;
  return true;
}

template <typename T>
result<T> Stack<T>::top() {
  if (count == 0) {
    return {{}, false};
  }
  return {Layers[count - 1], true};
}

template <typename T>
result<T> Stack<T>::pop() {
  if (count == 0) {
    return {{}, false};
  }
  return {Layers[--count], true};
}