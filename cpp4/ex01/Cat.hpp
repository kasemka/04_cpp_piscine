#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat(void);
	Cat(Cat const &srs);
	Cat &operator=(Cat const &rhs);
	virtual ~Cat(void);

	void makeSound(void) const;
};

#endif