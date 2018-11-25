#pragma once

#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "Screen.h"
#include "Keypad.h"
#include "DepositSlot.h"
#include "BankDatabase.h"
#include "Deposit.h"
#include "CardReader.h"
#include "Safe.h"

class ATM
{
	bool userAuthenticated;
	int currentAccountNumber;
	Screen screen;
	Keypad keypad;
	DepositSlot depositSlot;
	BankDatabase bankDatabase;
	CardReader cardReader;
	Safe safe;


	enum { BALANCE_INQUIRY = 1, WITHDRAWAL = 2, DEPOSIT = 3, EXIT = 4};
public:
	ATM();

	void run();

private:
	void authenticateUser();
	void performTransactions();
};