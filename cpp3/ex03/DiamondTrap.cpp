#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{

	this->_name = "NonameDiamondTrap";
	this->_hitpoints = 100;
	this->_damages = 30;
	ClapTrap::_name = this->_name + "_clap_name";

	std::cout << "DiamondTrap default constructor called" << std::endl;
	std::cout << "Name = " << this->_name << ", hit points = " << _hitpoints
			  << ", energy points = " << _energypoints << ", damages = " << _damages
			  << std::endl
			  << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
	return;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	(void)rhs;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energypoints = rhs._energypoints;
		this->_damages = rhs._damages;
	}
	std::cout << "Name = " << this->_name << ", hit points = " << _hitpoints
			  << ", energy points = " << _energypoints << ", damages = " << _damages << std::endl
			  << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_hitpoints = 100;
	this->_damages = 30;
	ClapTrap::_name = name + "_clap_name";

	std::cout << "DiamondTrap constructor called" << std::endl;
	std::cout << "Name = " << this->_name << ", hit points = " << _hitpoints
			  << ", energy points = " << _energypoints << ", damages = " << _damages << std::endl
			  << std::endl;
	return;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "You are " << _name << " and your second name is "
			  << ClapTrap::_name << ", son" << std::endl
			  << std::endl;
}