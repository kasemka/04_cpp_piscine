#include "span.hpp"

Span::Span(void) : _size(0)
{
	// std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int size) : _size(size)
{
}

Span::Span(Span const &cl)
{
	// std::cout << "Span copy constructor called" << std::endl;
	*this = cl;
	return;
}

Span &Span::operator=(Span const &cl)
{
	if (this != &cl)
	{
		_size = cl._size;
		_v1 = cl._v1;
	}
	return (*this);
}

Span::~Span(void)
{
	// std::cout << "Span default distructor called" << std::endl;
}

void Span::addNumber(int num)
{
	if (_v1.size() == _size)
		throw NoPlaceException();
	_v1.push_back(num);
}

void Span::betterAddNumber(int *nums, unsigned int len)
{
	if (_v1.size() == _size || _v1.size() + len > _size)
		throw NoPlaceException();
	_v1.insert(_v1.end(), nums, nums+10000);
}

int Span::shortestSpan() const
{
	if (_size > 1)
	{
		std::vector<int> v2;
		int min_1 = *std::min_element(_v1.begin(), _v1.end());
		v2 = _v1;
		v2.erase(std::find(v2.begin(), v2.end(), min_1));
		int min_2 = *std::min_element(v2.begin(), v2.end());
		return (min_2 - min_1);
	}
	else
		throw NoSpanException();
}

int Span::longestSpan() const
{
	if (_size > 1)
	{
		std::vector<int> v2;
		int max = *std::max_element(_v1.begin(), _v1.end());
		int min = *std::min_element(_v1.begin(), _v1.end());
		return (max - min);
	}
	else
		throw NoSpanException();
}
