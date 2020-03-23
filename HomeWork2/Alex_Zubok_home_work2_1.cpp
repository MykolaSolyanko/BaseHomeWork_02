#include <iostream>
#include <cmath>

int main() 
{
    unsigned long long var {}, summ_var {};
    std::cout << "Please enter integer value:";
    std::cin >> var;
    size_t index{};
    const uint8_t kZero = 0;
    const uint8_t kTen = 10;
    for ( size_t tmp = var, summ {}; tmp > kZero; tmp /= kTen ) {
        summ += tmp % kTen;
        ++index;
        summ_var = summ;
    }
    std::cout << "Summ of ";
    for ( size_t tmp = var, i = index; i > kZero; i-- ){
        int tmp_num = tmp / pow( kTen, i - 1 );
        std::cout << tmp_num;
        tmp -= tmp_num * pow( kTen, i - 1 );
        std::cout << ( i < 2 : " = " : " + " );
    }
    std::cout << summ_var << std::endl;
    std::cout << "Arithmetic means of " << summ_var << " / " << index << " = " << ( summ_var / index ) << std::endl;
    return 0;
}
