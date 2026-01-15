/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:09:09 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/13 19:27:32 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap fraggie("Fraggie");

	fraggie.attack("the wall");
	fraggie.takeDamage(50);
	fraggie.beRepaired(20);
	fraggie.highFivesGuys();
}
