#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b (a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << n << std::endl;
	Fixed d(n);

	std::cout << (static_cast<float>(d.getRawBits()) / (1 << 8)) << std::endl;
	std::cout << n << std::endl;

	return 0;
}
