
#include <iostream>

enum NUMBERS { FIRST = 1, SECOND, THIRD, FOURTH, FIFTH };

void array_input(int* begin, const int* end) {
    unsigned numbers = FIRST;
    while (begin != end) {
        std::cout << "Enter '" << numbers++ << "' element.\n";
        std::cin >> *begin;
        begin++;
    }
}

void array_print(int* begin, const int* end, const int kSize) {
    std::cout << "Result: array[" << kSize << "]{ ";
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout <<" }\n";
}

void delete_element(int* begin, const int* end, int input) {
    int count_del_elem{};
    while (begin != end) {
        if (*begin == input) {
            count_del_elem++;
            *begin = 0;
        }
        ++begin;
    }
    std::cout << "Found and deleted " << i << " elements.\n";
}

int main() {
    const size_t kSize = 5;
    std::cout << "This programm deletes elements from array.\n"
        "Array's size = "
        << kSize << std::endl;
    int array[kSize]{};
    int* begin = array;
    const int* end = begin + kSize;
    array_input(begin, end);
    array_print(begin, end, kSize);
    int input{};
    char Continue_Process = 'y';
    while (Continue_Process != 'n') {
        std::cout << "Enter, number to check its presence in array: ";
        while (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error, not number, type again: ";
        }
        delete_element(begin, end, input);
        array_print(begin, end, kSize);
        std::cout << "Continue, y/n? ";
        std::cin >> Continue_Process;
    }
    return 0;
}
