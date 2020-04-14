// stack is based on a unidirectional list
#include "Stack_TS_HW6.hpp"

Stack::~Stack() {
  if (count != 0) {
    clear();
  }
  delete head;
}

bool Stack::push(const int value) {
  if (count == k_max_size) {
    return false;
  }
  layer *NewLayer = new layer{value, head};
  head = NewLayer;
  count++;
  return true;
}

result Stack::top() {
  if (count == 0) {
    // return {{nullptr},false};  // error: no matching constructor for
    // initialization of 'result' (aka 'pair<int, bool>')
    return {{}, false};
  }
  return {head->inf, true};
}

result Stack::pop() {
  if (head == nullptr) {
    return {{}, false};
  }
  layer *hold = head->next;
  delete head;
  head = hold;
  count--;
  return {hold->inf, true};
}

void Stack::clear() {
  if (count == 0) {
    return;
  }
  while (head != nullptr) {
    layer *hold = head;
    head = head->next;
    delete hold;
  };
  head = nullptr;
  count = 0;
}

bool Stack::isEmpty() const { return count == 0; }

bool Stack::isFull() const { return count == k_max_size; }

size_t Stack::getCount() const { return count; }

size_t Stack::getMaxSize() const { return k_max_size; }
