#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
    this->_accountIndex = this->_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    this->_totalAmount += this->_amount;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << checkAmount() << ";"
              << "created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << checkAmount() << ";"
              << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    int p_amount = checkAmount();

    this->_amount += deposit;
    _totalAmount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << p_amount << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << checkAmount() << ";"
              << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    int p_amount = checkAmount();
    bool bRefusedFlag = false;

    if (this->_amount - withdrawal >= 0) {
        this->_amount -= withdrawal;
        _totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        _totalNbWithdrawals++;
    } else {
        bRefusedFlag = true;
    }

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << p_amount << ";"
              << "withdrawal:";
    if (bRefusedFlag) {
        std::cout << "refused" << std::endl;
        return false;
    }
    std::cout << withdrawal << ";"
              << "amount:" << checkAmount() << ";"
              << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const {
    return this->_amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << checkAmount() << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
    char timeStamp[20];
    std::time_t now = std::time(nullptr);

    std::strftime(timeStamp, sizeof(timeStamp), "%Y%m%d_%H%M%S", std::localtime(&now));
    std::cout << "[" << timeStamp << "] ";
}

Account::Account(void) {}

