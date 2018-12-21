#include "ATM.h"

ATM::ATM()
{
	userAuthenticated = false;
	currentAccountNumber = 0;
}

void ATM::run()
{
	while (true)
	{
		while (!userAuthenticated)
		{
			screen.displayMessageLine("\nWitamy!");
			authenticateUser();
		}

		performTransactions();
		userAuthenticated = false;
		currentAccountNumber = 0;
		screen.displayMessageLine("\nDziekujemy! Do zobaczenia");
		Sleep(3000);
		system("cls");
	}
}

void ATM::authenticateUser()
{
	int accountNumber = cardReader.getAccountNumber();
	screen.displayMessage("\nWprowadz twoj PIN: ");
	int pin = keypad.getInput();
	system("cls");

	if (cardReader.validatePIN(pin))
	{
		userAuthenticated = bankDatabase.authenticateUser(accountNumber);

		if (!userAuthenticated)
		{
			screen.displayMessageLine("Karta nie jest z tego banku");
			Sleep(3000);
			system("cls");
		}
		else
		{
			currentAccountNumber = accountNumber;
			system("cls");
		}
	}
	else
	{
		screen.displayMessageLine("Bledny PIN");
		Sleep(3000);
		system("cls");
	}
}

void ATM::performTransactions()
{
	bool userExited = false;

	Transaction*currentTransaction = nullptr;

	while (!userExited)
	{
		screen.displayMainMenu();
		int choice = keypad.getInput();
		

		switch (choice)
		{
		case BALANCE_INQUIRY:
		{
			system("cls");
			currentTransaction = new BalanceInquiry(currentAccountNumber, &screen, &bankDatabase);
			currentTransaction->execute();
			delete currentTransaction;
			currentTransaction = nullptr;
			break;
		}
		case WITHDRAWAL:
		{
			system("cls");
			currentTransaction = new Withdrawal(currentAccountNumber, &screen, &bankDatabase, &keypad,&safe);
			currentTransaction->execute();
			delete currentTransaction;
			currentTransaction = nullptr;
			break;
		}
		case DEPOSIT:
		{
			system("cls");
			currentTransaction = new Deposit(currentAccountNumber, &screen, &bankDatabase, &keypad);
			currentTransaction->execute();
			delete currentTransaction;
			currentTransaction = nullptr;
			break;
		}
		case EXIT:
		{
			screen.displayMessageLine("\nZamykanie systemu...");
			Sleep(3000);
			system("cls");
			userExited = true;
			break;
		}
		default:
		{
			screen.displayMessageLine("\nDokonano blednego wyboru. Prosze sprobowac ponownie");
			Sleep(3000);
			system("cls");
			break;
		}
		}
	}
}

