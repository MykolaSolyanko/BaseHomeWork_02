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
  Stack(const size_t size) : k_max_size{size} {};
  ~Stack() {
    if (count != 0) {
      clear();
    }
    delete head;
  };

  bool push(const T value);
  result<T> top();
  result<T> pop();

  void clear();

  bool isEmpty() const { return count == 0; };
  bool isFull() const { return count == k_max_size; };

  size_t getCount() const { return count; };
  size_t getMaxSize() const { return k_max_size; };

 private:
  layer<T> *head{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_max_size};
};

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
  layer<T> *hold = head->next;
  delete head;
  head = hold;
  count--;
  return {hold->inf, true};
}

template <typename T>
void Stack<T>::clear() {
  if (count == 0) {
    return;
  }
  while (head != nullptr) {
    layer<T> *hold = head;
    head = head->next;
    delete hold;
  };
  head = nullptr;
  count = 0;
}
