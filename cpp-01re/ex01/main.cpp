/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:51:59 by abchaman          #+#    #+#             */
/*   Updated: 2025/12/29 16:19:46 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i = 0;
	Zombie* horde = zombieHorde(5, "wa zombiiiiii");
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
}
