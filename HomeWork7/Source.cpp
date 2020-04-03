#include <iostream>
#include <random>
#include <functional>

void CreateRandArray(char* array, const int size) {
    std::random_device rd;
    std::mt19937 mersenne{ rd() };
    // std::knuth_b gen1;
    std::uniform_int_distribution <> dist('0', 'z');
    int index{};
    while (index < size) {
        int rand = dist(mersenne);
        if (((rand > '@') && (rand < '[')) || (rand > '`') || (rand < ':')) {
            *(array + index++) = rand;
        }
    }
}
void CreateRandArray(int* array, const int size) {
    std::random_device rd;
    std::mt19937 mersenne{ rd() };
    std::uniform_int_distribution<int> dist(0, size);
    for (int i{}; i < size; ++i) {
        *(array + i) = dist(mersenne);
    };
}
void CreateRandArray(double* array, const int size) {
    std::random_device rd;
    std::mt19937 mersenne{ rd() };
    std::uniform_real_distribution<double> dist(0, size);
    for (int i{}; i < size; ++i) {
        *(array + i) = dist(mersenne);
    }
}

