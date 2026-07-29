/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:29:22 by abchaman          #+#    #+#             */
/*   Updated: 2026/04/23 12:54:10 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat boss("abdocn", 120);
	AForm* rrf = NULL;
	AForm* scf = NULL;
	AForm* ppf = NULL;
	AForm* unknown = NULL;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	ppf = someRandomIntern.makeForm("presidential pardon", "abdo");

	unknown = someRandomIntern.makeForm("pizza delivery request", "Office");

	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf); // Should attempt to robotomize "Bender"
	}

	if (scf)
	{
		boss.signForm(*scf);
		boss.executeForm(*scf); // Should create a file called "Home_shrubbery"
	}

	if (ppf)
	{
		boss.signForm(*ppf);
		boss.executeForm(*ppf); // Should announce that "abdo" is pardoned
	}
	delete rrf;
	delete scf;
	delete ppf;
	delete unknown;

	return 0;
}
