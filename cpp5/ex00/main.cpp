#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bob("Bob", 150);

	try
	{
		bob.dec();
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl
				  << std::endl;
	}

	try
	{
		bob.inc();
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl
				  << std::endl;
	}

	try
	{
		bob.setGrade(0);
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl
				  << std::endl;
	}

	try
	{
		bob.setGrade(170);
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	return (0);
}