#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

// ==================== Constructors ====================
Cat::Cat()
:
Animal("Cat")
{
	brain = new Brain();
	std::cout << GREEN << "Cat default constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
Cat::Cat(const Cat &other)
:
Animal(other._type)
{
	brain = new Brain(*other.brain);
	std::cout << GREEN << "Cat copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
Cat &Cat::operator=(const Cat &other)
{
	std::cout << GREEN << "Cat copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

// ==================== Destructor =====================
Cat::~Cat()
{
	delete brain;
	std::cout << RED << "Cat destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
void Cat::makeSound() const
{
	std::cout << CYAN << "Meow!" << RESET << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain;
}
