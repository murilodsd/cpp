#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ==================== Constructors ====================
Intern::Intern()
{
}

// ================= Copy Constructor ==================
Intern::Intern(const Intern &other)
{
	(void)other;
}

// ========== Copy Assignment Operator Overload ==========
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

// ==================== Destructor =====================
Intern::~Intern()
{
}
// ================= Auxiliar Functions =================
AForm* Intern::createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}
AForm* Intern::createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}
AForm* Intern::createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

// ================== Member Functions ==================
AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	const std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*formCreators[])(const std::string&) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	std::cerr << "Intern: form \"" << name << "\" does not exist" << std::endl;
	return NULL;
}