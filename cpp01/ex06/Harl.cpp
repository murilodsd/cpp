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

// ================= Auxiliar Functions ================

void	print_msg(const std::string& str, const std::string& color = WHITE)
{
	std::cout << color << str << std::endl << RESET;
}

void	toUpperCase(std::string &str)
	{
		size_t i = 0;

		while (i < str.length())
		{
			str[i] = std::toupper(str[i]);
			i++;
		}
	};

// ================== Member Functions =================

void Harl::debug( void )
{
	print_msg("[ DEBUG ]", CYAN);
	print_msg("I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n");
}
void Harl::info( void )
{
	print_msg("[ INFO ]", CYAN);
	print_msg("I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n");
}
void Harl::warning( void )
{
	print_msg("[ WARNING ]", CYAN);
	print_msg("I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n");
}
void Harl::error( void )
{
	print_msg("[ ERROR ]", CYAN);
	print_msg("This is unacceptable! I want to speak to the manager now.\n");
}

void Harl::complain( std::string level )
{
	int i = 0;
	while(i < 4)
	{
		if (this->array_complain[i].level == level)
			break ;
		i++;
	}

	switch (i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			print_msg("[ Probably complaining about insignificant problems ]", BLUE);
			break;
	}
}
