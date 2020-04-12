#pragma once
#include <iostream>
// the queue is based on a bidirectional list

using result = std::pair<int, bool>;

static unsigned const k_defult_max_size{100};

struct node2directions {
  int Inf{};
  node2directions *next{nullptr};
  node2directions *prev{nullptr};
};

class Queue {
 public:
  Queue(const size_t size) : k_max_size{size} {};
  Queue() = default;
  ~Queue();

  bool enqueue(const int value);
  result peek();
  result dequeue();

  void clear();

  bool isEmpty() const;
  bool isFull() const;

  size_t getCount() const;
  size_t getMaxSize() const;

 private:
  node2directions *head{nullptr};
  node2directions *tail{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_max_size};
};
