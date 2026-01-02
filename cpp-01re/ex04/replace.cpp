/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:01:51 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/02 16:09:09 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replaceall(std::string filename, std::string s1, std::string s2)
{

	std::string result;
	int pos = 0;
	size_t found;

	while ((found = filename.find(s1, pos)) != std::string::npos)
	{
		result += filename.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += filename.substr(pos);

	return result;
}
