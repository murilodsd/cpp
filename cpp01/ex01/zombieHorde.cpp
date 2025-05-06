/* It must allocate N Zombie objects in a single allocation. Then, it must initialize the
zombies, giving each of them the name passed as a parameter. The function returns a
pointer to the first zombie. */
#include "Zombie.hpp"
#include <string>
Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieHorde;

	if (N <= 0)
	{
		std::cout << RED << "Parameter N must be greater than zero" << RESET << std::endl;
        	return (NULL);
	}
	
	zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombieHorde[i].set_name(name);

	return (zombieHorde);
}
