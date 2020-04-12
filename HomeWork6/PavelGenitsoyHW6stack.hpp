#pragma once
#include <utility>

class Stack {
public:
  Stack(size_t size);
  ~Stack();
  bool push(int value);
  std::pair<int, bool> pop();
  void clear();
  bool empty() const;
  size_t GetStackSize() const;
  std::pair<int, bool> top();
  std::pair<int, bool> GetStackLength() const;
  void print() const;
  int find(int value);

private:
  const size_t kSize{100};
  size_t index{};
  int *array{nullptr};
};
