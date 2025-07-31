#pragma once
#include <iostream>
#include <string>


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

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeRequiredToSign;
		const int		_gradeRequiredToExecute;

	public:
		// Default constructor
		Form();
		Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);


		// Copy constructor
		Form(const Form &other);

		// Copy assignment operator overload
		Form &operator=(const Form &other);

		// Destructor
		~Form();

		//Others Methods
		const std::string	&getName() const;
		bool			getIsSigned() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredToExecute() const;
		void			beSigned(const Bureaucrat& bureaucrat);

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

		class FormIsAlreadySignedException : public std::logic_error
		{
			public:
			FormIsAlreadySignedException();
		};
};

std::ostream&	operator<<(std::ostream &cout, const Form& form);