#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixpv;
	static int const _bits;

public:
	Fixed(void);
	Fixed(int i);
	Fixed(float f);

	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed &operator=(Fixed const &rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};


std::ostream & operator<<(std::ostream& stream, const Fixed& fixed);

#endif