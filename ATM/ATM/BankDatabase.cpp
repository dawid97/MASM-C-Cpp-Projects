#include "BankDatabase.h"

fstream & operator>>(fstream & file , list<Account*> & accounts)
{
	file.open("Accounts.txt", ios::in);

	if (file.good())
	{
		int accountNumber;
		double availableBalance, totalBalance;

		while (!file.eof())
		{
			file >> accountNumber >> availableBalance >> totalBalance;
			accounts.push_back(new Account(accountNumber, availableBalance, totalBalance));
		}
		file.close();
		return file;
	}
	else
	{
		cout << "Blad otwarcia pliku 'Accounts'" << endl;
		Sleep(3000);
		system("cls");
		return file;
	}
}

BankDatabase::BankDatabase()
{
	LoadAccounts();
}

void BankDatabase::LoadAccounts()
{
	fstream file;
	file >> accounts;
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

fstream & operator<<(fstream & file, list<Account*> & accounts)
{
	file.open("Accounts.txt", ios::out);

	if (file.good())
	{
		int accountNumber;
		double availableBalance, totalBalance;

		for (list<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++)
		{
			accountNumber = (*i)->getAccountNumber();
			availableBalance = (*i)->getAvailableBalance();
			totalBalance = (*i)->getTotalBalance();
			file << accountNumber << " " << availableBalance << " " << totalBalance;
			if ((*i) != accounts.back())
				file << endl;
		}
		file.close();
		return file;
	}
	else
	{
		cout << "Blad otwarcia pliku 'Accounts'!" << endl;
		Sleep(3000);
		system("cls");
		return file;
	}
}

void BankDatabase::saveAccounts()
{
	fstream file;
	file << accounts;
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
		{
			(*i)->credit(amount);
			saveAccounts();
		}
	}
	return;
}

void BankDatabase::debit(int userAccountNumber, double amount)
{
	for (list<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++)
	{
		if ((*i)->getAccountNumber() == userAccountNumber)
		{
			(*i)->debit(amount);
			saveAccounts();
		}
	}
	return;
}