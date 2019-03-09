#include<iostream>
#include<conio.h>
#include "awaria_samochodu.h"
#include "awaria_silnika.h"
#include "awaria_swiecy.h"


using namespace std;

void ownTerminator()
{
	std::cout << "Terminate" << std::endl;
	//	abort();
	exit(10);
}

int main()
{
	awaria_samochodu* tab[10];

	for (int i = 0; i < 9;) //tablica uzupelniona od 0-8 (9 elementow)
	{
		tab[i] = new awaria_samochodu(i * 100);
		i++;
		tab[i] = new awaria_silnika(i * 100, i * 10);
		i++;
		tab[i] = new awaria_swiecy(i * 100, i * 10, i);
		i++;
	}
	cout << typeid(*tab[0]).name() << endl;
	cout << typeid(awaria_samochodu).name() << endl;

	for (int i = 0; i < 9; i++)
	{
		try 
		{
			if (typeid(*tab[i]).name() == typeid(awaria_samochodu).name())
			{
				throw awaria_samochodu(10); //rzucony nowy obiekt typu awaria_samochodu//rzucilbym jakas strukture ktora zawiera blad
			}

			if (typeid(*tab[i]).name() == typeid(awaria_silnika).name())
			{
				throw awaria_silnika(100, 10); //rzucony nowy obiekt typu awaria_silnika//rzucilbym jakas strukture ktora zawiera blad
			}

			if (typeid(*tab[i]).name() == typeid(awaria_swiecy).name())
			{
				throw awaria_swiecy(1000, 100, 10); //rzucony nowy obiekt typu awaria_silnika//rzucilbym jakas strukture ktora zawiera blad
			}
		}
		catch (awaria_swiecy & e) //wazne zeby sie zaczynalo od najnizszego potomka bo klasa bazowa moze przechwycic dany wyjatek
		{
			cout << "Wyjatek awaria swiecy" << endl;
			e.naprawa();
			cout << endl << endl;
		}
		catch (awaria_silnika & e)
		{
			cout << "Wyjatek awaria silnika" << endl;
			e.naprawa();
			cout << endl << endl;

		}
		catch (awaria_samochodu & e)
		{
			cout << "Wyjatek awaria samochodu" << endl;
			e.naprawa();
			cout << endl << endl;
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		try
		{
			try
			{
				try
				{
					throw awaria_swiecy(1000, 100, 10);
				}
				catch (awaria_swiecy & e)
				{
					cout << "obsluga awari swiecy" << endl;
					e.naprawa();
					cout << endl << endl;
				}
				throw awaria_silnika(100, 10);
			}
			catch (awaria_silnika & e)
			{
				cout << "obsluga awari silnika" << endl;
				e.naprawa();
				cout << endl << endl;
			}
			throw awaria_samochodu(10);
		}
		catch (awaria_samochodu & e)
		{
			cout << "Obsluga awari samochodu" << endl;
			e.naprawa();
			cout << endl << endl;
		}
	}

	std::set_terminate(ownTerminator);

	//throw 1;


	_getch();
	return 0;
}