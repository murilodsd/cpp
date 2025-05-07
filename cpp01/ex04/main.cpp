#include <string>
#include <iostream>
#include <cstdlib>
#include "utils.hpp"
#include <fstream>
#include <cctype>
#include <functional>

typedef struct arguments
{
	std::string inputFileName;
	std::string strToBeReplaced;
	std::string strNew;

} s_arguments;

void handleArguments(int argc, std::string strToBeReplaced)
{
	if (argc != 4)
	{
		std::cerr << RED << "Error: Invalid number of arguments.\n"
			<< "Usage: ./program <filename> <string_to_replace> <new_string>" << RESET << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (strToBeReplaced.empty())
	{
		std::cerr << "Error: The string to replace cannot be empty." << std::endl;
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

void	setUpFiles(char *argv[], std::ifstream &file_in, std::ofstream &file_out)
{
	std::string inputFileName = argv[1];
	std::string outputFileName = inputFileName + std::string("replace");
	openInputFile(file_in, inputFileName.c_str(), std::ios::in);
	openOutputFile(file_out, outputFileName.c_str(), std::ios::out);
}

void	replace(std::ifstream &file_in, std::ofstream &file_out, \
	const std::string &strToBeReplaced, const std::string &strNew)
{
	std::string line;
	size_t	pos;
	size_t	end = 0;
	while (true)
	{
		std::getline(file_in, line);
		while (true)
		{
			pos = end;
			end = line.find(strToBeReplaced, pos);
			if (end == std::string::npos)
			{
				file_out << line.substr(pos);
				end = 0;
				break ;
			}
			file_out << line.substr(pos, end - pos);
			file_out << strNew;
			end += strToBeReplaced.size();
		}
		if (file_in.eof())
			break;
		file_out << std::endl;	
	}
}

int main(int argc, char *argv[])
{
	std::string strToBeReplaced = argv[2];
	
	handleArguments(argc, strToBeReplaced);
	
	std::ifstream file_in;
	std::ofstream file_out;
	setUpFiles(argv, file_in, file_out);
	
	std::string strNew = argv[3];
	replace(file_in, file_out, strToBeReplaced, strNew);
	
	file_in.close();
	file_out.close();
	return (EXIT_SUCCESS);
}
