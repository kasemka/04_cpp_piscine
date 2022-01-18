#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout<<"Zombie constructor called" <<std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " izzZ deaaaaaD..." << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}