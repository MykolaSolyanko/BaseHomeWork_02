#pragma once
#include <utility>

struct Stack {
  static const size_t kSize{100};
  size_t index{};
  int array[kSize]{};
};

bool push(Stack &s, int value);
std::pair<int, bool> pop(Stack &s);
void clear(Stack &s);
bool empty(Stack &s);
size_t GetStackSize(Stack &s);
std::pair<int, bool> top(Stack &s);
std::pair<int, bool> GetStackLength(Stack &s);
void print(Stack &s);
int find(Stack &s, int value);
