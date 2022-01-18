#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat bob("Bob", 40);
	Intern jack;

	Form *form1 = jack.makeForm("ShrubberyCreation", "home");
	std::cout << *form1;
	form1->beSigned(bob);
	form1->action();
	delete form1;
	std::cout << std::endl;

	Form *form2 = jack.makeForm("RobotomyRequest", "roboform");
	std::cout << *form2;
	try
	{
		form2->beSigned(bob);
		form2->execute(bob);
		form2->action();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete form2;
	std::cout << std::endl;

	bob.setGrade(1);
	Form *form3 = jack.makeForm("PresidentialPardon", "bossform");
	std::cout << *form3;
	try
	{
		form3->beSigned(bob);
		form3->execute(bob);
		form3->action();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete form3;
	std::cout << std::endl;

	return (0);
}