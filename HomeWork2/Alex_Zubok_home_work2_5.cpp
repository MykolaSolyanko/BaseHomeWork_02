#include <iostream>

bool is_delimiter(int value, int value_delim){
    return ( value % value_delim ) == 0;
}
int summ_number( int value ){
    int summ{};
    const uint8_t kTen = 10;
    for ( int tmp = value; tmp > 0; tmp /= kTen )
        summ += ( tmp % kTen );
    return summ;
}

int main(){
    unsigned int value{};
    std::cin >> value;
    for ( int i = value; i > 0; i-- ) {
        if ( is_delimiter( value, i ) ) {
            for ( int j = i - 1; j > 0; j-- ){
                if ( is_delimiter( value, j ) ) {
                    if ( summ_number( i ) > summ_number( j ) ) {
                        std::cout << "Best delimiter is " << i << std::endl;
                        return 0;
                    }
                    else {
                        std::cout << "Best delimiter is " << j << std::endl;
                        return 0;
                    }
                }
            }
        }
    }
}
