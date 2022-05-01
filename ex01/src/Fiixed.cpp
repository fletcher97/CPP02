#include <iostream>
#include <cmath>
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

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_n = n << _precision;
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_n = roundf(n * (1 << _precision));
	std::cout << "Float constructor value " << this->_n << std::endl;
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
	return (this->_n);
}

void
Fixed::setRawBits(int const  raw)
{
	this->_n = raw;
}

int
Fixed::toInt() const
{
	return this->_n >> _precision;
}

float
Fixed::toFloat() const
{
	return this->_n / static_cast<float>(1 << _precision);
}

std::ostream&
operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
