#include "BitcoinExchange.hpp"

void BitcoinExchange::printDatabase() const
{
	for (std::map<std::string, float>::const_iterator it = _btcData.begin(); it != _btcData.end(); it++)
	{
		std::cout << it->first << "--->" << it->second << std::endl;
	}
}
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.loadDatabase("data.csv");
	btc.processInput(av[1]);
	// btc.printDatabase();
}
