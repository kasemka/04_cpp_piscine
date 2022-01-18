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

	bool operator>(Fixed const &fix) const;
	bool operator<(Fixed const &fix) const;
	bool operator>=(Fixed const &fix) const;
	bool operator<=(Fixed const &fix) const;
	bool operator==(Fixed const &fix) const;
	bool operator!=(Fixed const &fix) const;
	Fixed operator+(Fixed const &fix)const;
	Fixed operator-(Fixed const &fix)const;
	Fixed operator*(Fixed const &fix)const;
	Fixed operator/(Fixed const &fix) const;
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &o, const Fixed &instance);

#endif