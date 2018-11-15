#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class Account
{
	int accountNumber;
	int pin;
	double availableBalance;
	double totalBalance;

public:
	Account() {}

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


class DepositSlot
{
public:
	bool isEnvelopeReceived()
	{
		return true;
	}
};

class CashDispenser
{
	const static int INITIAL_COUNT = 500;
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


class Keypad
{
	int nr;
public:
	Keypad()
	{
		nr = 0;
	}
	int getInput()
	{
		cin >> nr;
		return nr;
	}
};

class Screen
{
public:
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

class BankDatabase
{
	Account accounts[2];

public:

	BankDatabase()
	{
		accounts[0] = Account(12345, 54321, 1000.0, 1200.0);
		accounts[1] = Account(98765, 56789, 200.0, 200.0);
		accounts[2] = Account(55555, 55555, 200.0, 200.0);
		accounts[3] = Account(11111, 11111, 200.0, 200.0);
	}

private:

	Account*getAccount(int accountNumber)
	{
		Account*currentAccount = accounts;

		for (int i = 0; i < 4; i++)
		{
			if (currentAccount->getAccountNumber() == accountNumber)
				return currentAccount;
			currentAccount++;
		}
		return nullptr;
	}

public:

	bool authenticateUser(int userAccountNumber, int userPIN)
	{
		Account*userAccount = getAccount(userAccountNumber);

		if (userAccount != nullptr)
			return userAccount->validatePIN(userPIN);
		else
			return false;
	}

	double getAvailableBalance(int userAccountNumber)
	{
		return getAccount(userAccountNumber)->getAvailableBalance();
	}

	double getTotalBalance(int userAccountNumber)
	{
		return getAccount(userAccountNumber)->getTotalBalance();
	}

	void credit(int userAccountNumber, double amount)
	{
		getAccount(userAccountNumber)->credit(amount);
	}

	void debit(int userAccountNumber, double amount)
	{
		getAccount(userAccountNumber)->debit(amount);
	}
};


class Transaction
{
protected:
	int accountNumber;
	Screen screen;
	BankDatabase bankDatabase;

public:
	Transaction() {}

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

	virtual void execute() {}
};


class BalanceInquiry : public Transaction
{
public:
	BalanceInquiry() {}

	BalanceInquiry(int userAccountNumer, Screen atmScreen, BankDatabase atmBankDatabase) :Transaction(userAccountNumer, atmScreen, atmBankDatabase) {}

	void execute()
	{
		//BankDatabase bankDatabase = getBankDatabase();
		//Screen screen = getScreen();

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



class Withdrawal :public Transaction
{
	int amount;
	Keypad keypad;
	CashDispenser cashDispenser;
	BankDatabase bankDatabase;
	Screen screen;
	//static int CANCELED = 6;

public:
	Withdrawal(int userAccountNumber, Screen atmScreen, BankDatabase atmBankDatabase, Keypad atmKeypad, CashDispenser atmCashDispenser) :Transaction(userAccountNumber, atmScreen, atmBankDatabase)
	{
		keypad = atmKeypad;
		cashDispenser = atmCashDispenser;
	}

	void execute()
	{
		bool cashDispensed = false;
		double availableBalance;

		//BankDatabase bankDatabase = getBankDatabase();
		//Screen screen = getScreen();

		do
		{
			amount = displayMenuOfAmounts();

			if (amount != 6)//CANCELED
			{
				availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());


				if (amount <= availableBalance)
				{
					if (cashDispenser.isSufficientCashAvailable(amount))
					{
						bankDatabase.debit(getAccountNumber(), amount);

						cashDispenser.dispenseCash(amount);
						cashDispensed = true;

						screen.displayMessageLine("\nYour cash has been dispensed. Please take your cash now.");
					}
					else
						screen.displayMessageLine("\nInsufficient cash available in the ATM\n\nPlease choose a smaller amount");
				}
				else
				{
					screen.displayMessageLine("\nInsufficient funds in your account.\n\nPlease choose a smaller amount.");
				}
			}
			else
			{
				screen.displayMessageLine("\nCanceling transaction...");
				return;
			}
		} while (!cashDispensed);
	}

private:
	int displayMenuOfAmounts()
	{
		int userChoice = 0;
		//Screen*screen = getScreen();

		int amounts[] = { 0,20,40,60,100,200 };

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
			case 6://CANCELED
				userChoice = 6;//CANCELED
				break;
			default:
				screen.displayMessageLine("\nInvalid selection. Try again");
			}
		}
		return userChoice;
	}
};






class ATM
{
	bool userAuthenticated;
	int currentAccountNumber;
	Screen screen;
	Keypad keypad;
	CashDispenser cashDispenser;
	DepositSlot depositSlot;
	BankDatabase bankDatabase;

	enum { BALANCE_INQUIRY = 1, WITHDRAWAL = 2, DEPOSIT = 3, EXIT = 4 };

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


		bool userExited = false;


		Transaction*currentTransaction = nullptr;

		while (!userExited)
		{
			int mainMenuSelection = displayMainMenu();

			switch (mainMenuSelection)
			{
			case BALANCE_INQUIRY:
			{
				currentTransaction = &BalanceInquiry(currentAccountNumber, screen, bankDatabase);
				currentTransaction->execute();
				break;
			}
			case WITHDRAWAL:
			{

				currentTransaction = &Withdrawal(currentAccountNumber, screen, bankDatabase, keypad, cashDispenser);
				currentTransaction->execute();
				break;
			}
			case DEPOSIT:
			{

				//delete currentTransaction;
				//currentTransaction = nullptr;

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

	int displayMainMenu()
	{
		screen.displayMessageLine("\nMain menu:");
		screen.displayMessageLine("1-View my balance");
		screen.displayMessageLine("2-Withdraw cash");
		screen.displayMessageLine("3-Deposit funds");
		screen.displayMessageLine("4-Exit\n");
		screen.displayMessageLine("Enter a choice ");
		int choice = keypad.getInput();
		return choice;
	}


	/*
	Transaction*createTransaction(int type)
	{

	Transaction*tmp = new BalanceInquiry(currentAccountNumber, screen, bankDatabase);

		return tmp;
	}
	*/

};

int main()
{
	ATM atm;
	atm.run();

	_getch();
	return 0;
}