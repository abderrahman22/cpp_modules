/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:11:35 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/12 22:41:39 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() :ClapTrap()
{
	this->Hit_Points = 100;
	this->Energy_points = 100;
	this->Attack_Damage = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->Hit_Points = 100;
	this->Energy_points = 100;
	this->Attack_Damage = 30;
	std::cout << "FragTrap Parameterized Called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& other) :ClapTrap(other)
{
	std::cout << "Copy Constructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "ScavTrap Copy assignement called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor caller" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << Name << " says: 'Give me a high five, everyone!" << std::endl;
}
