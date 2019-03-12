#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct BladUjemnegoPromienia
{
	string wiadomosc;
};

double PoleKola(double r)
{
	cout << "obliczamy pole kola o promieniu " << r << endl;
	if (r >= 0)
	{
		return 3.14*r*r;
	}
	else
	{
		cout << "!!!Rzucenie wyjatku!!!" << endl;
		BladUjemnegoPromienia e;
		throw e;
	}
}

int main()
{
	try                                                                                                  
	{
		double wartosc = PoleKola(5.5);
		cout << "a) Pole kola = " << wartosc << endl;

		wartosc = PoleKola(-6);
		cout << "b) Pole kola = " << wartosc << endl;
	}
	catch (BladUjemnegoPromienia e)
	{
		e.wiadomosc = "zadany promien jest ujemny!";
		cout << e.wiadomosc << endl;
	}

	_getch();
	return 0;
}

