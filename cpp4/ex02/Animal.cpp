#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "Animal";
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
	return;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal assignation constructor called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal distructor called" << std::endl;
}

std::string Animal::getType(void) const
{
	return (type);
}

void Animal::setType(std::string newtype)
{
	type = newtype;
}
