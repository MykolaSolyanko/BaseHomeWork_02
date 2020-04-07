// stack is based on a unidirectional list
#pragma once
#include <iostream>

template <typename T>
using result = std::pair<T, bool>;

const size_t k_defult_max_size{100};

template <typename T>
struct layer {
  T inf{};
  layer<T> *next{nullptr};
};

template <typename T>
class Stack {
 public:
  Stack() = default;
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
  layer<T> *head{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_max_size};
};

template <typename T>
Stack<T>::Stack(const size_t size) : k_max_size{size} {};

template <typename T>
Stack<T>::~Stack() {
  if (count != 0) {
    clear();
  }
  delete head;
}

template <typename T>
bool Stack<T>::push(const T value) {
  if (count == k_max_size) {
    return false;
  }
  layer<T> *NewLayer = new layer<T>{value, head};
  head = NewLayer;
  count++;
  return true;
}

template <typename T>
result<T> Stack<T>::top() {
  if (count == 0) {
    return {{}, false};
  }
  return {head->inf, true};
}

template <typename T>
result<T> Stack<T>::pop() {
  if (head == nullptr) {
    return {{}, false};
  }
  layer<T> *to_delete = head;
  layer<T> *hold = to_delete->next;
  delete to_delete;
  head = hold;
  count--;
  return {hold->inf, true};
}

template <typename T>
void Stack<T>::clear() {
  if (count == 0) {
    return;
  }
  layer<T> *arrow = head;
  while (arrow != nullptr) {
    layer<T> *hold = arrow;
    arrow = arrow->next;
    delete hold;
  };
  head = nullptr;
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
