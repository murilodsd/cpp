#include "Zombie.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int N = 8;

	std::cout << YELLOW << "Creating a horde of " << N << " zombies...\n" << RESET << std::endl;

	Zombie* horde = zombieHorde(N, "Zombie");

	std::cout << YELLOW << "\nHorde created\n" << RESET << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << i << ":";
		horde[i].announce();
	}

	std::cout << YELLOW << "\nKilling zombies...\n" << RESET << std::endl;
	
	delete[] horde; 

	std::cout << YELLOW << "\nHorde killed\n" << RESET << std::endl;
	
	return (EXIT_SUCCESS);
}
