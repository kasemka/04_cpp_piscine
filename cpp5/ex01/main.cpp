#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bob("Bob", 150);

	try
	{
		Form form1("Form 1", 50, 160);
		std::cout << form1;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form form1("Form 1", 50, 50);
		std::cout << form1;
		bob.setGrade(40);
		form1.beSigned(bob);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form form2("Form 2", 20, 20);
		std::cout << form2;
		bob.setGrade(44);
		bob.signForm(form2);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}