#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl
			  << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return;
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain assignation constructor called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}

	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain distructor called" << std::endl;
}
