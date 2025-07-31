#pragma once
#include <iostream>
#include <string>
#include <exception>

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

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;
	public:
		// Default constructor
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);

		// Copy constructor
		Bureaucrat(const Bureaucrat &other);

		// Copy assignment operator overload
		Bureaucrat &operator=(const Bureaucrat &other);

		// Destructor
		~Bureaucrat();

		//others methods
		const std::string&	getName() const;
		int			getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
		void			signForm(AForm &Aform) const;
		void			executeForm(AForm const & form) const;

		//exceptions
		class GradeTooHighException : public std::logic_error
		{
			public:
			GradeTooHighException();
		};

		class GradeTooLowException : public std::logic_error
		{
			public:
			GradeTooLowException();
		};


};

//Operator Overloads
std::ostream& operator<<(std::ostream& cout, const Bureaucrat& bureaucrat);
