#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
protected:
	std::string ideas[100];

public:
	Brain(void);
	Brain(Brain const &src);
	Brain &operator=(Brain const &rhs);

	virtual ~Brain(void);
};

#endif