#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// const Animal *j = new Dog();
	// const Animal *i = new Cat();
	// j->makeSound();
	// i->makeSound();
	// delete j; //should not create a leak
	// delete i;

	int num = 4;
	Animal *CatDog[num];
	for (int i = 0; i < num; i++)
	{
		if (i % 2 == 0)
			CatDog[i] = new Cat;
		else
			CatDog[i] = new Dog;
	}

	for (int i = 0; i < num; i++)
		CatDog[i]->makeSound();

	for (int i = 0; i < num; i++)
		delete CatDog[i];

	std::cout << std::endl;
	return (0);
}

// Полиморфизм  — способность функции обрабатывать данные разных типов
// полиморфизм субтипов
