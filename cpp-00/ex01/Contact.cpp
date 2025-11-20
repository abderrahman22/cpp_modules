/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:09:38 by abchaman          #+#    #+#             */
/*   Updated: 2025/11/20 22:54:43 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string name)
{
	first_name = name;
}

void Contact::setLastName(std::string name)
{
	last_name = name;
}

void Contact::setNickName(std::string name)
{
	nickname = name;
}

void Contact::setPhoneNumber(std::string number)
{
	phone_number = number;
}
void Contact::setDarksetSecret(std::string secret)
{
	darkest_secret = secret;
}

std::string Contact::getFirstName()
{
	return first_name;
}
std::string Contact::getLastName()
{
	return last_name;
}

std::string Contact::getNickName()
{
	return nickname;
}

std::string Contact::getPhoneNumber()
{
	return phone_number;
}

std::string Contact::getDarksetSecret()
{
	return darkest_secret;
}
void Contact::display()
{
	std::cout << Contact::first_name << std::endl;
	std::cout << Contact::last_name << std::endl;
	std::cout << Contact::nickname << std::endl;
	std::cout << Contact::phone_number << std::endl;
	std::cout << Contact::darkest_secret << std::endl;
}
