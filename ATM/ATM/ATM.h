#pragma once

#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "Screen.h"
#include "Keypad.h"
#include "BankDatabase.h"
#include "Deposit.h"
#include "CardReader.h"
#include "Safe.h"
#include<Windows.h>

class ATM
{
	bool userAuthenticated;
	int currentAccountNumber;
	Screen screen;
	Keypad keypad;
	BankDatabase bankDatabase;
	CardReader cardReader;
	Safe safe;

	enum { BALANCE_INQUIRY = 1, WITHDRAWAL = 2, DEPOSIT = 3, EXIT = 4};

	void authenticateUser();
	void performTransactions();

public:
	ATM();
	void run();
};