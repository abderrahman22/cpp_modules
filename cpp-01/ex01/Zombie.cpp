/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 23:27:14 by abchaman          #+#    #+#             */
/*   Updated: 2025/12/01 14:42:12 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	
}
void Zombie::announce(void)
{
	std::cout << name + ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie(std::string nm)
{
	name = nm;
}
Zombie::~Zombie()
{
	std::cout << "destroyed" << std::endl;
}
