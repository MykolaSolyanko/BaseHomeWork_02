#include "StackOnArray_TS_HW6.hpp"

Stack::Stack() { Layers = new int[k_max_size]{}; };

Stack::Stack(const size_t size) : k_max_size{size} { Stack(); };

Stack::~Stack() { delete[] Layers; }

bool Stack::push(const int value) {
  if (count == k_max_size) {
    return false;
  }
  Layers[count++] = value;
  return true;
}

result Stack::top() {
  if (count == 0) {
    // return {{nullptr},false};  // error: no matching constructor for
    // initialization of 'result' (aka 'pair<int, bool>')
    return {{}, false};
  }
  return {Layers[count - 1], true};
}

result Stack::pop() {
  if (count == 0) {
    return {{}, false};
  }
  return {Layers[--count], true};
}

void Stack::clear() { count = 0; }

bool Stack::isEmpty() const { return count == 0; }

bool Stack::isFull() const { return count == k_max_size; }

size_t Stack::getCount() const { return count; }

size_t Stack::getMaxSize() const { return k_max_size; }
