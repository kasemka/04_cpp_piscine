#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl
			  << std::endl;
	type = "Cat";
}

Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat assignation constructor called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat distructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << type << ": meow..." << std::endl
			  << std::endl;
}