#include "Header.h"

const size_t kSize = 20;

template <typename T>
void Array_result(T* begin, const T* end, const size_t kSize) {
    std::cout << "result: array[" << kSize << "]{";
    for (begin; begin != end; ++begin) {
        std::cout << *begin << " ";
    }
    std::cout << "}\n";
}

template <typename T> void Swap(T* lhs, T* rhs) {
    std::cout << "swaping : lhs" << *lhs << ", rhs " << *rhs << "\n";
    T tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
    std::cout << "swap result: lhs" << *lhs << ", rhs " << *rhs << "\n";
}

template <typename T>
void Bubble_sort(T* begin, const T* end, Comparison comp) {
    for (T* bubble = begin; bubble != end; ++bubble) {
        for (T* next_bubble = bubble + 1; next_bubble != end; ++next_bubble) {
            if (comp(*bubble, *next_bubble)) {
                Swap(bubble, next_bubble);
            }
        }
    }
}

template <typename T> void Sort_settings(T* begin, T* end) {
    std::cout << "Select sort side: \n"
        "\t1 - left\n"
        "\t2 - right\n";
    short select;
    std::cin >> select;
    switch (select) {
    case LEFT: {
        auto comp = [](T a, T b) { return a > b; };
        Bubble_sort(begin, end, comp);
        break;
    }
    case RIGHT: {
        auto comp = [](T a, T b) { return a < b; };
        Bubble_sort(begin, end, comp);
        break;
    }
    default: {
        std::cout << "Error, using default-left side.\n";
        auto comp = [](T a, T b) { return a > b; };
        Bubble_sort(begin, end, comp);
        break;
    }
    }
}

template <typename T> void Random_whole_array(T* begin, const T* end) {
    std::mt19937 generator{};
    T kMin, kMax;
    std::cout << "Enter min number: ";
    std::cin >> kMin;
    std::cout << "Enter max number: ";
    std::cin >> kMax;
    std::uniform_int_distribution<T> distribution(kMin, kMax);
    for (; begin != end; ++begin) {
        *begin = distribution(generator);
    }
}

template <typename T> void Create_whole_array() {
    T array[kSize]{};
    T* begin = { array };
    T* end = begin + kSize;
    Random_whole_array(begin, end);
    std::cout << "Random input ";
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
}

void Create_whole() {
    std::cout << "Select real number type: \n"
        "\t1 - short\n"
        "\t2 - int\n"
        "\t3 - long\n";
    short select;
    std::cin >> select;
    switch (select) {
    case SHORT: {
        Create_whole_array <short>();
        break;
    }
    case INT: {
        Create_whole_array <int>();
        break;
    }
    case LONG: {
        Create_whole_array <long>();
        break;
    }
    default: {
        std::cout << "Error, using default int type.\n";
        Create_whole_array <int>();
        break;
    }
    }
}

template <typename T> void Random_fractional_array(T* begin, const T* end) {
    std::mt19937 generator{};
    T kMin, kMax;
    std::cout << "Enter min number: ";
    std::cin >> kMin;
    std::cout << "Enter max number: ";
    std::cin >> kMax;
    std::uniform_real_distribution<T> distribution(kMin, kMax);
    for (; begin != end; ++begin) {
        *begin = distribution(generator);
    }
}

template <typename T> void Create_fractional_array() {
    T array[kSize]{};
    T* begin = { array };
    T* end = begin + kSize;
    Random_fractional_array(begin, end);
    std::cout << "Random input ";
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
}

void Create_fractional() {
    std::cout << "Select real number type: \n"
        "\t1 - float\n"
        "\t2 - double";
    short select;
    std::cin >> select;
    switch (select) {
    case FLOAT: {
        Create_fractional_array <float>();
        break;
    }
    case DOUBLE: {
        Create_fractional_array <double>();
        break;
    }
    default: {
        std::cout << "Error, using default float type.\n";
        Create_fractional_array <float>();
        break;
    }
    }
}

void Random_char_array(char* begin, const char* end) {
    std::mt19937 generator{};
    int kUpperMin = 'A';
    int kUpperMax = 'Z';
    std::uniform_int_distribution<int> distribution_upper(kUpperMin, kUpperMax);
    int kLowerMin = 'a';
    int kLowerMax = 'z';
    std::uniform_int_distribution<int> distribution_lower(kLowerMin, kLowerMax);
    std::uniform_int_distribution<int> distribiton_switch(UPPER, LOWER);
    for (; begin != end; ++begin) {
        *begin = distribiton_switch(generator) ? distribution_upper(generator)
            : distribution_lower(generator);
    }
}

void Create_char() {
    char array[kSize]{};
    char* begin = { array };
    char* end = begin + kSize;
    Random_char_array(begin, end);
    std::cout << "Random input ";
    std::cout << array;
    Array_result(begin, end, kSize);

    Sort_settings(begin, end);
    std::cout << "Bubble sort ";
    Array_result(begin, end, kSize);
}
