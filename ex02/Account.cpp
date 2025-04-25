#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//CONSTRUCTOR
Account::Account(int initial_deposit)
:
_amount(initial_deposit)
{
	_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{

}


//GETTERS
//A palavra-chave static é usada apenas na declaração da função, dentro da definição da classe (geralmente no arquivo .h).
//você não deve repetir a palavra-chave static na definição (implementação) da função membro estática quando a escreve fora da classe (geralmente no arquivo .cpp).

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
int		Account::checkAmount(void)const
{
	return (this->_amount);
}

//SETTERS

void	Account::makeDeposit(int deposit)
{
	this->_amount+= deposit;
	this->_nbDeposits++;
	_totalAmount =+ deposit;
	_totalNbDeposits++;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	if (_totalAmount < withdrawal)
	{
		std::cout << "Doesn't have funds." << std::endl;
		return (false);
	}
	else 
	{
		this->_amount =- withdrawal;
		this->_nbWithdrawals += withdrawal;
		_totalAmount =- withdrawal;
		_totalNbWithdrawals++;
	}
	return (true);
}
void	Account::displayStatus(void)const
{

}

void	Account::_displayTimestamp( void )
{
	time_t result = ::time(nullptr);
	tm* local_time = ::localtime(&result);
	std::cout << "[" 
			  << (1900 + local_time->tm_year)
			  << (1 + local_time->tm_mon)
			  << local_time->tm_mday << "_"
			  << local_time->tm_hour
			  << local_time->tm_min
			  << local_time->tm_sec << "]";
}