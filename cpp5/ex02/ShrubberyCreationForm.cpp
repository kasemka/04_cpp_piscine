#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string targ) : Form("ShrubberyCreationForm", 145, 137),
																 _target(targ)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form) : Form(form.getName(), 145, 137), _target(form.get_target())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &form)
{
	if (this != &form)
		_target = form._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const
{
	std::ofstream file;
	file.open((_target+ "_shrubbery").c_str());

	try
	{
		file << "  *                                          *    " << std::endl;
		file << "             *          +          *              " << std::endl;
		file << "                       ***                        " << std::endl;
		file << "                      *****                       " << std::endl;
		file << "        *            *****o*                      " << std::endl;
		file << "                    **o*******             *      " << std::endl;
		file << "                   ***********                    " << std::endl;
		file << "                    ******o**                     " << std::endl;
		file << "   *                ***********                   " << std::endl;
		file << "                  ****o********                   " << std::endl;
		file << "                 o***********o***                 " << std::endl;
		file << "                ****o***o********                 " << std::endl;
		file.close();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::string ShrubberyCreationForm::get_target() const
{
	return (_target);
}
