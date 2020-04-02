#include "Queue_TS_HW6.hpp"
// the queue is based on a bidirectional list
Queue::Queue(size_t size) : k_max_size{size} {}

Queue::Queue() {}

Queue::~Queue() {
  if (count != 0) {
    clear();
  }
}

bool Queue::enqueue(int value) {
  if (count == k_max_size) {
    return false;
  }
  node2directions *last{nullptr};
  if (tail != nullptr) {
    last = tail;
  }

  node2directions *NewComponent = new node2directions{value, nullptr, tail};
  if (last != nullptr) {
    last->next = NewComponent;
  }
  tail = NewComponent;
  if (head == nullptr) {
    head = NewComponent;
  }
  count++;
  return true;
}

result Queue::peek() {
  if (count == 0) {
    return {{}, false};
  }
  return {head->next->Inf, true};
}

result Queue::dequeue() {
  if (head == nullptr) {
    return {{}, false};
  }
  node2directions *to_delete = head;
  node2directions *hold = to_delete->next;
  delete to_delete;
  head = hold;
  hold->prev = nullptr;
  count--;
  return {{hold->Inf}, true};
}

void Queue::clear() {
  if (count == 0) {
    return;
  }
  node2directions *arrow = head;
  head = nullptr;
  tail = nullptr;
  count = 0;
  while (arrow != tail) {
    node2directions *hold = arrow;
    arrow = arrow->next;
    delete hold;
  }
}

bool Queue::isEmpty() const { return count == 0; }

bool Queue::isFull() const { return count == k_max_size; }

size_t Queue::getCount() const { return count; }

size_t Queue::getMaxSize() const { return k_max_size; }