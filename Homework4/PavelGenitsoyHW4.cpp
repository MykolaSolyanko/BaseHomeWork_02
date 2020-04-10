#include <chrono>
#include <functional>
#include <iostream>
#include <random>

using UnsignedIntCompare = std::function<bool(unsigned int, unsigned int)>;
using DoubleCompare = std::function<bool(double, double)>;
using CharCompare = std::function<bool(char, char)>;

static const auto kMin_random_value{0};
static const auto kMax_random_value{25.0};
static const auto kMin_value_for_char{48};
static const auto kMax_value_for_char{122};
static const auto kMin_value_of_range_array{1};
static const auto kMax_value_of_range_array{100};
static const auto kNum_Asqii_of_slash{47};
static const auto kNum_Asqii_of_colon{58};
static const auto kNum_Asqii_of_commercial_at{64};
static const auto kNum_Asqii_of_left_square_bracket{91};
static const auto kNum_Asqii_of_apostrophe{96};

enum TypeSequence {
  BUBBLE_INCREASING = 1,
  BUBBLE_DECREASING,
  QUICKSORT_INCREASING,
  QUICKSORT_DECREASING
};

enum TypeElements { UNSIGNED_INT = 1, DOUBLE, CHAR };

enum TypeInitialisation { CUSTOM_ARRAY = 1, RANDOM_ARRAY };

auto GetInputFromCinForSizeArray(size_t min, size_t max) {
  size_t number{};
  while (std::cin >> number && (number < kMin_value_of_range_array ||
                                number > kMax_value_of_range_array)) {
    std::cout << "\nYou entered an incorrect size, try entering again.\nEnter "
                 "a num: ";
  }
  return number;
}

void RandomCreateArray(unsigned int *begin, unsigned int const *const end) {
  if (begin == nullptr || end == nullptr || begin >= end) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<unsigned int> Generate(kMin_random_value,
                                                       kMax_random_value);
  while (begin < end) {
    *begin++ = Generate(mt);
  }
}

void RandomCreateArray(double *begin, double const *const end) {
  if (begin == nullptr || end == nullptr || begin >= end) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> Generate(kMin_random_value,
                                                  kMax_random_value);
  while (begin < end) {
    *begin++ = Generate(mt);
  }
}

void RandomCreateArray(char *begin, char const *const end) {
  if (begin == nullptr || end == nullptr || begin >= end) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> Generate(kMin_value_for_char,
                                              kMax_value_for_char);
  while (begin < end) {
    int tmp = Generate(mt);
    if (((tmp < kNum_Asqii_of_left_square_bracket ||
          tmp > kNum_Asqii_of_apostrophe) &&
         (tmp > kNum_Asqii_of_commercial_at)) ||
        (tmp > kNum_Asqii_of_slash && tmp < kNum_Asqii_of_colon)) {
      *begin++ = static_cast<unsigned char>(tmp);
    }
  }
}

template <typename T> void CustomCreateArray(T *begin, T const *const end) {
  if (begin == nullptr || end == nullptr || begin >= end) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  T number{};
  while (begin < end) {
    std::cout << "\nEnter number in range[" << kMin_random_value << "..."
              << kMax_random_value << "]: " << std::endl;
    std::cin >> number;
    *begin++ = number;
  }
}

template <typename T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T> void PrintArray(const T array[], const size_t size) {
  if (array == nullptr) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  std::cout << "Array[";
  for (size_t i{0}; i < size; ++i) {
    std::cout << *(array + i);
    if (i != size - 1) {
      std::cout << "; ";
    }
  }
  std::cout << "]" << std::endl;
}

template <typename T1, typename T2>
void BubbleSort(T1 array[], const size_t size, T2 comp) {
  if (array == nullptr) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  for (int i = 0; i < size; i++) {
    for (int j = size - 1; j > i; j--) {
      if (comp(*(array + j), *(array + j - 1))) {
        swap<T1>(*(array + j - 1), *(array + j));
      }
    }
  }
}

template <typename T1, typename T2>
void QuickSort(T1 array[], int low, int high, T2 comp) {
  if (array == nullptr) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  int i{low};
  int j{high};
  T1 piv = array[(i + j) / 2];
  while (i <= j) {
    while (!(comp(array[i], piv) || (array[i] == piv))) {
      i++;
    }
    while (comp(array[j], piv)) {
      j--;
    }
    if (i <= j) {
      swap<T1>(array[j--], array[i++]);
    }
  }
  if (j > low) {
    QuickSort(array, low, j, comp);
  }
  if (i < high) {
    QuickSort(array, i, high, comp);
  }
}

template <typename T> void Do_U_wanna_See_array(T Array[], const size_t size) {
  if (Array == nullptr) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  std::cout << "\nIf u want to see the content of array, enter 1. If not - "
               "input any other number: ";
  size_t check{};
  std::cin >> check;
  if (check == 1) {
    PrintArray<T>(Array, size);
  }
}

template <typename T> void Sort(T Array[], const size_t size) {
  if (Array == nullptr) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  std::cout << "\nSelect sorting method and sequence type:" << std::endl;
  std::cout << "Enter 1 | if you want to use Bubble method to sort your array "
               "from smaller to bigger (increasing sequence)"
            << std::endl;
  std::cout << "Enter 2 | if you want to use Bubble method to sort your array "
               "from bigger to smaller (decreasing sequence)"
            << std::endl;
  std::cout << "Enter 3 | if you want to use Quicksort method to sort your "
               "array from smaller to bigger (increasing sequence)"
            << std::endl;
  std::cout << "Enter 4 | if you want to use Quicksort method to sort your "
               "array from bigger to smaller (decreasing sequence)"
            << std::endl;
  size_t choice{};
  std::cin >> choice;
  switch (choice) {
  case TypeSequence::BUBBLE_INCREASING: {
    auto first = std::chrono::system_clock::now();
    BubbleSort<T>(Array, size, [](char p1, char p2) { return p1 < p2; });
    auto second = std::chrono::system_clock::now();
    auto time = second - first;
    std::cout << "Time of work of this sort is - " << time.count()
              << " (milliseconds)" << std::endl;
    Do_U_wanna_See_array<T>(Array, size);
  } break;

  case TypeSequence::BUBBLE_DECREASING: {
    auto first = std::chrono::system_clock::now();
    BubbleSort<T>(Array, size, [](char p1, char p2) { return p1 > p2; });
    auto second = std::chrono::system_clock::now();
    auto time = second - first;
    std::cout << "Time of work of this sort is " << time.count()
              << " (milliseconds)" << std::endl;
    Do_U_wanna_See_array<T>(Array, size);
  } break;

  case TypeSequence::QUICKSORT_INCREASING: {
    auto first = std::chrono::system_clock::now();
    QuickSort<T>(Array, 0, size - 1, [](char p1, char p2) { return p1 > p2; });
    auto second = std::chrono::system_clock::now();
    auto time = second - first;
    std::cout << "Time of work of this sort is " << time.count()
              << " (milliseconds)" << std::endl;
    Do_U_wanna_See_array<T>(Array, size);
  } break;

  case TypeSequence::QUICKSORT_DECREASING: {
    auto first = std::chrono::system_clock::now();
    QuickSort<T>(Array, 0, size - 1, [](char p1, char p2) { return p1 < p2; });
    auto second = std::chrono::system_clock::now();
    auto time = second - first;
    std::cout << "Time of work of this sort is " << time.count()
              << " (milliseconds)" << std::endl;
    Do_U_wanna_See_array<T>(Array, size);
  } break;

  default:
    break;
  }
}

template <typename T> void Create_and_Init_array(T Array[], const size_t size) {
  if (Array == nullptr) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }
  std::cout << "\nSelect type of entering elements in the array:" << std::endl;
  std::cout << "Enter 1 | if you want to personally fill out elements of array "
               "(custom)"
            << std::endl;
  std::cout << "Enter 2 | if you want to use a random generator to fill out "
               "elements of array (random)"
            << std::endl;
  size_t choice{};
  std::cin >> choice;
  switch (choice) {
  case TypeInitialisation::CUSTOM_ARRAY:
    CustomCreateArray<T>(Array, Array + size);
    Do_U_wanna_See_array<T>(Array, size);
    Sort<T>(Array, size);
    break;

  case TypeInitialisation::RANDOM_ARRAY:
    RandomCreateArray(Array, Array + size);
    Do_U_wanna_See_array<T>(Array, size);
    Sort<T>(Array, size);
    break;

  default:
    break;
  }
}

int main() {
  do {
    std::cout << "\nChoose a type of elements of array:" << std::endl;
    std::cout << "1) Enter 1 |  to use (unsigned int)" << std::endl;
    std::cout << "2) Enter 2 |  to use (double)" << std::endl;
    std::cout << "3) Enter 3 |  to use (char)" << std::endl;
    int key{};
    std::cin >> key;
    switch (key) {
    case TypeElements::UNSIGNED_INT: {
      std::cout << "\nEnter size of array in range(1, 50): ";
      size_t kSize_u_int = GetInputFromCinForSizeArray(
          kMin_value_of_range_array, kMax_value_of_range_array);
      unsigned int *Array_u_int = new unsigned int[kSize_u_int]{};
      Create_and_Init_array<unsigned int>(Array_u_int, kSize_u_int);
      delete[] Array_u_int;
    } break;

    case TypeElements::DOUBLE: {
      std::cout << "\nEnter size of array in range(1, 50): ";
      size_t kSize_double = GetInputFromCinForSizeArray(
          kMin_value_of_range_array, kMax_value_of_range_array);
      double *Array_double = new double[kSize_double]{};
      Create_and_Init_array<double>(Array_double, kSize_double);
      delete[] Array_double;
    } break;

    case TypeElements::CHAR: {
      std::cout << "\nEnter size of array in range(1, 50): ";
      size_t kSize_char = GetInputFromCinForSizeArray(
          kMin_value_of_range_array, kMax_value_of_range_array);
      char *Array_char = new char[kSize_char]{};
      Create_and_Init_array<char>(Array_char, kSize_char);
      delete[] Array_char;
    } break;

    default:
      return 0;
    }
  } while (true);

  system("pause");
  return 0;
}
