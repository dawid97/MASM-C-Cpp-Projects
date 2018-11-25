#include "BankDatabase.h"



BankDatabase::BankDatabase()
{
	LoadFromFile();
}

void BankDatabase::LoadFromFile()
{
	fstream plik;
	plik.open("data.txt", ios::in);
	int accountNumber;
	double availableBalance, totalBalance;
	
	while (!plik.eof())
	{
		plik >> accountNumber >> availableBalance >> totalBalance;
		accounts.push_back(new Account(accountNumber,availableBalance, totalBalance));
	}
	plik.close();
}
void BankDatabase::displayAccounts()
{
	for (list<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++)
	{
		cout << (*i)->getAccountNumber() << endl;
		cout << (*i)->getAvailableBalance() << endl;
		cout << (*i)->getTotalBalance() << endl << endl;
	}
}

bool BankDatabase::authenticateUser(int userAccountNumber)
{
	
	for (list<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++)
	{
		if ((*i)->getAccountNumber() == userAccountNumber)
			return true;
	}
	return false;
}


void BankDatabase::saveToFile()
{
	fstream plik;
	plik.open("data.txt", ios::out);

	int accountNumber;
	double availableBalance, totalBalance;
	//plik << list<Account>accounts;

	for (list<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++)
	{
		accountNumber =(*i)->getAccountNumber();
		availableBalance = (*i)->getAvailableBalance();
		totalBalance = (*i)->getTotalBalance();
		plik << accountNumber << " " << availableBalance << " " << totalBalance;
		if ((*i) != accounts.back())
			plik << endl;
	}
	plik.close();
}




double BankDatabase::getAvailableBalance(int userAccountNumber)
{
	for (list<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++)
	{
		if ((*i)->getAccountNumber() == userAccountNumber)
			return (*i)->getAvailableBalance();
	}
	return 0;
}

double BankDatabase::getTotalBalance(int userAccountNumber)
{
	for (list<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++)
	{
		if ((*i)->getAccountNumber() == userAccountNumber)
			return (*i)->getTotalBalance();
	}
	return 0;
}

void BankDatabase::credit(int userAccountNumber, double amount)
{
	for (list<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++)
	{
		if ((*i)->getAccountNumber() == userAccountNumber)
			(*i)->credit(amount);
	}
	return;
}

void BankDatabase::debit(int userAccountNumber, double amount)
{
	for (list<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++)
	{
		if ((*i)->getAccountNumber() == userAccountNumber)
			(*i)->debit(amount);
	}
	return;
}