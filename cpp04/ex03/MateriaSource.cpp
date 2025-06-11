#include "MateriaSource.hpp"

// ==================== Constructors ====================
MateriaSource::MateriaSource()
:
_learnedCount(0)
{
	std::cout << GREEN << "MateriaSource default constructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
		this->_learnedMaterias[i] = NULL;
}

// ================= Copy Constructor ==================
MateriaSource::MateriaSource(const MateriaSource &other)
:
_learnedCount(other._learnedCount)
{
	std::cout << GREEN << "MateriaSource copy constructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other._learnedMaterias[i] != NULL)
			this->_learnedMaterias[i] = other._learnedMaterias[i]->clone();
		else
			this->_learnedMaterias[i] = NULL;
	}
}

// ========== Copy Assignment Operator Overload ==========
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << GREEN << "MateriaSource copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < this->_learnedCount; ++i)
        		delete this->_learnedMaterias[i];
		this->_learnedCount = other._learnedCount;
		for (int i = 0; i < 4; ++i)
		{
			if (other._learnedMaterias[i] != NULL)
				this->_learnedMaterias[i] = other._learnedMaterias[i]->clone();
			else
				this->_learnedMaterias[i] = NULL;
		}
	}
	return *this;
}

// ==================== Destructor =====================
MateriaSource::~MateriaSource()
{
	std::cout << RED << "MateriaSource destructor called!" << RESET << std::endl;
	for (int i = 0; i < this->_learnedCount; ++i)
       		delete this->_learnedMaterias[i];
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL || this->_learnedCount >= 4)
	{
		if (m != NULL)
		{
			std::cout << RED << "MateriaSource inventory is full, deleting materia to avoid memory leak" << RESET << std::endl;
			delete m;
		}
		else
			std::cout << RED << "Cannot learn NULL materia" << RESET << std::endl;
		return;
	}
	std::cout << CYAN << "MateriaSource learned new materia: " << m->getType() << RESET << std::endl;
	this->_learnedMaterias[this->_learnedCount] = m;
	this->_learnedCount++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_learnedCount; ++i)
	{
		if (this->_learnedMaterias[i]->getType() == type)
		{
			std::cout << CYAN << "MateriaSource creating materia: " << type << "..." << RESET << std::endl;
			return this->_learnedMaterias[i]->clone();
		}
	}
	std::cout << RED << "MateriaSource cannot create materia: " << type << " (not learned)" << RESET << std::endl;
	return NULL;
}