#include <iostream>

class queue {
public:
  bool is_empty();
  void push(int elmnt);
  int pop();
  void clear();
  const void print();
  const int get_qsize();
  const int get_MAX_qsize();
  const int get_first_elmnt();

private:
  static const int qSize{1000};
  int queue_str[qSize];
  int first_pos{1};
  int last_pos{0};
};
bool queue::is_empty() { return ((last_pos < first_pos) ? 1 : 0); }
void queue::push(int elmnt) {
  if (last_pos < qSize - 1) {
    last_pos++;
    queue_str[last_pos] = elmnt;
  } else {
    std::cout << " Queue is full. " << std::endl;
  }
};
int queue::pop() {
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
void queue::clear() {
  first_pos = 1;
  last_pos = 0;
}
const void queue::print() {
  if (is_empty()) {
    std::cout << "Queue is empty. No elements to print. " << std::endl;
  } else {
    std::cout << "queue state " << std::endl;
    for (int i = first_pos; i <= last_pos; ++i)
      std::cout << queue_str[i] << " ";
  }
  std::cout << std::endl;
}
const int queue::get_qsize() { return last_pos; }
const int queue::get_MAX_qsize() { return qSize; }
const int queue::get_first_elmnt() {
  if (is_empty()) {
    std::cout << "Queue is empty." << std::endl;
    return 0;
  } else {
    return queue_str[first_pos];
  }
}

int main() {
  queue q1;
  std::cout << q1.get_MAX_qsize() << std::endl;
  q1.print();
  q1.push(10);

  q1.print();
  q1.push(20);
  q1.push(30);
  std::cout << "Queue is empty? " << q1.is_empty() << std::endl;
  std::cout << "Get size: " << q1.get_qsize() << std::endl;
  q1.print();
  q1.pop();
  q1.print();
  q1.clear();
  q1.print();
  return 0;
}
