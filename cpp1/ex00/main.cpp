#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;

	zombie = newZombie("Dr. Zomboss");
	zombie->announce();
	delete zombie;
	randomChump("Digger Zombie");
	return (0);
}
