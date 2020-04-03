#include <chrono>
#include <functional>
#include <iostream>
#include <random>
enum ARRAY_CREATON { RANDOM = 1, CUSTOM };
enum ORDER { MORE = 1, LESS };
static const int kSize;
using IntCompare = std::function<bool(int, int)>;
using DoubleCompare = std::function<bool(double, double)>;
using CharCompare = std::function<bool(char, char)>;
char *AllocCharArray(size_t kSize) {
  char *array = new char[kSize];
  std::cout << "Please, enter char string with max " << kSize << " elements"
            << std::endl;
  std::cin >> array;
  return array;
}
void DeleteAllocCharArray(char *array) { delete[] array; }
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
  int index{};
  while (index < size) {
    int rand = dist(mersenne);
    if (((rand > '@') && (rand < '[')) || (rand > '`') || (rand < ':')) {
      *(array + index++) = rand;
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
void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
void swap(double &a, double &b) {
  double t = a;
  a = b;
  b = t;
}
void swap(char &a, char &b) {
  char t = a;
  a = b;
  b = t;
}
bool more(int a, int b) { return a > b; }
bool more(double a, double b) { return a > b; }
bool more(char a, char b) { return a > b; }
bool less(int a, int b) { return a < b; }
bool less(double a, double b) { return a < b; }
bool less(char a, char b) { return a < b; }
void BubbleSort(int *array, int size, IntCompare compare) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      auto *first = (array + j);
      auto *second = (array + j + 1);
      if (compare(*first, *second)) {
        swap(*first, *second);
      }
    }
  }
}
void BubbleSortTime(int *array, int size, IntCompare compare) {
  auto begin = std::chrono::steady_clock::now();
  BubbleSort(array, size, compare);
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Bubble sort time: " << elapsed_ms.count() << " ms\n";
}
void BubbleSort(double *array, int size, DoubleCompare compare) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      auto *first = (array + j);
      auto *second = (array + j + 1);
      if (compare(*first, *second)) {
        swap(*first, *second);
      }
    }
  }
}
void BubbleSortTime(double *array, int size, DoubleCompare compare) {
  auto begin = std::chrono::steady_clock::now();
  BubbleSort(array, size, compare);
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Bubble sort time: " << elapsed_ms.count() << " ms\n";
}
void BubbleSort(char *array, int size, CharCompare compare) {
  auto begin = std::chrono::steady_clock::now();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      auto *first = (array + j);
      auto *second = (array + j + 1);
      if (compare(*first, *second)) {
        swap(*first, *second);
      }
    }
  }
}
void BubbleSortTime(char *array, int size, CharCompare compare) {
  auto begin = std::chrono::steady_clock::now();
  BubbleSort(array, size, compare);
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Bubble sort time: " << elapsed_ms.count() << " ms\n";
}
void QuickSort(int *array, int low, int high, IntCompare compare) {

  int i{low};
  int j{high};
  int pivot = array[(i + j) / 2];
  while (i <= j) {
    while (!(compare(array[i], pivot) || (array[i] == pivot)))
      i++;
    while (compare(array[j], pivot))
      j--;
    if (i <= j) {
      swap(array[j], array[i]);
      i++;
      j--;
    }
  }
  if (j > low)
    QuickSort(array, low, j, compare);
  if (i < high)
    QuickSort(array, i, high, compare);
}
void QuickSort(double *array, int low, int high, DoubleCompare compare) {
  int i{low};
  int j{high};
  double pivot = array[(i + j) / 2];
  while (i <= j) {
    while (!(compare(array[i], pivot) || (array[i] == pivot)))
      i++;
    while (compare(array[j], pivot))
      j--;
    if (i <= j) {
      swap(array[j], array[i]);
      i++;
      j--;
    }
  }
  if (j > low)
    QuickSort(array, low, j, compare);
  if (i < high)
    QuickSort(array, i, high, compare);
}
void QuickSort(char *array, int low, int high, CharCompare compare) {
  int i{low};
  int j{high};
  char pivot = array[(i + j) / 2];
  while (i <= j) {
    while (!(compare(array[i], pivot) || (array[i] == pivot)))
      i++;
    while (compare(array[j], pivot))
      j--;
    if (i <= j) {
      swap(array[j], array[i]);
      i++;
      j--;
    }
  }
  if (j > low)
    QuickSort(array, low, j, compare);
  if (i < high)
    QuickSort(array, i, high, compare);
}
void QuickSortTime(int *array, int low, int high, IntCompare compare) {
  auto begin = std::chrono::steady_clock::now();
  QuickSort(array, low, high, compare);
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Quick sort time: " << elapsed_ms.count() << " ms\n";
}
void QuickSortTime(double *array, int low, int high, DoubleCompare compare) {
  auto begin = std::chrono::steady_clock::now();
  QuickSort(array, low, high, compare);
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  std::cout << "The Quick sort time: " << elapsed_ms.count() << " ms\n";
}
void CreateIntArray(int *array, int size) {
  std::cout << "Please, choose the type of array:" << std::endl;
  std::cout << "1 random;" << std::endl;
  std::cout << "2 custom." << std::endl;
  int choise2;
  std::cin >> choise2;
  switch (choise2) {
  case ARRAY_CREATON::RANDOM: {
    CreateRandArray(array, size);
    PrintArray(array, size);
    break;
  }
  case ARRAY_CREATON::CUSTOM: {
    CreateCustomArray(array, size);
    PrintArray(array, size);
    break;
  }
  default:
    break;
  }
}
void SortArray(int *array, int size) {
  std::cout << "Please, choose the type of array sorting:" << std::endl;
  std::cout << "1 more (from smaller to bigger);" << std::endl;
  std::cout << "2 less (from bigger to smaller)." << std::endl;
  int choise2{};
  std::cin >> choise2;
  switch (choise2) {
  case ORDER::MORE: {
    auto Fptr = static_cast<bool (*)(int, int)>(&more);
    BubbleSortTime(array, size, Fptr);
    PrintArray(array, size);
    QuickSortTime(array, 0, size - 1, Fptr);
    PrintArray(array, size);
    break;
  }
  case ORDER::LESS: {
    auto Fptr = static_cast<bool (*)(int, int)>(&less);
    BubbleSortTime(array, size, Fptr);
    PrintArray(array, size);
    QuickSortTime(array, 0, size - 1, Fptr);
    PrintArray(array, size);
    break;
  }
  default:
    break;
  }
}
void CreateDoubleArray(double *array, int size) {
  std::cout << "Please, choose the type of array:" << std::endl;
  std::cout << "1 random;" << std::endl;
  std::cout << "2 custom." << std::endl;
  int choise2;
  std::cin >> choise2;
  switch (choise2) {
  case ARRAY_CREATON::RANDOM: {
    CreateRandArray(array, size);
    PrintArray(array, size);
    break;
  }
  case ARRAY_CREATON::CUSTOM: {
    CreateCustomArray(array, size);
    PrintArray(array, size);
    break;
  }
  default:
    break;
  }
}
void SortDoubleArray(double *array, int size) {

  std::cout << "Please, choose the type of array sorting:" << std::endl;
  std::cout << "1 more (from smaller to bigger);" << std::endl;
  std::cout << "2 less (from bigger to smaller)." << std::endl;
  int choise2{};
  std::cin >> choise2;
  switch (choise2) {
  case ORDER::MORE: {
    auto Fptr = static_cast<bool (*)(double, double)>(&more);
    BubbleSortTime(array, size, Fptr);
    PrintArray(array, size);
    QuickSortTime(array, 0, size - 1, Fptr);
    PrintArray(array, size);
    break;
  }
  case ORDER::LESS: {
    auto Fptr = static_cast<bool (*)(double, double)>(&less);
    BubbleSortTime(array, size, Fptr);
    PrintArray(array, size);
    QuickSortTime(array, 0, size - 1, Fptr);
    PrintArray(array, size);
    break;
  }
  default:
    break;
  }
}

std::pair<char *, int> CreateCharArray() {
  std::cout << "Please, choose the type of array:" << std::endl;
  std::cout << "1 random;" << std::endl;
  std::cout << "2 custom." << std::endl;
  int choise3{}, size{};
  char *array = new char[kSize];
  std::cin >> choise3;
  switch (choise3) {
  case ARRAY_CREATON::RANDOM: {
    std::cout << "Please, choose the size of array (from 1 to 10 000)"
              << std::endl;
    std::cin >> size;
    CreateRandArray(array, size);
    PrintArray(array, size);
    return std::pair<char *, int>(array, size);
  }
  case ARRAY_CREATON::CUSTOM: {
    array = AllocCharArray(kSize);
    size = LengthCharArray(array);
    PrintArray(array, size);
    return std::pair<char *, int>(array, size);
  }
  default:
    return std::pair<char *, int>(nullptr, 0);
  }
}
void SortCharArray(char *array, int size) {
  std::cout << "Please, choose the type of array sorting:" << std::endl;
  std::cout << "1 more (from smaller to bigger);" << std::endl;
  std::cout << "2 less (from bigger to smaller)." << std::endl;
  int choise3{};
  std::cin >> choise3;
  switch (choise3) {
  case ORDER::MORE: {
    auto Fptr = static_cast<bool (*)(char, char)>(&more);
    BubbleSortTime(array, size, Fptr);
    PrintArray(array, size);
    break;
  }
  case ORDER::LESS: {
    auto Fptr = static_cast<bool (*)(char, char)>(&less);
    BubbleSortTime(array, size, Fptr);
    PrintArray(array, size);
    break;
  }
  default:
    break;
  }
}
