#if !defined(FIXED_HPP)
#define FIXED_HPP

class Fixed
{
private:
	int _n;
	static int const _precision = 8;
public:
	Fixed();
	Fixed(Fixed const &other);
	~Fixed();
	Fixed& operator=(Fixed const &other);

	int getRawBits() const;
	void setRawBits(int const  raw);
};

#endif // FIXED_HPP
