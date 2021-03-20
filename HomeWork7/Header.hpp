#pragma once
extern const int kSize;
template <typename T> void PrintArray(const T* array, const int size) {
    for (int i{}; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
template <typename T> void swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
template <typename T1, typename T2> void BubbleSort(T1* arrptr, int size, T2 comp) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            auto* first = (arrptr + j);
            auto* second = (arrptr + j + 1);
            if (comp(*first, *second)) {
                swap(*first, *second);
            }
        }
    }
}
template <typename T>
void CreateRandArray(T* array, const int size){}
template <> void CreateRandArray <int> (int* array, const int size) {
    std::random_device rd;
    std::mt19937 mersenne{ rd() };
    std::uniform_int_distribution<int> dist(0, size);
    for (int i{}; i < size; ++i) {
        *(array + i) = dist(mersenne);
    };
}
template <>
void CreateRandArray<double>(double* array, const int size) {
    std::random_device rd;
    std::mt19937 mersenne{ rd() };
    std::uniform_real_distribution < double > dist(0, size);
    for (int i{}; i < size; ++i) {
        *(array + i) = dist(mersenne);
    }
}

template <>
void CreateRandArray<char>(char* array, const int size) {
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
template <typename T>
void RandArrSort() {
    std::cout << "Please, choose the size of array (from 1 to 10 000)" << std::endl;
    int size{};
    std::cin >> size;
    T* arr = new T[size] {};
    if (size <= kSize && size > 0) {
        CreateRandArray(arr, size);
        PrintArray(arr, size);
        BubbleSort(arr, size, [](T a, T b) {
            return (a < b);
            });
        PrintArray(arr, size);
    }
    delete[] arr;
}
