#include "Screen.h"


void Screen::displayMessage(string message)
{
	cout << message;
}

void Screen::displayMessageLine(string message)
{
	cout << message << endl;
}

void Screen::displayZlAmount(double amount)
{
	cout << amount << "zl";
}

void Screen::displayMainMenu()
{
	cout << "\nMenu glowne:" << endl;
	cout << "1-Stan konta" << endl;
	cout << "2-Wyplata" << endl;
	cout << "3-Wplata" << endl;
	cout << "4-Wyjscie\n" << endl;
	cout << "Dokonaj wyboru: ";
}

void Screen::displayWithdrawalMenu()
{
	cout << "\nMenu wyplat:" << endl;
	cout << "1 - 20zl" << endl;
	cout << "2 - 50zl" << endl;
	cout << "3 - 100zl" << endl;
	cout << "4 - 200zl" << endl;
	cout << "5 - 500zl" << endl;
	cout << "6 - 1000zl" << endl;
	cout << "7 - 2000zl" << endl;
	cout << "8 - Zakoncz transakcje" << endl;
	cout << "\nDokonaj wyboru: ";
}