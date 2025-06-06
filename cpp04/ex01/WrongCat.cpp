#include "WrongCat.hpp"
#include <iostream>

// ==================== Constructors ====================
WrongCat::WrongCat()
:
WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat default constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
WrongCat::WrongCat(const WrongCat &other)
:
WrongAnimal(other._type)
{
	std::cout << GREEN << "WrongCat copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << GREEN << "WrongCat copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// ==================== Destructor =====================
WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
void WrongCat::makeSound() const
{
	std::cout << CYAN << "Meow!" << RESET << std::endl;
}
