#pragma once
#include "Common_TS_HW7.hpp"
// the queue is based on a bidirectional list

template <typename T>
struct node2directions {
  T Inf{};
  node2directions *next<T>{nullptr};
  node2directions *prev<T>{nullptr};
};

template <typename T>
class Queue {
 public:
  Queue(const size_t size);
  Queue();
  Queue(Queue &) = delete;
  ~Queue();

  bool enqueue(const T value);
  result<T> peek();
  result<T> dequeue();

  void clear();

  bool isEmpty() const;
  bool isFull() const;

  size_t getCount() const;
  size_t getMaxSize() const;

 private:
  node2directions<T> *head{nullptr};
  node2directions<T> *tail{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_max_size};
};

template <typename T>
Queue<T>::Queue(size_t size) : k_max_size{size} {}

template <typename T>
Queue<T>::Queue() {}

template <typename T>
Queue<T>::~Queue() {
  if (count != 0) {
    clear();
  }
}

template <typename T>
bool Queue<T>::enqueue(T value) {
  if (count == k_max_size) {
    return false;
  }
  node2directions<T> *last{nullptr};
  if (tail != nullptr) {
    last = tail;
  }

  node2directions<T> *NewComponent =
      new node2directions<T>{value, nullptr, tail};
  if (last != nullptr) {
    last->next = NewComponent;
  }
  tail = NewComponent;
  if (head == nullptr) {
    head = NewComponent;
  }
  count++;
  return true;
}

template <typename T>
result<T> Queue<T>::peek() {
  if (count == 0) {
    return {{}, false};
  }
  return {head->Inf, true};
}

template <typename T>
result<T> Queue<T>::dequeue() {
  if (head == nullptr) {
    return {{}, false};
  }
  node2directions<T> *to_delete = head;
  node2directions<T> *hold = to_delete->next;
  delete to_delete;
  head = hold;
  hold->prev = nullptr;
  count--;
  return {{hold->Inf}, true};
}

template <typename T>
void Queue<T>::clear() {
  if (count == 0) {
    return;
  }
  node2directions<T> *arrow = head;
  head = nullptr;
  tail = nullptr;
  count = 0;
  while (arrow != tail) {
    node2directions<T> *hold = arrow;
    arrow = arrow->next;
    delete hold;
  }
}

template <typename T>
bool Queue<T>::isEmpty() const {
  return count == 0;
}

template <typename T>
bool Queue<T>::isFull() const {
  return count == k_max_size;
}

template <typename T>
size_t Queue<T>::getCount() const {
  return count;
}

template <typename T>
size_t Queue<T>::getMaxSize() const {
  return k_max_size;
}