#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl
			  << std::endl;
	type = "Dog";
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return;
}

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog assignation constructor called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog distructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout <<type<< ": gaf-gaf!!!" << std::endl
			  << std::endl;
}