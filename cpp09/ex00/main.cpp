#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#ifndef COLORS
#define COLORS
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#endif

/**
 * @brief Processes a CSV file containing Bitcoin data and inserts values into the Btc object.
 *
 * The function reads the provided input file stream, discards the header line,
 * and then parses each subsequent line as a date and value pair separated by a comma.
 * Each parsed value is inserted into the given Btc object.
 *
 * @param btc Reference to a Btc object where the parsed values will be inserted.
 * @param btc_infos_file Input file stream containing the Bitcoin data in CSV format.
 *
 * @throws std::runtime_error If there is an error reading the header line.
 * @note The header line of the CSV file will be discarded.
 */
void process_btc_file(BitcoinExchange &btc, std::ifstream &btc_infos_file) {
	std::string line;

	// Header discarded
	if (!std::getline(btc_infos_file, line)) {
		if (!btc_infos_file.eof())
			throw std::runtime_error("Error: Reading header line");
		else
			throw std::runtime_error("Error: Data.csv is empty");
	}
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: Wrong header in data.csv");
	// Parses each subsequent line as a date and value pair and inserted into the given Btc object.
	while (std::getline(btc_infos_file, line)) {
		std::istringstream iss(line);
		std::string date;
		std::string value;
		std::getline(iss, date, ',');
		std::getline(iss, value);
		std::stringstream ss(value);
		float btc_value;
		ss >> btc_value;
		if (ss.fail() || !ss.eof())
			throw std::runtime_error("Error: Invalid value in data.csv");
		btc.insertValue(date, btc_value);
	}
}

void checkDate(std::string date) {
	std::istringstream iss(date);
	int year, month, day;
	char trace1, trace2;

	if (date.size() != 10)
		throw std::runtime_error("Bad date format");
	// Check if is a digit (except for the index 4 and 7: "-")
	for (size_t i = 0; i < date.size(); i++) {
		if ((i != 4 && i != 7) && (date[i] < '0' || date[i] > '9'))
			throw std::runtime_error("Bad date format");
	}

	iss >> year >> trace1 >> month >> trace2 >> day;

	if (iss.fail() || !iss.eof() || trace1 != '-' || trace2 != '-') {
		throw std::runtime_error("Bad date format");
	}
	// Validate year, month, and day ranges
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		throw std::runtime_error("Invalid date");
	}
	// Validate months with 30 days (April, June, September, November)
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		throw std::runtime_error("Invalid date");
	}
	// Validate February, accounting for leap years
	if (month == 2) {
		bool bissexto = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if ((bissexto && day > 29) || (!bissexto && day > 28)) {
			throw std::runtime_error("Invalid date");
		}
	}
}

/*
Cenário					getline				Operador >>
Stream Vazio (1ª tentativa)		fail() e eof() true		fail() e eof() true
Leitura da última linha com sucesso	fail() false, eof() true	fail() false, eof() true
Tentativa de leitura após o fim		fail() e eof() true		fail() e eof() true
*/
void checkInputValue(std::istringstream &iss, std::string &date, float &value) {
	char delimiter;

	iss >> date;
	if (iss.fail())
		throw std::runtime_error("Bad input date");
	checkDate(date);
	iss >> delimiter;
	if (iss.fail() || delimiter != '|')
		throw std::runtime_error("Bad delimiter");
	iss >> value;
	if (iss.fail() || !iss.eof())
		throw std::runtime_error("The value is not a valid number or there is any character after the value");
	// These conditions already handle the overflow problem
	if (value < 0)
		throw std::runtime_error("The value cannot be negative.");
	if (value > 1000)
		throw std::runtime_error("The value cannot exceed 1000.");
}

void printInfo(BitcoinExchange &btc, std::string &date, float &value) {
	std::map<std::string, float>::const_iterator it;
	float btc_value;

	it = btc.getBtcMap().lower_bound(date);
	if (it != btc.getBtcMap().end() && date == (*it).first)
		btc_value = (*it).second;
	else if (btc.getBtcMap().begin() == it)
		throw std::runtime_error("No available Bitcoin data for this date or any previous date.");
	else
		btc_value = (*(--it)).second;

	std::cout << date << " => " << value << " = " << btc_value * value << std::endl;
}

void process_input_file(BitcoinExchange &btc, std::ifstream &btc_input_file) {
	std::string line;
	std::string date;
	float value;

	// Header discarded
	if (!std::getline(btc_input_file, line)) {
		if (btc_input_file.eof())
			throw std::runtime_error("Input file is empty");
		else
			throw std::runtime_error("Error readind input file");
	}
	if (line != "date | value")
		throw std::runtime_error("File header should be 'date | value'");
	// Get the btc total amount
	while (std::getline(btc_input_file, line)) {
		std::istringstream iss(line);
		try {
			checkInputValue(iss, date, value);
			printInfo(btc, date, value);
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}

int main(int argc, char const *argv[]) {
	BitcoinExchange btc;
	if (argc != 2) {
		std::cerr << RED << "Error: Usage: ./btc <file>" << RESET << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file_input(argv[1]);
	if (!file_input.is_open()) {
		std::cerr << RED << "Error: Could not open file " + std::string(argv[1]) << RESET
			  << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream btc_infos_file("data.csv");
	if (!btc_infos_file.is_open()) {
		std::cerr << RED << "Error: Could not open file data.csv" << RESET << std::endl;
		return EXIT_FAILURE;
	}
	try {
		process_btc_file(btc, btc_infos_file);
		process_input_file(btc, file_input);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
