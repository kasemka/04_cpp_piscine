#include "Fixed.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed(void) : _fixpv(0)
{
	return;
}

Fixed::Fixed(const int i)
{
	this->_fixpv = i * (1 << Fixed::_bits);
	return;
}

Fixed::Fixed(const float f)
{
	this->_fixpv = roundf(f * (1 << Fixed::_bits));
	return;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
	return (this->_fixpv);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixpv = raw;
}

int Fixed::toInt(void) const
{
	return (this->_fixpv >> this->_bits);
}

float Fixed::toFloat(void) const
{
	return (float(this->_fixpv) / float(1 << Fixed::_bits));
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_fixpv = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const &fix) const
{
	return (_fixpv > fix._fixpv);
}

bool Fixed::operator<(Fixed const &fix) const
{
	return (_fixpv < fix._fixpv);
}

bool Fixed::operator>=(Fixed const &fix) const
{
	return (_fixpv >= fix._fixpv);
}

bool Fixed::operator<=(Fixed const &fix) const
{
	return (_fixpv <= fix._fixpv);
}

bool Fixed::operator==(Fixed const &fix) const
{
	return (_fixpv == fix._fixpv);
}

bool Fixed::operator!=(Fixed const &fix) const
{
	return (_fixpv != fix._fixpv);
}

Fixed Fixed::operator+(Fixed const &fix) const
{
	Fixed newfix(*this);
	newfix._fixpv = this->_fixpv + fix._fixpv;
	return (newfix);
}

Fixed Fixed::operator-(Fixed const &fix) const
{
	Fixed newfix(*this);
	newfix._fixpv = this->_fixpv - fix._fixpv;
	return (newfix);
}

Fixed Fixed::operator*(Fixed const &fix) const
{
	Fixed newfix(*this);

	newfix._fixpv = ((long)this->_fixpv * (long)fix._fixpv) / (1 << Fixed::_bits);
	return (newfix);
}

Fixed Fixed::operator/(Fixed const &fix) const
{
	Fixed newfix(*this);
	long long value;

	if (fix._fixpv != 0)
	{
		value = this->_fixpv * (1 << Fixed::_bits);
		newfix._fixpv = value / fix._fixpv;
		return (newfix);
	}
	std::cout << "zero devision" << std::endl;
	return (*this);
}

Fixed &Fixed::operator++(void)
{
	_fixpv++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	_fixpv--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed newfix(*this);
	_fixpv++;
	return (newfix);
}

Fixed Fixed::operator--(int)
{
	Fixed newfix(*this);
	_fixpv--;
	return (newfix);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}
std::ostream &operator<<(std::ostream &o, Fixed const &instance)
{
	o << instance.toFloat();
	return (o);
}
