#include "Deposit.h"

Deposit::Deposit(int userAccountNumber, Screen*atmScreen, BankDatabase*atmBankDatabase, Keypad*atmKeypad, DepositSlot*atmDepositSlot):Transaction(userAccountNumber, atmScreen, atmBankDatabase)
{
	keypad = atmKeypad;
	depositSlot = atmDepositSlot;
}

void Deposit::execute()
{
	amount = promptForDepositAmount();

	if (amount != 0)
	{
		screen->displayMessage("\nPlease insert a deposit envelope cantaining");
		screen->displayDollarAmount(amount);
		screen->displayMessageLine(".");

		bool envelopeReceived = depositSlot->isEnvelopeReceived();

		if (envelopeReceived)
		{
			screen->displayMessageLine("\nYour envelope has been received.\nNOTE: The money just deposited will not be available intil we verify the amount of any enclosed cash and your checks clear.");

			bankDatabase->credit(getAccountNumber(), amount);
			bankDatabase->saveToFile();
		}
		else
		{
			screen->displayMessageLine("\nYou did not insert an envelope, so the ATM has canceled your transaction.");
		}
	}
	else
	{
		screen->displayMessageLine("\nCanceling transaction...");
	}
}


double Deposit::promptForDepositAmount()
{
	screen->displayMessage("\nPlease enter a deposit amount in CENTS (or 0 to cancel): ");
	int input = keypad->getInput();

	if (input == 0)
		return 0;
	else
	{
		return(double)input / 100;
	}
}
