#include <iostream>


int main(int argc, char* argv[]) {
    std::cout << "This programm sums up even numbers.\n Uneven numbers will be "
        "discarded.\n"
    "Enter number of values: \n";
    int number;
    std::cin >> number;
    int sum{}, i = 1;
    while (number != 0) {
        int value;
        std::cout << "Enter value"<< i<<": ";
        std::cin >> value;
        if (value % 2 != 0) {
            sum += value;
        }
        --number;
        i++;
    }
    std::cout << "Sum of even numbers: " << sum << std::endl;
    return 0;
}
