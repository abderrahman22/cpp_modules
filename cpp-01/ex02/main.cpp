/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:51:35 by abchaman          #+#    #+#             */
/*   Updated: 2025/12/01 17:54:28 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string test = "HI THIS IS BRAIN";
	std::string *ptr = &test;
	std::string &ref = test;

	std::cout << &test << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;

	std::cout << test << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
}
