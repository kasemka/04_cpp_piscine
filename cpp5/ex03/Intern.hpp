#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(void);
	~Intern(void);
	Intern(Intern const &res);
	Intern &operator=(Intern const &res);
	Form *makeForm(std::string formName, std::string target);
};

#endif