#include <iostream>
#include <functional>
#include "Header.hpp"

const int kSize = 10000;
enum ARRAY_TYPE {
    INT = 1,
    DOUBLE,
    CHAR,
    EXIT
};

auto  moreI(int a, int b) {//какие-то глюки. не могу ни перегрузить ни вынести в Source.cpp
    return a > b;
}
auto  moreD(double a, double b) {
    return a > b;
}
auto   moreC(char a, char b) {
    return a > b;
}
auto  lessI(int a, int b) {
    return a < b;
}
auto lessD(double a, double b) {
    return a < b;
}
auto  lessC(char a, char b) {
    return a < b;
}
int main()
{
    int choise;
    do {
        std::cout << "Please, choose the type of elements of array:" << std::endl;
        std::cout << "1 integer;" << std::endl;
        std::cout << "2 double;" << std::endl;
        std::cout << "3 char." << std::endl; 
        std::cout << "4 EXIT." << std::endl;
        std::cin >> choise;
        switch (choise) {
        case ARRAY_TYPE::INT:{
            std::cout << "Please, choose the size of array (from 1 to 100)" << std::endl;
            int int_arr_size{};
            std::cin >> int_arr_size;
            int* int_arr = new int[kSize] {};
            if (int_arr_size < 10001 && int_arr_size>0) {
                std::cout << "Please, choose the type of array:" << std::endl;
                std::cout << "1 random;" << std::endl;
                std::cout << "2 custom." << std::endl;
                int choise2;
                std::cin >> choise2;
                switch (choise2) {
                case 1:{                                      
                    CreateRandArray(int_arr, int_arr_size);                 
                    PrintArray(int_arr, int_arr_size);
                    break;
                }
                case 2:{
                    CreateCustomArray(int_arr, int_arr_size);
                    PrintArray(int_arr, int_arr_size);
                    break;
                }
                default:
                    break;
                }
                std::cout << "Please, choose the type of array sorting:" << std::endl;
                std::cout << "1 more (from smaller to bigger);" << std::endl;
                std::cout << "2 less (from bigger to smaller)." << std::endl;
                std::cin >> choise2;
                switch (choise2) {
                case 1:{                   
                    BubbleSort(int_arr, int_arr_size, moreI);                                   
                    PrintArray(int_arr, int_arr_size);                  
                    QuickSortTime(int_arr, 0, int_arr_size - 1, moreI);                   
                    PrintArray(int_arr, int_arr_size);
                    break;
                }
                case 2: {
                    BubbleSort(int_arr, int_arr_size, lessI);                    
                    PrintArray(int_arr, int_arr_size);
                    QuickSortTime(int_arr, 0, int_arr_size - 1, lessI);                    
                    PrintArray(int_arr, int_arr_size);
                    break;
                }
                default:
                    break;
                }
            }
            delete[] int_arr;
            break;
            return 0;
        }
        case ARRAY_TYPE::DOUBLE:{
            std::cout << "Please, choose the size of array (from 1 to 10 000)" << std::endl;
            int double_arr_size{};
            std::cin >> double_arr_size;
            double* d_arr = new double[kSize] {};
            if (double_arr_size < 10001 && double_arr_size>0) {
                std::cout << "Please, choose the type of array:" << std::endl;
                std::cout << "1 random;" << std::endl;
                std::cout << "2 custom." << std::endl;
                int choise2;
                std::cin >> choise2;
                switch (choise2) {
                case 1: {
                    CreateRandArray(d_arr, double_arr_size);
                    PrintArray(d_arr, double_arr_size);
                    break;
                }
                case 2: {
                    CreateCustomArray(d_arr, double_arr_size);
                    PrintArray(d_arr, double_arr_size);
                    break;
                }
                default:
                    break;
                }
                std::cout << "Please, choose the type of array sorting:" << std::endl;
                std::cout << "1 more (from smaller to bigger);" << std::endl;
                std::cout << "2 less (from bigger to smaller)." << std::endl;
                std::cin >> choise2;
                switch (choise2) {
                case 1: {
                    BubbleSort(d_arr, double_arr_size, moreD);
                    PrintArray(d_arr, double_arr_size);
                    QuickSortTime(d_arr, 0, double_arr_size - 1, moreD);
                    PrintArray(d_arr, double_arr_size);
                    break;
                }
                case 2: {
                    BubbleSort(d_arr, double_arr_size, lessD);
                    PrintArray(d_arr, double_arr_size);
                    QuickSortTime(d_arr, 0, double_arr_size - 1, lessD);
                    PrintArray(d_arr, double_arr_size);
                    break;
                }
            
                default:
                    break;
                }
            }
            delete[] d_arr;
            break;
            return 0;
        }
        case ARRAY_TYPE::CHAR: {
          char *c_arr = new char[kSize]{};

          std::cout << "Please, choose the type of array:" << std::endl;
          std::cout << "1 random;" << std::endl;
          std::cout << "2 custom." << std::endl;
          int choise3;
          int char_arr_size{};
          std::cin >> choise3;
          switch (choise3) {
          case 1: {
            std::cout << "Please, choose the size of array (from 1 to 10 000)"
                      << std::endl;

            std::cin >> char_arr_size;
            CreateRandArray(c_arr, char_arr_size);
            PrintArray(c_arr, char_arr_size);
            break;
          }
          case 2: {
            c_arr = AllocCharArray(kSize);
            size_t char_arr_size = LengthCharArray(c_arr);
            PrintArray(c_arr, char_arr_size);
            break;
          }
          default:
            break;
          }
          std::cout << "Please, choose the type of array sorting:" << std::endl;
          std::cout << "1 more (from smaller to bigger);" << std::endl;
          std::cout << "2 less (from bigger to smaller)." << std::endl;
          std::cin >> choise3;
          switch (choise3) {
          case 1: {
            BubbleSort(c_arr, char_arr_size, moreC);
            PrintArray(c_arr, char_arr_size);
            // QuickSortTime(c_arr, 0, char_arr_size - 1, moreC);
            PrintArray(c_arr, char_arr_size);
            break;
          }
          case 2: {
            BubbleSort(c_arr, char_arr_size, lessC);
            PrintArray(c_arr, char_arr_size);
            //  QuickSortTime(c_arr, 0, char_arr_size - 1, lessC);
            PrintArray(c_arr, char_arr_size);
            break;
          }

          default:
            break;
          }

          delete[] c_arr;
          break;
          return 0;
        }
        case ARRAY_TYPE::EXIT:{
            return 0;
        }
        default:
            break;
        }
    } while (true);
     
     
    return 0;
}
