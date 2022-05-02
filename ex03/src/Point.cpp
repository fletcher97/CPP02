#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{}

Point::Point(const Point& p) : _x(Fixed(p._x)), _y(Fixed(p._y))
{}

Point&
Point::operator=(const Point& p)
{
	this->_x = p._x;
	this->_y = p._y;
	return *this;
}

Point::~Point()
{}

const Fixed
Point::getX() const
{
	return this->_x;
}

const Fixed
Point::getY() const
{
	return this->_y;
}

bool
Point::operator==(const Point& other) const
{
	return this->_x == other._x && this->_y == other._y;
}

std::ostream&
operator<<(std::ostream& out, const Point& p)
{
	out << "x: " << p.getX();
	out << " y: " << p.getY();
	return out;
}
