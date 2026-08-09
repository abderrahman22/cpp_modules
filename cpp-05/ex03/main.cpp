#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	Intern someRandomIntern;
	AForm* rrf = NULL;
	AForm* scf = NULL;
	AForm* ppf = NULL;
	AForm* unknown = NULL;

	std::cout << " TEST 1: Intern creating forms " << std::endl;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	ppf = someRandomIntern.makeForm("presidential pardon", "abdo");

	unknown = someRandomIntern.makeForm("pizza delivery request", "Office");

	std::cout << "\n TEST 2: Bureaucrats interacting with generated forms " << std::endl;
	try
	{
		Bureaucrat boss("boss", 1);
		Bureaucrat noob("noob", 140);

		if (scf)
		{
			std::cout << "\n--- Shrubbery ---" << std::endl;
			noob.signForm(*scf);
			noob.executeForm(*scf);
			boss.executeForm(*scf);
		}

		if (rrf)
		{
			std::cout << "\n--- Robotomy ---" << std::endl;
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			boss.executeForm(*rrf);
		}

		if (ppf)
		{
			std::cout << "\n--- Presidential ---" << std::endl;
			boss.signForm(*ppf);
			boss.executeForm(*ppf);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n TEST 3: Cleaning up memory " << std::endl;

	delete rrf;
	delete scf;
	delete ppf;
	delete unknown;

	return 0;
}
