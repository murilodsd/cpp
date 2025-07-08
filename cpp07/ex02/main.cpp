#include <iostream>
#include <cstdlib>
#include "Array.hpp"

/* int main()
{
	Array<int> int_array;
	std::cout << int_array.size() << std::endl;

	try
	{
		std::cout << int_array[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Erro accessing array: " << e.what() << '\n';
	}
	

	Array<int> int_array5(5);
	std::cout << int_array5.size() << std::endl;

	std::cout << int_array5[0] << std::endl;
	int_array5[0] = 10;
	std::cout << int_array5[0] << std::endl;

	int_array = int_array5;

	return 0;
} */


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