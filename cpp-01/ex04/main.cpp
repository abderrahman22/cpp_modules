/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:19:32 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/06 05:27:03 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "number of arguments is not correct" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty())
	{
		std::cerr << "s1 cannot be empty" << std::endl;
		//!If s1 is empty, find("") will match everywhere!
		return (1);
	}
	std::ifstream inputfile(filename.c_str());

	if (!inputfile.is_open())
	{
		std::cerr << "cannot open the input file" << std::endl;
		return (1);
	}
	std::string outputfilename = filename + ".replace";
	std::ofstream outputfile(outputfilename.c_str());
	if (!outputfile.is_open())
	{
		std::cerr << "Error: Cannot create output file" << std::endl;
		inputfile.close();
		return 1;
	}
	std::string line;
	while (std::getline(inputfile, line))
	{
		std::string modifiedline = replaceall(line, s1, s2);
		outputfile << modifiedline;
		if (!inputfile.eof())
			outputfile << std::endl;
	}
	inputfile.close();
	outputfile.close();
}
