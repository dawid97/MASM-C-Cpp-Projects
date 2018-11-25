#pragma once
#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"

class Deposit :public Transaction
{
	double amount;
	Keypad*keypad;
	DepositSlot*depositSlot;

	double promptForDepositAmount();

public:
	Deposit(int userAccountNumber, Screen*atmScreen, BankDatabase*atmBankDatabase, Keypad*atmKeypad, DepositSlot*atmDepositSlot);
	void execute();
};