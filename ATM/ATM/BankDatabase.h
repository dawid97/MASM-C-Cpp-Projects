#pragma once
#include "Account.h"
#include<list>
#include<fstream>
#include<iostream>
using namespace std;

class BankDatabase
{
    list<Account*> accounts;

public:

	BankDatabase();
	void saveToFile();
	void displayAccounts();
	
private:

	void LoadFromFile();

public:

	bool authenticateUser(int userAccountNumber);
	
	double getAvailableBalance(int userAccountNumber);

	double getTotalBalance(int userAccountNumber);

	void credit(int userAccountNumber, double amount);

	void debit(int userAccountNumber, double amount);
};
