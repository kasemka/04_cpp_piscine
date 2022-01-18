#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
public:
	Weapon(void);
	Weapon(std::string gun);
	~Weapon(void);
	std::string &getType(void) ;
	void setType(const std::string &gun);
	std:: string _weapon;

	
};

#endif