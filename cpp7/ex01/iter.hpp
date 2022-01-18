#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <unistd.h>

template <typename T, typename F>
void iter(T *arr, size_t len, F foo)
{
	for (size_t j = 0; j < len; j++)
		foo(arr[j]);
}

template <typename T>
void print(T &arr)
{
	std::cout << arr << std::endl;
}

template <typename T>
void print_address(T &arr)
{
	std::cout << "adress: "<< & arr << std::endl;
}

class Test
{
public:
	Test(){};
	~Test(){};
};
#endif