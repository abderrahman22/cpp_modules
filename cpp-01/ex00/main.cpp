/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:24:39 by abchaman          #+#    #+#             */
/*   Updated: 2025/11/26 23:24:04 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "heap allocation :" << std::endl;
	Zombie* newzombie = newZombie("bo3o");
	newzombie->announce();
	delete newzombie;


	std::cout << "stack allcotaion" << std::endl;
	randomChump("3sila");
}
