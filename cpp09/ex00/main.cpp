#include <iostream>
#include <cstdlib>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <string>
#include <sstream>
#include "Btc.hpp"

#ifndef COLORS
# define COLORS
# define RESET "\033[0m"
# define BOLD "\033[1m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
#endif


void process_btc_file(Btc &btc, std::ifstream &btc_infos_file)
{
	std::string line;

	if (!std::getline(btc_infos_file, line))
	{
		if (!btc_infos_file.eof())
			throw std::runtime_error("Error: Reading header line");
		else
			std::cerr << RED << "Error: Data.csv is empty" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	while(std::getline(btc_infos_file, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string value;
		std::getline(iss, date, ',');
		std::getline(iss, value);
		btc.insertValue(date, atof(value.c_str()));
	}
}

void checkDate(std::string date)
{
	std::istringstream iss(date);
	int year, month, day;
	char trace1, trace2;

	if (date.size() != 10)
		throw std::runtime_error("Bad date format");
	for (size_t i = 0; i < date.size(); i++)
	{
		if ((i != 4 && i != 7) && (date[i] < '0' || date[i] > '9'))
			throw std::runtime_error("Bad date format");
	}

	iss >> year >> trace1 >> month >> trace2 >> day;

	if (iss.fail() || !iss.eof() || trace1 != '-' || trace2 != '-')
	{
       		throw std::runtime_error("Bad date format");
	}
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		throw std::runtime_error("Invalid date");
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		throw std::runtime_error("Invalid date");
	}
	if (month == 2)
	{
		bool bissexto = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if ((bissexto && day > 29) || (!bissexto && day > 28))
		{
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
void checkInputValue(std::istringstream &iss, std::string& date, float& value)
{
	char delimiter;

	iss >> date;
	if (iss.fail())
		throw std::runtime_error("Bad input");
	checkDate(date);
	iss >> delimiter;
	if (iss.fail() || delimiter != '|')
		throw std::runtime_error("Bad delimiter");
	iss >> value;
	if (iss.fail())
		throw std::runtime_error("The value is not a valid number.");
	if (value < 0)
		throw std::runtime_error("The value cannot be negative.");
	if (value > 1000)
		throw std::runtime_error("The value cannot exceed 1000.");
}

void printInfo(Btc &btc, std::string& date, float& value)
{
	std::map<std::string, float>::const_iterator it;
	float btc_value;

	it = btc.getBtcMap().lower_bound(date);
	if (date == (*it).first)
		btc_value = (*it).second;
	else
		btc_value = (*(--it)).second;

	std::cout << date << " => " << value << " = " << btc_value * value << std::endl;
}

void	process_input_file(Btc &btc, std::ifstream &btc_input_file)
{
	std::string line;
	std::string date;
	float value;
	
	if (!std::getline(btc_input_file, line))
	{
		if (btc_input_file.eof())
			std::cerr << RED << "Error: Input file is empty" << RESET << std::endl;
		else
			std::cerr << RED << "Error: Error readind input file" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	while (std::getline(btc_input_file, line))
	{
		std::istringstream iss(line);
		try
		{
			checkInputValue(iss, date, value);
			printInfo(btc, date, value);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}

int main(int argc, char const *argv[])
{
	Btc btc;
	if (argc != 2)
	{
		std::cerr << RED  << "Error: Usage: ./btc <file>" << RESET << std::endl;
		return EXIT_FAILURE;
	}
	
	std::ifstream file_input(argv[1]);
	if (!file_input.is_open())
	{
		std::cerr << RED  << "Error: Could not open file " + std::string(argv[1]) << RESET << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream btc_infos_file("data.csv");
	if (!btc_infos_file.is_open())
	{
		std::cerr << RED << "Error: Could not open file data.csv" << RESET << std::endl;
		return EXIT_FAILURE;
	}
	process_btc_file(btc, btc_infos_file);
	process_input_file(btc, file_input);
	return EXIT_SUCCESS;
}
