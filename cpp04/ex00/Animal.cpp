#include "Animal.hpp"
#include <iostream>

// ==================== Constructors ====================
Animal::Animal()
:
_type("Unknown Animal")
{
	std::cout << GREEN << "Animal default constructor called!" << RESET << std::endl;
}
Animal::Animal(std::string type)
:
_type(type)
{
	std::cout << GREEN << "Animal parametrized constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
Animal::Animal(const Animal &other)
:
_type(other._type)
{
	std::cout << GREEN << "Animal copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
Animal &Animal::operator=(const Animal &other)
{
	std::cout << GREEN << "Animal copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// ==================== Destructor =====================
Animal::~Animal()
{
	std::cout << RED << "Animal destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================

const std::string& Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << CYAN << "Unknown animal makes an undefined sound." << RESET << std::endl;
}
