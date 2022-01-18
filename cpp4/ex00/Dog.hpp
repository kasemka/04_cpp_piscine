#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const &srs);
	Dog &operator=(Dog const &rhs);
	virtual ~Dog(void);

	void makeSound(void) const;
};

#endif