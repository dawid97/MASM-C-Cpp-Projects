#pragma once
#include "BankDatabase.h"

class CardReader
{
	int accountNumber;
	int pin;
public:
	CardReader();
	int getAccountNumber();
	bool validatePIN(int userPIN);
};
