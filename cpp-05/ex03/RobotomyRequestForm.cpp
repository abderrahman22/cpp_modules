#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default target"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkExecution(executor);
	std::cout << "Bzzz Vrrr" << std::endl;

	if (std::rand() % 2)
	{
		std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl;
	}
	else
		std::cout << _target << " robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){};
