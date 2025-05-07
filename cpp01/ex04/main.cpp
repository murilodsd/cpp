#include <string>
#include <iostream>
#include <cstdlib>
#include "utils.hpp"
#include <fstream>
#include <cctype>
#include <functional>

void validateArguments(int argc)
{
    if (argc != 4)
    {
        std::cerr << RED << "Error: Invalid number of arguments.\n"
                  << "Usage: ./program <filename> <string_to_replace> <new_string>" << RESET << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void openInputFile(std::ifstream &file_in, const char *filename, std::ios_base::openmode mode)
{
	file_in.open(filename, mode);
	if (!file_in)
	{
		std::cerr << "Error: Could not open the input file: " << filename << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void openOutputFile(std::ofstream &file_out, const char *filename, std::ios_base::openmode mode)
{
    file_out.open(filename, mode);
    if (!file_out)
    {
        std::cerr << "Error: Could not open the output file: " << filename << std::endl;
        std::exit(EXIT_FAILURE);
    }
}


int main(int argc, char *argv[])
{
	validateArguments(argc);

	
	std::string inputFileName = argv[1];
	std::ifstream file_in;
	openInputFile(file_in, argv[1], std::ios::in);
	std::string outputFileName = argv[1] + std::string("replace");
	std::ofstream file_out;
	openOutputFile(file_out, outputFileName.c_str(), std::ios::out);
	
	while (true)
	{
		std::string line;
		std::getline(file_in, line);
		std::cout << line;
		file_out << line;
		if (file_in.eof())
			break;
		std::cout << std::endl;
		file_out << std::endl;	
	}
	file_in.close();
	file_out.close();
	return (EXIT_SUCCESS);
}
