/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:05:21 by abchaman          #+#    #+#             */
/*   Updated: 2025/12/31 17:10:19 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& sla7) : name(name), sla7(sla7){}

void HumanA::attack()
{
	std::cout << name + " "<< "attack with their " << sla7.getType() << std::endl;
}
