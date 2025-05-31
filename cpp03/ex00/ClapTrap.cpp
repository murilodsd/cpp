#include "ClapTrap.hpp"
#include <string>
#include <iostream>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// ================= Auxiliar Functions ================
void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints != 0 && _hitPoints != 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << CYAN << _name << RESET << " attacks " << CYAN << target << RESET
				  << ", causing " << CYAN << _attackDamage << RESET << " points of damage! Now has "
				  << CYAN << _energyPoints << RESET << " energy points." << std::endl;
	}
	else if (_hitPoints == 0)
		std::cout << RED << "ClapTrap " << _name << " cannot attack because it has no hit points left." << RESET << std::endl;
	else
		std::cout << RED << "ClapTrap " << _name << " cannot attack because it has no energy points left." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints < amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << CYAN << _name << RESET << " lost " << CYAN << amount << RESET
			  << " hit points. Now has " << CYAN << _hitPoints << RESET << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints != 0 && _hitPoints != 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << CYAN << _name << RESET << " has been repaired and recovered "
				  << CYAN << amount << RESET << " hit points. Now has " << CYAN << _hitPoints << RESET
				  << " hit points and " << CYAN << _energyPoints << RESET << " energy points." << std::endl;
	}
	else if (_hitPoints == 0)
		std::cout << RED << "ClapTrap " <<  _name << " cannot be repaired because it has no hit points left." << RESET << std::endl;
	else
		std::cout << RED << "ClapTrap " <<  _name << " cannot be repaired because it has no energy points left." << RESET << std::endl;
}

// ==================== Constructor ====================
ClapTrap::ClapTrap()
:
_name("Default"),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0)
{
	std::cout << GREEN << "ClapTrap default constructor called: "
			  << "name=" << _name << ", "
			  << "hitPoints=" << _hitPoints << ", "
			  << "energyPoints=" << _energyPoints << ", "
			  << "attackDamage=" << _attackDamage
			  << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:
_name(name),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0)
{
	std::cout << GREEN << "ClapTrap parameterized constructor called: "
			  << "name=" << _name << ", "
			  << "hitPoints=" << _hitPoints << ", "
			  << "energyPoints=" << _energyPoints << ", "
			  << "attackDamage=" << _attackDamage
			  << RESET << std::endl;
}

// ================= Copy Constructor ==================
ClapTrap::ClapTrap(const ClapTrap &other)
:
_name(other._name),
_hitPoints(other._hitPoints),
_energyPoints(other._energyPoints),
_attackDamage(other._attackDamage)
{
	std::cout << GREEN << "ClapTrap copy constructor called: "
			  << "name=" << _name << ", "
			  << "hitPoints=" << _hitPoints << ", "
			  << "energyPoints=" << _energyPoints << ", "
			  << "attackDamage=" << _attackDamage
			  << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << GREEN << "ClapTrap copy assignment operator called: "
		<< "ClapTrap '" << _name << "' is receiving values from ClapTrap '" << other._name << "'. " << RESET << std::endl;
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
ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap destructor called for " << _name << RESET << std::endl;
}
