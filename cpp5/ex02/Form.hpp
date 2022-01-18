#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

// class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _gradeSign;
	const int _gradeExec;
	bool _signed;

public:
	virtual ~Form(void);
	Form &operator=(Form const &cl);
	Form(Form const &cl);
	Form(const std::string &name, const int gradeSign, const int gradeExec);

	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getSigned() const;
	bool beSigned(Bureaucrat const &b);
	void execute(Bureaucrat const &executor);
	virtual void action() const = 0;

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
	class UnsignedFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form &cl);

#endif