#include "BalanceInquiry.h"

BalanceInquiry::BalanceInquiry(int userAccountNumer, Screen*atmScreen, BankDatabase*atmBankDatabase) :Transaction(userAccountNumer, atmScreen, atmBankDatabase) {}

void BalanceInquiry::execute()
{
	cout << bankDatabase << endl;
	double availableBalance = bankDatabase->getAvailableBalance(getAccountNumber());
	double totalBalance = bankDatabase->getTotalBalance(getAccountNumber());

	screen->displayMessageLine("\nBalance Information:");
	screen->displayMessage(" - Available balance:");
	screen->displayDollarAmount(availableBalance);
	screen->displayMessage("\n - Total balance:      ");
	screen->displayDollarAmount(totalBalance);
	screen->displayMessageLine("");
}