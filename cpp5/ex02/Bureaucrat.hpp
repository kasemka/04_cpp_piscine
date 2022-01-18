#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat(void);
	virtual ~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &cl);
	Bureaucrat(Bureaucrat const &cl);
	Bureaucrat(std::string name, int grade);

	std::string getName() const;
	int getGrade() const;
	void setGrade(int i);

	Bureaucrat &inc();
	Bureaucrat &dec();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	void signForm(Form const &f) const;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &cl);

#endif