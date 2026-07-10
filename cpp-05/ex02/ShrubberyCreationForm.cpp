#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default target"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "File is not opened";
}

void ShrubberyCreationForm::execute(Bureaucrat const& other) const
{
	this->checkExecution(other);
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open())
	{
		throw FileOpenException();
	}
	outfile << "   /\\ \n  /	\\ \n /____\\ \n	|| \n";
	outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};
