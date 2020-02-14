// LottoDllCpp.cpp : Defines the exported functions for the DLL.
#include "stdafx.h" 
#include <utility>
#include <limits.h>
#include "CPP_DLL.h"




/*funkcja porownuje dwie tablice pierwsza to liczby wygrywajace a druga to liczby z pliku.
  Funkcja zwraca ilosc trafien*/
int numberOfHits(int*generatedNumbers, int*numbersFromFile)
{
	int counter = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (numbersFromFile[i] == generatedNumbers[k])
				counter++;
		}
	}

	return counter;
}




/*funkcja oblicza wygrane przypadajace na jedna osobe.
  Funkcja zwraca pole pieniezna dla szostki.*/
void calculatePrices(int*numbersOfWins, int*winForOnePerson, int poolOfMoney)
{
	int moneyFor6 = poolOfMoney / 100 * 44;
	int moneyFor5 = poolOfMoney / 100 * 8;
	int moneyFor3 = 24 * numbersOfWins[3];
	int moneyFor4 = poolOfMoney - moneyFor6 - moneyFor5 - moneyFor3;

	//szostka
	if (numbersOfWins[0] > 0)
		winForOnePerson[0] = (moneyFor6 / numbersOfWins[0]);
	else
		winForOnePerson[0] = 0;

	//piatka
	if (numbersOfWins[1] > 0)
		winForOnePerson[1] = (moneyFor5 / numbersOfWins[1]);
	else
		winForOnePerson[1] = 0;

	//czworka
	if (numbersOfWins[2] > 0)
		winForOnePerson[2] = (moneyFor4 / numbersOfWins[2]);
	else
		winForOnePerson[2] = 0;

	//trojka
	if (numbersOfWins[3] > 0)
		winForOnePerson[3] = (moneyFor3 / numbersOfWins[3]);
	else
		winForOnePerson[3] = 0;
}
