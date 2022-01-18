#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string targ) : Form("PresidentialPardonForm", 25, 5),
																   _target(targ)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &form) : Form(form.getName(), 25, 5), _target(form.get_target())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &form)
{
	if (this != &form)
		_target = form._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox..." << std::endl;
}

std::string PresidentialPardonForm::get_target() const
{
	return (_target);
}
