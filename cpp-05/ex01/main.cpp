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
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 42);
		Form simple("Simple", 50, 50);
		std::cout << alice.getName() << " (grade " << alice.getGrade() << ")" << std::endl;
		std::cout << simple << std::endl;
		alice.signForm(simple);
		std::cout << simple << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
