#include "Zombie.hpp"
#include <string>

Zombie::Zombie()
{
	std::cout << GREEN << "Zombie created" << RESET << std::endl;
}

Zombie::Zombie(std::string zombieName)
:
name(zombieName)
{
	std::cout << GREEN << "Zombie created" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << name << ": killed" << RESET  << std::endl;
}

void	Zombie::announce()
{
	std::cout << CYAN  << name << ": BraiiiiiiinnnzzzZ..." << RESET  << std::endl;
}

void	Zombie::set_name(std::string zombieName)
{
	name = zombieName;
}