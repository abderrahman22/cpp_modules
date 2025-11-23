/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:09:38 by abchaman          #+#    #+#             */
/*   Updated: 2025/11/23 16:58:22 by abchaman         ###   ########.fr       */
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
void Contact::setDarkestSecret(std::string secret)
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

std::string Contact::getDarkestSecret()
{
	return darkest_secret;
}
