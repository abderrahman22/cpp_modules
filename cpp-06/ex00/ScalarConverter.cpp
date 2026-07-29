#include "ScalarConverter.hpp"

std::string parse(const std::string &literal)
{
	const std::string pseudos[6] = {"-inff", "+inff", "nanf"};
	for (int i = 0; i < 3; i++)
	{
		if (literal == pseudos[i])
		{
			return "pseudo";
		}
	}
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		return "char";
	}


	bool hasDot = false;
	bool hasF = false;
	size_t i = 0;


	if (literal[i] == '-' || literal[i] == '+')
	{
		i++;
	}

	if (i == literal.length())
	{
		return "invalid";
	}
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot) return "invalid";
			hasDot = true;
		}
		else if (literal[i] == 'f')
		{
			if (i != literal.length() - 1) return "invalid";
			hasF = true;
		}
		else if (!std::isdigit(literal[i]))
		{
			return "invalid";
		}
	}
	if (hasF) return "float";
	if (hasDot) return "double";
	return "int";
}
void ScalarConverter::convert(const std::string &literal)
{

}
