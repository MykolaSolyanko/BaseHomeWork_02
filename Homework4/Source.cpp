#include <chrono>
#include <functional>
#include <iostream>
#include <random>

char *AllocCharArray(size_t kSize) {
  char *array = new char[kSize];
  std::cout << "Please, enter char string with max " << kSize << " elements"
            << std::endl;
  std::cin >> array;
  return array;
}
size_t LengthCharArray(char *array) {
  if (array == nullptr) {
    return 0;
  };
  size_t arr_size{0};
  while (array[arr_size] != '\0') {
    ++arr_size;
  }
  return arr_size;
}
void CreateRandArray(char *array, const int size) {
  std::random_device rd;
  std::mt19937 mersenne{rd()};
  // std::knuth_b gen1;
  std::uniform_int_distribution<> dist('0', 'z');
  for (int i = 0; i < size; i++) {
    int rand = dist(mersenne);
    if (((rand > 64) && (rand < 91)) || (rand > 96) || (rand < 58)) {
      *(array + i) = rand;
    } else {
      --i;
    }
  }
}
void CreateRandArray(int *array, const int size) {
  std::random_device rd;
  std::mt19937 mersenne{rd()};
  std::uniform_int_distribution<int> dist(0, size);
  for (int i{}; i < size; ++i) {
    *(array + i) = dist(mersenne);
  };
}
void CreateRandArray(double *array, const int size) {
  std::random_device rd;
  std::mt19937 mersenne{rd()};
  std::uniform_real_distribution<double> dist(0, size);
  for (int i{}; i < size; ++i) {
    *(array + i) = dist(mersenne);
  }
}
void CreateCustomArray(int *array, const int size) {
  int a{};
  for (int i{}; i < size; ++i) {
    std::cout << "Please, enter the " << i + 1
              << "th element of array:" << std::endl;
    std::cin >> a;
    *(array + i) = a;
  };
}
void CreateCustomArray(double *array, const int size) {
  double a{};
  for (int i{}; i < size; ++i) {
    std::cout << "Please, enter the " << i + 1
              << "th element of array:" << std::endl;
    std::cin >> a;
    *(array + i) = a;
  };
}
void PrintArray(int *array, const int size) {
  for (int i{}; i < size; ++i) {
    std::cout << *(array + i) << " ";
  }
  std::cout << std::endl;
}
void PrintArray(double *array, const int size) {
  for (int i{}; i < size; ++i) {
    std::cout << *(array + i) << " ";
  }
  std::cout << std::endl;
}
void PrintArray(char *array, const int size) {
  for (int i{}; i < size; ++i) {
    std::cout << *(array + i);
  }
  std::cout << std::endl;
}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void swap(double *a, double *b) {
  double t = *a;
  *a = *b;
  *b = t;
}
void swap(char *a, char *b) {
  char t = *a;
  *a = *b;
  *b = t;
}

void BubbleSort(int *array, int size, std::function<bool(int, int)> compare) {
  auto begin = std::chrono::steady_clock::now();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (compare(*(array + j), *(array + j + 1))) {
        swap(array + j, array + (j + 1));
      }
    }
  }
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Bubble sort time: " << elapsed_ms.count() << " ms\n";
}
void BubbleSort(double *array, int size,
                std::function<bool(double, double)> compare) {
  auto begin = std::chrono::steady_clock::now();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (compare(*(array + j), *(array + j + 1))) {
        swap(array + j, array + (j + 1));
      }
    }
  }
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Bubble sort time: " << elapsed_ms.count() << " ms\n";
}
void BubbleSort(char *array, int size,
                std::function<bool(char, char)> compare) {
  auto begin = std::chrono::steady_clock::now();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (compare(*(array + j), *(array + j + 1))) {
        swap(array + j, array + (j + 1));
      }
    }
  }
  for (int i{}; i < size; ++i) {
  }
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Bubble sort time: " << elapsed_ms.count() << " ms\n";
}
void QuickSort(int *array, int low, int high,
               std::function<bool(int, int)> compare) {

  int i{low};
  int j{high};
  int pivot = array[(i + j) / 2];
  while (i <= j) {
    while (!(compare(array[i], pivot) || (array[i] == pivot)))
      i++;
    while (compare(array[j], pivot))
      j--;
    if (i <= j) {
      swap(array + j, array + i);
      i++;
      j--;
    }
  }
  if (j > low)
    QuickSort(array, low, j, compare);
  if (i < high)
    QuickSort(array, i, high, compare);
}
void QuickSort(double *array, int low, int high,
               std::function<bool(double, double)> compare) {
  int i{low};
  int j{high};
  double pivot = array[(i + j) / 2];
  while (i <= j) {
    while (!(compare(array[i], pivot) || (array[i] == pivot)))
      i++;
    while (compare(array[j], pivot))
      j--;
    if (i <= j) {
      swap(array + j, array + i);
      i++;
      j--;
    }
  }
  if (j > low)
    QuickSort(array, low, j, compare);
  if (i < high)
    QuickSort(array, i, high, compare);
}
void QuickSort(char *array, int low, int high,
               std::function<bool(char, char)> compare) {
  int i{low};
  int j{high};
  char pivot = array[(i + j) / 2];
  while (i <= j) {
    while (!(compare(array[i], pivot) || (array[i] == pivot)))
      i++;
    while (compare(array[j], pivot))
      j--;
    if (i <= j) {
      swap(array + j, array + i);
      i++;
      j--;
    }
  }
  if (j > low)
    QuickSort(array, low, j, compare);
  if (i < high)
    QuickSort(array, i, high, compare);
}
void QuickSortTime(int *array, int low, int high,
                   std::function<bool(int, int)> compare) {
  auto begin = std::chrono::steady_clock::now();
  QuickSort(array, low, high, compare);
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Quick sort time: " << elapsed_ms.count() << " ms\n";
}
void QuickSortTime(double *array, int low, int high,
                   std::function<bool(double, double)> compare) {
  auto begin = std::chrono::steady_clock::now();
  QuickSort(array, low, high, compare);
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Quick sort time: " << elapsed_ms.count() << " ms\n";
}
