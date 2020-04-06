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

template <typename T = int> void CreateIntRandArray(T *array, const int size) {
  std::random_device rd;
  std::mt19937 mersenne{rd()};
  std::uniform_int_distribution<> dist(0, size);
  for (int i{}; i < size; ++i) {
    *(array + i) = dist(mersenne);
  };
}
template <typename T = double>
void CreateDoubleRandArray(T *array, const int size) {
  std::random_device rd;
  std::mt19937 mersenne{rd()};
  std::uniform_real_distribution<> dist(0, size);
  for (int i{}; i < size; ++i) {
    *(array + i) = dist(mersenne);
  }
}

template <typename T = char>
void CreateCharRandArray(T *array, const int size) {
  std::random_device rd;
  std::mt19937 mersenne{rd()};
  // std::knuth_b gen1;
  std::uniform_int_distribution<> dist('0', 'z');
  int index{};
  while (index < size) {
    int rand = dist(mersenne);
    if (((rand > '@') && (rand < '[')) || (rand > '`') || (rand < ':')) {
      *(array + index++) = rand;
    }
  }
}
