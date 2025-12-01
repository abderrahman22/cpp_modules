/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 23:27:22 by abchaman          #+#    #+#             */
/*   Updated: 2025/11/29 22:07:47 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i = 0;
	int N = 5;
	Zombie* newZombies = zombieHorde(N, "Zombie Hord");
	while (i < N)
	{
		newZombies[i].announce();
		i++;
	}
	delete[] newZombies;
}
