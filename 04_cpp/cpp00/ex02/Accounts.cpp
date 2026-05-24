#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <algorithm>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor for starting an account
Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

// deconstructor
Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << _amount << ";closed" << std::endl;

    _nbAccounts--;
}

// display time stamp
// size_t strftime(char* str, size_t count, const char* format, const struct tm* time);
void	Account::_displayTimestamp( void )
{
    time_t  timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);

    char output[50];
    strftime(output, 50, "%Y%m%d_%H%M%S", &datetime);
    std::cout << "[" << output << "] ";
}

// Account infos
void    Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
    << ";total:" << _totalAmount << 
    ";deposits:" << _totalNbDeposits 
    << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// display indiv acc status
void    Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
    << ";amount:" << _amount 
    << ";deposits:" << _nbDeposits 
    << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// make deposit
void    Account::makeDeposit( int deposit )
{
    int new_amount = _amount + deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";p_amount:" << _amount
    << ";deposit:" << deposit
    << ";amount:" << new_amount
    << ";nb_deposits:" << _nbDeposits + 1 << std::endl;

    _totalAmount += deposit;
    _amount = new_amount;
    _totalNbDeposits += 1;
    _nbDeposits += 1;
}

// withdrawal
bool    Account::makeWithdrawal( int withdrawal )
{
    int new_amount = _amount - withdrawal;

    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:" << withdrawal
        << ";amount:" << new_amount
        << ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
        _totalAmount -= withdrawal;
        _amount = new_amount;
        _totalNbWithdrawals += 1;
        _nbWithdrawals += 1;
        return (true);
    }
}
