#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// ==================== Constructors ====================
PresidentialPardonForm::PresidentialPardonForm()
:
AForm("Presidential Pardon", 25, 5),
_target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
:
AForm("Presidential Pardon", 25, 5),
_target(target)
{
}

// ================= Copy Constructor ==================
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
:
AForm(other),
_target(other._target)
{
}

// ========== Copy Assignment Operator Overload ==========
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// ==================== Destructor =====================
PresidentialPardonForm::~PresidentialPardonForm()
{
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecutionRequirements(executor);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
