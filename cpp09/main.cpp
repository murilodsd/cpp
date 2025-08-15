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
	for (std::map<std::string,float>::const_iterator it = btc.getBtcMap().begin(); it != btc.getBtcMap().end(); it++)
	{
		std::cout << "date: " << (*it).first << " value: " << (*it).second << std::endl;
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
	return EXIT_SUCCESS;

}
