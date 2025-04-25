// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	//CONST
	//promete não modificar o estado observável do objeto no qual ela é chamada.
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:
	//STATIC
	//Significa que existe apenas uma única cópia dessa variável para toda a classe
	//Você não pode atribuir novos valores a membros de dados não-estáticos (ex: this->_amount = 0; seria um erro de compilação).
	//Você não pode chamar outras funções membro não-const no mesmo objeto (this), porque essas outras funções poderiam potencialmente modificar o objeto. Você só pode chamar outras funções membro que também sejam const.
	//Você pode modificar variáveis membro declaradas como mutable, que são uma exceção a essa regra, mas devem ser usadas com cuidado.
	//Você pode modificar variáveis membro static, pois elas pertencem à classe, não ao objeto individual.
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
