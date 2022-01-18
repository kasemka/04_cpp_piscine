#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string _target;

public:
	PresidentialPardonForm(std::string targ);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &form);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &form);

	void action() const;
	std::string get_target() const;
};

#endif