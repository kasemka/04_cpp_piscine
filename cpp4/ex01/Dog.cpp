#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	this->brain = new Brain();
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
		this->brain = new Brain();
		*this->brain = *rhs.brain;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog distructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound(void) const
{
	std::cout << type << ": gaf-gaf!!!" << std::endl
			  << std::endl;
}