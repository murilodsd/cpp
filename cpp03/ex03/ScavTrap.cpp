#include "ScavTrap.hpp"
#include <iostream>

// ================= Member Functions ===================

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints != 0 && _hitPoints != 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << CYAN << _name << RESET << " attacks " << CYAN << target << RESET
				  << ", causing " << CYAN << _attackDamage << RESET << " points of damage! Now has "
				  << CYAN << _energyPoints << RESET << " energy points." << std::endl;
	}
	else if (_hitPoints == 0)
		std::cout << RED << "ScavTrap " << _name << " cannot attack because it has no hit points left." << RESET << std::endl;
	else
		std::cout << RED << "ScavTrap " << _name << " cannot attack because it has no energy points left." << RESET << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << YELLOW << "ScavTrap " << _name << " is now in Gate keeper mode." << RESET << std::endl;
}

// ==================== Constructors ====================
ScavTrap::ScavTrap()
:
ClapTrap("Default", 100, DEFAULT_EP, 20)
{
	std::cout << GREEN << "ScavTrap default constructor called" << RESET << std::endl;
};

ScavTrap::ScavTrap(std::string name)
:
ClapTrap(name, 100, DEFAULT_EP, 20)
{
    	std::cout << GREEN << "ScavTrap parameterized constructor called" << RESET << std::endl;
};

// ================= Copy Constructor ==================
ScavTrap::ScavTrap(const ScavTrap &other)
:
ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
    	std::cout << GREEN << "ScavTrap copy constructor called: "
		<< "name=" << _name << ", "
		<< "hitPoints=" << _hitPoints << ", "
		<< "energyPoints=" << _energyPoints << ", "
		<< "attackDamage=" << _attackDamage
		<< RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << GREEN << "ScavTrap copy assignment operator called: "
		<< "ScavTrap '" << _name << "' is receiving values from ScavTrap '" << other._name << "'. " << RESET << std::endl;
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
ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor called for " << _name << RESET << std::endl;
}