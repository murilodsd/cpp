#pragma once
#include <string>

class ClapTrap
{
	private:
		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		// Constructors
		ClapTrap();
		ClapTrap(std::string name);

		// Copy constructor
		ClapTrap(const ClapTrap &other);

		// Copy assignment operator overload
		ClapTrap &operator=(const ClapTrap &other);
		
		//others method
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Destructor
		~ClapTrap();
};
