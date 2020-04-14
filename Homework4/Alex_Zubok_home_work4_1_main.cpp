#include "sorts.hpp"

int main() {
  std::cout << "Please enter size of array: ";
  size_t arr_size{};
  std::cin >> arr_size;
  std::cout << "Please enter how you fill integer array: 1) manual, 2) auto: ";
  uint16_t fill_array{};
  std::cin >> fill_array;
  int *array_quick = new int[arr_size];
  int *array_buble = new int[arr_size];
  if (fill_array == eManual) {
    for (size_t i = 0; i < arr_size; i++)
      std::cin >> array_quick[i];
  } else if (fill_array == eAuto) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uid(0, 100);
    for (size_t i = 0; i < arr_size; i++)
      array_quick[i] = uid(gen);
  } else
    std::cout << "You don't entered the type of filling the array!";
  memcpy(array_buble, array_quick, sizeof(int) * arr_size);
  std::cout << "Origin array for both sorts is : ";
  print_array(array_quick, array_quick + arr_size);
  auto start = std::chrono::system_clock::now();
  qSort(array_quick, array_quick + arr_size,
        [](int a, int b) { return a > b; });
  auto end = std::chrono::system_clock::now();
  std::cout << "Result of quick sort array: ";
  print_array(array_quick, array_quick + arr_size);
  std::cout << "Time for sorting is: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                   .count()
            << " nanoseconds" << std::endl;

  start = std::chrono::system_clock::now();
  bSort(array_buble, array_buble + arr_size,
        [](int a, int b) { return a > b; });
  end = std::chrono::system_clock::now();
  std::cout << "Result of buble sort array: ";
  print_array(array_buble, array_buble + arr_size);
  std::cout << "Time for sorting is: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                   .count()
            << " nanoseconds" << std::endl;
  delete[] array_quick;
  delete[] array_buble;
  return 0;
}
