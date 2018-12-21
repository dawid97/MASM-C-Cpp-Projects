#include "Deposit.h"

Deposit::Deposit(int userAccountNumber, Screen*atmScreen, BankDatabase*atmBankDatabase, Keypad*atmKeypad):Transaction(userAccountNumber, atmScreen, atmBankDatabase)
{
	keypad = atmKeypad;
}

void Deposit::execute()
{
	screen->displayMessage("\nProsze wpisac kwote lub 0 aby zakonczyc: ");
	amount = keypad->getInput();
	system("cls");

	if (amount != 0)
	{
		screen->displayMessage("Wplacona gotowka:");
		screen->displayZlAmount(amount);
		Sleep(3000);
		system("cls");
		bankDatabase->credit(getAccountNumber(), amount);
	}
	else
	{
		screen->displayMessageLine("\nKonczenie transakcji...");
		Sleep(3000);
		system("cls");
	}
}
