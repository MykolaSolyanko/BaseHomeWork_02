#include <iostream>

class Queue {
public:
  bool is_empty();
  void push(int elmnt);
  int pop();
  void clear();
  const int get_qsize();
  const int get_qcapacity();
  const int get_first_elmnt();
  ~Queue();

private:
  static const int qSize{1000};
  int *queue_str = new int[qSize];
  int first_pos{0};
  int last_pos{0};
};

Queue::~Queue() { delete[] queue_str; };
bool Queue::is_empty() { return (last_pos == 0) && (first_pos == 0); }
void Queue::push(int elmnt) {
  if (last_pos < qSize) {
    queue_str[last_pos++] = elmnt;
  } else {
    std::cout << " Queue is full. " << std::endl;
  }
};
int Queue::pop() {
  if (is_empty()) {
    std::cout << "Queue is empty" << std::endl;
    return 0;
  }
  int elmnt = queue_str[first_pos];
  for (int i = first_pos; i < last_pos; ++i) {
    queue_str[i] = queue_str[i + 1];
  }
  last_pos--;
  return elmnt;
}
void Queue::clear() {
  first_pos = 0;
  last_pos = 0;
}

const int Queue::get_qsize() { return last_pos; }
const int Queue::get_qcapacity() { return qSize; }
const int Queue::get_first_elmnt() {
  if (is_empty()) {
    std::cout << "Queue is empty." << std::endl;
    return 0;
  } else {
    return queue_str[first_pos];
  }
}

int main() {
  Queue q1;
  std::cout << q1.get_qcapacity() << std::endl;
  q1.push(10);
  q1.push(20);
  q1.push(30);
  std::cout << "Queue is empty? " << q1.is_empty() << std::endl;
  std::cout << "Get size: " << q1.get_qsize() << std::endl;
  std::cout << "1st element" << q1.get_first_elmnt() << std::endl;
  q1.pop();
  q1.clear();

  return 0;
}
