#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		// Default constructor
		FragTrap();
		FragTrap(std::string name);

		// Copy constructor
		FragTrap(const FragTrap &other);

		// Copy assignment operator overload
		FragTrap &operator=(const FragTrap &other);

		// Destructor
		~FragTrap();

		// Member Functions
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};