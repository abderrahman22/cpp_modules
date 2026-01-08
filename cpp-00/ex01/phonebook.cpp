/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:52:09 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/07 23:22:31 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook() : total_contact(0) ,index(0){}

void PhoneBook::add_to_mi7fada()
{
	Contact jdid;
	std::string input;

	while (1)
	{
		std::cout << "enter the first name : ";
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl << "Input cancelled." << std::endl;
			return;
		}
		if (input.empty())
			std::cout << "Error: First name cannot be empty!" << std::endl;
		else
			break;
	}
	jdid.setFirstName(input);

	while (1)
	{
		std::cout << "enter the last name : ";
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl << "Input cancelled." << std::endl;
			return;
		}
		if (input.empty())
			std::cout << "Error: Last name cannot be empty!" << std::endl;
		else
			break;
	}
	jdid.setLastName(input);

	while (1)
	{
		std::cout << "enter the NickName : ";
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl << "Input cancelled." << std::endl;
			return;
		}
		if (input.empty())
			std::cout << "Error: Nickname cannot be empty!" << std::endl;
		else
			break;
	}
	jdid.setNickName(input);

	while (1)
	{
		std::cout << "enter the Phone Number : ";
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl << "Input cancelled." << std::endl;
			return;
		}
		if (input.empty())
			std::cout << "Error: Phone number cannot be empty!" << std::endl;
		else
			break;
	}
	jdid.setPhoneNumber(input);

	while (1)
	{
		std::cout << "enter the Darkest Secret : ";
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl << "Input cancelled." << std::endl;
			return;
		}
		if (input.empty())
			std::cout << "Error: Darkest secret cannot be empty!" << std::endl;
		else
			break;
	}
	jdid.setDarkestSecret(input);

	mi7fada[index] = jdid;
	index = (index + 1) % 8;
	if (total_contact < 8)
		total_contact++;
	std::cout << "Contact added successfully" << std::endl;
}

void PhoneBook::display_all_contacts()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < total_contact; i++)
	{
		std::cout << std::setw(10) << i << "|";

		std::string firstName = mi7fada[i].getFirstName();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		std::cout << std::setw(10) << firstName << "|";

		std::string lastName = mi7fada[i].getLastName();
		if (lastName.length() > 10)
			lastName = lastName.substr(0, 9) + ".";
		std::cout << std::setw(10) << lastName << "|";

		std::string nickname = mi7fada[i].getNickName();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << std::endl;
	}
}

void PhoneBook::display_contact(int index)
{
	std::cout << "First Name : " << mi7fada[index].getFirstName() << std::endl;
	std::cout << "Last Name : " << mi7fada[index].getLastName() << std::endl;
	std::cout << "Nickname Name : " << mi7fada[index].getNickName() << std::endl;
	std::cout << "Phone Number : " << mi7fada[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << mi7fada[index].getDarkestSecret() << std::endl;
}

void PhoneBook::search_from_mi7fada()
{
	std::string index_str;
	if (total_contact == 0)
	{
		std::cout << "no contact found" << std::endl;
		return ;
	}
	display_all_contacts();
	std::cout << "enter a specific index from 0 to 7 :" << std::endl;
	if(!(std::getline(std::cin, index_str)))
		return ;
	int index_int;
	std::stringstream ss(index_str);
	if (!(ss >> index_int) || !ss.eof())
	{
		std::cout << std::endl << "Input cancelled." << std::endl;
		return ;
	}
	if (index_int >= 0 && index_int < total_contact)
		display_contact(index_int);
	else
		std::cout << "invalid index" << std::endl;
}
