#pragma once
#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"
#include<Windows.h>

class BalanceInquiry : public Transaction
{

public:
	BalanceInquiry(int userAccountNumer, Screen*atmScreen, BankDatabase*atmBankDatabase);
	void execute();
};