#pragma once
#include "BankDatabase.h"

struct Card
{
	int accountNumber;
	int pin;
};

class CardReader
{
	Card card;

public:
	CardReader();
	int getAccountNumber();
	bool validatePIN(int userPIN);
};
