/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:05:28 by abchaman          #+#    #+#             */
/*   Updated: 2025/12/31 17:13:45 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon& sla7)
{
	this->sla7 = &sla7;
}
void HumanB::attack()
{
	if (sla7)
		std::cout << name + " " << "attack with their " << sla7->getType() << std::endl;
	else
		std::cout << "no weapon" << std::endl;

}
