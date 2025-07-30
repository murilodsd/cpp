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

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeRequiredToSign;
		const int		_gradeRequiredToExecute;

	protected:
		void checkExecutionRequirements(const Bureaucrat& executor) const;
	
	public:
		// Default constructor
		AForm();
		AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);


		// Copy constructor
		AForm(const AForm &other);

		// Copy assignment operator overload
		AForm &operator=(const AForm &other);

		// Destructor
		virtual ~AForm();

		//Others Methods
		const std::string	&getName() const;
		bool			getIsSigned() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredToExecute() const;
		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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

		class AFormIsAlreadySignedException : public std::logic_error
		{
			public:
				AFormIsAlreadySignedException();
		};
		
		class AFormNotSignedException : public std::logic_error
		{
			public:
				AFormNotSignedException();
		};
};

std::ostream&	operator<<(std::ostream &cout, const AForm& Aform);


//Exceptions
class FileOpenException : public std::runtime_error {
	public:
		FileOpenException(const std::string &filename);
};

class FileAlreadyExistsException : public std::runtime_error {
	public:
		FileAlreadyExistsException(const std::string &filename);
};
