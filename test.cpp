/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:33:24 by abchaman          #+#    #+#             */
/*   Updated: 2026/04/20 16:57:25 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception"
#include <iostream>

class Myclass : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "error occur";
		}
};


int main()
{
	try
	{
		throw Myclass();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}

}
