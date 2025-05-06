#include "Zombie.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "Zombie");


	for (int i = 0; i < N; i++)
	{
		std::cout << i << ":";
		horde[i].announce(); // Cada zumbi anuncia seu nome
	}

	// Libera a memória do array de zumbis
	delete[] horde; // Chama o destrutor de cada zumbi automaticamente

	return (EXIT_SUCCESS);
}
