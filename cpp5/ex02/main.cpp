#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat bob("Bob", 150);

	try
	{
		ShrubberyCreationForm tree("Garden_plant_form");
		std::cout << tree;
		bob.setGrade(136);
		tree.beSigned(bob);
		tree.action();
		tree.execute(bob);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		RobotomyRequestForm robform("Roboform");
		std::cout << robform;
		bob.setGrade(40);
		robform.beSigned(bob);
		robform.action();
		robform.execute(bob);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		PresidentialPardonForm bossform("Form of high importance");
		std::cout << bossform;
		bob.setGrade(10);
		bossform.beSigned(bob);
		bossform.action();
		bossform.execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}