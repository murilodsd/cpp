#include "DiamondTrap.hpp"
#include <iostream>

// ================= Member Functions ===================

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << YELLOW << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << RESET << std::endl;
}

// ==================== Constructors ====================
DiamondTrap::DiamondTrap()
:
ClapTrap("Default_clap_name", 100, 50, 30),
ScavTrap(),
FragTrap(),
_name("Default")
{
	std::cout << GREEN << "DiamondTrap default constructor called" << RESET << std::endl;
};

DiamondTrap::DiamondTrap(std::string name)
:
ClapTrap(name + "_clap_name", 100, 50, 30),
ScavTrap(),
FragTrap(),
_name(name)
{
    	std::cout << GREEN << "DiamondTrap parameterized constructor called" << RESET << std::endl;
};

// ================= Copy Constructor ==================
DiamondTrap::DiamondTrap(const DiamondTrap &other)
:
ClapTrap(other.ClapTrap::_name, other._hitPoints, other._energyPoints, other._attackDamage),
ScavTrap(),
FragTrap(),
_name(other._name)
{
    	std::cout << GREEN << "DiamondTrap copy constructor called: "
		<< "ClapTrapName=" << ClapTrap::_name << ", "
		<< "name=" << _name << ", "
		<< "hitPoints=" << _hitPoints << ", "
		<< "energyPoints=" << _energyPoints << ", "
		<< "attackDamage=" << _attackDamage
		<< RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << GREEN << "DiamondTrap copy assignment operator called: "
		<< "DiamondTrap '" << _name << "' is receiving values from DiamondTrap '" << other._name << "'. " << RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::_name = other.ClapTrap::_name;
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << GREEN << "ClapTrapName=" << ClapTrap::_name << ", "
		<< "name=" << _name << ", "
		<< "hitPoints=" << _hitPoints << ", "
		<< "energyPoints=" << _energyPoints << ", "
		<< "attackDamage=" << _attackDamage
		<< RESET << std::endl;
	return *this;
}

// ==================== Destructor =====================
DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor called for " << _name << RESET << std::endl;
}