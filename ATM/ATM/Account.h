#pragma once

class Account
{
	int accountNumber;
	double availableBalance;
	double totalBalance;

public:

	Account(int theAccountNumber,double theAvailableBalance, double theTotalBalane);


	double getAvailableBalance();

	double getTotalBalance();

	void credit(double amount);

	void debit(double amount);

	int getAccountNumber();

};