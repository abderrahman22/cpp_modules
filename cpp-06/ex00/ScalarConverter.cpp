#include "ScalarConverter.hpp"

const char* ScalarConverter::Impossible::what() const throw()
{
	return "impossible";
}
const char* ScalarConverter::NonDisplayable::what() const throw()
{
	return "Non Displayable";
}

std::string parse(const std::string &literal)
{
	const std::string pseudos[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int i = 0; i < 6; i++)
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

static void printChar(double value)
{
	if (value != value || value < 0.0 || value > 127.0)
	{
		throw ScalarConverter::Impossible();
	}
	char c = static_cast<char>(value);
	if (c < 32 || c > 126) {
		throw ScalarConverter::NonDisplayable();
	}
	std::cout << "'" << c << "'" << std::endl;
}

static void printInt(double value)
{
	if (value != value || value < -2147483648.0 || value > 2147483647.0)
	{
		throw ScalarConverter::Impossible();
	}
	int i = static_cast<int>(value);
	std::cout << i << std::endl;
}

static void printFloat(double value, const std::string& type)
{
	float f = static_cast<float>(value);

	std::cout << f;
	if (type != "pseudo" && f == std::floor(f))
	{
		std::cout << ".0f" << std::endl;
	}
	else
	{
		std::cout << "f" << std::endl;
	}
}

static void printDouble(double value, const std::string& type)
{
	double d = static_cast<double>(value);

	std::cout << d;
	if (type != "pseudo" && d == std::floor(d))
	{
		std::cout << ".0" << std::endl;
	}
	else
	{
		std::cout << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	std::string type = parse(literal);

	if (type == "invalid")
	{
		std::cout << "Error: Invalid literal format." << std::endl;
		return;
	}
	double rawValue = 0.0;
	if (type == "char")
	{
		rawValue = static_cast<double>(literal[0]);
	} else
	{
		rawValue = std::strtod(literal.c_str(), NULL);
	}
	std::cout << "char: ";
	try
	{
		printChar(rawValue);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "int: ";
	try
	{
		printInt(rawValue);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "float: ";
	printFloat(rawValue, type);

	std::cout << "double: ";
	printDouble(rawValue, type);
}
