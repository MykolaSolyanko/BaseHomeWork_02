#pragma once

struct Stack {
  static const size_t kSize{100};
  size_t index{};
  int array[kSize]{};
};

bool push(Stack &s, int value);
bool pop(Stack &s);
void clear(Stack &s);
bool empty(Stack &s);
int top(Stack &s);
size_t GetStackLength(Stack &s);
void print(Stack &s);
