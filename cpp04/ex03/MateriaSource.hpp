#pragma once
#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_learnedMaterias[4];
		int		_learnedCount;
	public:
		// Default constructor
		MateriaSource();

		// Copy constructor
		MateriaSource(const MateriaSource &other);

		// Copy assignment operator overload
		MateriaSource &operator=(const MateriaSource &other);

		// Destructor
		~MateriaSource();

		// Member Functions
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
