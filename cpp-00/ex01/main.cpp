/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:09:24 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/05 20:21:36 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	std::string input;
	PhoneBook phone;

	while (1)
	{
		std::cout << "Enter a command: ADD or SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
			break;
		}
		if (input == "ADD")
		{
			phone.add_to_mi7fada();
			if (std::cin.eof() || std::cin.fail())
			{
				std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
				break;
			}
		}
		else if (input == "SEARCH")
		{
			phone.search_from_mi7fada();
			if (std::cin.eof() || std::cin.fail())
			{
				std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
				break;
			}
		}
		else if (input == "EXIT")
		{
			std::cout << "GOOD BYE!" << std::endl;
			break;
		}
	}
}
