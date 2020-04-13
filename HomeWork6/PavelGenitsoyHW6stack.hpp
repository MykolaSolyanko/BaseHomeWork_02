#pragma once

class Stack {
public:
  bool push(int value);
  bool pop();
  void clear();
  bool empty() const;
  int top();
  size_t GetStackLength();
  void print() const;

private:
  static const size_t kSize{100};
  size_t index{};
  int array[kSize]{};
};
