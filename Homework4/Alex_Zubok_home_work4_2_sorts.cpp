#include <cstring>
#include <iostream>

using Comp_unsigned = bool (*)(unsigned, unsigned);
bool More(unsigned a, unsigned b) { return a > b; }
bool Less(unsigned a, unsigned b) { return a < b; }

unsigned *user_partiotion(unsigned *begin, unsigned *end,
                          Comp_unsigned func = More) {
  unsigned pivot = *(end - 1);
  unsigned *i = begin - 1;
  for (unsigned *j = begin; j != end; j++) {
    if (func(pivot, *j)) { //*j < pivot !func
      i++;
      unsigned tmp = *j;
      *j = *i;
      *i = tmp;
    }
  }
  unsigned tmp = *(i + 1);
  *(i + 1) = *(end - 1);
  *(end - 1) = tmp;
  return (i + 1);
}
void qSort(unsigned *begin, unsigned *end, Comp_unsigned func = More) {
  if (begin < end) {
    unsigned *pi = user_partiotion(begin, end, func);
    qSort(begin, pi, func);
    qSort(pi + 1, end, func);
  }
}

void print_array(const unsigned *begin, const unsigned *const end) {
  std::cout << "Array[ " << *begin;
  for (const unsigned *i = begin + 1; i != end; i++)
    std::cout << ", " << *i;
  std::cout << " ]" << std::endl;
}

using Comp_double = bool (*)(double, double);
bool More(double a, double b) { return a > b; }
bool Less(double a, double b) { return a < b; }

double *user_partiotion(double *begin, double *end, Comp_double func = More) {
  double pivot = *(end - 1);
  double *i = begin - 1;
  for (double *j = begin; j != end; j++) {
    if (func(pivot, *j)) { //*j < pivot !func
      i++;
      double tmp = *j;
      *j = *i;
      *i = tmp;
    }
  }
  double tmp = *(i + 1);
  *(i + 1) = *(end - 1);
  *(end - 1) = tmp;
  return (i + 1);
}
void qSort(double *begin, double *end, Comp_double func = More) {
  if (begin < end) {
    double *pi = user_partiotion(begin, end, func);
    qSort(begin, pi, func);
    qSort(pi + 1, end, func);
  }
}

void print_array(const double *begin, const double *const end) {
  std::cout << "Array[ " << *begin;
  for (const double *i = begin + 1; i != end; i++)
    std::cout << ", " << *i;
  std::cout << " ]" << std::endl;
}

using Comp_char = bool (*)(char, char);
bool More(char a, char b) { return a > b; }
bool Less(char a, char b) { return a < b; }

void print_array(const char *begin, const char *const end) {
  std::cout << "Array[ " << *begin;
  for (const char *i = begin + 1; i != end; i++)
    std::cout << *i;
  std::cout << " ]" << std::endl;
}

void Sort(char *begin, const char *const end, Comp_char func = More) {
  for (char *c_l1 = begin; c_l1 != end; c_l1++) {
    for (char *c_l2 = c_l1 + 1; c_l2 != end; c_l2++) {
      if (!func(*c_l2, *c_l1)) {
        int tmp = *c_l1;
        *c_l1 = *c_l2;
        *c_l2 = tmp;
      }
    }
  }
}

void bSort(char *begin, const char *const end, Comp_char func = More) {
  char *array1; // for Upper case
  char *array2; // for lower case
  char *array3; // for digits
  char *array4; // for else symbol
  size_t size_arr1{};
  size_t size_arr2{};
  size_t size_arr3{};
  size_t size_arr4{};
  for (char *c = begin; c != end; c++) {
    if (*c < 91 && *c > 64)
      size_arr1++;
    else if (*c < 123 && *c > 96)
      size_arr2++;
    else if (*c < 58 && *c > 47)
      size_arr3++;
    else
      size_arr4++;
  }
  array1 = new char[size_arr1];
  array2 = new char[size_arr2];
  array3 = new char[size_arr1];
  array4 = new char[size_arr2];
  size_t i{}, j{}, k{}, l{};
  for (char *c = begin; c != end; c++) {
    if (*c < 91 && *c > 64) {
      *(array1 + i) = *c;
      i++;
    } else if (*c < 123 && *c > 96) {
      *(array2 + j) = *c;
      j++;
    } else if (*c < 58 && *c > 47) {
      *(array3 + k) = *c;
      k++;
    } else {
      *(array4 + l) = *c;
      l++;
    }
  }
  Sort(array1, array1 + size_arr1, func);
  Sort(array2, array2 + size_arr2, func);
  Sort(array3, array3 + size_arr3, func);
  Sort(array4, array4 + size_arr4, func);
  char *tmp_string = new char[size_arr1 + size_arr2 + size_arr3 + size_arr4];
  std::strncpy(tmp_string, array1, size_arr1);
  std::strncat(tmp_string, array2, size_arr2);
  std::strncat(tmp_string, array3, size_arr3);
  std::strncat(tmp_string, array4, size_arr4);
  std::strncpy(begin, tmp_string, size_arr1 + size_arr2 + size_arr3 + size_arr4);
  delete[] tmp_string;
  delete[] array1;
  delete[] array2;
  delete[] array3;
  delete[] array4;
}
