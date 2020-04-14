#include <iostream>
const size_t qSize = 100;

struct Queue {
  int *queue_str = new int[qSize];
  int first_pos;
  int last_pos;
};

void create_q(Queue &q) {
  q.first_pos = 0;
  q.last_pos = 0;
};
bool is_q_empty(Queue &q) { return (q.last_pos == 0) && (q.first_pos == 0); }

void push_q_elmnt(Queue &q, int elmnt) {
  if (q.last_pos < qSize - 1) {
    q.queue_str[q.last_pos++] = elmnt;
  } else {
    std::cout << " Queue is full. " << std::endl;
  }
};
int pop_q_elmnt(Queue &q) {
  if (is_q_empty(q)) {
    std::cout << "Queue is empty" << std::endl;
    return 0;
  }
  int elmnt = q.queue_str[q.first_pos];
  for (int i = q.first_pos; i < q.last_pos - 1; ++i) {
    q.queue_str[i] = q.queue_str[i + 1];
  }
  q.last_pos--;
  return elmnt;
}
void delete_q(Queue &q) { delete[] q.queue_str; };
int main() {
  Queue q1;
  create_q(q1);
  std::cout << is_q_empty(q1) << std::endl;
  push_q_elmnt(q1, 10);
  push_q_elmnt(q1, 20);
  std::cout << pop_q_elmnt(q1) << std::endl;
  push_q_elmnt(q1, 30);
  push_q_elmnt(q1, 40);
  std::cout << pop_q_elmnt(q1) << std::endl;
  delete_q(q1);
}
