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

	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;

	Fixed operator+(Fixed const &other) const;
	Fixed operator-(Fixed const &other) const;
	Fixed operator*(Fixed const &other) const;
	Fixed operator/(Fixed const &other) const;

	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	int getRawBits() const;
	void setRawBits(int const  raw);

	float toFloat() const;
	int toInt() const;
};
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_HPP
