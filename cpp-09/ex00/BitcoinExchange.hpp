#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <stdlib.h>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _btcData;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadDatabase(const std::string& filename);
		void processInput(const std::string& filename) const;
		bool isValidDate(const std::string& date) const;
		void displayResult(const std::string& date, double value) const;
		void printDatabase() const;
};

#endif
