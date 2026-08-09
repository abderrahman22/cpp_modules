#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << " TEST 1: ShrubberyCreationForm " << std::endl;
	try
	{
		Bureaucrat intern("intern", 140);
		Bureaucrat abdo("abdo", 130);
		ShrubberyCreationForm form1("garden");

		std::cout << form1 << std::endl;

		abdo.executeForm(form1);
		intern.signForm(form1);
		intern.executeForm(form1);
		abdo.executeForm(form1);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n TEST 2: RobotomyRequestForm " << std::endl;
	try
	{
		Bureaucrat boss("boss", 50);
		Bureaucrat ceo("ceo", 1);
		RobotomyRequestForm form2("Bender");

		std::cout << form2 << std::endl;

		boss.signForm(form2);
		boss.executeForm(form2);

		ceo.executeForm(form2);
		ceo.executeForm(form2);
		ceo.executeForm(form2);
		ceo.executeForm(form2);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n TEST 3: PresidentialPardonForm " << std::endl;
	try
	{
		Bureaucrat zaphod("zaphod", 1);
		PresidentialPardonForm form3("Arthur Dent");

		std::cout << form3 << std::endl;

		zaphod.signForm(form3);
		zaphod.executeForm(form3);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
