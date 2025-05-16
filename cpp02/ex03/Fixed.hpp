#pragma once
#include <ostream>

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

	// Constructors
	Fixed(const int number);
	Fixed(const float number);

	// Copy constructor
	Fixed(const Fixed &other);

	// Copy assignment operator overload
	Fixed &operator=(const Fixed &other);

	// Comparison Operators overload
	bool	operator>(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	// Arithmetic operators overload
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	// Increment/decrement operators overload
	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	// min/max functions
	static Fixed	&min(Fixed &fixedNum1, Fixed &fixedNum2);
	static const Fixed	&min(const Fixed &fixedNum1, const Fixed &fixedNum2);
	static Fixed	&max(Fixed &fixedNum1, Fixed &fixedNum2);
	static const Fixed	&max(const Fixed &fixedNum1, const Fixed &fixedNum2);


	// Destructor
	~Fixed();

	int	getRawBits( void ) const;
	void 	setRawBits( int const raw );

	float	toFloat( void ) const;
	int	toInt( void ) const;
};

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);