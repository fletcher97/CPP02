#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// OBJ creation/destruction

Fixed::Fixed()
{
	this->_n = 0;
}

Fixed::Fixed(Fixed const &other)
{
	*this = other;
}

Fixed::Fixed(int const n)
{
	this->_n = n << _precision;
}

Fixed::Fixed(float const n)
{
	this->_n = roundf(n * (1 << _precision));
}

Fixed::~Fixed()
{}

// OP overload

Fixed&
Fixed::operator=(Fixed const &other)
{
	this->_n = other.getRawBits();
	return *this;
}

bool
Fixed::operator>(Fixed const &other) const
{
	return this->_n > other._n;
}

bool
Fixed::operator<(Fixed const &other) const
{
	return other > *this;
}

bool
Fixed::operator>=(Fixed const &other) const
{
	return *this == other || *this > other;
}

bool
Fixed::operator<=(Fixed const &other) const
{
	return *this == other || *this < other;
}

bool
Fixed::operator==(Fixed const &other) const
{
	return this->_n == other._n;
}

bool
Fixed::operator!=(Fixed const &other) const
{
	return this->_n != other._n;
}

Fixed
Fixed::operator+(Fixed const &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed
Fixed::operator-(Fixed const &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed
Fixed::operator*(Fixed const &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed
Fixed::operator/(Fixed const &other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed
Fixed::operator++(void)
{
	this->_n++;
	return *this;
}

Fixed
Fixed::operator++(int)
{
	const Fixed old (*this);
	this->_n++;
	return old;
}

Fixed
Fixed::operator--(void)
{
	this->_n--;
	return *this;
}

Fixed
Fixed::operator--(int)
{
	const Fixed old (*this);
	this->_n--;
	return old;
}


std::ostream&
operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

// Funcs

Fixed&
Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed&
Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed&
Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed&
Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}


// Getter/Setter

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

// Conv

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
