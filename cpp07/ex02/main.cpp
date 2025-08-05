#include <iostream>
#include <cstdlib>
#include "Array.hpp"

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

int main()
{
	std::cout << BOLD << CYAN << "\n=== Testing default constructor (empty array) ===" << RESET << std::endl;
	Array<int> int_array;
	std::cout << "Size: " << int_array.size() << std::endl;

	std::cout << BOLD << CYAN << "\n=== Testing access to empty array (should throw exception) ===" << RESET << std::endl;
	try
	{
		std::cout << int_array[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error accessing array: " << e.what() << RESET << '\n';
	}
	
	std::cout << BOLD << CYAN << "\n=== Testing constructor with size 5 ===" << RESET << std::endl;
	Array<int> int_array5(5);
	std::cout << "Size: " << int_array5.size() << std::endl;

	std::cout << BOLD << CYAN << "\n=== Testing array access and assignment ===" << RESET << std::endl;
	std::cout << "Initial value at index 0: " << int_array5[0] << std::endl;
	int_array5[0] = 10;
	std::cout << "Value after assignment: " << int_array5[0] << std::endl;
	
	std::cout << BOLD << CYAN << "\n=== Testing assignment operator ===" << RESET << std::endl;
	std::cout << BOLD << CYAN << "empty array = array of size 5" << RESET << std::endl;
	int_array = int_array5;
	std::cout << "Value after assignment operator: " << int_array.size() << std::endl;

	std::cout << BOLD << CYAN << "\n=== Testing with complex type (std::string) ===" << RESET << std::endl;
	Array<std::string> string_array(3);
	std::cout << "String array size: " << string_array.size() << std::endl;
	string_array[0] = "Hello";
	string_array[1] = "World";
	string_array[2] = "!";

	std::cout << "String array contents: ";
	for (unsigned int i = 0; i < string_array.size(); i++)
	{
		std::cout << GREEN << string_array[i] << " " << RESET;
	}
	std::cout << std::endl;

	std::cout << BOLD << CYAN << "\n=== End of tests ===\n" << RESET << std::endl;
	return 0;
}

/* 
#define MAX_VAL 750
int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */