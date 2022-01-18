#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie();
	std::string name;
	void announce(void) const;

};

Zombie *zombieHorde(int N, std::string name);


#endif
