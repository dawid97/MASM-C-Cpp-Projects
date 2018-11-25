#pragma once
#include<iostream>
#include<string>
#include "Account.h"
using namespace std;

class Screen
{
public:
	void displayMessage(string message);
	void displayMessageLine(string message);
	void displayDollarAmount(double amount);
	void displayMainMenu();
	void displayWithdrawalMenu();
};