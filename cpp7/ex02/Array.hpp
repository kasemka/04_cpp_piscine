#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <ctime>
#include <stdlib.h>

template <typename T>

class Array
{
private:
	size_t _len;
	T *_arr;

public:
	Array() : _arr(NULL){};
	~Array()
	{
		if (_arr != NULL)
		{
			delete[] _arr;
			// std::cout<<"array was freed"<<std::endl;
		}
	};
	Array(Array &s) { *this = s; };
	Array(unsigned int n) : _len(n)
	{
		_arr = new T[n];
	};
	Array &operator=(Array &other)
	{
		this->_len = other._len;
		if (this == &other)
			return (*this);
		this->_arr = new T[_len];
		for (size_t i = 0; i < _len; i++)
			this->_arr[i] = other._arr[i];
		return (*this);
	};

	T &operator[](size_t ind)
	{
		if (ind >= _len)
			throw std::out_of_range("index out of range.");
		return (_arr[ind]);
	};
	size_t size() const { return (_len); };
};

#endif
