#include <iostream>
template <typename T> class queue {
public:
  bool is_empty();
  void push(T elmnt);
  T pop();
  void clear();
  const int get_qsize();
  const int get_qcapacity();
  const T get_first_elmnt();
  ~queue();

private:
  static const int qSize{1000};
  T *queue_str = new T[qSize];
  int first_pos{0};
  int last_pos{0};
};
template <typename T> queue<T>::~queue() { delete[] queue_str; }
template <typename T> bool queue<T>::is_empty() {
  return last_pos == 0 && first_pos == 0;
}
template <typename T> void queue<T>::push(T elmnt) {
  if (last_pos < qSize) {
    queue_str[last_pos++] = elmnt;
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
  first_pos = 0;
  last_pos = 0;
}

template <typename T> const int queue<T>::get_qsize() { return last_pos; }
template <typename T> const int queue<T>::get_qcapacity() { return qSize; }
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
  std::cout << q1.get_qcapacity() << std::endl;

  q1.push(10);
  q1.push(20);
  q1.push(30);

  std::cout << "Get size: " << q1.get_qsize() << std::endl;
  q1.pop();
  q1.clear();
  queue<char> qc;

  qc.push('a');
  qc.push('b');
  qc.push('c');
  std::cout << "Queue is empty? " << qc.is_empty() << std::endl;

  qc.pop();
  qc.clear();
  return 0;
}
