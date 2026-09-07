#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_btcData = other._btcData;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	if (!file.is_open())
	{
		std::cerr << "Error : file is not opened" << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t comma_pos = line.find(',');
		if (comma_pos != std::string::npos)
		{
			std::string date = line.substr(0, comma_pos);
			std::string ratestr = line.substr(comma_pos + 1);
			// std::cout << "DEBUG rateStr: [" << ratestr << "]" << std::endl;
			float ratefloat = atof(ratestr.c_str());
			_btcData[date] = ratefloat;
		}
	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (isLeap && day > 29)
			return false;
		if (!isLeap && day > 28)
			return false;
	}
	return true;
}

void BitcoinExchange::displayResult(const std::string& date, double value) const
{
	std::map<std::string, float>::const_iterator it = _btcData.lower_bound(date);

	if (it == _btcData.end())
	{
		--it;
	}
	else if (it->first != date)
	{
		if (it == _btcData.begin())
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return;
		}
		--it;
	}
	float result = value * it->second;
	std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
	{
		std::cerr << "Error : file is not opened" << std::endl;
		return;
	}
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t sepPos = line.find(" | ");
		if (sepPos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, sepPos);
		std::string valueStr = line.substr(sepPos + 3);
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		double value = atof(valueStr.c_str());

		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		displayResult(date, value);
	}

	file.close();
}

