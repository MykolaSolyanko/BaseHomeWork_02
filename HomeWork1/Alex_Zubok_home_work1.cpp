#include <iostream>
#include <limits>
#include <cmath>

int main() 
{
    long long var_a {};
    size_t kMin = 1, kMax = 500;
    std::cout << "Please enter value for variable 'a' from 1 till 500, and press 'Enter':";
    while ( !( std::cin >> var_a ) || std::cin.fail() || var_a < kMin || var_a > kMax ) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<long long>::max(), '\n');
        std::cout << "You set incorrect value for variable 'a', please enter again variable 'a' from 1 till 500, and press 'Enter':";
    }
    std::cout << "You are successfully set variable 'a' = " << var_a << std::endl;
    
    
    long long var_b {};
    std::cout << "Please enter value for variable 'b' from 1 till 500, and press 'Enter':";
    while ( ! ( std::cin >> var_b ) || std::cin.fail() || var_b < kMin || var_b > kMax ) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<long long>::max(), '\n');
        std::cout << "You set incorrect value for variable 'b', please enter again variable 'b' from 1 till 500, and press 'Enter':";
        
    }
    std::cout << "You are successfully set variable 'b' = " << var_b << std::endl;

    long long var_c {};
    std::cout << "Please enter value for variable 'c' from 1 till 500, and press 'Enter':";
    while ( ! ( std::cin >> var_c ) || std::cin.fail() || var_c < kMin || var_c > kMax ) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<long long>::max(), '\n');
        std::cout << "You set incorrect value for variable 'c', please enter again variable 'c' from 1 till 500, and press 'Enter':";
        
    }
    std::cout << "You are successfully set variable 'c' = " << var_c << std::endl;
    
    const uint8_t Kfour = 4;
    const uint8_t Ktwo = 2;

    long long disc = ( var_b * var_b ) - ( Kfour * var_a * var_c ) ;

    if ( disc > 0 ) {
        double x1 = ( -var_b + std::sqrt( disc ) ) / ( Ktwo * var_a );
        double x2 = ( -var_b - std::sqrt( disc ) ) / ( Ktwo * var_a );
        std::cout << "We have two roots!" << std::endl;
        std::cout << "Value of variable 'x1' = " << x1 << std:: endl;
        std::cout << "Value of variable 'x2' = " << x2 << std:: endl;
    }
    else if ( disc == 0 ) {
        double x = ( -var_b ) / ( Ktwo * var_a );
        std::cout << "We have one roots!" << std::endl;
        std::cout << "Value of variable 'x' = " << x << std:: endl;
    }
    else {
        std::cout << "We don't have any roots!" << std::endl;
    }

    return 0;
}
