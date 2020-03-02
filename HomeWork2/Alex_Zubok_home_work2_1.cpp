#include <iostream>

int main() 
{
    long long var {}, summ_var {};
    std::cout << "Please enter integer value:";
    std::cin >> var;
    size_t index{};
    for ( size_t tmp = var, summ {}, iter {}; tmp > 0; tmp/=10) {
        summ += tmp % 10;
        ++iter;
        index = iter;
        summ_var = summ;
    }
    std::cout << "Summ of " << var << " value = " << summ_var << std::endl;
    std::cout << "Arithmetic means of " << var << " value = " << ( summ_var / index ) << std::endl;
    return 0;
}
