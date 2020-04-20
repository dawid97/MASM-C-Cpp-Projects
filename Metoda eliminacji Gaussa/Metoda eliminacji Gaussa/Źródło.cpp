#include <iostream>
#include <fstream>
#include <cstdlib>

//#include<conio.h>

#include <string>

using namespace std;
const int W = 50;
const int K=50;




int Operations(int nr_kroku, float macierz[W][K])            // Wykonywanie dzia³añ
{
	fstream plik;
	plik.open("wartosci macierza.txt", ios::in);
	if (plik.good() == true)
	{
		int Wiersz;
		int Kolumna;
		plik >> Wiersz >> Kolumna;
		for (int k = 1 + nr_kroku; k < Wiersz; k++)
		{
			for (int p = Kolumna - 1; p >= nr_kroku; p--)
			{
				macierz[k][p] = (macierz[k][p] - ((macierz[k][nr_kroku] / macierz[nr_kroku][nr_kroku])*macierz[nr_kroku][p]));
			}
		}
	}
	else
	{
		cout << "Nie uzyskano dostepu do pliku!" << endl;  // B³¹d odczytu pliku
		return 0;

	}
	plik.close();//Zamykanie pliku

}



int Display_macierz(float macierz[W][K])          // Wyswietlenie macierza
{
	fstream plik;
	plik.open("wartosci macierza.txt", ios::in);
		if (plik.good() == true)
		{
			int Wiersz;
			int Kolumna;
			plik >> Wiersz >> Kolumna;

			for (int p = 0; p < Wiersz; p++)
			{
				for (int k = 0; k < Kolumna; k++)
				{
					cout << macierz[p][k] << '\t' << '\t';
				}
				cout << endl << endl << endl << endl;
			}
			cout << "........................................................................................................." << endl << endl << endl;
		}
		else
		{
			cout << "Nie uzyskano dostepu do pliku!" << endl;  // B³¹d odczytu pliku
			return 0;

		}
	plik.close();//Zamykanie pliku
}



int Open_Loading_file(float macierz[W][K])           //Otwieranie pliku i wczytywanie wartosci z pliku do macierza
{
	fstream plik;
	plik.open("wartosci macierza.txt", ios::in);  // Sprawdzenie poprawnosci otwarcia pliku

	if (plik.good() == true)
	{
		int Wiersz;
		int Kolumna;
		plik >> Wiersz >> Kolumna;

		if (Wiersz > 0 && Kolumna > 0) // Sprawdza czy u¿ytkownik poda³ dodatnia liczbe kolumn i wierszy
		{


			for (int p = 0; p < Wiersz; p++)
			{
				{
					for (int k = 0; k < Kolumna; k++)
						plik >> macierz[p][k];
				}
			}
		}
		else
		{
			cout << "Liczba wierszy i Kolumn powinna byc dodatnia" << endl;
			return 0;
		}
	}
	else
	{
		cout << "Nie uzyskano dostepu do pliku!" << endl;  // B³¹d odczytu pliku
		return 0;

	}
	plik.close();//Zamykanie pliku

}


int Ilosc_macierzy(float macierz[W][K])   // Obliczenie iloœci rzêdów macierzy
{
	fstream plik;
	plik.open("wartosci macierza.txt", ios::in);
	if (plik.good() == true)
	{
		int Wiersz;
		int Kolumna;
		plik >> Wiersz >> Kolumna;
		int Rzad_macierzy;
		int Wiersze_zerowe = 0;
		int licznik;

		for (int f = 0; f < Wiersz; f++)
		{
			licznik = 0;

			for (int l = 0; l < Kolumna; l++)
			{
				if (macierz[f][l] == 0)
				{
					licznik++;
				}
			}

			if (licznik == Kolumna)
			{
				Wiersze_zerowe++;
			}
		}

		Rzad_macierzy = Wiersz - Wiersze_zerowe;

		return Rzad_macierzy;
	}
	else
	{
		cout << "Nie uzyskano dostepu do pliku!" << endl;  // B³¹d odczytu pliku
		return 0;

	}
	plik.close();//Zamykanie pliku
}




int funkcja_glowna(float macierz[W][K])
{
	fstream plik;
	plik.open("wartosci macierza.txt", ios::in);
	if (plik.good() == true)
	{
		int Wiersz;
		int Kolumna;
		plik >> Wiersz >> Kolumna;

		for (int i = 0; i < Kolumna; i++)
		{
			float suma_wierszy_w_kolumnie = 0;

			for (int s = i; s < Wiersz; s++)    // Sprawdzenie czy w danej kolumnie mozna znalezsc element rozny od zera
			{
				if (macierz[s][i] == 0)
					suma_wierszy_w_kolumnie++;
			}

			if (suma_wierszy_w_kolumnie == Wiersz - i)
			{
				cout << "nie mozna znalesc wiecej elementow rozych od zera!" << endl;
				cout << "Rzad macierzy jest rowny " << Ilosc_macierzy(macierz) << endl;   // Wyswietlenie iloœci rzêdu macierzy
				return 0;
			}

			else if (macierz[i][i] != 0)
			{
				Operations(i, macierz);  // Wykonywanie dzia³añ

			}

			else
			{
				for (int k = 1 + i; k < Wiersz; k++)
				{
					if (macierz[k][i] != 0)
					{
						for (int p = 0; p < Kolumna; p++)
						{
							swap(macierz[k][p], macierz[i][p]);//Zamiana wierszy
						}
						break;
					}
				}

				Operations(i, macierz); // Wykonywanie dzia³añ
			}

			Display_macierz(macierz);   // Wyœwietlenie macierza
		}
		cout << "Rzad macierzy jest rowny " << Ilosc_macierzy(macierz) << endl; // Wyswietlenie iloœci rzêdu macierzy
		return 0;
	}
	else
	{
		cout << "Nie uzyskano dostepu do pliku!" << endl;  // B³¹d odczytu pliku
		return 0;

	}
	plik.close();//Zamykanie pliku

}




int main()
{
	cout << "                METODA ELIMINACJI GAUSSA" << endl;
	cout << "........................................................................................................." << endl << endl << endl;

	float macierz[W][K];

	Open_Loading_file(macierz);   //Wczytywanie wartosci z pliku do tabeli
	Display_macierz(macierz); //Wyswietlenie macierza
	funkcja_glowna(macierz);//G³ówne operacje na macierzu

	int a;
	cin >> a;
	//system("pause");
	//_getch();
	return 0;
}