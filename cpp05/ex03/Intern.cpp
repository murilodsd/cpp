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

t_form_create_function AForm::form_create_functions[3] = {
    {"shrubbery creation", &Intern::createShrubbery},
    {"robotomy request", &Intern::createRobotomy}, 
    {"presidential pardon", &Intern::createPresidential}
};


// ================== Member Functions ==================
AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	for (int i = 0; i < 3; i++)
	{
		if (AForm::form_create_functions[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return AForm::form_create_functions[i].execute_function(target);
		}
	}
	std::cerr << "Intern: form \"" << name << "\" does not exist" << std::endl;
	return NULL;
}