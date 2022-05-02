#if !defined(POINT_HPP)
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed _x;
	Fixed _y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& p);
	Point& operator=(const Point& p);
	~Point();

	bool operator==(const Point& other) const;

	const Fixed getX() const;
	const Fixed getY() const;
};
std::ostream& operator<<(std::ostream& out, const Point& fixed);

#endif // POINT_HPP
