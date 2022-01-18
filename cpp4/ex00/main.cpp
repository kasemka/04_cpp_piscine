// #include "Animal.hpp"

#include "Dog.hpp"
#include "Cat.hpp"

class WrongAnimal
{
public:
	WrongAnimal(void){};
	virtual ~WrongAnimal(void){std::cout << "WrongAnimal distructor called" << std::endl;};
	virtual void makeSound() const
	{
		std::cout << "WrongAnimal: pi!" << std::endl;
	}
};

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void) : WrongAnimal(){};
	~WrongCat(void){std::cout << "WrongCat distructor called" << std::endl;};
	void makeSound() const
	{
		std::cout << "WrongCat: pi meow!" << std::endl;
	}
};

//Polymorphism
int main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal *c = new WrongCat();
	c->makeSound();

	delete j;
	delete i;
	delete meta;
	delete c;
	return (0);
}