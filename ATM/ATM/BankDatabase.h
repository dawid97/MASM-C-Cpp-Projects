#pragma once
#include "Account.h"
#include "Screen.h"
#include<list>
#include<fstream>
#include<iostream>
#include<Windows.h>
using namespace std;

class BankDatabase
{
    list<Account*> accounts;

public:
	BankDatabase();

private:
	void LoadAccounts();
	void saveAccounts();

public:
    bool authenticateUser(int userAccountNumber);
	double getAvailableBalance(int userAccountNumber);
	double getTotalBalance(int userAccountNumber);
	void credit(int userAccountNumber, double amount);
	void debit(int userAccountNumber, double amount);
};
