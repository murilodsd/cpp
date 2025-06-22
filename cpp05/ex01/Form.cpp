#include "Form.hpp"
#include "Bureaucrat.hpp"

// ==================== Constructors ====================
Form::Form()
:
_name("Default"),
_isSigned(false),
_gradeRequiredToSign(150),
_gradeRequiredToExecute(150)
{
	if (_gradeRequiredToExecute > 150 || _gradeRequiredToSign > 150)
		throw Form::GradeTooLowException();
	if (_gradeRequiredToExecute < 1 || _gradeRequiredToSign < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
:
_name(name),
_isSigned(false),
_gradeRequiredToSign(gradeRequiredToSign),
_gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (_gradeRequiredToExecute > 150 || _gradeRequiredToSign > 150)
		throw Form::GradeTooLowException();
	if (_gradeRequiredToExecute < 1 || _gradeRequiredToSign < 1)
		throw Form::GradeTooHighException();
}



// ================= Copy Constructor ==================
Form::Form(const Form &other)
:
_name(other._name),
_isSigned(other._isSigned),
_gradeRequiredToSign(other._gradeRequiredToSign),
_gradeRequiredToExecute(other._gradeRequiredToExecute)
{
}

// ========== Copy Assignment Operator Overload ==========
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

// ==================== Destructor =====================
Form::~Form()
{
}
// ================= Auxiliar Functions =================
std::ostream&	operator<<(std::ostream &out, const Form& form)
{
	out << "Form: " << form.getName() 
		 << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		 << ", Grade required to sign: " << form.getGradeRequiredToSign()
		 << ", Grade required to execute: " << form.getGradeRequiredToExecute() << '\n';
	return (out);
}

// ================== Member Functions ==================
const std::string&	Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_gradeRequiredToSign < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	if (_isSigned == true)
		throw Form::FormIsAlreadySignedException();
	_isSigned = true;
}

Form::GradeTooLowException::GradeTooLowException() 
: std::runtime_error("Form grade is too low")
{
}

Form::GradeTooHighException::GradeTooHighException() 
: std::runtime_error("Form grade is too high")
{
}

Form::FormIsAlreadySignedException::FormIsAlreadySignedException()
: std::runtime_error("Form is already signed")
{
}