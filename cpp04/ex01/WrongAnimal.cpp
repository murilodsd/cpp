#include "WrongAnimal.hpp"
#include <iostream>

// ==================== Constructors ====================
WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal default constructor called!" << RESET << std::endl;
}
WrongAnimal::WrongAnimal(std::string type)
:
_type(type)
{
	std::cout << GREEN << "WrongAnimal parametrized constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
WrongAnimal::WrongAnimal(const WrongAnimal &other)
:
_type(other._type)
{
	std::cout << GREEN << "WrongAnimal copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << GREEN << "WrongAnimal copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// ==================== Destructor =====================
WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================

const std::string& WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << CYAN << "Unknown WrongAnimal makes an undefined sound." << RESET << std::endl;
}
