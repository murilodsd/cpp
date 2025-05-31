#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Default constructor
		ScavTrap();
		ScavTrap(std::string name);

		// Copy constructor
		ScavTrap(const ScavTrap &other);

		// Copy assignment operator overload
		ScavTrap &operator=(const ScavTrap &other);

		// Destructor
		~ScavTrap();

		// Member Functions
		void	attack(const std::string& target);
		void	guardGate(void);
};