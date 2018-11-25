#include "Transaction.h"

Transaction::Transaction(int userAccountNumber, Screen*atmScreen, BankDatabase*atmBankDatabase)
{
	accountNumber = userAccountNumber;
	screen = atmScreen;
	bankDatabase =atmBankDatabase;
}

int Transaction::getAccountNumber()
{
	return accountNumber;
}




