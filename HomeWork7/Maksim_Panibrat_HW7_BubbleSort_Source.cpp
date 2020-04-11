#include "Header.h"

const size_t kSize = 20;

template <typename T>
void Array_result(T *begin, const T *end, const size_t kSize) {
  std::cout << "result: array[" << kSize << "]{";
  for (begin; begin != end; ++begin) {
    std::cout << *begin << " ";
  }
  std::cout << "}\n";
}

template <typename T> void Swap(T *lhs, T *rhs) {
  std::cout << "swaping : lhs" << *lhs << ", rhs " << *rhs << "\n";
  T tmp = *lhs;
  *lhs = *rhs;
  *rhs = tmp;
  std::cout << "swap result: lhs" << *lhs << ", rhs " << *rhs << "\n";
}

template <typename T>
void Bubble_sort(T *begin, const T *end, Comparison comp) {
  for (T *bubble = begin; bubble != end; ++bubble) {
    for (T *next_bubble = bubble + 1; next_bubble != end; ++next_bubble) {
      if (comp(*bubble, *next_bubble)) {
        Swap(bubble, next_bubble);
      }
    }
  }
}

template <typename T> void Sort_settings(T *begin, T *end) {
  std::cout << "Select sort side: \n"
               "\t1 - left\n"
               "\t2 - right\n";
  short select;
  std::cin >> select;
  switch (select) {
  case (LEFT): {
    auto comp = [](T a, T b) { return a > b; };
    Bubble_sort(begin, end, comp);
    break;
  }
  case (RIGHT): {
    auto comp = [](T a, T b) { return a < b; };
    Bubble_sort(begin, end, comp);
    break;
  }
  default: {
    std::cout << "Error, using default-left side.\n";
    auto comp = [](T a, T b) { return a > b; };
    Bubble_sort(begin, end, comp);
    break;
  }
  }
}

template <typename T> void Random_whole_array(T *begin, const T *end) {
  std::mt19937 generator{};
  T kMin, kMax;
  std::cout << "Enter min number: ";
  std::cin >> kMin;
  std::cout << "Enter max number: ";
  std::cin >> kMax;
  std::uniform_int_distribution<T> distribution(kMin, kMax);
  for (; begin != end; ++begin) {
    *begin = distribution(generator);
  }
}

void Create_whole() {
  std::cout << "Select real number type: \n"
               "\t1 - short\n"
               "\t2 - int\n"
               "\t3 - long\n";
  short select;
  std::cin >> select;
  switch (select) {
  case (SHORT): {
    short array[kSize]{};
    short *begin = {array};
    short *end = begin + kSize;
    Random_whole_array(begin, end);
    std::cout << "Random input ";
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
    break;
  }
  case (INT): {
    int array[kSize]{};
    int *begin = {array};
    int *end = begin + kSize;
    Random_whole_array(begin, end);
    std::cout << "Random input ";
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
    break;
  }
  case (LONG): {
    long array[kSize]{};
    long *begin = {array};
    long *end = begin + kSize;
    Random_whole_array(begin, end);
    std::cout << "Random input ";
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
    break;
  }
  default: {
    std::cout << "Error, using default int type.\n";
    int array[kSize]{};
    int *begin = {array};
    int *end = begin + kSize;
    Random_whole_array(begin, end);
    std::cout << "Random input ";
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
    break;
  }
  }
}

template <typename T> void Random_fractional_array(T *begin, const T *end) {
  std::mt19937 generator{};
  T kMin, kMax;
  std::cout << "Enter min number: ";
  std::cin >> kMin;
  std::cout << "Enter max number: ";
  std::cin >> kMax;
  std::uniform_real_distribution<T> distribution(kMin, kMax);
  for (; begin != end; ++begin) {
    *begin = distribution(generator);
  }
}

void Create_fractional() {
  std::cout << "Select real number type: \n"
               "\t1 - float\n"
               "\t2 - double";
  int select;
  std::cin >> select;
  switch (select) {
  case (FLOAT): {
    float array[kSize]{};
    float *begin = {array};
    float *end = begin + kSize;
    Random_fractional_array(begin, end);
    std::cout << "Random input ";
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
    break;
  }
  case (DOUBLE): {
    double array[kSize]{};
    double *begin = {array};
    double *end = begin + kSize;
    Random_fractional_array(begin, end);
    std::cout << "Random input ";
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
    break;
  }
  default: {
    std::cout << "Error, using default float type.\n";
    float array[kSize]{};
    float *begin = {array};
    float *end = begin + kSize;
    Random_fractional_array(begin, end);
    std::cout << "Random input ";
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
    break;
  }
  }
}

void Random_char_array(char *begin, const char *end) {
  std::mt19937 generator{};
  int kUpperMin = 'A', kUpperMax = 'Z';
  std::uniform_int_distribution<int> distribution_upper(kUpperMin, kUpperMax);
  int kLowerMin = 'a', kLowerMax = 'z';
  std::uniform_int_distribution<int> distribution_lower(kLowerMin, kLowerMax);
  std::uniform_int_distribution<int> distribiton_switch(UPPER, LOWER);
  for (; begin != end; ++begin) {
    *begin = distribiton_switch(generator) ? distribution_upper(generator)
                                           : distribution_lower(generator);
  }
}

void Create_char() {
  char array[kSize]{};
  char *begin = {array};
  char *end = begin + kSize;
  Random_char_array(begin, end);
  std::cout << "Random input ";
  std::cout << array;
  Array_result(begin, end, kSize);

  Sort_settings(begin, end);
  std::cout << "Bubble sort ";
  Array_result(begin, end, kSize);
}
