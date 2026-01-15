/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:31:46 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/15 16:05:21 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other):  Animal(other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain	(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy Assignemet called" << std::endl;
	if (this == &other)
		return *this;
	else
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat makeSound called" << std::endl;
}
Brain* Cat::getBrain() const { return this->brain; }
