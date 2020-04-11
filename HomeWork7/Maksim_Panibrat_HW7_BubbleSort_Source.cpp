#include "Header.h"

const size_t kSize = 20;

template <typename T>
static void Array_result(T *begin, const T *end, const size_t kSize) {
  std::cout << "result: array[" << kSize << "]{";
  for (begin; begin != end; ++begin) {
    std::cout << *begin << " ";
  }
  std::cout << "}\n";
}

template <typename T> static void Swap(T *lhs, T *rhs) {
  std::cout << "swaping : lhs" << *lhs << ", rhs " << *rhs << "\n";
  T tmp = *lhs;
  *lhs = *rhs;
  *rhs = tmp;
  std::cout << "swap result: lhs" << *lhs << ", rhs " << *rhs << "\n";
}

template <typename T> static void Bubble_sort(T *begin, const T *end) {
  auto comp = [](T a, T b) {
    return a < b;
  }; /*sort less to left side  return a < b
       sort less to right side return a > b*/
  for (T *bubble = begin; bubble != end; ++bubble) {
    for (T *next_bubble = begin; next_bubble != end; ++next_bubble) {
      if (comp(*bubble, *next_bubble)) {
        Swap(bubble, next_bubble);
      }
    }
  }
}

template <typename T> void Random_natural_array(T *begin, const T *end) {
  std::mt19937 generator{};
  T kMin, kMax;
  std::cout << "Enter min number: ";
  std::cin >> kMin;
  std::cout << "Enter max number: ";
  std::cin >> kMax;
  std::uniform_int_distribution<T> distribution(kMin, kMax);
  for (begin; begin != end; ++begin) {
    *begin = distribution(generator);
  }
}

void Create_natural() {
    std::cout << "Select real number type: \n"
        "\t1 - short\n"
        "\t2 - int\n"
        "\t3 - long\n";
    int select;
    std::cin >> select;
    switch (select) {
    case(1): {
        short array[kSize]{};
        short* begin = { array };
        short* end = begin + kSize;
        Random_natural_array(begin, end);
        std::cout << "Random input ";
        Array_result(begin, end, kSize);

        Bubble_sort(begin, end);
        std::cout << "Bubble sort ";
        Array_result(begin, end, kSize);
        break;}
    case(2): {
        int array[kSize]{};
        int* begin = { array };
        int* end = begin + kSize;
        Random_natural_array(begin, end);
        std::cout << "Random input ";
        Array_result(begin, end, kSize);

        Bubble_sort(begin, end);
        std::cout << "Bubble sort ";
        Array_result(begin, end, kSize);
        break;}
    case(3): {
        long array[kSize]{};
        long* begin = { array };
        long* end = begin + kSize;
        Random_natural_array(begin, end);
        std::cout << "Random input ";
        Array_result(begin, end, kSize);

        Bubble_sort(begin, end);
        std::cout << "Bubble sort ";
        Array_result(begin, end, kSize);
        break;}
    default: {
        std::cout << "Error, using default int type.\n";
        int array[kSize]{};
        int* begin = { array };
        int* end = begin + kSize;
        Random_natural_array(begin, end);
        std::cout << "Random input ";
        Array_result(begin, end, kSize);

        Bubble_sort(begin, end);
        std::cout << "Bubble sort ";
        Array_result(begin, end, kSize);
        break;}
    }
}

template <typename T> void Random_real_array(T *begin, const T *end) {
  std::mt19937 generator{};
  T kMin, kMax;
  std::cout << "Enter min number: ";
  std::cin >> kMin;
  std::cout << "Enter max number: ";
  std::cin >> kMax;
  std::uniform_real_distribution<T> distribution(kMin, kMax);
  for (begin; begin != end; ++begin) {
    *begin = distribution(generator);
  }
}

void Create_real() {
    std::cout << "Select real number type: \n"
        "\t1 - float\n"
        "\t2 - double";
    int select;
    std::cin >> select;
    switch (select) {
    case(1): {
        float array[kSize]{};
        float* begin = { array };
        float* end = begin + kSize;
        Random_real_array(begin, end);
        std::cout << "Random input ";
        Array_result(begin, end, kSize);

        Bubble_sort(begin, end);
        std::cout << "Bubble sort ";
        Array_result(begin, end, kSize);
        break;}
    case(2): {
        double array[kSize]{};
        double* begin = { array };
        double* end = begin + kSize;
        Random_real_array(begin, end);
        std::cout << "Random input ";
        Array_result(begin, end, kSize);

        Bubble_sort(begin, end);
        std::cout << "Bubble sort ";
        Array_result(begin, end, kSize);
        break;}
    default: {
        std::cout << "Error, using default float type.\n";
        float array[kSize]{};
        float* begin = { array };
        float* end = begin + kSize;
        Random_real_array(begin, end);
        std::cout << "Random input ";
        Array_result(begin, end, kSize);

        Bubble_sort(begin, end);
        std::cout << "Bubble sort ";
        Array_result(begin, end, kSize);
        break;}
    }
}

void Random_char_array(char *begin, const char *end) {
  std::mt19937 generator{};
  int kUpperMin = 65, kUpperMax = 90;
  std::uniform_int_distribution<int> distribution_upper(kUpperMin, kUpperMax);
  int kLowerMin = 97, kLowerMax = 122;
  std::uniform_int_distribution<int> distribution_lower(kLowerMin, kLowerMax);
  std::uniform_int_distribution<int> distribiton_switch(0, 1);
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

  Bubble_sort(begin, end);
  std::cout << "Bubble sort ";
  Array_result(begin, end, kSize);
}
