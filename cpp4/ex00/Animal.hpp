#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(Animal const &srs);
	Animal &operator=(Animal const &rhs);
	virtual ~Animal(void);

	virtual void makeSound(void) const;
	std::string getType(void) const;
	void setType(std::string);
};

#endif