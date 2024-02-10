#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* constructor */
Account::Account(int initial_deposit) {
  _nbAccounts++;
  _totalAmount += initial_deposit;
  this->_accountIndex = _nbAccounts - 1;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  this->_amount = initial_deposit;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "created" << std::endl;
}

/* destructor */
Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t result;
  std::time(&result);

  struct tm *time = localtime(&result);
  std::cout << "[" << std::setw(2) << std::setfill('0') << time->tm_year
            << std::setw(2) << std::setfill('0') << time->tm_mon - 1
            << std::setw(2) << std::setfill('0') << time->tm_mday
            << std::setw(2) << std::setfill('0') << time->tm_hour
            << std::setw(2) << std::setfill('0') << time->tm_min << std::setw(2)
            << std::setfill('0') << time->tm_sec << "] ";
}

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";"
            << "total:" << _totalAmount << ";"
            << "deposits:" << _totalNbDeposits << ";"
            << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

/* getter */
int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "deposits:" << this->_nbDeposits << ";"
            << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  int prev_amount = this->_amount;
  _totalNbDeposits++;
  _totalAmount += deposit;
  this->_nbDeposits++;
  this->_amount += deposit;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "p_amount:" << prev_amount << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << this->_amount << ";"
            << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  int prev_amount = this->_amount;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "p_amount:" << prev_amount << ";";
  if (withdrawal > this->_amount) {
    std::cout << "withdrawal:refused" << std::endl;
    return false;
  } else {
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "withdrawal:" << withdrawal << ";"
              << "amount:" << this->_amount << ";"
              << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
  }
}
