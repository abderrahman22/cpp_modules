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

int main()
{
	try
	{
		Bureaucrat alice("Alice", 2);
		std::cout << alice << std::endl;

		alice.incrementGrade();
		std::cout << alice << std::endl;

		alice.incrementGrade();
	} catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
