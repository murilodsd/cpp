#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//CONSTRUCTOR
Account::Account(int initial_deposit)
:
_accountIndex(Account::_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
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
	return (_amount);
}

//SETTERS

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";

	this->_amount+= deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

//DISPLAY INFOS
void	Account::displayStatus(void)const
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t _time = time(nullptr);
	tm* local_time = localtime(&_time);
	std::cout << "[" 
		<< (1900 + local_time->tm_year)
		<< std::setfill('0') << std::setw(2) << (1 + local_time->tm_mon)
		<< std::setfill('0') << std::setw(2) << local_time->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << local_time->tm_hour
		<< std::setfill('0') << std::setw(2) << local_time->tm_min
		<< std::setfill('0') << std::setw(2) << local_time->tm_sec << "]";
}
