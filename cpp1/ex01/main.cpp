#include "Zombie.hpp"

int main(void)
{
	int i = 0;
	int N = 3;

	Zombie *zombie = zombieHorde(N, "Gargantuar");
	while (i < N)
		zombie[i++].announce();
	delete[] zombie;
	return (0);
}
