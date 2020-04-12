#pragma once
#include <iostream>

// the queue is based on a bidirectional list

template <typename T>
using result = std::pair<T, bool>;

static const size_t k_defult_queue_max_size{100};

template <typename T>
struct node2directions {
  T Inf{};
  node2directions<T> *next{nullptr};
  node2directions<T> *prev{nullptr};
};

template <typename T>
class Queue {
 public:
  Queue() = default;
  Queue(const size_t size) : k_max_size{size} {};
  ~Queue() {
    if (count != 0) {
      clear();
    }
  };

  bool enqueue(const T value);
  result<T> peek() {
    if (count == 0) {
      return {{}, false};
    }
    return {head->Inf, true};
  };
  result<T> dequeue();

  void clear();

  bool isEmpty() const { return count == 0; };
  bool isFull() const { return count == k_max_size; };

  size_t getCount() const { return count; };
  size_t getMaxSize() const { return k_max_size; };

 private:
  node2directions<T> *head{nullptr};
  node2directions<T> *tail{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_queue_max_size};
};

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
result<T> Queue<T>::dequeue() {
  if (head == nullptr) {
    return {{}, false};
  }
  node2directions<T> *hold = head->next;
  delete head;
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
  count = 0;
  while (arrow != tail) {
    node2directions<T> *hold = arrow;
    arrow = arrow->next;
    delete hold;
  }
  head = nullptr;
  tail = nullptr;
}