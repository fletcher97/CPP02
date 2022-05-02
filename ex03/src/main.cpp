#include <iostream>
#include <cmath>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p);

int main()
{
	const Point a (0.0f, 0.0f);
	const Point b (0.0f, 10.0f);
	const Point c (10.0f, 10.0f);

	const Point p1 (0.0f, 0.0f); // a
	const Point p2 (0.0f, 10.0f); // b
	const Point p3 (10.0f, 10.0f); // c

	const Point p4 (0.0f, 5.0f); // a - b
	const Point p5 (5.0f, 10.0f); // b - c
	const Point p6 (5.0f, 5.0f); // c - a

	const Point p7 (2.0f, 8.0f); // in
	const Point p8 ((++Fixed(0)).toFloat(), 8.0f); // in
	const Point p9 (2.0f, (--Fixed(10)).toFloat()); // in
	const Point p10 ((++Fixed(0)).toFloat(), (--Fixed(10)).toFloat()); // in

	const Point p11 (10.0f, 0.0f); // out
	const Point p12 ((--Fixed(0)).toFloat(), 8.0f); // out
	const Point p13 (2.0f, (++Fixed(10)).toFloat()); // out
	const Point p14 ((--Fixed(0)).toFloat(), (++Fixed(10)).toFloat()); // out

	std::cout << "a: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "b: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "c: " << bsp(a, b, c, p3) << std::endl;
	std::cout << std::endl;
	std::cout << "a-b: " << bsp(a, b, c, p4) << std::endl;
	std::cout << "b-c: " << bsp(a, b, c, p5) << std::endl;
	std::cout << "c-a: " << bsp(a, b, c, p6) << std::endl;
	std::cout << std::endl;
	std::cout << "in: " << bsp(a, b, c, p7) << std::endl;
	std::cout << "in edge x: " << bsp(a, b, c, p8) << std::endl;
	std::cout << "in edge y: " << bsp(a, b, c, p9) << std::endl;
	std::cout << "in edge x+y: " << bsp(a, b, c, p10) << std::endl;
	std::cout << std::endl;
	std::cout << "out: " << bsp(a, b, c, p11) << std::endl;
	std::cout << "out edge x: " << bsp(a, b, c, p12) << std::endl;
	std::cout << "out edge y: " << bsp(a, b, c, p13) << std::endl;
	std::cout << "out edge x+y: " << bsp(a, b, c, p14) << std::endl;
	return 0;
}
