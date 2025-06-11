#include "Character.hpp"

// ==================== Constructors ====================
Character::Character()
:
_name("default")
{
	std::cout << GREEN << "Character default constructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(std::string name)
:
_name(name)
{
	std::cout << GREEN << "Character string constructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

// ================= Copy Constructor ==================
Character::Character(const Character &other)
:
_name(other._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
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
			if (_inventory[i] != NULL)
				{
					delete _inventory[i];  // ← Deleta diretamente
					_inventory[i] = NULL;
				}
		}
		for (int i = 0; i < 4; ++i)
		{
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

// ==================== Destructor =====================
Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
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
	if (!m)
	{
		std::cout << RED << "Cannot equip a null materia!" << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << CYAN << "Materia equipped in slot " << i << "!" << RESET << std::endl;
			return ;
		}
	}
	std::cout << RED << "Inventory is full! Please unequip an item first." << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
	{
		std::cout << CYAN << "Materia unequipped from slot " << idx << "!" << RESET << std::endl;
		AMateria::addDroppedMateria(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << RED << "Cannot unequip from slot " << idx << "! Invalid slot or empty." << RESET << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
	else
		std::cout << RED << "Cannot use materia from slot " << idx << "! Invalid slot or empty." << RESET << std::endl;
}