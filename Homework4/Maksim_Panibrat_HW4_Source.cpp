#include <iostream>
#include <random>
#include "Header.h"

void Manual_array(int* begin, int* end) {
    std::cout << "You choosed manual array input.\n"
        "Enter elements, that bigger than 0: \n";

    for (begin; begin != end; ++begin) {
        std::cin >> *begin;
        while (*begin < 0) {
            std::cout << "Error, less than 0, type again: ";
            std::cin >> *begin;
        }
    }
    return;
}


void Random_array(int* begin, int* end) {
    std::cout << "You choosed random array.\n";
    std::mt19937 generator(0);
    std::uniform_int_distribution<int> distribution(0, 16);
    for (begin;begin != end;++begin)
    {
        *begin = distribution(generator);
    }
    return;
}

void Array_result(int* begin, int* end, const size_t kSize) {
    std::cout << "result: array[" << kSize << "]{";
    for (begin; begin != end-1; ++begin) {
        std::cout << *begin << ",";
    }
    std::cout << *begin << "}\n";
    return;
}

static void Swap(int* lhs, int* rhs) {
    std::cout << "swaping : lhs" << *lhs << ", rhs " << *rhs << "\n";
    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
    std::cout << "swap result: lhs" << *lhs << ", rhs " << *rhs << "\n";
    return;
}

void Bubble_sort(int* begin, int* end, Comparison comp) {
    for (int* bubble = begin; bubble != end;++bubble) {
        for (int* next_bubble = begin; next_bubble != end;++next_bubble) {
            if (comp(*bubble, *next_bubble)) {
                Swap(bubble, next_bubble);
            }
        }
    }
    return;
}

int* partition(int* begin, int* end, Comparison comp) {
    int*  pivot = end;
    int* i = (begin - 1);
    for (int* j = begin; j <= end - 1;j++) {
        if (comp(*j, *pivot)) {
            i++;
            Swap(i, j);
        }
    }
    Swap((i + 1), end);
    return (i + 1);
}

void Quick_sort(int* begin, int*end, Comparison comp) {
    if (begin<end) {
        int* pi = partition(begin, end, comp);
        Quick_sort(begin, (pi - 1), comp);
        Quick_sort((pi + 1), end, comp);
    }
    return;
}
