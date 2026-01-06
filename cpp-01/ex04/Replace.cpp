/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:01:51 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/06 05:26:55 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

std::string replaceall(std::string filename, std::string s1, std::string s2)
{
	size_t found;

	while ((found = filename.find(s1)) != std::string::npos)
	{
		filename.erase(found, s1.length());
		filename.insert(found, s2);
	}
	return filename;
}
