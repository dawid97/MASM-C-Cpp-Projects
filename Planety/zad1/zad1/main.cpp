#include <iostream>
#include <conio.h>
#include "cialo_niebieskie.h"
#include"gwiazda.h"
#include"Planeta.h"
#include"pulsar.h"
using namespace std;

int main()
{
	cialo_niebieskie *tab[9];

	for (int i = 0; i < 9;)
	{
		tab[i] = new gwiazda(i * 100 + 10, "Gwiazda", 119*i, i * 3600, i);
		i++;
		tab[i] = new Planeta(i * 1232, "Planeta", 273*i, i);
		i++;
		tab[i] = new pulsar(i * 123, "Pulsar", 31*i, i * 12345, 0, i * 2000, S);
		i++;
	}

	
	for (int i = 0; i < 9; i++)
	{
		tab[i]->wypisz();
		cout << endl << endl << endl;
	}
	
	cout << "-----------------------------------------------------------------------------" << endl;

	
	for (int i = 0; i < 9; i++)
	{
		cout << *tab[i];
		cout << endl << endl << endl;
	}
	


	cialo_niebieskie::wypiszIloscObiektow();

	for (int i = 0; i < 9; i++)
	{
		delete(tab[i]);

	}

	cialo_niebieskie::wypiszIloscObiektow();


	_getch();
	return 0;
}