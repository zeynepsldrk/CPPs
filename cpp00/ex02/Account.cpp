#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit ){
    _amount = initial_deposit;
    _nbAccounts++;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	
}

int	Account::getTotalAmount( void )
{
	
}

int	Account::getNbDeposits( void )
{

}

int	Account::getNbWithdrawals( void )
{

}

void	Account::displayAccountsInfos( void )
{

}
