/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:09:09 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/12 22:41:03 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main()
{
	ScavTrap scavvy("Scavvy");
	scavvy.attack("a target");
	scavvy.takeDamage(50);
	scavvy.beRepaired(20);
	scavvy.guardGate();
	return 0;
}
