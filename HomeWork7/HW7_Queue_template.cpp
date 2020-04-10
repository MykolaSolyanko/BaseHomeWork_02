#include <iostream>
template <typename T> class queue {
public:
  bool is_empty();
  void push(T elmnt);
  T pop();
  void clear();
  const void print();
  const int get_qsize();
  const int get_MAX_qsize();
  const T get_first_elmnt();

private:
  static const int qSize{1000};
  T queue_str[qSize];
  int first_pos{1};
  int last_pos{0};
};
template <typename T> bool queue<T>::is_empty() {
  return ((last_pos < first_pos) ? 1 : 0);
}
template <typename T> void queue<T>::push(T elmnt) {
  if (last_pos < qSize - 1) {
    last_pos++;
    queue_str[last_pos] = elmnt;
  } else {
    std::cout << " Queue is full. " << std::endl;
  }
};
template <typename T> T queue<T>::pop() {
  if (is_empty()) {
    std::cout << "Queue is empty" << std::endl;
    return 0;
  }
  T elmnt = queue_str[first_pos];
  for (int i = first_pos; i < last_pos; ++i) {
    queue_str[i] = queue_str[i + 1];
  }
  last_pos--;
  return elmnt;
}
template <typename T> void queue<T>::clear() {
  first_pos = 1;
  last_pos = 0;
}
template <typename T> const void queue<T>::print() {
  if (is_empty()) {
    std::cout << "Queue is empty. No elements to print. " << std::endl;
  } else {
    std::cout << "queue state " << std::endl;
    for (int i = first_pos; i <= last_pos; ++i)
      std::cout << queue_str[i] << " ";
  }
  std::cout << std::endl;
}
template <typename T> const int queue<T>::get_qsize() { return last_pos; }
template <typename T> const int queue<T>::get_MAX_qsize() { return qSize; }
template <typename T> const T queue<T>::get_first_elmnt() {
  if (is_empty()) {
    std::cout << "Queue is empty." << std::endl;
    return 0;
  } else {
    return queue_str[first_pos];
  }
}

int main() {
  queue<int> q1;
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
  queue<char> qc;
  std::cout << qc.get_MAX_qsize() << std::endl;
  qc.print();
  qc.push('a');

  qc.print();
  qc.push('b');
  qc.push('c');
  std::cout << "Queue is empty? " << qc.is_empty() << std::endl;
  std::cout << "Get size: " << qc.get_qsize() << std::endl;
  qc.print();
  qc.pop();
  qc.print();
  qc.clear();
  qc.print();

  return 0;
}
