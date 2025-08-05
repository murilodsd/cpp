#include <iostream>
#include <cstdlib>
#include "Array.hpp"

int main()
{
	std::cout << "Testing default constructor (empty array):" << std::endl;
	Array<int> int_array;
	std::cout << "Size: " << int_array.size() << std::endl;

	std::cout << "Testing access to empty array (should throw exception):" << std::endl;
	try
	{
		std::cout << int_array[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error accessing array: " << e.what() << '\n';
	}
	
	std::cout << "Testing constructor with size 5:" << std::endl;
	Array<int> int_array5(5);
	std::cout << "Size: " << int_array5.size() << std::endl;

	std::cout << "Testing array access and assignment:" << std::endl;
	std::cout << "Initial value at index 0: " << int_array5[0] << std::endl;
	int_array5[0] = 10;
	std::cout << "Value after assignment: " << int_array5[0] << std::endl;

	std::cout << "Testing assignment operator:" << std::endl;
	int_array = int_array5;

	std::cout << "Testing with complex type (std::string):" << std::endl;
	Array<std::string> string_array(3);
	std::cout << "String array size: " << string_array.size() << std::endl;
	string_array[0] = "Hello";
	string_array[1] = "World";
	string_array[2] = "!";
	
	std::cout << "String array contents: ";
	for (unsigned int i = 0; i < string_array.size(); i++)
	{
		std::cout << string_array[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}


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
}