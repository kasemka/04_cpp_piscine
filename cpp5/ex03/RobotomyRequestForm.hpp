#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <time.h>
#include <cstdlib>



class RobotomyRequestForm : public Form
{
private:
	std::string _target;

public:
	RobotomyRequestForm(std::string targ);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &form);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &form);

	void action() const;
	std::string get_target() const;
};

#endif