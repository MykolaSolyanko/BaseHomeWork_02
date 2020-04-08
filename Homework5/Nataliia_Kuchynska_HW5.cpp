#include <iostream>
const size_t qSize = 100;

struct Queue {
  int queue_str[qSize];
  int first_pos;
  int last_pos;
};

void create_q(struct Queue &q) {
  q.first_pos = 1;
  q.last_pos = 0;
};
bool is_q_empty(struct Queue &q) {
  return ((q.last_pos < q.first_pos) ? 1 : 0);
}

void push_q_elmnt(struct Queue &q, int elmnt) {
  if (q.last_pos < qSize - 1) {
    q.last_pos++;
    q.queue_str[q.last_pos] = elmnt;
  } else {
    std::cout << " Queue is full. " << std::endl;
  }
};
int pop_q_elmnt(struct Queue &q) {
  if (is_q_empty(q)) {
    std::cout << "Queue is empty" << std::endl;
    return 0;
  }
  int elmnt = q.queue_str[q.first_pos];
  for (int i = q.first_pos; i < q.last_pos; ++i) {
    q.queue_str[i] = q.queue_str[i + 1];
  }
  q.last_pos--;
  return elmnt;
}

void print_q(struct Queue &q) {
  if (is_q_empty(q)) {
    std::cout << "Queue is empty. No elements to print. " << std::endl;
  } else {
    std::cout << "queue state " << std::endl;
    for (int i = q.first_pos; i <= q.last_pos; ++i)
      std::cout << q.queue_str[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  Queue q1;
  create_q(q1);
  std::cout << is_q_empty(q1) << std::endl;
  push_q_elmnt(q1, 10);
  push_q_elmnt(q1, 20);
  print_q(q1);
  pop_q_elmnt(q1);
  print_q(q1);
  pop_q_elmnt(q1);
  print_q(q1);
}
