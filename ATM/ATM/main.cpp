#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

#include "Screen.h"
#include "Account.h"
#include "Keypad.h"
#include "DepositSlot.h"
#include "BankDatabase.h"
#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "ATM.h"



int main()
{
	ATM atm;
	atm.run();

	_getch();
	return 0;
}