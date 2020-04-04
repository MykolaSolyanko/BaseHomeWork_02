#pragma once
#include "Common_TS_HW6.hpp"
// the queue is based on a bidirectional list

struct node2directions {
  int Inf{};
  node2directions *next{nullptr};
  node2directions *prev{nullptr};
};

class Queue {
 public:
  Queue(const size_t size);
  Queue();
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
