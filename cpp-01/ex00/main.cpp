/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:22:31 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/06 00:57:38 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	//heap alloc
	Zombie* a = newZombie("aaa");
	a->announce();
	delete a;
	//stack alloc
	randomChump("yo");
}
