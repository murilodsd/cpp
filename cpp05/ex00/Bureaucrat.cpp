#include "Bureaucrat.hpp"

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
	cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (cout);
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
