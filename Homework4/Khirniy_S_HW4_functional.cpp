#include "Khirniy_S_HW4_Head.h"
#include <chrono>
#include <iostream>
#include <random>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void BubbleSortArray(int* array, int size, IntCompare compare) {
    for (int i{}; i < size - 1; ++i) {
        for (int j{}; j < size - i - 1; ++j) {
            if (compare(*(array + j), *(array + j + 1))) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}
void BubbleSortTime(int* array, int size, IntCompare compare) {
    auto begin = std::chrono::high_resolution_clock::now();
    BubbleSortArray(array, size, compare);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_mcs =
        std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The bubble sort time is: " << elapsed_mcs.count()
        << " microseconds" << std::endl;
}
void QuickSortArray(int* array, int low, int high, IntCompare compare) {
    int i{ low };
    int j{ high };
    int pivot = array[(i + j) / 2];
    while (i <= j) {
        while (!(compare(array[i], pivot) || (array[i] == pivot))) {
            i++;
        }
        while (compare(array[j], pivot)) {
            j--;
        }
        if (i <= j) {
            swap(array[j], array[i]);
            i++;
            j--;
        }
    }
    if (j > low)
        QuickSortArray(array, low, j, compare);
    if (i < high)
        QuickSortArray(array, i, high, compare);
}
void QuickSortTime(int* array, int low, int high, IntCompare compare) {
    auto begin = std::chrono::high_resolution_clock::now();
    QuickSortArray(array, low, high, compare);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_mcs =
        std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The quick sort time is: " << elapsed_mcs.count()
        << " microseconds" << std::endl;
}
void CreateRandomIntArray(int* array, const int size) {
    std::random_device rd;
    std::mt19937_64 marsenne{ rd() };
    std::uniform_int_distribution<int> dist(0, size);
    for (int i{}; i < size; i++) {
        *(array + i) = dist(marsenne);
    }
}
void CreateManualIntArray(int* array, const int size) {
    int a{};
    for (int i{}; i < size; ++i) {
        std::cout << "Enter the " << i + 1 << "th element of array: " << std::endl;
        std::cin >> a;
        *(array + i) = a;
    }
}
void PrintArray(int* array, const int size) {
    for (int i{}; i < size; ++i) {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;
}
void CreateIntArray(int* array, int size) {
    std::cout << "Please, choose the type of array:" << std::endl;
    std::cout << "1 manual filling array;" << std::endl;
    std::cout << "2 random filling array." << std::endl;
    int choise2;
    std::cin >> choise2;
    enum ARRAY_CREATE { MANUAL = 1, RANDOM };
    switch (choise2) {
    case ARRAY_CREATE::MANUAL: {
        CreateManualIntArray(array, size);
        PrintArray(array, size);
        break;
    }
    case ARRAY_CREATE::RANDOM: {
        CreateRandomIntArray(array, size);
        PrintArray(array, size);
        break;
    }
    default:
        break;
    }
}
bool to_bigger(int a, int b) { return a > b; }
bool to_smaller(int a, int b) { return a < b; }
void SortArray(int* array, int size) {
    std::cout << "Please, choose the type of array sorting:" << std::endl;
    std::cout << "1 from smaller to bigger;" << std::endl;
    std::cout << "2 from bigger to smaller." << std::endl;
    int choise2{};
    std::cin >> choise2;
    enum ORDER { TO_BIGGER = 1, TO_SMALLER };
    switch (choise2) {
    case ORDER::TO_BIGGER: {
        auto Fptr = static_cast<bool (*)(int, int)>(&to_bigger);
        BubbleSortTime(array, size, Fptr);
        PrintArray(array, size);
        QuickSortTime(array, 0, size - 1, Fptr);
        PrintArray(array, size);
        break;
    }
    case ORDER::TO_SMALLER: {
        auto Fptr = static_cast<bool (*)(int, int)>(&to_smaller);
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
