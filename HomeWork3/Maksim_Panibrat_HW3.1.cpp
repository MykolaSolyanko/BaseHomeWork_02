#include <iostream>


int main(int argc, char* argv[]) {
    std::cout << "This program reverses string\n";
    const size_t kMaxSize = 31;
    char array[kMaxSize]{};
    std::cout << "Enter string for reverse, in range of " << kMaxSize - 1 << " symbols: ";
    std::cin >> array;
    const int size = strlen(array);
    int i{};
    char* begin = { array - 1 }, * end = { begin + size }, temp_array[kMaxSize]{};
    while (*end!=*begin) {
        temp_array[i] = *end;
        --end;
        i++;
    }
    i=0;
    std::cout << "Result: ";
        while (i != kMaxSize) {
        array[i] = temp_array[i];
        if (temp_array[i] != 0) {
            std::cout << array[i];
        }
        i++;
    }
    return 0;
}
