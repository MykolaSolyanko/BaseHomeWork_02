#include <iostream>
#include <cmath>

size_t count(int value){
    size_t count {};
    const uint8_t kZero = 0;
    for ( int tmp = ( value > kZero)? value : -value; tmp > kZero; tmp /= 10 )
        ++count;
    return count;
}

int main() {
    int value {}, rev_value {};
    const uint8_t kTen = 10;
    std::cout << "Please enter your number that need to reverse: ";
    std::cin >> value;
    for( int tmp = value, i = count(value); i > 0; i--, tmp /= kTen )
        rev_value += ( ( tmp % kTen ) * pow(kTen, ( count(tmp) - 1 ) ) );
    
    std::cout << "My reverse value = " << rev_value << std::endl;

    return 0;
}
