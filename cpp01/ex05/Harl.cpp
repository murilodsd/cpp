#include <iostream>
#include <string>
#include "Harl.hpp"

// ==================== Constructor ====================
Harl::Harl()
{
	this->array_complain[0].level = "DEBUG";
	this->array_complain[0].ptrFunc = &Harl::debug;

	this->array_complain[1].level = "INFO";
	this->array_complain[1].ptrFunc = &Harl::info;

	this->array_complain[2].level = "WARNING";
	this->array_complain[2].ptrFunc = &Harl::warning;

	this->array_complain[3].level = "ERROR";
	this->array_complain[3].ptrFunc = &Harl::error;
}

// ==================== Destructor =====================
Harl::~Harl()
{
}

// ================== Member Functions =================

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.\
\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.\
\nI’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	for(int i = 0; i < 4; i++)
	{
		if (this->array_complain[i].level == level)
			(this->*(array_complain[i].ptrFunc))();
	}	
}