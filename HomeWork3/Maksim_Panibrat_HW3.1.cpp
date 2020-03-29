#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "This program reverses string\n";
    const size_t kMaxSize = 31;
    char array[kMaxSize]{};
    std::cout << "Enter string for reverse, in range of " << kMaxSize - 1
        << " symbols: ";
    std::cin >> array;
    const size_t size = strlen(array);
    char* begin = { array }, * end = { begin + size };
    while (end > begin) {
        --end;
        int tmp = *begin;
        *begin = *end;
        *end = tmp;
        ++begin;
    }
    std::cout << "Result: " << array;
    return 0;
}
