#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename fig>

void swap(fig &a, fig &b)
{
	fig temp = a;
	a = b;
	b = temp;
}

template <typename fig>

fig min(fig &a, fig &b)
{
	if (a > b)
		return (b);
	return (a);
}

template <typename fig>

fig max(fig &a, fig &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif