#include "Zombie.hpp"
#include <string>

//This function creates a zombie, names it, and makes it announce itself.
void	randomChump( std::string name )
{
	Zombie	zombie;

	zombie.set_name(name);
	zombie.announce();
}