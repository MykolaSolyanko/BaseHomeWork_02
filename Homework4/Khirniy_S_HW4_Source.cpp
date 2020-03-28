#include "Khirniy_S_HW4_Head.h"
#include <iostream>

const int kMaxSize = 1000;
const int kMinSize = 0;

int main() {

    std::cout << "Select size of array from " << kMinSize << " to " << kMaxSize
        << std::endl;
    int int_arr_size{};
    std::cin >> int_arr_size;
    int* int_arr = new int[int_arr_size] {};
    if (int_arr_size <= kMaxSize && int_arr_size > kMinSize) {
        CreateIntArray(int_arr, int_arr_size);
        SortArray(int_arr, int_arr_size);
        return 0;
    }
}
