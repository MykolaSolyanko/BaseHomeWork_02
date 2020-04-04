#include "sorts.hpp"

int main() {
  // Array unsigned
  std::cout << "Please enter size of array for unsigned type: ";
  size_t arr_size{};
  std::cin >> arr_size;
  std::cout << "Filling your array, please check....\n";
  unsigned *array_unsigned = new unsigned[arr_size];
  std::random_device rd_u;
  std::mt19937 gen_u(rd_u());
  std::uniform_int_distribution<> uid_u(0, 100);
  for (size_t i = 0; i < arr_size; i++)
    array_unsigned[i] = uid_u(gen_u);

  std::cout << "Origin array for unsigned type is: ";
  print_array(array_unsigned, array_unsigned + arr_size);
  qSort(array_unsigned, array_unsigned + arr_size, [](unsigned a, unsigned b) { return a > b; });
  std::cout << "Result of sort array: ";
  print_array(array_unsigned, array_unsigned + arr_size);
  delete[] array_unsigned;

  // Array double
  std::cout << "Please enter size of array for unsigned type: ";
  std::cin >> arr_size;
  std::cout << "Filling your array, please check....\n";
  double *array_double = new double[arr_size];
  std::mt19937 gen_d(time(0));
  std::uniform_real_distribution<> uid_d(0, 1);
  for (size_t i = 0; i < arr_size; i++)
    array_double[i] = uid_d(gen_d);

  std::cout << "Origin array for double type is: ";
  print_array(array_double, array_double + arr_size);
  qSort(array_double, array_double + arr_size, [](double a, double b) { return a > b; });
  std::cout << "Result of sort array: ";
  print_array(array_double, array_double + arr_size);
  delete[] array_double;

  // Array char
  std::cout << "Please enter size of array for unsigned type: ";
  std::cin >> arr_size;
  std::cout << "Filling your array, please check....\n";
  char *array_char = new char[arr_size];
  std::random_device rd_c;
  std::mt19937 gen_c(rd_c());
  std::uniform_int_distribution<> uid_c(30, 122);
  for (size_t i = 0; i < arr_size; i++)
    array_char[i] = uid_c(gen_c);

  std::cout << "Origin array for char type is: ";
  print_array(array_char, array_char + arr_size);
  bSort(array_char, array_char + arr_size, [](char a, char b) { return a < b; });
  std::cout << "Result of sort array: ";
  print_array(array_char, array_char + arr_size);
  delete[] array_char;

  return 0;
}
