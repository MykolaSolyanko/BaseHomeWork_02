#pragma once
#include "Common_TS_HW7.hpp"

template <typename T>
struct layer {
  T inf{};
  layer<T> *next{nullptr};
};

template <typename T>
class Stack {
 public:
  Stack();
  Stack(const size_t size);
  ~Stack();

  bool push(const T value);
  result<T> top();
  result<T> pop();

  void clear();

  bool isEmpty() const;
  bool isFull() const;

  size_t getCount() const;
  size_t getMaxSize() const;

 private:
  const size_t k_max_size{k_defult_max_size};
  size_t count{0};
  T *Layers;
};

template <typename T>
Stack<T>::Stack() {
  Layers<T> = new T[k_max_size]{};
};

template <typename T>
Stack<T>::Stack(const size_t size) : k_max_size{size} {
  Stack();
};

template <typename T>
Stack<T>::~Stack() {
  delete[] Layers;
}

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
    // return {{nullptr},false};  // error: no matching constructor for
    // initialization of 'result' (aka 'pair<int, bool>')
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

template <typename T>
void Stack<T>::clear() {
  count = 0;
}

template <typename T>
bool Stack<T>::isEmpty() const {
  return count == 0;
}

template <typename T>
bool Stack<T>::isFull() const {
  return count == k_max_size;
}

template <typename T>
size_t Stack<T>::getCount() const {
  return count;
}

template <typename T>
size_t Stack<T>::getMaxSize() const {
  return k_max_size;
}
