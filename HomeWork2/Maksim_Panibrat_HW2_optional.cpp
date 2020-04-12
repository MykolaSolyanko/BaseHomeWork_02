#include <iostream>

void Christmas_Tree() {
    std::cout << "This program prints christmas tree from stars\n"
        "Enter tree size (max number of stars):  ";
    size_t max_stars_number;
    std::cin >> max_stars_number;
    if (max_stars_number % 2 == 0) {
        max_stars_number += 1;
    }
    char star = '*', null = ' ';
    const size_t half_max_stars = max_stars_number / 2;
    for (size_t string_number = 0; string_number < half_max_stars + 1;
        ++string_number) {
        for (size_t i = 0; i < max_stars_number; i++) {
            if (i < (half_max_stars - string_number) ||
                i >(half_max_stars + string_number)) {
                std::cout << null;
            }
            else {
                std::cout << star;
            }
        }
        std::cout << std::endl;
    }
}

void Bit_Counter() {
    std::cout << "This programm counts set bits.\n";
    size_t input;
    short set_bits{};
    std::cout << "Enter number for analize: ";
    size_t size_bit{ sizeof(input) * 8 };
    size_t current_index_bit{};
    for (std::cin >> input; current_index_bit != size_bit; ++current_index_bit) {
        if ((input & 1 << current_index_bit) != 0) {
            set_bits++;
        }
    }
    std::cout << "Number of set bits: " << set_bits << std::endl;
}

void Set_Bit() {
    std::cout << "This programm checks if bit is set.\n"
        "Enter number for analize: ";
    size_t input;
    std::cin >> input;
    std::cout << "Enter bit for check: ";
    size_t bit;
    std::cin >> bit;
    size_t check = 1LL << bit;
    std::cout << "Selected bit-number: " << check << std::endl;
    std::cout << ((check & input) ? "Yes" : "No");
}

enum { CHRISTMAS_TREE = 1, BIT_COUNTER, SET_BIT };

int main() {
    std::cout << "Select program: \n"
        "1: Christmas tree\n"
        "2: Bit counter\n"
        "3: Set bits\n";
    int select;
    std::cin >> select;
    switch (select) {
    case CHRISTMAS_TREE:
        Christmas_Tree();
        break;
    case BIT_COUNTER:
        Bit_Counter();
        break;
    case SET_BIT:
        Set_Bit();
        break;
    default:
        std::cout << "End of program\n";
        return 0;
    }
    return 0;
}
