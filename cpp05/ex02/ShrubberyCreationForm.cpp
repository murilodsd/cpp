#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

// ==================== Constructors ====================
ShrubberyCreationForm::ShrubberyCreationForm()
:
AForm("Shrubbery Creation", 145, 137),
_target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:
AForm("Shrubbery Creation", 145, 137),
_target(target)
{
}

// ================= Copy Constructor ==================
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
:
AForm(other),
_target(other._target)
{
}

// ========== Copy Assignment Operator Overload ==========
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// ==================== Destructor =====================
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecutionRequirements(executor);

	std::string filename = _target + "_shrubbery";
	
	std::ifstream infile(filename.c_str());
	if (infile.is_open())
	{
		infile.close();
		throw FileAlreadyExistsException(filename);
	}
	
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open())
		throw FileOpenException(filename);

	outfile << "      #o###" << '\n';
	outfile << "    #####o###" << '\n';
	outfile << "   #o#\\#|#/###" << '\n';
	outfile << "    ###\\|/#o#" << '\n';
	outfile << "     # }|{  #" << '\n';
	outfile << "       }|{" << '\n';

	outfile.close();
}
