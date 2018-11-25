#pragma once
#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"

class BalanceInquiry : public Transaction
{
	int accountNumber;

public:
	BalanceInquiry(int userAccountNumer, Screen*atmScreen, BankDatabase*atmBankDatabase);

	void execute();
	
};