#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

class NotFoundException : public std::exception
	{
	public:
		virtual const char *what() const throw(){
			return ("Item not found");
		};
	};



template <typename T>
void easyfind(T cont, int fig)
{
	std::cout << "Searching " << fig << std::endl;

	if (find(cont.begin(), cont.end(), fig) != cont.end())
	{
		int index = std::distance(cont.begin(), find(cont.begin(), cont.end(), fig));
		std::cout << "Found. The first occurrence of element in index " << index << std::endl;
	}
	else
		throw NotFoundException();
}

#endif