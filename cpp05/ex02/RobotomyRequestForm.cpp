#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// ==================== Constructors ====================
RobotomyRequestForm::RobotomyRequestForm()
:
AForm("Robotomy Request", 72, 45),
_target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
:
AForm("Robotomy Request", 72, 45),
_target(target)
{
}

// ================= Copy Constructor ==================
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
:
AForm(other),
_target(other._target)
{
}

// ========== Copy Assignment Operator Overload ==========
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// ==================== Destructor =====================
RobotomyRequestForm::~RobotomyRequestForm()
{
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecutionRequirements(executor);

	std::cout << "VRRRRRRRRRR...." << std::endl;

	static bool seeded = false;
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}

	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << _target << " robotomization failed!" << std::endl;
}
