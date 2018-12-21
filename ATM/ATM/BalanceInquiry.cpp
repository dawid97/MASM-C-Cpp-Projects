#include "BalanceInquiry.h"

BalanceInquiry::BalanceInquiry(int userAccountNumer, Screen*atmScreen, BankDatabase*atmBankDatabase) :Transaction(userAccountNumer, atmScreen, atmBankDatabase) {}

void BalanceInquiry::execute()
{
	double availableBalance = bankDatabase->getAvailableBalance(getAccountNumber());
	double totalBalance = bankDatabase->getTotalBalance(getAccountNumber());

	screen->displayMessageLine("\nInformacje o koncie:");
	screen->displayMessage(" - Dostepne saldo:");
	screen->displayZlAmount(availableBalance);
	screen->displayMessage("\n - Calkowite saldo:");
	screen->displayZlAmount(totalBalance);
	screen->displayMessageLine("");
	Sleep(8000);
	system("cls");
}