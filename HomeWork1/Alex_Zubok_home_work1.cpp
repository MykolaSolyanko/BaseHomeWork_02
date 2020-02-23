#include <iostream>
#include <cmath>

int main() 
{
    long long var_a {};
    std::cout << "Please enter value for variable 'a' from 1 till 500, and press 'Enter':";
    while ( std::cin ) {
        std::cin >> var_a;
        if ( var_a < 1 || var_a > 500 ) {
            std::cout << var_a << std::endl;
            std::cout << "You set incorrect value for variable 'a', please enter again variable 'a' from 1 till 500, and press 'Enter':";
        }
        else
            break;
        
    }
    std::cout << "You are successfully set variable 'a' = " << var_a << std::endl;
    
    
    long long var_b {};
    std::cout << "Please enter value for variable 'b' from 1 till 500, and press 'Enter':";
    while ( std::cin ) {
        std::cin >> var_b;
        if ( var_b < 1 || var_b > 500 ) {
            std::cout << var_b << std::endl;
            std::cout << "You set incorrect value for variable 'b', please enter again variable 'b' from 1 till 500, and press 'Enter':";
        }
        else
            break;
        
    }
    std::cout << "You are successfully set variable 'b' = " << var_b << std::endl;

    long long var_c {};
    std::cout << "Please enter value for variable 'c' from 1 till 500, and press 'Enter':";
    while ( std::cin ) {
        std::cin >> var_c;
        if ( var_c < 1 || var_c > 500 ) {
            std::cout << var_c << std::endl;
            std::cout << "You set incorrect value for variable 'c', please enter again variable 'c' from 1 till 500, and press 'Enter':";
        }
        else
            break;
        
    }
    std::cout << "You are successfully set variable 'c' = " << var_c << std::endl;
    
    const uint8_t fourth = 4;

    long long disc = ( var_b * var_b ) - ( fourth * var_a * var_c ) ;

    if ( disc > 0 ) {
        const uint8_t twice = 2;
        double x1 {}, x2 {};
        x1 = ( -var_b + std::sqrt( disc ) ) / ( twice * var_a );
        x2 = ( -var_b - std::sqrt( disc ) ) / ( twice * var_a );

        std::cout << "We have two roots!" << std::endl;
        std::cout << "Value of variable 'x1' = " << x1 << std:: endl;
        std::cout << "Value of variable 'x2' = " << x2 << std:: endl;
    }
    else if ( disc == 0 ) {
        double x {};
        const uint8_t twice = 2;
        x = -var_b / ( twice * var_a );
        std::cout << "We have one roots!" << std::endl;
        std::cout << "Value of variable 'x' = " << x << std:: endl;
    }
    else {
        std::cout << "We don't have any roots!" << std::endl;
    }

    return 0;
}
