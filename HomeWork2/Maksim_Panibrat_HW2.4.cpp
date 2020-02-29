#include <iostream>

int main() {
    std::cout << "This programm sums up even numbers.\n Uneven numbers will be "
        "discarded.\n";
    const int kMinNumber = 1, kMaxNumber = 50;
    std::cout << "Enter amount of numbers in range [" << kMinNumber << "..."
        << kMaxNumber << "]\n";
    int number;
    std::cin >> number;
    while (number < kMinNumber || number > kMaxNumber) {
        std::cout << "Error, out of amount range\n";
        std::cin >> number;
    }
    const int kMinValue = -60, kMaxValue = 90;
    std::cout << "Enter numbers in range [" << kMinValue << "..." << kMaxValue
        << "]\n";
    size_t sum{ 0 }, iter{ 1 };
    while (iter <= number) {
        int value;
        std::cin >> value;
        if (value < kMinValue || value > kMaxValue) {
            std::cout << "Error, out of value range, please try again\n";
            continue;
        }
        if (value % 2) {
            sum += value;
        }
        ++iter;
    }
    std::cout << "Sum of even numbers = " << sum << std::endl;
    return 0;
}
