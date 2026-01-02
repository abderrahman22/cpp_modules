/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:19:32 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/02 15:56:37 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "replace.hpp"

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
	//!In C++98, std::ifstream and std::ofstream constructors don't accept std::string - they only accept const char* (C-style strings).
	//?You need to convert std::string to const char* using .c_str()
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
