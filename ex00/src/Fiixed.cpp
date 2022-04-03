#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_n = 0;
}

Fixed::Fixed(Fixed const &other)
{
	this->_n = other._n;
}

Fixed::~Fixed(){}

Fixed&
Fixed::operator=(Fixed const &other)
{
	this->_n = other._n;
	return *this;
}

int
Fixed::getRawBits() const
{
	return (this->_n);
}

void
Fixed::setRawBits(int const  raw)
{
	this->_n = raw;
}
