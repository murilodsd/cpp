#pragma once
#include <iostream>
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* inventory[4];
	public:
		// Default constructor
		Character();
		Character(std::string name)

		// Copy constructor
		Character(const Character &other);

		// Copy assignment operator overload
		Character &operator=(const Character &other);

		// Destructor
		~Character();

		//Merber Functions
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#include "Character.hpp"

// ==================== Constructors ====================
Character::Character()
{
	std::cout << GREEN << "Character default constructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Character::Character(std::string name)
:
_name(name)
{
	std::cout << GREEN << "Character string constructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

// ================= Copy Constructor ==================
Character::Character(const Character &other)
:
_name(other._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i] != NULL)
		inventory[i] = other.inventory[i]->clone();
		else
		inventory[i] = NULL;
	}
	std::cout << GREEN << "Character copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
Character &Character::operator=(const Character &other)
{
	std::cout << GREEN << "Character copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; ++i)
		{
			if (inventory[i] != NULL)
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			if (other.inventory[i] != NULL)
			inventory[i] = other.inventory[i]->clone();
			else
			inventory[i] = NULL;
		}
	}
	return *this;
}

// ==================== Destructor =====================
Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	std::cout << RED << "Character destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
std::string const & Character::getName() const
{
	return (_name);
}
void Character::equip(AMateria* m)
{

}
void Character::unequip(int idx)
{

}
void Character::use(int idx, ICharacter& target)
{

}