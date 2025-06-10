#pragma once
#include <string>
#include <iostream>
#include "ICharacter.hpp"

#ifndef COLORS

# define COLORS
# define RESET "\033[0m"
# define BOLD "\033[1m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

#endif

class AMateria
{
	protected:
		std::string	_type;
	public:
		// Default constructor
		AMateria();
		AMateria(std::string const & type);

		// Copy constructor
		AMateria(const AMateria &other);

		// Copy assignment operator overload
		AMateria &operator=(const AMateria &other);

		// Destructor
		virtual ~AMateria();

		//Member functions
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
