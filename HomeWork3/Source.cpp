#include <iostream>

char* cin_char_array(int kSize) {
    char* array = new char[kSize];
    std::cout << "Please, enter char string with max " << kSize << " elements" << std::endl;
    std::cin >> array;
    return array;
}
int sizeof_char_array(char* array) {
    if (array == nullptr) { return 0; };
    int arr_size{ 0 };
    while (array[arr_size] != '\0') {
        ++arr_size;
    }
    return arr_size;
}
void PrintCharArrayReverse(char* array, int size) {
    if (array == nullptr) { return; };
    if (size != 0) {
        for (int i{ size - 1 }; i >= 0; --i) {
            std::cout << array[i];
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Array is empty." << std::endl;
    }
}
void PrintUpperCaseCharArray(char* array, int size) {
    if (array == nullptr) { return; }
    if (size != 0) {
        for (int i{ 0 }; i < size; ++i) {
            if (array[i] >= 97 && array[i] <= 122) {
                std::cout << char(array[i] - 32);
            }
            else { std::cout << array[i]; }
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Array is empty." << std::endl;
    }
}
void PrintLowerCaseCharArray(char* array, int size) {
    if (array == nullptr) { return; }
    if (size != 0) {
        for (int i{ 0 }; i < size; ++i) {
            if (array[i] >= 65 && array[i] <= 92) {
                std::cout << char(array[i] + 32);
            }
            else { std::cout << array[i]; }
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Array is empty." << std::endl;
    }
}
void is_digit(char* array, int size) {
    if (array == nullptr) { return; }
    if (size > 0) {
        char* dig_array = new char[size];
        int j{};
        for (int i{ 0 }; i < size; ++i) {
            if (array[i] >= 48 && array[i] <= 57) {
                dig_array[j] = array[i];
                ++j;
            }

        }
        if (j > 0) {
            std::cout << "is_digit: ";
            for (int i = 0; i < j; ++i) {
                std::cout << *(dig_array + i) << " ";
            }
        }
        else {
            std::cout << "No digits  in the string";
        }
        delete[] dig_array;
        std::cout << std::endl;
    }
    else {
        std::cout << "Array is empty." << std::endl;
    }
}

void InsertElemIntArray(int* array, int size) {}
void PartialSortElemArray(int* array, int size) {
    int tmp;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}
void PrintIntArray(int* array, int size) {
    for (int i{}; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
