#if !defined(FIXED_HPP)
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _n;
	static int const _precision = 8;
public:
	Fixed();
	Fixed(Fixed const &other);
	Fixed(int const n);
	Fixed(float const n);
	~Fixed();
	Fixed& operator=(Fixed const &other);

	int getRawBits() const;
	void setRawBits(int const  raw);

	float toFloat() const;
	int toInt() const;
};
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_HPP
