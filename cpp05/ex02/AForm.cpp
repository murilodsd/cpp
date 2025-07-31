#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ==================== Constructors ====================
AForm::AForm()
:
_name("Default"),
_isSigned(false),
_gradeRequiredToSign(150),
_gradeRequiredToExecute(150)
{
	if (_gradeRequiredToExecute > 150 || _gradeRequiredToSign > 150)
		throw AForm::GradeTooLowException();
	if (_gradeRequiredToExecute < 1 || _gradeRequiredToSign < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
:
_name(name),
_isSigned(false),
_gradeRequiredToSign(gradeRequiredToSign),
_gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (_gradeRequiredToExecute > 150 || _gradeRequiredToSign > 150)
		throw AForm::GradeTooLowException();
	if (_gradeRequiredToExecute < 1 || _gradeRequiredToSign < 1)
		throw AForm::GradeTooHighException();
}



// ================= Copy Constructor ==================
AForm::AForm(const AForm &other)
:
_name(other._name),
_isSigned(other._isSigned),
_gradeRequiredToSign(other._gradeRequiredToSign),
_gradeRequiredToExecute(other._gradeRequiredToExecute)
{
}

// ========== Copy Assignment Operator Overload ==========
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

// ==================== Destructor =====================
AForm::~AForm()
{
}
// ================= Auxiliar Functions =================
std::ostream&	operator<<(std::ostream &out, const AForm& Aform)
{
	out << "AForm: " << Aform.getName() 
		 << ", Signed: " << (Aform.getIsSigned() ? "Yes" : "No")
		 << ", Grade required to sign: " << Aform.getGradeRequiredToSign()
		 << ", Grade required to execute: " << Aform.getGradeRequiredToExecute();
	return (out);
}

// ================== Member Functions ==================
const std::string&	AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_gradeRequiredToSign < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	if (_isSigned == true)
		throw AForm::AFormIsAlreadySignedException();
	_isSigned = true;
}

void AForm::checkExecutionRequirements(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw AFormNotSignedException();
	if (this->getGradeRequiredToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
}

// ================== Class Exceptions ==================

AForm::GradeTooLowException::GradeTooLowException() 
: std::logic_error("The grade is too low")
{
}

AForm::GradeTooHighException::GradeTooHighException() 
: std::logic_error("The grade is too high")
{
}

AForm::AFormIsAlreadySignedException::AFormIsAlreadySignedException()
: std::logic_error("Form is already signed")
{
}

AForm::AFormNotSignedException::AFormNotSignedException()
: std::logic_error("Form is not signed")
{
}

// ================== General Exceptions ==================

FileOpenException::FileOpenException(const std::string& filename)
:
std::logic_error("Could not open file " + filename)
{
}

FileAlreadyExistsException::FileAlreadyExistsException(const std::string& filename)
:
std::logic_error("File " + filename + " already exists")
{
}