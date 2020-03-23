#include <iostream>

bool range_check( long long x, int a, int b ){
    return ( x >= a  ) && ( x <= b );
}

bool modul_remainder( int value, unsigned int modul_value ){
    return ( value % modul_value ) != 0;
}

void check_valid_input( int &value, int a, int b ){
    while ( !( std::cin >> value ) || ! ( range_check( value, a, b ) ) ) {
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );
        std::cout << "Sorry, you enter invalid number of quantity inputs, please enter again[" << a << " - " << b << "]: ";
    }
}

int main(){
    int iter{};
    const int kMin_inputs = -60, kMin_range = 1;
    const int kMax_inputs = 90, kMax_range = 50;
    std::cout << "Please enter number of quantity inputs number from 1 till 50: ";
    check_valid_input( iter, kMin_range, kMax_range );
    std::cout << "Please enter " << iter << " inputs[ " << kMin_inputs << " - " << kMax_inputs << " ]." << std::endl;
    long long summ{};
    const int kTwo = 2;
    for ( size_t index = 1; index <= iter; index++){
        int tmp {};
        std::cout << "Enter " << index << " value: ";
        check_valid_input( tmp, kMin_inputs, kMax_inputs );
        if ( modul_remainder(tmp, kTwo) )
            summ += tmp;
    }

    std::cout << "The sum of the pair numbers is " << summ << std::endl;

    return 0;
}
