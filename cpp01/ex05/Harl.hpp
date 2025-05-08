#pragma once
#include <string>

class Harl;

typedef void(Harl::*t_ptrFunc)(void);

typedef struct s_complain
{
	std::string level;
	t_ptrFunc ptrFunc;
} t_complain;

class Harl
{
	private:
		t_complain array_complain[4];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl();
		~Harl();
		void complain( std::string level );
};



