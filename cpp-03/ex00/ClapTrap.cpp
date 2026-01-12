/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:09:04 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/12 22:35:18 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), Hit_Points(10), Energy_points(10), Attack_Damage(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name): Name(Name), Hit_Points(10), Energy_points(10), Attack_Damage(0)
{
	std::cout << "Parameterized Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->Name = other.Name;
	this->Attack_Damage = other.Attack_Damage;
	this->Energy_points = other.Energy_points;
	this->Hit_Points = other.Hit_Points;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (Energy_points == 0 || Hit_Points ==0)
	{
		std::cout << "Cannot Attack" << std::endl;
	}
	else
	{
		Energy_points--;
		std::cout << "ClapTrap " << Name << " attacks " << target << " causing " << Attack_Damage << "points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_Points == 0)
	{
		std::cout << "ClapTrap " << Name << " is already dead!" << std::endl;
		return;
	}
	if (amount >= Hit_Points)
		Hit_Points = 0;
	else
		Hit_Points -= amount;
	std::cout << "ClapTrap " << Name << " takes " << amount
		<< " points of damage! HP is now " << Hit_Points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_Points == 0 || Energy_points == 0)
	{
		std::cout << "ClapTrap " << Name << " can't repair: No health or energy!" << std::endl;
		return;
	}

	Energy_points -= 1;
	Hit_Points += amount;
	std::cout << "ClapTrap " << Name << " repairs itself for " << amount
			<< " points! HP is now " << Hit_Points << std::endl;
}
