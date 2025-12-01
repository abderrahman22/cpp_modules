/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 23:27:20 by abchaman          #+#    #+#             */
/*   Updated: 2025/11/29 22:17:09 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setNames(std::string name)
{
	this->name = name;
}
Zombie* zombieHorde( int N, std::string name )
{
	int i = 0;
	Zombie* arr_zombie = new Zombie[N];
	while (i < N)
	{
		arr_zombie[i].setNames(name);
		i++;
	}
	return arr_zombie;
}
