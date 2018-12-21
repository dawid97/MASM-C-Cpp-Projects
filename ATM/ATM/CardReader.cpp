#include "CardReader.h"

fstream & operator>>(fstream & file, Card & card)
{
	file.open("Card.txt", ios::in);
	file >> card.accountNumber >> card.pin;
	file.close();
	return file;
}

CardReader::CardReader()
{
	fstream file;
	file >> card;
}

int CardReader::getAccountNumber()
{
	return card.accountNumber;
}

bool CardReader::validatePIN(int userPIN)
{
	if (userPIN == card.pin)
		return true;
	else
		return false;
}