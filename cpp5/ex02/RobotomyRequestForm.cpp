#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string targ) : Form("RobotomyRequestForm", 72, 45),
															 _target(targ)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form) : Form(form.getName(), 72, 45), _target(form.get_target())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &form)
{
	if (this != &form)
		_target = form._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const
{
	srand(time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed..." << std::endl;
}

std::string RobotomyRequestForm::get_target() const
{
	return (_target);
}
