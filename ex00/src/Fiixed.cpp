#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&
Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n = other.getRawBits();
	return *this;
}

int
Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

void
Fixed::setRawBits(int const  raw)
{
	this->_n = raw;
}
