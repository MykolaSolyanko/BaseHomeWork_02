#include <iostream>
#include <limits>

int count(int &value){
    size_t count {};
    for ( size_t tmp = value; tmp > 0; tmp /= 10)
        ++count;
    return count;
}
int Fsumma(int &value){
    size_t summ{};
    for ( size_t tmp = value; tmp > 0; tmp /= 10)
        summ += ( tmp % 10 );
    return summ;
}

int main()
{
    const uint8_t kHappy_Count {6};
    int happy_ticket{};
    std::cout << "Please enter your happy ticket, and pess 'Enter': ";
    while( !( std::cin >> happy_ticket ) || std::cin.fail() || count(happy_ticket) != kHappy_Count ) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cout << "You enter wrong ticket number, please try again and pess 'Enter': ";
    }
    int lSum = happy_ticket / 1000, rSum = happy_ticket % 1000;
    std::cout << (( Fsumma( lSum ) == Fsumma( rSum ) )? "Congratulations, you won!" : "Unfortunately you lost, the next time you are lucky!") << std::endl;
    return 0;
}
