#include "ATM.h"

ATM::ATM()
{
	userAuthenticated = false;
	currentAccountNumber = 0;
}

void ATM::run()
{
	//cout << &bankDatabase << endl;
	//bankDatabase.displayAccounts();
	while (true)
	{
		while (!userAuthenticated)
		{
			screen.displayMessageLine("\nWelcome!");
			authenticateUser();
		}

		performTransactions();
		userAuthenticated = false;
		currentAccountNumber = 0;
		screen.displayMessageLine("\nThank you! Goodbye");
	}
}

void ATM::authenticateUser()
{
	
	int accountNumber = cardReader.getAccountNumber();
	screen.displayMessage("\nEnter your PIN: ");
	int pin = keypad.getInput();

	if (cardReader.validatePIN(pin))
	{
		userAuthenticated = bankDatabase.authenticateUser(accountNumber);
	}

	if (userAuthenticated)
	{
		currentAccountNumber = accountNumber;
	}
	else
		screen.displayMessageLine("Invalid PIN or The card is not from this bank. Please try again.");
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
			currentTransaction = new BalanceInquiry(currentAccountNumber, &screen, &bankDatabase);
			currentTransaction->execute();
			delete currentTransaction;
			break;
		}
		case WITHDRAWAL:
		{

			currentTransaction = new Withdrawal(currentAccountNumber, &screen, &bankDatabase, &keypad,&safe);
			currentTransaction->execute();
			delete currentTransaction;
			break;
		}
		case DEPOSIT:
		{
			currentTransaction = new Deposit(currentAccountNumber, &screen, &bankDatabase, &keypad, &depositSlot);
			currentTransaction->execute();
			delete currentTransaction;
			break;
		}
		case EXIT:
		{
			screen.displayMessageLine("\nExiting the system...");
			userExited = true;
			break;
		}
		default:
		{
			screen.displayMessageLine("\nYou did not enter a valid selection. Try again.");
			break;
		}
		}
	}
}

