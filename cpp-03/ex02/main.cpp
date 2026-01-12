/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:09:09 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/12 22:29:54 by abchaman         ###   ########.fr       */
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
