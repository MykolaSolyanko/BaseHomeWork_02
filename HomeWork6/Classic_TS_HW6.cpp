#include "Classic_TS_HW6.hpp"

#include <iostream>

static const char k_mes_head[]{"}"};
static const char k_mes_forward[]{"forward"};
static const char k_mes_backward[]{"backward"};
static const char k_mes_empty[]{"empty"};
static const char k_mes_arrow[]{"=>"};
static const char k_mes_double_arrow[]{"<=>"};
static const char k_mes_nullptr[]{"]"};
static const char k_mes_tail[]{"{"};

// stack is based on a unidirectional list
Stack::Stack() { head = new layer; }

Stack::Stack(const size_t size) : k_max_size{size} { head = new layer; }

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

// the queue is based on a bidirectional list

Equeue::Equeue() {
  Equeue::head = new node2directions;
  Equeue::tail = new node2directions;
}

Equeue::Equeue(size_t size) : k_max_size{size} {
  head = new node2directions;

  tail = new node2directions;
  head->next = tail;
  tail->prev = head;
}

Equeue::~Equeue() {
  if (count != 0) {
    // clear();
  }
  delete Equeue::head;
  delete Equeue::tail;
}

bool Equeue::enqueue(int value) {
  if (count == k_max_size) {
    return false;
  }
  node2directions *NewComponent = new node2directions;
  node2directions *first = head->next;
  NewComponent->save = value;
  NewComponent->next = first;
  NewComponent->prev = head;
  head->next = NewComponent;
  first->prev = NewComponent;
  return true;
}

result Equeue::peek() {
  if (count == 0) {
    return {{}, false};
  }
  return {head->next->save, true};
}

result Equeue::dequeue() {
  if (head->next == nullptr) {
    return {{}, false};
  }
  node2directions *to_delete = head->next;
  node2directions *hold = to_delete->next;
  delete to_delete;
  head->next = hold;
  hold->prev = head;
  count--;
  return {{hold->save}, true};
}

bool Equeue::printAllForward() const {
  std::cout << k_mes_forward << k_mes_head;
  if (head->next == tail) {
    std::cout << k_mes_empty << k_mes_tail << std::endl;
    return false;
  }
  node2directions *arrow = head->next;
  while (arrow->next != nullptr) {
    std::cout << k_mes_double_arrow;
    std::cout << (arrow->save);  //
    arrow = arrow->next;
  }
  std::cout << k_mes_double_arrow << k_mes_tail << std::endl;
  return true;
};

bool Equeue::printAllBackward() const {
  std::cout << k_mes_backward << k_mes_head;
  if (tail->prev == head) {
    std::cout << k_mes_empty << k_mes_tail << std::endl;
    return false;
  }
  node2directions *arrow = tail->prev;
  while (arrow->prev != nullptr) {
    std::cout << k_mes_double_arrow;
    std::cout << (arrow->save);  //
    arrow = arrow->prev;
  }
  std::cout << k_mes_double_arrow << k_mes_tail << std::endl;
  return true;
};

void Equeue::clear() {
  if (count == 0) {
    return;
  }
  node2directions *arrow = head->next;
  head->next = tail;
  tail->prev = head;
  count = 0;
  while (arrow != nullptr) {
    node2directions *hold = arrow;
    arrow = arrow->next;
    delete hold;
  }
}

bool Equeue::swap() {
  if (head->next == tail || head->next->next == tail) {
    return false;
  }

  node2directions *first = head->next;
  node2directions *second = first->next;
  node2directions *hold = second->next;

  head->next = second;
  second->next = first;
  first->next = hold;
  hold->prev = first;
  first->prev = second;
  second->prev = head;
  return true;
}

bool Equeue::isEmpty() const { return count == 0; }

bool Equeue::isFull() const { return count == k_max_size; }

size_t Equeue::getCount() const { return count; }

size_t Equeue::getMaxSize() const { return k_max_size; }