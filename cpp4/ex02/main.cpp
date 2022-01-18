// #include "Animal.hpp"

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	// const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();


	delete j;
	delete i;
	// delete meta;
	return (0);
}


// абстрактные классы не может соз экземпляры класс, могут только исп-ся как базовый класс
// если в классе хоть 1 чисто виртуальный метод virtual ...=0, то он считается астр