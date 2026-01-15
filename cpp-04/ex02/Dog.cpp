/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:31:58 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/15 16:05:51 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy Assignemet called" << std::endl;
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

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog makeSound called" << std::endl;
}
Brain* Dog::getBrain() const { return this->brain; }
