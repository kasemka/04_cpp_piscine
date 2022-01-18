#include "Fixed.hpp"

Fixed::Fixed(void) : _fixpv(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixpv = i << Fixed::_bits;
	return;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixpv = roundf(f * (1 << Fixed::_bits));
	return;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_fixpv = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (_fixpv);
}

void Fixed::setRawBits(int const raw)
{
	_fixpv = raw;
}

int Fixed::toInt(void) const
{
	return (_fixpv >> this->_bits);
}

float Fixed::toFloat(void) const
{
	return (float(_fixpv) / (1 << Fixed::_bits));
}

int const Fixed::_bits = 8;

std::ostream &operator<<(std::ostream &stream, Fixed const &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
