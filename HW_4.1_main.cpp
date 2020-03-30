#include <iostream>
#include <chrono>
#include <ctime>
#include "header.hpp"

int main()
{
    std::cout << "This program sorts array using one of two metods: bubble sort or quick sort.\n";
    std::cout << "Array input methods list:\n"
        "\t1 - Manual input\n"
        "\t2 - Random input\n"
        "Select input method from list: ";

    const size_t kSize = 30;
    int array[kSize]{};
    int* begin = { array }, * end = begin + kSize;
    int select;
    std::cin >> select;
    switch(select){
    case(INPUT::MANUAL_INPUT):
        Manual_array(begin, end);
        std::cout << "Manual input ";
        break;
    case(INPUT::RANDOM_INPUT):
        Random_array(begin, end);
        std::cout << "Random input ";
        break;
    default:
        std::cout << "Error undefined selection, starting default input method.\n";
        Random_array(begin, end);
        std::cout << "Random input ";
        break;
    }
    Array_result(begin, end, kSize);

    auto direction = [](int a, int b) { return a < b; }; /*sort less to left side  return a < b
                                                           sort less to right side return a > b*/

    std::cout << "Sort methods list:\n"
        "\t1 - Bubble sort\n"
        "\t2 - Quick sort\n"
        "Select sort method from list: ";

    std::cin >> select;

    std::chrono::time_point<std::chrono::system_clock> start, end_t;
    start = std::chrono::system_clock::now();

    switch (select) {
    case(SORT::BUBBLE_SORT):
        Bubble_sort(begin,end, direction);
        std::cout << "Bubble sort ";
        break;
    case(SORT::QUICKSORT):
        end = end - 1;
        Quick_sort(begin, end, direction);
        std::cout << "Quick sort ";
        break;
    default:
        std::cout << "Error, undefined selection, starting default bubble sort.\n";
        Bubble_sort(begin, end, direction);
        std::cout << "Bubble sort ";
        break;
    }

    end_t = std::chrono::system_clock::now();
    float elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
        (end_t - start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end_t);

    Array_result(begin, end, kSize);

    std::cout << "Time: " << elapsed_seconds << "s\n";

    return 0;
}
