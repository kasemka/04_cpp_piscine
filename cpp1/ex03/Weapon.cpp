#include "Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string gun)
{
	setType(gun);
}

Weapon::~Weapon(void)
{
}

std::string &Weapon::getType(void)
{
	return (this->_weapon);
}

void Weapon::setType(const std::string &gun)
{
	this->_weapon = gun;
}