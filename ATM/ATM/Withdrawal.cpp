#include "Withdrawal.h"

Withdrawal::Withdrawal(int userAccountNumber, Screen*atmScreen, BankDatabase*atmBankDatabase, Keypad*atmKeypad,Safe*atmSafe):Transaction(userAccountNumber, atmScreen, atmBankDatabase)
{
	safe = atmSafe;
	keypad = atmKeypad;
}

void Withdrawal::execute()
{
	cout << bankDatabase << endl;
	bool cashDispensed = false;
	double availableBalance = 0;

	do
	{
		amount = displayMenuOfAmounts();

		if (amount != 8)
		{
			availableBalance = bankDatabase->getAvailableBalance(getAccountNumber());


			if (amount <= availableBalance)
			{
				if (safe->reduceSafe(amount))
				{
						bankDatabase->debit(getAccountNumber(), amount);
						bankDatabase->saveToFile();
						safe->czyalarm();
						cashDispensed = true;
						screen->displayMessageLine("\nYour cash has been dispensed. Please take your cash now.");
				}
				else
					screen->displayMessageLine("\nInsufficient cash available in the ATM");
			
			}
			else
				screen->displayMessageLine("\nInsufficient funds in your account.\n\nPlease choose a smaller amount.");
		}
		else
		{
			screen->displayMessageLine("\nCanceling transaction...");
			return;
		}
	} while (!cashDispensed);
}

int Withdrawal::displayMenuOfAmounts()
{
	int userChoice = 0;

	int amounts[] = { 0,20,50,100,200,500,1000,2000 };

	while (userChoice == 0)
	{
		screen->displayWithdrawalMenu();

		int input = keypad->getInput();

		switch (input)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			userChoice = amounts[input];
			break;
		case 8:
			userChoice = 8;
			break;
		default:
			screen->displayMessageLine("\nInvalid selection. Try again");
		}
	}
	return userChoice;
}