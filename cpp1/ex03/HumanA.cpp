#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

void HumanA::attack()
{
	std::cout << _name << " attacks with his " << weapon.getType() << std::endl;
}
