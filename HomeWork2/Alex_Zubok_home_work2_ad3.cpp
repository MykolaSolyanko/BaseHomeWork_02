#include <iostream>
#include <bitset>

int main()
{
	unsigned long value {}, number {};
  const int kOne = 1;
	std::cout << "Please enter number from 0 till 255: ";
	std::cin >> value >> number;
	std::bitset<8> one_byte(value);

	std::cout << ( ( one_byte.test( number - kOne ) )? "Yes":"No" ) << std::endl;
	return 0;
}
