#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void)
{
	// std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
	// std::cout << "Bureaucrat constructor wtih args called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cl)
{
	// std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = cl;
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &cl)
{
	if (this != &cl)
	{
		setGrade(cl._grade);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Bureaucrat default distructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setGrade(int i)
{
	if (i > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (i < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = i;
}

Bureaucrat &Bureaucrat::inc()
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
	return (*this);
	;
}

Bureaucrat &Bureaucrat::dec()
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Bureaucrat::signForm(Form const &f) const
{
	std::string s;

	if (f.getGradeSign() < getGrade())
		s = "grade is too low!";
	if (f.getGradeSign() >= getGrade())
		std::cout << getName() << " signs " << f.getName() << std::endl;
	else
	{
		std::cout << getName() << " cannot sign " << f.getName() << " because " << getName() << "'s " << s << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &cl)
{
	o << "Name: " << cl.getName() << ", grade: " << cl.getGrade() << std::endl;
	return (o);
}