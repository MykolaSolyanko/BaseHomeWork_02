// stack is based on a unidirectional list
#pragma once
#include "Common_TS_HW6.hpp"

struct layer {
  int inf{};
  layer *next{nullptr};
};

class Stack {
 public:
  Stack() = default;
  Stack(const size_t size) : k_max_size{size} {};
  ~Stack() { delete[] Layers; };

  bool push(const int value);
  result top();
  result pop();

  void clear();

  bool isEmpty() const;
  bool isFull() const;

  size_t getCount() const;
  size_t getMaxSize() const;

 private:
  const size_t k_max_size{k_defult_max_size};
  size_t count{0};
  int *Layers = new int[k_max_size];
};