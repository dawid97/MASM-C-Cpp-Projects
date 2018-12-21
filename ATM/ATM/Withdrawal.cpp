#include "Withdrawal.h"

Withdrawal::Withdrawal(int userAccountNumber, Screen*atmScreen, BankDatabase*atmBankDatabase, Keypad*atmKeypad,Safe*atmSafe):Transaction(userAccountNumber, atmScreen, atmBankDatabase)
{
	safe = atmSafe;
	keypad = atmKeypad;
}

void Withdrawal::execute()
{
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
						safe->isAlarm();
						cashDispensed = true;
						screen->displayMessageLine("\nGotowka zostala wyplacona. Prosze zabrac gotowke.");
						Sleep(3000);
						system("cls");
				}
				else
				{
					screen->displayMessageLine("\nBrak dostepnej gotowki w bankomacie");
					Sleep(3000);
					system("cls");
				}
			
			}
			else
			{
				screen->displayMessageLine("\nBrak wystarczajacej ilosci gotowki na koncie.\n\nProsze wybrac mniejsza kwote.");
				Sleep(3000);
				system("cls");
			}

		}
		else
		{
			screen->displayMessageLine("\nKonczenie transakcji...");
			Sleep(3000);
			system("cls");
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
			system("cls");
			userChoice = amounts[input];
			break;
		case 8:
			system("cls");
			userChoice = 8;
			break;
		default:
		{
			screen->displayMessageLine("\nBledny wybor. Prosze sprobowac ponownie");
			Sleep(3000);
			system("cls");
		}
		}
	}
	return userChoice;
}