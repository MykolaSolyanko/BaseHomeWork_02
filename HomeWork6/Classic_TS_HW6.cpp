#include "Classic_TS_HW6.hpp"

#include <iostream>

static const char k_mes_head[]{"}"};
static const char k_mes_empty[]{"empty"};
static const char k_mes_arrow[]{"=>"};
static const char k_mes_nullptr[]{"]"};
Stack::Stack() { Stack::head = new layer; }

Stack::Stack(const size_t size) : k_max_size{size} { Stack::head = new layer; }

// Stack::Stack(const Stack &Stack) = delete;

Stack::~Stack() {
  if (count != 0) {
    clear();
  }
  delete Stack::head;
}

bool Stack::push(const int value) {
  if (count == k_max_size) {
    return false;
  }
  layer *NewLayer = new layer;
  NewLayer->inf = value;
  NewLayer->next = head->next;
  head->next = NewLayer;
  count++;
  return true;
}

result Stack::top() {
  if (count == 0) {
    return {{}, false};
  }
  return {head->next->inf, true};
}

result Stack::pop() {
  if (head->next == nullptr) {
    return {{}, false};
  }
  layer *to_delete = head->next;
  layer *hold = to_delete->next;
  delete to_delete;
  head->next = hold;
  count--;
  return {hold->inf, true};
}

void Stack::clear() {
  if (count == 0) {
    return;
  }
  layer *arrow = head;
  while (arrow != nullptr) {
    layer *hold = arrow;
    arrow = arrow->next;
    delete hold;
  };
  count = 0;
}

bool Stack::swap() {
  if (head->next == nullptr || head->next->next == nullptr) {
    return false;
  }
  layer *first = head->next;
  layer *second = first->next;
  layer *hold = second->next;

  head->next = second;
  second->next = first;
  first->next = hold;
  return true;
}

bool Stack::printAll() const {
  std::cout << k_mes_head;
  if (head == nullptr) {
    std::cout << k_mes_empty << k_mes_nullptr << std::endl;
    return false;
  }
  layer *arrow = head->next;
  while (arrow != nullptr) {
    std::cout << arrow->inf << k_mes_arrow;
    arrow = arrow->next;
  }
  std::cout << k_mes_nullptr << std::endl;
  return true;
}

bool Stack::isEmpty() const { return count == 0; }

bool Stack::isFull() const { return count == k_max_size; }

size_t Stack::getCount() const { return count; }

size_t Stack::getMaxSize() const { return k_max_size; }