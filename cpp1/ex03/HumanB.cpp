#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack()
{
	std::cout << _name << " attacks with his " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &club)
{
	weapon = &club;
}