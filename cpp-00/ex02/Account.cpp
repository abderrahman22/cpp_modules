/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:49:16 by abchaman          #+#    #+#             */
/*   Updated: 2025/11/25 18:03:41 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

// int	getNbAccounts( void );
// int	getTotalAmount( void );
// int	getNbDeposits( void );
// int	getNbWithdrawals( void );
// void	displayAccountsInfos( void );
// Account( int initial_deposit );
// ~Account( void );
// void	makeDeposit( int deposit );
// bool	makeWithdrawal( int withdrawal );
// int		checkAmount( void ) const;
// void	displayStatus( void ) const;
// void	_displayTimestamp( void );


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	std::cout << "[19920104_091532]";
}
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
}

Account::~Account()
{
	_displayTimestamp();
	_nbAccounts--;
	_totalAmount-= _amount;
}
int Account::getNbAccounts(){return _nbAccounts;}
int Account::getTotalAmount(){return _totalAmount;}
int Account::getNbDeposits(){return _totalNbDeposits;}
int Account::getNbWithdrawals(){return _totalNbWithdrawals;}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts" << _nbAccounts << ";"
		<< "total" << _totalAmount << ";"
		<< "deposits" << _totalNbDeposits << ";"
		<< "withdrawals" << _totalNbWithdrawals
		<< std::endl;
}

int		Account::checkAmount() const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
		std::cout << "index" << _accountIndex << ";"
		<< "amount" << _amount << ";"
		<< "deposits" << _nbDeposits << ";"
		<< "withdrawals" << _nbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit( int deposit)
{
	_displayTimestamp();
	std::cout << "index" << _accountIndex << ";"
		<< "p_amount" << _amount << ";"
		<< "deposit" << deposit << ";"
		<< "amount" << _amount + deposit << ";"
		<< "nb_Deposits" << _nbDeposits <<
		std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
	{
		displayAccountsInfos();
		std::cout << "index" << _accountIndex << ";"
			<< "p_amount" << _amount << ";"
			<< "withdrawal:refused" << std::endl;
		return false;
	}
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount - withdrawal << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	return true;
}
