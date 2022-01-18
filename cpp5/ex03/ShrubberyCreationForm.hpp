#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;

public:
	ShrubberyCreationForm(std::string targ);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &form);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);

	void action() const;
	std::string get_target() const;
};

#endif

// shrubbery - кустарник