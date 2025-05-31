#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	
	public:
		// Default constructor
		DiamondTrap();
		DiamondTrap(std::string name);

		// Copy constructor
		DiamondTrap(const DiamondTrap &other);

		// Copy assignment operator overload
		DiamondTrap &operator=(const DiamondTrap &other);

		// Destructor
		~DiamondTrap();

		// Member Functions
		void	attack(const std::string& target);
		void	whoAmI(void);
};