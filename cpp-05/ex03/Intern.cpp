#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {};

AForm* Intern::MakePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}
AForm* Intern::MakeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm* Intern::MakeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

const char* Intern::NotintheForm::what() const throw()
{
	return "Not in the Form";
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	std::string formname[3] = {"shrubbery creation", "robotomy request", "presedential Pardon"};
	AForm* (Intern::*FormsToMake[3])(std::string target) = {
		&Intern::MakeShrubbery,
		&Intern::MakeRobotomy,
		&Intern::MakePresidential};
	try
	{
		for (size_t i = 0; i < 3; i++)
		{
			if (name == formname[i])
			{
				std::cout << "intern created" << name << std::endl;
				return (this->*FormsToMake[i])(target);
			}
		}
	}
	catch(const std::exception& e)
	{
		throw NotintheForm();
	}
	return NULL;
}
