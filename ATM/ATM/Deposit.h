#pragma once
#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include<Windows.h>


class Deposit :public Transaction
{
	double amount;
	Keypad*keypad;
	
public:
	Deposit(int userAccountNumber, Screen*atmScreen, BankDatabase*atmBankDatabase, Keypad*atmKeypad);
	void execute();
};