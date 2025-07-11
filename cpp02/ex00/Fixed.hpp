#pragma once

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
#define WHITESPACE_CHARS " \t\n\r\f\v"

class Fixed
{
	private:
	int	_fixedPointNumber;
	static const int	 _fractionalBits = 8;

	public:
	// Default constructor
	Fixed();

	// Copy constructor
	Fixed(const Fixed &other);

	// Copy assignment operator overload
	Fixed &operator=(const Fixed &other);

	// Destructor
	~Fixed();

	int	getRawBits( void ) const;
	void 	setRawBits( const int &raw );
};