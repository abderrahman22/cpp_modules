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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << " TEST 1: Instantiating with Grade 0 (Too High) " << std::endl;
	try
	{
		Bureaucrat abdo("Abdo", 0);
		// If the line above works, this next line will print (it shouldn't!)
		std::cout << abdo << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n TEST 2: Instantiating with Grade 151 (Too Low) " << std::endl;
	try
	{
		Bureaucrat intern("Intern", 151);
		std::cout << intern << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n TEST 3: Incrementing past Grade 1 " << std::endl;
	try
	{
		Bureaucrat boss("Boss", 2);
		std::cout << boss << std::endl;

		boss.incrementgrade(); // Grade goes to 1 (Valid)
		std::cout << "After first increment: " << boss << std::endl;

		boss.incrementgrade(); // Grade tries to go to 0 (Should throw!)
		std::cout << "You should not see this print!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n TEST 4: Decrementing past Grade 150 " << std::endl;
	try
	{
		Bureaucrat slacker("Slacker", 149);
		std::cout << slacker << std::endl;

		slacker.decrementgrade(); // Grade goes to 150 (Valid)
		std::cout << "After first decrement: " << slacker << std::endl;

		slacker.decrementgrade(); // Grade tries to go to 151 (Should throw!)
		std::cout << "You should not see this print!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
