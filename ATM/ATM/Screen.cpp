#include "Screen.h"


void Screen::displayMessage(string message)
{
	cout << message;
}

void Screen::displayMessageLine(string message)
{
	cout << message << endl;
}

void Screen::displayDollarAmount(double amount)
{
	cout << "$" << amount;
}

void Screen::displayMainMenu()
{
	cout << "\nMain menu:" << endl;
	cout << "1-View my balance" << endl;
	cout << "2-Withdraw cash" << endl;
	cout << "3-Deposit funds" << endl;
	cout << "4-Exit\n" << endl;
	cout << "Enter a choice ";
}

void Screen::displayWithdrawalMenu()
{
	cout << "\nWithdrawal Menu:" << endl;
	cout << "1 - 20zl" << endl;
	cout << "2 - 50zl" << endl;
	cout << "3 - 100zl" << endl;
	cout << "4 - 200zl" << endl;
	cout << "5 - 500zl" << endl;
	cout << "6 - 1000zl" << endl;
	cout << "7 - 2000zl" << endl;
	cout << "8 - Cancel transaction" << endl;
	cout << "\nChoose a withdrawal amount: ";
}