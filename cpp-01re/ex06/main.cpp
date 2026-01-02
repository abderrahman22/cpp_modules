/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:08:04 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/02 21:27:04 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harll.hpp"

void harl::complain(std::string level)
{
	int pos = -1;
	void (harl::*functions[4])(void) = {&harl::debug, &harl::info, &harl::warning, &harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			pos = i;
		}
	}
	switch (pos)
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			(this->*functions[0])();
			(this->*functions[1])();
			(this->*functions[2])();
			(this->*functions[3])();
			break;
		case 1:
			(this->*functions[1])();
			(this->*functions[2])();
			(this->*functions[3])();
			break;
		case 2:
			(this->*functions[2])();
			(this->*functions[3])();
			break;
		case 3:
			(this->*functions[3])();
			break;
	}
}
int main(int ac, char **av)
{
	harl bo3bo3;
	if (ac == 2)
		bo3bo3.complain(av[1]);
	else
		std::cout << "number of arguments u entered incorrect" << std::endl;
}
