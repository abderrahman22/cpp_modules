/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:55:52 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/12 21:08:23 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
	this->Hit_Points = 100;
	this->Energy_points = 50;
	this->Attack_Damage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->Hit_Points = 100;
	this->Energy_points = 50;
	this->Attack_Damage = 20;
	std::cout << "ScavTrap Parameterized Constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (Energy_points == 0 || Hit_Points ==0)
	{
		std::cout << "Cannot Attack" << std::endl;
	}
	else
	{
		Energy_points--;
		std::cout << "ScavTrap " << Name << " attacks " << target << " causing " << Attack_Damage << "points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (Hit_Points == 0)
	{
		std::cout << "Cannot be in the Gatekeeper because of Hp is 0!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap is now in the Gate Keeper" << std::endl;
}
