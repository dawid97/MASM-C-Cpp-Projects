#include "CardReader.h"


CardReader::CardReader()
{
	fstream plik;
	plik.open("karta.txt", ios::in);
	plik >> accountNumber >> pin;
	plik.close();
}

int CardReader::getAccountNumber()
{
	return accountNumber;
}

bool CardReader::validatePIN(int userPIN)
{
	if (userPIN == pin)
		return true;
	else
		return false;
}