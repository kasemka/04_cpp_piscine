#include "Form.hpp"

Form::Form(const std::string &name, const int gradeSign, const int gradeExec) : _name(name),
																				_gradeSign(gradeSign),
																				_gradeExec(gradeExec),
																				_signed(false)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (gradeSign < 1 || gradeExec < 1)
		throw Bureaucrat::GradeTooHighException();
}

Form::Form(Form const &cl) : _name(cl._name),
							 _gradeSign(cl._gradeSign),
							 _gradeExec(cl._gradeSign),
							 _signed(cl._signed)
{
	std::cout << "Form copy constructor called" << std::endl;
	return;
}

Form &Form::operator=(Form const &cl)
{
	if (this != &cl)
	{
		this->_signed = cl._signed;
	}
	return (*this);
}

Form::~Form(void) {}

std::string Form::getName() const
{
	return (_name);
}

int Form::getGradeSign() const
{
	return (_gradeSign);
}

int Form::getGradeExec() const
{
	return (_gradeExec);
}

bool Form::getSigned() const
{
	return (_signed);
}

bool Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else
	{
		_signed = true;
		b.signForm(*this);
		return (true);
	}
}

void Form::execute(Bureaucrat const &executor)
{
	if (_signed)
	{
		if (executor.getGrade() <= getGradeExec())
			std::cout<<executor.getName() <<" signs for execution"<<std::endl;
		else
			throw GradeTooLowException();
	}
	else
		throw UnsignedFormException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::UnsignedFormException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &o, Form &cl)
{
	o << cl.getName() << " needs " << cl.getGradeSign()
	  << " grades to sign and "
	  << cl.getGradeExec() << " grades to execute"
	  << std::endl;
	return (o);
}