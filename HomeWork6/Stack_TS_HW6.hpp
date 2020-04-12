// stack is based on a unidirectional list
#pragma once
#include <iostream>

static const unsigned k_defult_max_stack_size{100};

using result = std::pair<int, bool>;

struct layer {
  int inf{};
  layer *next{nullptr};
};

class Stack {
 public:
  Stack() = default;
  Stack(const size_t size) : k_max_size{size} {};
  ~Stack();

  bool push(const int value);
  result top();
  result pop();

  void clear();

  bool isEmpty() const;
  bool isFull() const;

  size_t getCount() const;
  size_t getMaxSize() const;

 private:
  layer *head{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_max_stack_size};
};
