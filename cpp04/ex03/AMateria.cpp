#include "AMateria.hpp"

// ========== Static Variables Initialization ==========
AMateria** AMateria::_droppedMaterias = NULL;
size_t      AMateria::_droppedCount = 0;
size_t      AMateria::_droppedCapacity = 0;

// ==================== Constructors ====================
AMateria::AMateria()
{
	std::cout << GREEN << "AMateria default constructor called!" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type)
:
_type(type)
{
	std::cout << GREEN << "AMateria string constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
AMateria::AMateria(const AMateria &other)
:
_type(other._type)
{
	std::cout << GREEN << "AMateria copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << GREEN << "AMateria copy assignment operator called!" << RESET << std::endl;
	(void)other;
	return *this;
}

// ==================== Destructor =====================
AMateria::~AMateria()
{
std::cout << RED << "AMateria destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	// Base implementation does nothing - derived classes should override this
}

void AMateria::addDroppedMateria(AMateria* m) {
	if (m == NULL)
		return;

	if (_droppedCount >= _droppedCapacity)
	{
		size_t newCapacity = (_droppedCapacity == 0) ? 4 : _droppedCapacity * 2;

		AMateria** newDropped = new AMateria*[newCapacity];

		for (size_t i = 0; i < _droppedCount; ++i)
			newDropped[i] = _droppedMaterias[i];

		delete[] _droppedMaterias;

		_droppedMaterias = newDropped;
		_droppedCapacity = newCapacity;
	}

	_droppedMaterias[_droppedCount] = m;
	_droppedCount++;
}

void AMateria::cleanupDroppedMaterias() {
	for (size_t i = 0; i < _droppedCount; ++i)
		delete _droppedMaterias[i];

	delete[] _droppedMaterias;

	_droppedMaterias = NULL;
	_droppedCount = 0;
	_droppedCapacity = 0;
}