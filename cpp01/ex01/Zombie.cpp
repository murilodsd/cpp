#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << GREEN << "Zombie created" << RESET << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << RED << name << ": killed" << RESET  << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << CYAN  << name << ": BraiiiiiiinnnzzzZ..." << RESET  << std::endl;
}

void	Zombie::set_name(std::string _name)
{
	name = _name;
}