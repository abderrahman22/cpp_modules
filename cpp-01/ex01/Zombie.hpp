/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 23:27:17 by abchaman          #+#    #+#             */
/*   Updated: 2025/11/29 22:15:30 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void announce( void );
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void setNames(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
