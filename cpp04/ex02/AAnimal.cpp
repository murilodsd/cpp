#include "AAnimal.hpp"
#include <iostream>

// ==================== Constructors ====================
AAnimal::AAnimal()
:
_type("Unknown AAnimal")
{
	std::cout << GREEN << "AAnimal default constructor called!" << RESET << std::endl;
}
AAnimal::AAnimal(std::string type)
:
_type(type)
{
	std::cout << GREEN << "AAnimal parametrized constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
AAnimal::AAnimal(const AAnimal &other)
:
_type(other._type)
{
	std::cout << GREEN << "AAnimal copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << GREEN << "AAnimal copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// ==================== Destructor =====================
AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================

const std::string& AAnimal::getType() const
{
	return (_type);
}

void AAnimal::makeSound() const
{
	std::cout << CYAN << "Unknown Aanimal makes an undefined sound." << RESET << std::endl;
}
