#include "BitcoinExchange.hpp"

// ==================== Constructors ====================
BitcoinExchange::BitcoinExchange()
{
}

// ================= Copy Constructor ==================
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
:
btc_map(other.btc_map)
{
}

// ========== Copy Assignment Operator Overload ==========
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		btc_map = other.btc_map;
	return *this;
}

// ==================== Destructor =====================
BitcoinExchange::~BitcoinExchange()
{
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
const std::map<std::string, float>& BitcoinExchange::getBtcMap() const
{
	return btc_map;
}

void BitcoinExchange::insertValue(const std::string& date, float value)
{
	btc_map[date] = value;
}