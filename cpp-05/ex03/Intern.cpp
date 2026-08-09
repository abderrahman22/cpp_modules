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


AForm* Intern::makeForm(const std::string name, const std::string target)
{
    std::string formname[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*FormsToMake[3])(std::string target) = {
        &Intern::MakeShrubbery,
        &Intern::MakeRobotomy,
        &Intern::MakePresidential
    };

    for (size_t i = 0; i < 3; i++)
    {
        if (name == formname[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*FormsToMake[i])(target);
        }
    }
    std::cout << "Error: Intern cannot create '" << name << "' because it does not exist." << std::endl;
    return NULL;
}