#pragma once
template <typename T> void PrintArray(const T *array, const int size) {
  for (int i{}; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}
template <typename T> void swap(T &a, T &b) {
  T t = a;
  a = b;
  b = t;
}
template <typename T> bool more(T a, T b) { return a > b; }
template <typename T> bool less(T a, T b) { return a < b; }
template <typename T1, typename T2>
void BubbleSort(T1 *arrptr, int size, T2 comp) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      auto *first = (arrptr + j);
      auto *second = (arrptr + j + 1);
      if (comp(*first, *second)) {
        swap(*first, *second);
      }
    }
  }
}

void CreateRandArray(char *array, const int size);
void CreateRandArray(int *array, const int size);
void CreateRandArray(double *array, const int size);
