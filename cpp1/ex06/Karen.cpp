#include "Karen.hpp"

Karen::Karen(void)
{
}

Karen::~Karen(void)
{
}

void Karen::complain(std::string level)
{
	int i = 0;
	std::string _plevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (_plevel[i] != level && i < 4)
		i++;
	switch (i)
	{
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl
				  << std::endl;
		break;
	case 0:
		std::cout << "[ " << _plevel[0] << " ]" << std::endl;
		std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
				  << std::endl
				  << std::endl;
	case 1:
		std::cout << "[ " << _plevel[1] << " ]" << std::endl;
		std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"
				  << std::endl
				  << std::endl;
	case 2:
		std::cout << "[ " << _plevel[2] << " ]" << std::endl;
		std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month." << std::endl
				  << std::endl;
	case 3:
		std::cout << "[ " << _plevel[3] << " ]" << std::endl;
		std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl
				  << std::endl;
	}
}
