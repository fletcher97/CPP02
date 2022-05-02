#include "Point.hpp"

float
sign(const Point p1, const Point p2, const Point p3)
{
	return (((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())) - ((p2.getX() - p3.getX()) * (p1.getY() - p3.getY()))).toFloat();
}

bool
inLine(const Point p, const Point p1, const Point p2)
{
	// Checkout outisde of square
	if (p.getX() < Fixed::min(p1.getX(), p2.getX())
		|| p.getX() > Fixed::max(p1.getX(), p2.getX())
		|| p.getY() < Fixed::min(p1.getY(), p2.getY())
		|| p.getY() > Fixed::max(p1.getY(), p2.getY()))
		return false;

	// check vertical
	if (p2.getX() - p1.getX() == Fixed(0))
		return p.getY() >= Fixed::min(p1.getY(), p2.getY())
		|| p.getY() <= Fixed::max(p1.getY(), p2.getY());

	Fixed m = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
	Fixed c = p2.getY() - (m * p2.getX());

	return p.getY() == (m * p.getX()) + c;
}

bool
bsp(Point const a, Point const b, Point const c, Point const p)
{

	if (p == a || p == b || p == c
		|| inLine(p, a, b) || inLine(p, b, c) || inLine(p, c, a))
		return false;

	float f1 = sign(p, a, b);
	float f2 = sign(p, b, c);
	float f3 = sign(p, c, a);

	return (f1 >= 0 && f2 >= 0 && f3 >= 0) || (f1<= 0 && f2 <= 0 && f3 <= 0);
}
