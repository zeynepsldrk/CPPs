#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit): _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _totalAmount += initial_deposit;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << " index:" <<_accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
    if (_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
    else
    {
        std::cout << ";amount:" << _amount << ";withdrawal:" << withdrawal << ";denied" << std::endl;
        return false;
    }
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits 
        << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{
    std::time_t now;
    std::tm *info;
    char buff[20];

    std::time(&now);
    info = std::localtime(&now);
    std::strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S]", info);
    std::cout << buff;
}