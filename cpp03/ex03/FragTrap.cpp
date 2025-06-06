#include "FragTrap.hpp"
#include <iostream>

// ================= Member Functions ===================

void FragTrap::attack(const std::string& target)
{
	if (_energyPoints != 0 && _hitPoints != 0)
	{
		_energyPoints--;
		std::cout << "FragTrap " << CYAN << _name << RESET << " attacks " << CYAN << target << RESET
				  << ", causing " << CYAN << _attackDamage << RESET << " points of damage! Now has "
				  << CYAN << _energyPoints << RESET << " energy points." << std::endl;
	}
	else if (_hitPoints == 0)
		std::cout << RED << "FragTrap " << _name << " cannot attack because it has no hit points left." << RESET << std::endl;
	else
		std::cout << RED << "FragTrap " << _name << " cannot attack because it has no energy points left." << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << YELLOW << "FragTrap " << _name << " requests a high five! ✋" << RESET << std::endl;
}

// ==================== Constructors ====================
FragTrap::FragTrap()
:
ClapTrap("Default", 100, 100, 30)
{
	std::cout << GREEN << "FragTrap default constructor called" << RESET << std::endl;
};

FragTrap::FragTrap(std::string name)
:
ClapTrap(name, 100, 100, 30)
{
    	std::cout << GREEN << "FragTrap parameterized constructor called" << RESET << std::endl;
};

// ================= Copy Constructor ==================
FragTrap::FragTrap(const FragTrap &other)
:
ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
    	std::cout << GREEN << "FragTrap copy constructor called: "
		<< "name=" << _name << ", "
		<< "hitPoints=" << _hitPoints << ", "
		<< "energyPoints=" << _energyPoints << ", "
		<< "attackDamage=" << _attackDamage
		<< RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << GREEN << "FragTrap copy assignment operator called: "
		<< "FragTrap '" << _name << "' is receiving values from FragTrap '" << other._name << "'. " << RESET << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << GREEN << "name=" << _name << ", "
		<< "hitPoints=" << _hitPoints << ", "
		<< "energyPoints=" << _energyPoints << ", "
		<< "attackDamage=" << _attackDamage
		<< RESET << std::endl;
	return *this;
}

// ==================== Destructor =====================
FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap destructor called for " << _name << RESET << std::endl;
}