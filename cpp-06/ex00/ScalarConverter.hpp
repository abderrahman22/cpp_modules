#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void convert(const std::string& literal);
		class Impossible : public std::exception
		{
			public :
			const char* what() const throw();
		};
		class NonDisplayable : public std::exception
		{
			public :
			const char* what() const throw();
		};
};

#endif
