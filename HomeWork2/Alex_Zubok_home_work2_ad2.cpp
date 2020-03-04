#include <iostream>
#include <bitset>

int main()
{
	unsigned long value {};
	std::cout << "Please enter number from 0 till 255: ";
	std::cin >> value;
	std::bitset<8> one_byte(value);
	std::cout << "Integer number is " << value << " ---> " << one_byte << " > number of bites set is " << one_byte.count() << std::endl;
	return 0;
}
