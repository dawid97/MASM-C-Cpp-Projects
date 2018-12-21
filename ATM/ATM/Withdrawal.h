#pragma once
#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "Safe.h"
#include<Windows.h>


class Withdrawal :public Transaction
{
	int amount;
	Keypad*keypad;
	Safe*safe;

	int displayMenuOfAmounts();

public:
	Withdrawal(int userAccountNumber, Screen*atmScreen, BankDatabase*atmBankDatabase, Keypad*atmKeypad,Safe*atmSafe);
	void execute();
};
