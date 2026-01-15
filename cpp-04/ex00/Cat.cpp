/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:31:46 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/14 16:36:30 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& other):  Animal(other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy Assignemet called" << std::endl;
	this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat makeSound called" << std::endl;
}
