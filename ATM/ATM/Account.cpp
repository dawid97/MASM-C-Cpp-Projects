#include "Account.h"

Account::Account(int theAccountNumber, double theAvailableBalance, double theTotalBalane)
{
	accountNumber = theAccountNumber;
	availableBalance = theAvailableBalance;
	totalBalance = theTotalBalane;
}


double Account::getAvailableBalance()
{
	return availableBalance;
}

double Account::getTotalBalance()
{
	return totalBalance;
}

void Account::credit(double amount)
{
	totalBalance += amount;
}

void Account::debit(double amount)
{
	availableBalance -= amount;
	totalBalance -= amount;
}

int Account::getAccountNumber()
{
	return accountNumber;
}



