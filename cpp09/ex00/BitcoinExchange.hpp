#pragma once
#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> btc_map;

	public:
		// Default constructor
		BitcoinExchange();

		// Copy constructor
		BitcoinExchange(const BitcoinExchange &other);

		// Copy assignment operator overload
		BitcoinExchange &operator=(const BitcoinExchange &other);

		// Destructor
		~BitcoinExchange();

		const std::map<std::string, float>& getBtcMap() const;
		void insertValue(const std::string&, float);
};