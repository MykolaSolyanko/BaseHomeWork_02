#include <iostream>
#include <cmath>

int main() 
{
    unsigned long long var {}, summ_var {};
    std::cout << "Please enter integer value:";
    std::cin >> var;
    size_t index{};
    for ( size_t tmp = var, summ {}, iter {}; tmp > 0; tmp /= 10 ) {
        summ += tmp % 10;
        ++iter;
        index = iter;
        summ_var = summ;
    }
    std::cout << "Summ of ";
    for ( size_t tmp = var, i = index; i > 0; i-- ){
        int tmp_num = tmp / pow( 10, i - 1 );
        std::cout << tmp_num;
        tmp -= tmp_num * pow( 10, i - 1 );
        if ( i < 2 ) {
            std::cout << " = ";
        }
        else {
            std::cout << " + ";
        }
    }
    std::cout << summ_var << std::endl;
    std::cout << "Arithmetic means of " << summ_var << " / " << index << " = " << ( summ_var / index ) << std::endl;
    return 0;
}
