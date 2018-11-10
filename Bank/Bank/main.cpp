#include<iostream>
#include<string>

using namespace std;

class ATM
{
	bool userAuthenticated;
	int currentAccountNumber;
	Screen screen;
	Keypad keypad;
	CashDispenser cashDispenser;
	DepositSlot depositSlot;
	BankDatabase bankDatabase;

	enum { BALANCE_INQUIRY, WITHDRAWAL, DEPOSIT, EXIT};

public:
	ATM()
	{
		userAuthenticated = false;
		currentAccountNumber = 0;
	}

	void run()
	{
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

private:
	void authenticateUser()
	{
		screen.displayMessage("\nPlease enter your account number: ");
		int accountNumber = keypad.getInput();
		screen.displayMessage("\nEnter your PIN: ");
		int pin = keypad.getInput();

		userAuthenticated = bankDatabase.authenticateUser(accountNumber, pin);

		if (userAuthenticated)
		{
			currentAccountNumber = accountNumber;
		}
		else
			screen.displayMessageLine("Invalid account number or PIN. Please try again.");
	}

	void performTransactions()
	{
		Transaction currentTransaction = null;

		bool userExited = false;

		while (!userExited)
		{
			int mainMenuSelection = displayMainMenu();

			switch (mainMenuSelection)
			{
			case BALANCE_INQUIRY:
			case WITHDRAWAL:
			case DEPOSIT:

				CurrentTransaction = createTransacion(mainMenuSelection);

				currentTransacion.execute();
				break;
			case EXIT:
				screen.displayMeassageLine("\nExiting the system...");
				userExited = true;
				break;
			default:
				screen.displayMessageLine("\nYou did not enter a valid selection. Try again.");
				break;
			}
		}
	}

	int displayMainMenu()
	{
		screen.displayMessageLine("\nMain menu:");
		screen.displayMessageLine("1-View my balance");
		screen.displayMessageLine("2-Withdraw cash");
		screen.displayMessageLine("3-Deposit funds");
		screen.displayMessageLine("4-Exit\n");
		screen.displayMessageLine("Enter a choice ");
		return keypad.getInput();
	}

	Transaction createTransaction(int type)
	{
		Transaction temp = null;

		switch(type)
		{
		case BALANCE_INQUIRY:
			temp = new BalanceInquiry(currentAccountNumber, screen, bankDatabase);
			break;
		case WITHDRAWAL:
			temp = new Withdrawal(currentAccountNumber, screen, bankDatabase, keypad, depositSlot);
			break;
		}

		return temp;
	}
};


class Screen
{
public:
	void*operator new(size_t rozmiar)
	{
		return(::new char[rozmiar]);
	}
	void displayMessage(string message)
	{
		cout << message;
	}

	void displayMessageLine(string message)
	{
		cout << message << endl;
	}

	void displayDollarAmount(double amount)
	{
		cout << "$" << amount;
	}
};

import java.util.Scanner;

class Keypad
{
	Scanner input;

public:
	Keypad()
	{
		input = new Scanner(System.in);
	}

	int getInput()
	{
		return input.nextInt();
	}
};


class CashDispenser
{
	final static int INITIAL_COUNT = 500;
	int count;
public:
	CashDispenser()
	{
		count = INITIAL_COUNT;
	}

	void dispenseCash(int amount)
	{
		int billsRequired = amount / 20;
		count -= billsRequired;
	}

	bool isSufficientCashAvailable(int amount)
	{
		int billsRequired = amount / 20;

		if (count >= billsRequired)
			return true;
		else
			return false;
	}
};


class DepositSlot
{
public:
	bool isEnvelopeReceived()
	{
		return true;
	}
};

class Account
{
	int accountNumber;
	int pin;
	double availableBalance;
	double totalBalance;

public:
	Account(int theAccountNumber, int thePIN, double theAvailableBalance, double theTotalBalane)
	{
		accountNumber = theAccountNumber;
		pin = thePIN;
		availableBalance = theAvailableBalance;
		totalBalance = theTotalBalane;
	}

	bool validatePIN(int userPIN)
	{
		if (userPIN == pin)
			return true;
		else
			return false;
	}

	double getAvailableBalance()
	{
		return availableBalance;
	}

	double getTotalBalance()
	{
		return totalBalance;
	}

	void credit(double amount)
	{
		totalBalance += amount;
	}

	void debit(double amount)
	{
		availableBalance -= amount;
		totalBalance -= amount;
	}

	int getAccountNumber()
	{
		return accountNumber;
	}
};

class BankDatabase
{
	Account[] accounts;
public:
	BankDatabase()
	{
		accounts = new Account[2];
		accounts[0] = new Account(12345, 54321, 1000.0, 1200.0);
		accounts[1] = new Account(98765, 56789, 200.0, 200.0);
	}

private:
	Account getAccount(int accountNumber)
	{

		for (Account currentAccount : accounts)
		{
			if (currentAccount.getAccountNumber() == accountNumber)
				return currentAccount;
		}
		return null;
	}

public:

	bool authenticateUser(int userAccountNumber, int userPIN)
	{
		Account userAccount = getAccount(userAccountNumber);

		if (userAccount != null)
			return userAccount.validatePIN(userPIN);
		else
			return false;
	}

	double getAvailableBalance(int userAccountNumber)
	{
		return getAccount(userAccountNumber).getAvailableBalance();
	}

	double getTotalBalance(int userAccountNumber)
	{
		return getAccount(userAccountNumber).getTotalBalance();
	}

	void credit(int userAccountNumber, double amount)
	{
		getAccount(userAccountNumber).credit(amount);
	}

	void debit(int userAccountNumber, double amount)
	{
		getAccount(userAccountNumber).debit(amount);
	}
};


class Transaction
{
	int accountNumber;
	Screen screen;
	BankDatabase bankDatabase;

public:
	Transaction(int userAccountNumber, Screen atmScreen, BankDatabase atmBankDatabase)
	{
		accountNumber = userAccountNumber;
		screen = atmScreen;
		bankDatabase = atmBankDatabase;
	}

	int getAccountNumber()
	{
		return accountNumber;
	}

	Screen getScreen()
	{
		return screen;
	}

	BankDatabase getBankDatabase()
	{
		return bankDatabase;
	}

	abstract void execute();
};



class BalanceInquiry : public Transaction
{
public:
	BalanceInquiry(int userAccountNumer, Screen atmScreen, BankDatabase atmBankDatabase)
	{
		super(userAccountNumer, atmScreen, atmBankDatabase);
	}

	void execute()
	{
		BankDatabase bankDatabase = getBankDatabase();
		Screen screen = getScreen();

		double availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());
		double totalBalance = bankDatabase.getTotalBalance(getAccountNumber());

		screen.displayMessageLine("\nBalance Information:");
		screen.displayMessage(" - Available balance:");
		screen.displayDollarAmount(availableBalance);
		screen.displayMessage("\n - Total balance:      ");
		screen.displayDollarAmount(totalBalance);
		screen.displayMessageLine("");
	}
};

class Withdrawal public Transaction
{
	int amount;
	Keypad keypad;
	CashDispenser cashDispenser;
	final static int CANCELED = 6;

public:
	Withdrawal(int userAccountNumber, Screen atmScreen, BankDatabase atmBankDatabase, Keypad atmKeypad, CashDispenser atmCashDispenser)
	{
		super(userAccountNumber, atmScreen, atmBankDatabase);

		keypad = atmKeypad;
		cashDispenser = atmCashDispenser;
	}

	void execute()
	{
		bool cashDispensed = false;
		double availableBalance;

		BankDatabase bankDatabase = getBankDatabase();
		Screen screen = getScreen();

		do
		{
			amount = displayMenuOfAmounts();

			if (amount != CANCELED)
			{
				availableBalance = BankDatabase.getAvailableBalance(getAccountNumber());


				if (amount <= availableBalance)
				{
					if (cashDispenser.isSufficientCashAvailable(amount))
					{
						BankDatabase.debit(getAccountNumber(), amount);

						cashDispenser.dispenseCash(amount);
						cashDispensed = true;

						screen.displayMessageLine("\nYour cash has been" + "dispensed. Please take your cash now.");
					}
					else
						screen.displayMessageLine("\nInsufficient cash available in the ATM." + "\n\nPlease choose a smaller amount");
				}
				else
				{
					screen.displayMessageLine("\nInsufficient funds in your account." + "\n\nPlease choose a smaller amount.");
				}
			}
			else
			{
				screen.displayMessageLine("\nCanceling transaction...");
				return;
			}
		} while (!cashDispenser)
	}

private:
	int displayMenuOfAmounts()
	{
		int userChoice = 0;
		Screen screen = getScreen();

		int[] amounts = { 0,20,40,60,100,200 };

		while (userChoice == 0)
		{
			screen.displayMessageLine("\nWithdrawal Menu:");
			screen.displayMessageLine("1 - $20");
			screen.displayMessageLine("2 - $40");
			screen.displayMessageLine("3 - $60");
			screen.displayMessageLine("4 - $100");
			screen.displayMessageLine("5 - $200");
			screen.displayMessageLine("6 - Cancel transaction");
			screen.displayMessage("\nChoose a withdrawal amount: ");

			int input = keypad.getInput();

			switch (input)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				userChoice = amounts[input];
				break;
			case CANCELED:
				userChoice = CANCELED;
				break;
			default:
				screen.displayMessageLine("\nInvalid selection. Try again");
			}
		}
		return userChoice;
	}
};

class Deposit :public Transaction
{
	double amount;
	Keypad keypad;
	DepositSlot depositSlot;
	final static int CANCELED = 0;

public:
	Deposit(int userAccountNumber, Screen atmScreen, BankDatabase atmBankDatabase, Keypad atmKeypad, DepositSlot atmDepositSlot)
	{
		super(userAccountNumber, atmScreen, atmBankDatabase);

		keypad = atmKeypad;
		depositSlot = atmDepositSlot;
	}

	void execute()
	{
		BankDatabase bankDatabase = getBankDatabase();
		Screen screen = getScreen();

		amount = promptForDepositAmount();

		if (amount != CANCELED)
		{
			screen.displayMessage("\nPlease insert a deposit envelope cantaining");
			screen.displayDollarAmount(amount);
			screen.displayMessageLine(".");

			bool envelopeReceived = depositSlot.isEnvelopeReceived();

			if (envelopeReceived)
			{
				screen.displayMessageLine("\nYour envelope has been " +
					"received.\nNOTE: The money just deposited will not " +
					"be available intil we verify the amount of any " +
					"enclosed cash and your checks clear.");

				BankDatabase.credit(getAccountNumber(), amount);
			}
			else
			{
				screen.displayMessageLine("\nYou did not insert an" +
					"envelope, so the ATM has canceled your transaction.");
			}
		}
		else
		{
			screen.displayMessageLine("\nCanceling transaction...");
		}
	}

private:
	double promptForDepositAmount()
	{
		Screen screen = getScreen();
		screen.displayMessage("\nPlease enter a deposit amount in " +
			"CENTS (or 0 to cancel): ");
		int input = keypad.getInput();

		if (input == CANCELED)
			return CANCELED;
		else
		{
			return(double)input / 100;
		}
	}	
};

int main()
{
	ATM atmbank;
	atmbank

	return 0;
}






















