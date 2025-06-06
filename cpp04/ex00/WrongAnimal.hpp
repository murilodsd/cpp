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

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		// Default constructor
		WrongAnimal();
		WrongAnimal(std::string type);

		// Copy constructor
		WrongAnimal(const WrongAnimal &other);

		// Copy assignment operator overload
		WrongAnimal &operator=(const WrongAnimal &other);

		// Destructor
		~WrongAnimal();

		//Getters
		const std::string& getType() const;

		//Member functions
		void makeSound() const;
};
