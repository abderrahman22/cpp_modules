/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:09:09 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/12 22:38:52 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clippy("Clippy");

	clippy.attack("a fly");
	clippy.takeDamage(5);
	clippy.beRepaired(3);

	clippy.takeDamage(10);
	clippy.attack("a fly");
	clippy.beRepaired(10);

	return 0;
}
