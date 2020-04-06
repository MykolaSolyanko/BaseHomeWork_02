#include <iostream>
#include <random>
#include "Header.h"

void Manual_array(int* begin, const int* end) {
    std::cout << "You choosed manual array input.\n"
        "Enter elements, that bigger than 0: \n";

    for (begin; begin != end; ++begin) {
        std::cin >> *begin;
        while (*begin < 0) {
            std::cout << "Error, less than 0, type again: ";
            std::cin >> *begin;
        }
    }
}


void Random_array(int* begin, const int* end) {
    std::cout << "You choosed random array.\n";
    std::mt19937 generator{};
    int kMinRange = 0, kMaxRange = 16;
    std::uniform_int_distribution <int> distribution(kMinRange, kMaxRange);
    for (begin;begin != end;++begin)
    {
        *begin = distribution(generator);
    }
}

void Array_result(int* begin, const int* end, const size_t kSize) {
    std::cout << "result: array[" << kSize << "]{";
    for (begin; begin != end; ++begin) {
        std::cout << *begin << " ";
    }
    std::cout << "}\n";
}

static void Swap(int* lhs, int* rhs) {
    std::cout << "swaping : lhs" << *lhs << ", rhs " << *rhs << "\n";
    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
    std::cout << "swap result: lhs" << *lhs << ", rhs " << *rhs << "\n";
}

void Bubble_sort(int* begin, const int* end, Comparison comp) {
    for (int* bubble = begin; bubble != end;++bubble) {
        for (int* next_bubble = begin; next_bubble != end;++next_bubble) {
            if (comp(*bubble, *next_bubble)) {
                Swap(bubble, next_bubble);
            }
        }
    }
}

int* partition(int* begin, int* end, Comparison comp) {
    int*  pivot = end;
    int* i = (begin - 1);
    for (int* j = begin; j != end; j++) {
        if (comp(*j, *pivot)) {
            i++;
            Swap(i, j);
        }
    }
    Swap((i + 1), end);
    return (i + 1);
}

void Quick_sort(int* begin, int* end, Comparison comp) {
    if (begin < end) {
        int* pi = partition(begin, end, comp);
        Quick_sort(begin, (pi - 1), comp);
        Quick_sort((pi + 1), end, comp);
    }
}
