#pragma once
#include "BankDatabase.h"
#include "Screen.h"


class Transaction
{
protected:
	int accountNumber;
	Screen*screen;
	BankDatabase*bankDatabase;

public:
	Transaction(int userAccountNumber, Screen*atmScreen, BankDatabase*atmBankDatabase);

	int getAccountNumber();

	virtual void execute() = 0;
};