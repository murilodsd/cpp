#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ==================== Constructors ====================
Bureaucrat::Bureaucrat()
:
_name("Default"),
_grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
:
_name(name),
_grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// ================= Copy Constructor ==================
Bureaucrat::Bureaucrat(const Bureaucrat &other)
:
_name(other._name),
_grade(other._grade)
{
}

// ========== Copy Assignment Operator Overload ==========
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

// ==================== Destructor =====================
Bureaucrat::~Bureaucrat()
{
}
// ================= Auxiliar Functions =================
std::ostream& operator<<(std::ostream& cout, const Bureaucrat& bureaucrat)
{
	cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '\n';
	return (cout);
}

// ================= Class Exceptions =================
Bureaucrat::GradeTooHighException::GradeTooHighException() 
:
std::runtime_error("Grade too high for bureaucrat")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException() 
:
std::runtime_error("Grade too low for bureaucrat")
{
}

// ================== Member Functions ==================
const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
	try {
		form.beSigned(*this);
		std::cout << GREEN << _name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception caught: Bureaucrat " << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: Bureaucrat " << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

