#include <cstring>
#include <iostream>

void swap(unsigned *a, unsigned *b) {
  unsigned tmp = *a;
  *a = *b;
  *b = tmp;
}

bool More(unsigned a, unsigned b) { return a > b; }
using Comp_unsigned = bool (*)(unsigned, unsigned);

unsigned *user_partiotion(unsigned *begin, unsigned *end,
                          Comp_unsigned func = More) {
  unsigned pivot = *(end - 1);
  unsigned *i = begin - 1;
  for (unsigned *j = begin; j != end; j++) {
    if (func(pivot, *j)) { //*j < pivot !func
      i++;
      swap(i, j);
    }
  }
  swap(i + 1, end - 1);
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

void swap(double *a, double *b) {
  double tmp = *a;
  *a = *b;
  *b = tmp;
}

double *user_partiotion(double *begin, double *end, Comp_double func = More) {
  double pivot = *(end - 1);
  double *i = begin - 1;
  for (double *j = begin; j != end; j++) {
    if (func(pivot, *j)) { //*j < pivot !func
      i++;
      swap(i, j);
    }
  }
  swap(i + 1, end - 1);
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

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void print_array(const char *begin, const char *const end) {
  std::cout << "Array[ " << *begin;
  for (const char *i = begin + 1; i != end; i++)
    std::cout << *i;
  std::cout << " ]" << std::endl;
}

void Sort(char *begin, const char *const end, Comp_char func = More) {
  for (char *c_l1 = begin; c_l1 != end; c_l1++) {
    for (char *c_l2 = c_l1 + 1; c_l2 != end; c_l2++) {
      if (!func(*c_l2, *c_l1))
        swap(c_l1, c_l2);
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
    if (*c <= 'Z' && *c >= 'A')
      size_arr1++;
    else if (*c <= 'z' && *c >= 'a')
      size_arr2++;
    else if (*c <= '9' && *c >= '0')
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
    if (*c <= 'Z' && *c >= 'A') {
      *(array1 + i) = *c;
      i++;
    } else if (*c <= 'z' && *c >= 'a') {
      *(array2 + j) = *c;
      j++;
    } else if (*c <= '9' && *c >= '0') {
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
  strncpy(tmp_string, array1, size_arr1);
  strncat(tmp_string, array2, size_arr2);
  strncat(tmp_string, array3, size_arr3);
  strncat(tmp_string, array4, size_arr4);
  strncpy(begin, tmp_string, size_arr1 + size_arr2 + size_arr3 + size_arr4);
  delete[] tmp_string;
  delete[] array1;
  delete[] array2;
  delete[] array3;
  delete[] array4;
}
