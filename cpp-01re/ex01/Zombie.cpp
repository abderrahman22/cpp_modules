/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:55:37 by abchaman          #+#    #+#             */
/*   Updated: 2025/12/29 16:21:16 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << name + " BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie(){}
Zombie::~Zombie()
{
	std::cout << "destroyed" << std::endl;
}
