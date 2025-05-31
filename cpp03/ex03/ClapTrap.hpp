#pragma once
#include <string>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class ClapTrap
{
	protected:
		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		// Constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);


		// Copy constructor
		ClapTrap(const ClapTrap &other);

		// Copy assignment operator overload
		ClapTrap &operator=(const ClapTrap &other);
		
		//others method
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Destructor
		~ClapTrap();
};
