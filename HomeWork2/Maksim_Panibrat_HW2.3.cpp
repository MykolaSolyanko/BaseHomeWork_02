#include <iostream>

void reverse_num(int number) {
    int reverse_num{};
    while (number != 0){
        reverse_num *= 10;
        reverse_num += number % 10;
        number /= 10;
    }
    std::cout << "Result: " << reverse_num << std::endl;
}


int main(int argc, char* argv[]) {
    std::cout << "This program turns number in reverse.\n"
    "Enter number to reverse it\n";
    int number;
    std::cin >> number;
    reverse_num(number);

    return 0;
}
