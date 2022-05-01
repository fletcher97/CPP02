#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b ( 10 );
	Fixed const c ( 42.42f );
	Fixed const d ( b );

	a = Fixed( 1234.4321f );

	std::cout << "A is: " << a << std::endl;
	std::cout << "B is: " << b << std::endl;
	std::cout << "C is: " << c << std::endl;
	std::cout << "D is: " << d << std::endl;

	std::cout << "A is: " << a.toInt() << " as int." << std::endl;
	std::cout << "B is: " << b.toInt() << " as int." << std::endl;
	std::cout << "C is: " << c.toInt() << " as int." << std::endl;
	std::cout << "D is: " << d.toInt() << " as int." << std::endl;

	std::cout << "A is: " << a.toFloat() << " as float." << std::endl;
	std::cout << "B is: " << b.toFloat() << " as float." << std::endl;
	std::cout << "C is: " << c.toFloat() << " as float." << std::endl;
	std::cout << "D is: " << d.toFloat() << " as float." << std::endl;

	return 0;
}
