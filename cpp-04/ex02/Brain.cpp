/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:07:11 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/15 15:43:28 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called" <<std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		ideas[i] = "Default";
	}
}
Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}
Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy Assignement called" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return *this;
}
Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
	{
		this->ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return this->ideas[index];
	}
	return "";
}
