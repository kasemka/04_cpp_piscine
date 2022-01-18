#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &res)
{
	if (this != &res)
		*this = res;
}

Intern &Intern::operator=(Intern const &res)
{
	(void)res;
	return *this;
}

Intern::~Intern()
{
}

Form *Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	Form *forms[3];
	forms[0] = new ShrubberyCreationForm(target);
	forms[1] = new RobotomyRequestForm(target);
	forms[2] = new PresidentialPardonForm(target);
	int i = 0;
	while (i < 3)
	{
		if (formNames[i] == formName)
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		delete forms[1];
		delete forms[2];
		return forms[i];
	case 1:
		delete forms[0];
		delete forms[2];
		return forms[i];
	case 2:
		delete forms[0];
		delete forms[1];
		return forms[i];
	}
	return (NULL);
}