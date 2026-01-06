/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:55:08 by abchaman          #+#    #+#             */
/*   Updated: 2025/12/29 16:19:16 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
	this->name = name;
}
Zombie* zombieHorde(int N, std::string name )
{
	int i = 0;
	Zombie *arr_zombie = new Zombie[N];
	while (i < N)
	{
		arr_zombie[i].setName(name);
		i++;
	}
	return arr_zombie;
}
