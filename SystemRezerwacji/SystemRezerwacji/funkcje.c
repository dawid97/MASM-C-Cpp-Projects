#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include "funkcje.h"


int PoprawnoscDaty(int rr, int mm, int dd)
{
	if (rr >= 2018 && rr <= 2022)
	{
		if (mm >= 1 && mm <= 12)
		{
			if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
				return 1;
			else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
				return 1;
			else if ((dd >= 1 && dd <= 28) && (mm == 2))
				return 1;
			else if (dd == 29 && mm == 2 && (rr % 400 == 0 || (rr % 4 == 0 && rr % 100 != 0)))
				return 1;
			else
				return 0;

		}
		else
			return 0;
	}
	else
		return 0;
}

int PoprawnoscGodziny(int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo)
{
	int G1M1 = (GodzinaOd * 60) + MinutaOd;
	int G2M2 = (GodzinaDo * 60) + MinutaDo;

	if (G1M1 >= G2M2)
		return 0;

	if ((GodzinaOd > 6) && (GodzinaOd <23) && (GodzinaDo > 6) && (GodzinaDo<23) && (MinutaOd >= 0) && (MinutaOd<60) && (MinutaDo >= 0) && (MinutaDo<60))
		return 1;

	return 0;
}

int PoprawnoscStolika(int NumerStolika)
{
	if ((NumerStolika > 0) && (NumerStolika<11))
		return 1;

	return 0;
}

int PoprawnoscNumeruTelefonu(int NumerTelefonu)
{
	if (100000000 < NumerTelefonu < 999999999)
		return 1;

	return 0;
}




int KolizjaRezerwacji(Rezerwacja*rezerwacja, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo)
{
	if (rezerwacja == NULL)
		return 0;

	Rezerwacja*pomoc = rezerwacja;

	int G1M1 = GodzinaOd * 60 + MinutaOd;
	int G2M2 = GodzinaDo * 60 + MinutaDo;
	int G3M3, G4M4;

	while (pomoc != NULL)
	{
		G3M3 = ((pomoc->GodzinaOd) * 60) + (pomoc->MinutaOd);
		G4M4 = ((pomoc->GodzinaDo) * 60) + (pomoc->MinutaDo);

		if (((G3M3<G2M2) && (G1M1 <= G3M3)) || ((G1M1<G4M4) && (G4M4 <= G2M2)))
			return 1;

		pomoc = pomoc->NastepnaRezerwacja;
	}

	return 0;
}




Dzien*SzukajDnia(Dzien*dzien, int rr, int mm, int dd)
{
	if (dzien == NULL)
		return NULL;

	Dzien*pomoc = dzien;

	while (pomoc != NULL)
	{
		if ((pomoc->Rok == rr) && (pomoc->Miesiac = mm) && (pomoc->Dzien == dd))
			return pomoc;

		pomoc = pomoc->NastepnyDzien;
	}

	return NULL;
}

Stolik*SzukajStolika(Stolik*stolik, int NumerStolika)
{
	if (stolik == NULL)
		return NULL;

	Stolik*pomoc = stolik;

	while (pomoc != NULL)
	{
		if (pomoc->NumerStolika == NumerStolika)
			return pomoc;

		pomoc = pomoc->NastepnyStolik;
	}

	return NULL;
}

Rezerwacja*SzukajRezerwacji(Rezerwacja*rezerwacja, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo)
{
	if (rezerwacja == NULL)
		return NULL;

	Rezerwacja*pomoc = rezerwacja;

	while (pomoc != NULL)
	{
		if ((pomoc->GodzinaOd == GodzinaOd) && (pomoc->GodzinaDo == GodzinaDo) && (pomoc->MinutaOd == MinutaOd) && (pomoc->MinutaDo == MinutaDo))
			return pomoc;

		pomoc = pomoc->NastepnaRezerwacja;
	}

	return NULL;
}






void WyswietlDate(int rr, int mm, int dd)
{
	printf("Data:");

	if (mm > 9 && dd > 9)
		printf("%d-%d-%d\n", rr, mm, dd);
	else if (mm>9 && dd<10)
		printf("%d-%d-0%d\n", rr, mm, dd);
	else if (mm<10 && dd>9)
		printf("%d-0%d-%d\n", rr, mm, dd);
	else
		printf("%d-0%d-0%d\n", rr, mm, dd);
	return;
}

void WyswietlGodzine(int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo)
{
	printf("Godzina rezerwacji: ");

	if (GodzinaOd > 9 && MinutaOd > 9)
		printf("%d:%d", GodzinaOd, MinutaOd);
	else if (GodzinaOd>9 && MinutaOd<10)
		printf("%d:0%d", GodzinaOd, MinutaOd);
	else if (GodzinaOd<10 && MinutaOd>9)
		printf("0%d:%d", GodzinaOd, MinutaOd);
	else
		printf("0%d:0%d", GodzinaOd, MinutaOd);

	printf("-");

	if (GodzinaDo > 9 && MinutaDo > 9)
		printf("%d:%d\n", GodzinaDo, MinutaDo);
	else if (GodzinaDo>9 && MinutaDo<10)
		printf("%d:0%d\n", GodzinaDo, MinutaDo);
	else if (GodzinaDo<10 && MinutaDo>9)
		printf("0%d:%d\n", GodzinaDo, MinutaDo);
	else
		printf("0%d:0%d\n", GodzinaDo, MinutaDo);

	return;
}

void WyswietlRezerwacje(Rezerwacja*rezerwacja)
{
	if (rezerwacja == NULL)
		return;


	WyswietlGodzine(rezerwacja->GodzinaOd, rezerwacja->GodzinaDo, rezerwacja->MinutaOd, rezerwacja->MinutaDo);
	return;
}

void WyswietlKlienta(Klient*klient)
{
	if (klient == NULL)
		return;

	printf("Imie:%s\n", klient->Imie);
	printf("Nazwisko:%s\n", klient->Nazwisko);
	printf("Numer telefonu:%d\n", klient->NumerTelefonu);
	printf("Rodzaj rezerwacji:%s\n", klient->RodzajRezerwacji);

	return;
}

void WyswietlStolik(Stolik*stolik)
{

	printf("Numer stolika:%d\n", stolik->NumerStolika);
	printf("Liczba miejsc:%d\n", stolik->LiczbaMiejsc);
	return;
}

void WyswietlDzien(Dzien*dzien)
{
	WyswietlDate(dzien->Rok, dzien->Miesiac, dzien->Dzien);
	return;
}

void WyswietlWstep(void)
{
	printf("----------------------------------\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("System rezerwacji stolikow\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("----------------------------------\n");

	return;
}

void WyswietlDostepneStoliki(void)
{
	int stoliki[10] = { 2,2,2,2,2,3,3,3,4,4 };

	printf("DOSTEPNE STOLIKI\n");
	printf("---------------------\n");

	for (int i = 0; i < 10; i++)
	{
		printf("Numer stolika:%d\n", i + 1);
		printf("Liczba miejsc:%d\n", stoliki[i]);
		printf("---------------------\n");
	}

	return;
}




void WstawStoliki(Stolik**stolik)
{


	int stoliki[10] = { 2,2,2,2,2,3,3,3,4,4 };


	(*stolik) = malloc(sizeof(Stolik));
	(*stolik)->LiczbaMiejsc = stoliki[9];
	(*stolik)->NumerStolika = 10;
	(*stolik)->NastepnyStolik = NULL;
	(*stolik)->PoprzedniStolik = NULL;
	(*stolik)->Rezerwacja = NULL;



	for (int i = 8; i >= 0; i--)

	{
		Stolik*nowy = malloc(sizeof(Stolik));
		nowy->Rezerwacja = NULL;
		nowy->PoprzedniStolik = NULL;
		nowy->LiczbaMiejsc = stoliki[i];
		nowy->NumerStolika = i + 1;
		nowy->NastepnyStolik = (*stolik);
		(*stolik)->PoprzedniStolik = nowy;
		(*stolik) = nowy;
	}

	return;
}

void WstawRezerwacje(Rezerwacja**rezerwacja, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo)
{
	if ((*rezerwacja) == NULL)
	{
		(*rezerwacja) = malloc(sizeof(Rezerwacja));
		(*rezerwacja)->GodzinaDo = GodzinaDo;
		(*rezerwacja)->GodzinaOd = GodzinaOd;
		(*rezerwacja)->MinutaOd = MinutaOd;
		(*rezerwacja)->MinutaDo = MinutaDo;
		(*rezerwacja)->NastepnaRezerwacja = NULL;
		(*rezerwacja)->PoprzedniaRezerwacja = NULL;
		(*rezerwacja)->Klient = NULL;
		return;
	}

	Rezerwacja*nowa = malloc(sizeof(Rezerwacja));
	nowa->GodzinaDo = GodzinaDo;
	nowa->GodzinaOd = GodzinaOd;
	nowa->Klient = NULL;
	nowa->MinutaDo = MinutaDo;
	nowa->MinutaOd = MinutaOd;
	nowa->PoprzedniaRezerwacja = NULL;
	nowa->NastepnaRezerwacja = (*rezerwacja);
	(*rezerwacja)->PoprzedniaRezerwacja = nowa;
	(*rezerwacja) = nowa;
	return;
}

void WstawKlienta(Klient**klient, char*Imie, char*Nazwisko, int NumerTelefonu, char*RodzajRezerwacji)
{

	if ((*klient) == NULL)
	{
		(*klient) = malloc(sizeof(Klient));
		(*klient)->NumerTelefonu = NumerTelefonu;
		(*klient)->Imie = Imie;
		(*klient)->Nazwisko = Nazwisko;
		(*klient)->RodzajRezerwacji = RodzajRezerwacji;
		return;
	}

	return;
}

void WstawDzien(Dzien**dzien, int rr, int mm, int dd)
{
	if ((*dzien) == NULL)
	{
		(*dzien) = malloc(sizeof(Rezerwacja));
		(*dzien)->Dzien = dd;
		(*dzien)->Miesiac = mm;
		(*dzien)->Rok = rr;
		(*dzien)->Stoliki = NULL;
		(*dzien)->NastepnyDzien = NULL;
		(*dzien)->PoprzedniDzien = NULL;
		return;
	}

	Dzien*nowy = malloc(sizeof(Dzien));
	nowy->Dzien = dd;
	nowy->Miesiac = mm;
	nowy->Rok = rr;
	nowy->Stoliki = NULL;
	nowy->PoprzedniDzien = NULL;
	nowy->NastepnyDzien = (*dzien);
	(*dzien)->PoprzedniDzien = nowy;
	(*dzien) = nowy;

	return;
}





void UsunKlienta(Klient**klient)
{
	if ((*klient) == NULL)
		return;

	free((*klient)->Imie);
	free((*klient)->Nazwisko);
	free((*klient)->RodzajRezerwacji);
	free((*klient));
	return;
}

void UsunWybranaRezerwacje(Rezerwacja**rezerwacja, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo)
{
	if ((*rezerwacja) == NULL)
		return;


	Rezerwacja*pomoc = (*rezerwacja);

	while (pomoc != NULL)
	{
		if ((pomoc->GodzinaOd == GodzinaOd) && (pomoc->GodzinaDo == GodzinaDo) && (pomoc->MinutaOd == MinutaOd) && (pomoc->MinutaDo == MinutaDo))
		{
			if (pomoc->PoprzedniaRezerwacja != NULL)
				pomoc->PoprzedniaRezerwacja->NastepnaRezerwacja = pomoc->NastepnaRezerwacja;
			else
				(*rezerwacja) = (*rezerwacja)->NastepnaRezerwacja;
			if (pomoc->NastepnaRezerwacja != NULL)
				pomoc->NastepnaRezerwacja->PoprzedniaRezerwacja = pomoc->PoprzedniaRezerwacja;

			free(pomoc);
			return;
		}

		pomoc = pomoc->NastepnaRezerwacja;
	}

	return;
}

void UsunStoliki(Stolik**stolik)
{
	if ((*stolik) == NULL)
		return;

	Stolik*pomoc = (*stolik);
	while (pomoc != NULL)
	{
		(*stolik) = (*stolik)->NastepnyStolik;
		free(pomoc);
		pomoc = (*stolik);
	}

	return;
}

void UsunWybranyDzien(Dzien**dzien, int rr, int mm, int dd)
{
	if ((*dzien) == NULL)
		return;

	Dzien*pomoc = (*dzien);

	while (pomoc != NULL)
	{
		if ((pomoc->Rok == rr) && (pomoc->Miesiac == mm) && (pomoc->Dzien == dd))
		{
			if (pomoc->PoprzedniDzien != NULL)
				pomoc->PoprzedniDzien->NastepnyDzien = pomoc->NastepnyDzien;
			else
				(*dzien) = (*dzien)->NastepnyDzien;
			if (pomoc->NastepnyDzien != NULL)
				pomoc->NastepnyDzien->PoprzedniDzien = pomoc->PoprzedniDzien;

			free(pomoc);
			return;
		}
		pomoc = pomoc->NastepnyDzien;
	}

	return;
}

void UsunWszystkieRezerwacje(Rezerwacja**rezerwacja)
{
	if (rezerwacja == NULL)
		return;

	Rezerwacja*pomoc = (*rezerwacja);

	while ((*rezerwacja) != NULL)
	{
		(*rezerwacja) = (*rezerwacja)->NastepnaRezerwacja;
		free(pomoc);
		pomoc = (*rezerwacja);
	}

	return;
}





void ZapisDoPliku(Dzien*dzien,char*NazwaPliku)
{
	FILE*plik;

	if (dzien == NULL)
	{
		if (remove(NazwaPliku) == 0)
			return;
	}

	if ((fopen_s(&plik,NazwaPliku, "w")) != 0)
		return;

	Dzien*DniPomoc = dzien;
	Stolik*StolikiPomoc = DniPomoc->Stoliki;
	Rezerwacja*RezerwacjePomoc = StolikiPomoc->Rezerwacja;


	while (DniPomoc != NULL)
	{
		StolikiPomoc = DniPomoc->Stoliki;

		while (StolikiPomoc != NULL)
		{
			RezerwacjePomoc = StolikiPomoc->Rezerwacja;

			while (RezerwacjePomoc != NULL)
			{


				fprintf(plik, "%d ", DniPomoc->Rok);
				fprintf(plik, "%d ", DniPomoc->Miesiac);
				fprintf(plik, "%d ", DniPomoc->Dzien);
				fprintf(plik, "%d ", StolikiPomoc->NumerStolika);
				fprintf(plik, "%d ", RezerwacjePomoc->GodzinaDo);
				fprintf(plik, "%d ", RezerwacjePomoc->GodzinaOd);
				fprintf(plik, "%d ", RezerwacjePomoc->MinutaDo);
				fprintf(plik, "%d ", RezerwacjePomoc->MinutaOd);
				fprintf(plik, "%s ", RezerwacjePomoc->Klient->Imie);
				fprintf(plik, "%s ", RezerwacjePomoc->Klient->Nazwisko);
				fprintf(plik, "%d ", RezerwacjePomoc->Klient->NumerTelefonu);
				fprintf(plik, "%s\n", RezerwacjePomoc->Klient->RodzajRezerwacji);

				RezerwacjePomoc = RezerwacjePomoc->NastepnaRezerwacja;
			}
			StolikiPomoc = StolikiPomoc->NastepnyStolik;
		}
		DniPomoc = DniPomoc->NastepnyDzien;
	}

	fclose(plik);
	return;
}

void WyswietlRezerwacjeWOkreslonymDniuAdministrator(Dzien*dzien, int rr, int mm, int dd)
{
	if (PoprawnoscDaty(rr, mm, dd) == 0)
	{
		printf("Data jest niepoprawna\n");
		_getch();
		return;
	}

	if (dzien == NULL)
	{
		printf("Brak rezerwacji w okreslonym dniu\n");
		_getch();
		return;
	}

	Dzien*pomoc = dzien;
	Dzien*SzukanyDzien = SzukajDnia(pomoc, rr, mm, dd);

	if (SzukanyDzien == NULL)
	{
		printf("Brak rezerwacji w okreslonym dniu\n");
		_getch();
		return;
	}


	WyswietlDzien(SzukanyDzien);

	Stolik*pomoc1 = SzukanyDzien->Stoliki;
	Rezerwacja*pomoc2 = SzukanyDzien->Stoliki->Rezerwacja;

	while (pomoc1 != NULL)
	{
		printf("-----------------------\n");
		WyswietlStolik(pomoc1);

		pomoc2 = pomoc1->Rezerwacja;

		if (pomoc2 == NULL)
		{
			printf("\n");
			printf("Brak rezerwacji\n");
		}


		while (pomoc2 != NULL)
		{
			printf("\n");
			WyswietlRezerwacje(pomoc2);
			WyswietlKlienta(pomoc2->Klient);
			printf("\n");


			pomoc2 = pomoc2->NastepnaRezerwacja;
		}

		pomoc1 = pomoc1->NastepnyStolik;

	}

	return;
}

void WstawRezerwacjeWOkreslonymDniuUzytkownik(Dzien**dzien, int rr, int mm, int dd, int NumerStolika, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo, char*Imie, char*Nazwisko, int NumerTelefonu, char*RodzajRezerwacji)
{
	int a = 0;

	if (PoprawnoscDaty(rr, mm, dd) == 0)
	{
		printf("Bledna data\n");
		_getch();
		return;
	}

	Dzien*SzukanyDzien = SzukajDnia((*dzien), rr, mm, dd);

	if (SzukanyDzien == NULL)
	{
		WstawDzien(&(*dzien), rr, mm, dd);
		SzukanyDzien = SzukajDnia((*dzien), rr, mm, dd);
		WstawStoliki(&(SzukanyDzien->Stoliki));
		a = 1;
	}

	if (PoprawnoscStolika(NumerStolika) == 0)
	{
		printf("Bledny numer stolika\n");


		if (a == 1)
		{
			UsunStoliki(&(SzukanyDzien->Stoliki));
			UsunWybranyDzien(&(*dzien), rr, mm, dd);
		}

		_getch();
		return;
	}

	Stolik*SzukanyStolik = SzukajStolika(SzukanyDzien->Stoliki, NumerStolika);

	if (PoprawnoscGodziny(GodzinaOd, GodzinaDo, MinutaOd, MinutaDo) == 0)
	{
		printf("Bledna godzina\n");


		if (a == 1)
		{
			UsunStoliki(&(SzukanyDzien->Stoliki));
			UsunWybranyDzien(&(*dzien), rr, mm, dd);
		}

		_getch();
		return;
	}


	if (KolizjaRezerwacji(SzukanyStolik->Rezerwacja, GodzinaOd, GodzinaDo, MinutaOd, MinutaDo) == 1)
	{
		printf("Kolizja rezerwacji\n");


		if (a == 1)
		{
			UsunStoliki(&(SzukanyDzien->Stoliki));
			UsunWybranyDzien(&(*dzien), rr, mm, dd);
		}

		_getch();
		return;
	}

	WstawRezerwacje(&(SzukanyStolik->Rezerwacja), GodzinaOd, GodzinaDo, MinutaOd, MinutaDo);
	Rezerwacja*SzukanaRezerwawcja = SzukajRezerwacji(SzukanyStolik->Rezerwacja, GodzinaOd, GodzinaDo, MinutaOd, MinutaDo);

	if (PoprawnoscNumeruTelefonu(NumerTelefonu) == 0)
	{
		printf("Bledny numer telefonu\n");


		UsunWybranaRezerwacje(&(SzukanyStolik->Rezerwacja), GodzinaOd, GodzinaDo, MinutaOd, MinutaDo);

		if (a == 1)
		{
			UsunStoliki(&(SzukanyDzien->Stoliki));
			UsunWybranyDzien(&(*dzien), rr, mm, dd);
		}

		_getch();
		return;
	}

	WstawKlienta(&(SzukanaRezerwawcja->Klient), Imie, Nazwisko, NumerTelefonu, RodzajRezerwacji);
	system("cls");
	printf("Dokonano rezerwacji!\n");
	Sleep(3000);

	return;
}

void WyswietlRezerwacjeWOkreslonymDniuUzytkownik(Dzien*dzien, int rr, int mm, int dd)
{
	if (PoprawnoscDaty(rr, mm, dd) == 0)
	{
		printf("Data jest niepoprawna\n");
		_getch();
		return;
	}

	if (dzien == NULL)
	{
		printf("Brak rezerwacji w okreslonym dniu\n");
		_getch();
		return;
	}

	Dzien*SzukanyDzien = SzukajDnia(dzien, rr, mm, dd);

	if (SzukanyDzien == NULL)
	{
		printf("Brak rezerwacji w okreslonym dniu\n");
		_getch();
		return;
	}


	WyswietlDzien(SzukanyDzien);

	Stolik*pomoc1 = SzukanyDzien->Stoliki;
	Rezerwacja*pomoc2 = SzukanyDzien->Stoliki->Rezerwacja;

	while (pomoc1 != NULL)
	{
		printf("-----------------------\n");
		WyswietlStolik(pomoc1);

		pomoc2 = pomoc1->Rezerwacja;


		if (pomoc2 == NULL)
		{
			printf("\n");
			printf("Brak rezerwacji\n");
		}

		while (pomoc2 != NULL)
		{
			printf("\n");
			WyswietlRezerwacje(pomoc2);
			printf(" \n");

			pomoc2 = pomoc2->NastepnaRezerwacja;
		}


		pomoc1 = pomoc1->NastepnyStolik;

	}

	return;
}

void UsunWybranaRezerwacjeAdministrator(Dzien**dzien, int rr, int mm, int dd, int NumerStolika, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo)
{
	Dzien*SzukanyDzien = SzukajDnia((*dzien), rr, mm, dd);

	if (SzukanyDzien == NULL)
	{
		printf("Blednie podany dzien\n");
		_getch();
		return;
	}

	if (PoprawnoscStolika(NumerStolika) == 0)
	{
		printf("Blednie podany numer stolika\n");
		_getch();
		return;
	}

	Stolik*SzukanyStolik = SzukajStolika(SzukanyDzien->Stoliki, NumerStolika);

	if (SzukanyStolik == NULL)
	{
		printf("Blednie podany numer stolika\n");
		_getch();
		return;
	}

	Rezerwacja*SzukanaRezerwacja = SzukajRezerwacji(SzukanyStolik->Rezerwacja, GodzinaOd, GodzinaDo, MinutaOd, MinutaDo);

	if (SzukanaRezerwacja == NULL)
	{
		printf("Nie ma takiej godziny rezerwacji\n");
		_getch();
		return;
	}

	UsunKlienta(&(SzukanaRezerwacja->Klient));
	UsunWybranaRezerwacje(&SzukanyStolik->Rezerwacja, GodzinaOd, GodzinaDo, MinutaOd, MinutaDo);

	Stolik*pomoc = SzukanyDzien->Stoliki;
	int licznik = 0;

	while (pomoc != NULL)
	{
		if (pomoc->Rezerwacja == NULL)
			licznik = licznik + 1;

		pomoc = pomoc->NastepnyStolik;
	}

	if (licznik == 10)
	{
		UsunStoliki(&(SzukanyDzien->Stoliki));
		UsunWybranyDzien(&(*dzien), rr, mm, dd);
	}

	system("cls");
	printf("Rezerwacja zostala usunieta!\n");
	Sleep(3000);

	return;
}

void UsunWszystkieRezerwacjeAdministrator(Dzien**dzien)
{
	if ((*dzien) == NULL)
	{
		printf("Brak rezerwacji do usuniecia\n");
		_getch();
		return;
	}

	Dzien*DniPomoc = (*dzien);
	Stolik*StolikiPomoc = DniPomoc->Stoliki;
	Rezerwacja*RezerwacjePomoc = StolikiPomoc->Rezerwacja;


	while (DniPomoc != NULL)
	{
		StolikiPomoc = DniPomoc->Stoliki;

		while (StolikiPomoc != NULL)
		{
			UsunWszystkieRezerwacje(&(StolikiPomoc->Rezerwacja));
			StolikiPomoc = StolikiPomoc->NastepnyStolik;
		}

		UsunStoliki(&(DniPomoc->Stoliki));
		(*dzien) = (*dzien)->NastepnyDzien;
		free(DniPomoc);
		DniPomoc = (*dzien);
	}

	return;
}

void UsunWszystkieRezerwacjeWOkreslonymDniuAdministrator(Dzien**dzien, int rr, int mm, int dd)
{
	if ((*dzien) == NULL)
	{
		printf("Brak rezerwacji do usuniecia\n");
		_getch();
		return;
	}

	Dzien*DniPomoc = SzukajDnia((*dzien), rr, mm, dd);

	if (DniPomoc == NULL)
	{
		printf("Nie znaleziono takiego dnia\n");
		_getch();
		return;
	}

	Stolik*StolikiPomoc = DniPomoc->Stoliki;
	Rezerwacja*RezerwacjePomoc = StolikiPomoc->Rezerwacja;


	while (StolikiPomoc != NULL)
	{
		UsunWszystkieRezerwacje(&(StolikiPomoc->Rezerwacja));     //cos nie tak z ta funkcja????
		StolikiPomoc = StolikiPomoc->NastepnyStolik;
	}

	UsunStoliki(&(DniPomoc->Stoliki));
	UsunWybranyDzien(&(*dzien), rr, mm, dd);

	printf("Wybrana rezerwacja zostala usunieta!\n");
	Sleep(3000);
	return;
}

void OdtworzStruktureZPliku(Dzien**dzien,char*NazwaPliku)
{
	FILE*plik;

	if ((fopen_s(&plik,NazwaPliku, "r")) != 0)
		return;

	int rr; int mm; int dd;

	int GodzOd; int MinutaOd;
	int GodzDo; int MinutaDo;

	char*Imie;  char*Nazwisko;
	int NumerTelefonu;  int NumerStolika;
	char*RodzajRezerwacji;


	fseek(plik, 0, SEEK_END);

	if (ftell(plik) == 0)
		return;

	fseek(plik, 0, SEEK_SET);


	while (fscanf(plik, "%d", &rr) != EOF)
	{

		Imie = malloc(50);
		Nazwisko = malloc(50);
		RodzajRezerwacji = malloc(50);

		fscanf(plik, "%d", &mm);
		fscanf(plik, "%d", &dd);
		fscanf(plik, "%d", &NumerStolika);
		fscanf(plik, "%d", &GodzDo);
		fscanf(plik, "%d", &GodzOd);
		fscanf(plik, "%d", &MinutaDo);
		fscanf(plik, "%d", &MinutaOd);
		fscanf(plik, "%s", Imie);
		fscanf(plik, "%s", Nazwisko);
		fscanf(plik, "%d", &NumerTelefonu);
		fscanf(plik, "%s", RodzajRezerwacji);

		Dzien*SzukanyDzien = SzukajDnia((*dzien), rr, mm, dd);

		if (SzukanyDzien == NULL)
		{
			WstawDzien(&(*dzien), rr, mm, dd);
			SzukanyDzien = SzukajDnia((*dzien), rr, mm, dd);
		}

		WstawStoliki(&(SzukanyDzien->Stoliki));

		Stolik*SzukanyStolik = SzukajStolika(SzukanyDzien->Stoliki, NumerStolika);

		WstawRezerwacje(&(SzukanyStolik->Rezerwacja), GodzOd, GodzDo, MinutaOd, MinutaDo);

		Rezerwacja*SzukanaRezerwacja = SzukajRezerwacji(SzukanyStolik->Rezerwacja, GodzOd, GodzDo, MinutaOd, MinutaDo);

		WstawKlienta(&(SzukanaRezerwacja->Klient), Imie, Nazwisko, NumerTelefonu, RodzajRezerwacji);
	}

	fclose(plik);
	return;
}

int WyswietlDniWKtorychRezerwacjaAdministrator(Dzien*dzien)
{
	if (dzien == NULL)
	{
		printf("Brak rezerwacji\n");
		_getch();
		return 0;
	}

	Dzien*pomoc = dzien;

	while (pomoc != NULL)
	{
		WyswietlDate(pomoc->Rok, pomoc->Miesiac, pomoc->Dzien);
		pomoc = pomoc->NastepnyDzien;
	}

	return 1;
}

int Wyswietl(Dzien*dzien, WskNaFunkcje funkcja)
{
	return funkcja(dzien);
}

int Menu(int argc, char*argv[])
{
	Dzien*dzien = NULL;
	
	OdtworzStruktureZPliku(&dzien,argv[1]);

	char znak;

	int Wybor = 9;

	int Rok; int Miesiac; int Dzien;

	int GodzOd; int MinutaOd;
	int GodzDo; int MinutaDo;

	char*Imie = malloc(50);  char*Nazwisko = malloc(50);
	int NumerTelefonu;  int NumerStolika;
	char*RodzajRezerwacji = malloc(50);

	do
	{
		system("cls");

		WyswietlWstep();
		printf("%s", argv[1]);
		printf("1.Uzytkownik\n");
		printf("2.Administrator\n");
		printf("0.Zakoncz\n");
		scanf("%c", &znak);
		

		if (isdigit(znak) == 0)
			continue;

		Wybor = znak - '0';

		switch (Wybor)
		{
		case 1:

			system("cls");
			WyswietlWstep();
			printf("1.Wyswietl dostepne stoliki\n");
			printf("2.Wyswietl rezerwacje w okreslonym dniu\n");
			printf("3.Dokonaj rezerwacji\n");
			printf("0.Zakoncz\n");
			
			scanf("%c", &znak);
			scanf("%c", &znak);

			if (isdigit(znak) == 0)
				break;

			Wybor = znak - '0';
			
			switch (Wybor)
			{

			case 1:

				system("cls");
				WyswietlDostepneStoliki();
				_getch();
				break;

			case 2:

				system("cls");
				printf("Podaj dzien:");
				scanf("%d", &Dzien);
				system("cls");
				printf("Podaj miesiac:");
				scanf("%d", &Miesiac);
				system("cls");
				printf("Podaj rok:");
				scanf("%d", &Rok);
				system("cls");
				WyswietlRezerwacjeWOkreslonymDniuUzytkownik(dzien, Rok, Miesiac, Dzien);
				_getch();
				break;


			case 3:

				system("cls");
				printf("Podaj dzien:");
				scanf("%d", &Dzien);
				system("cls");
				printf("Podaj miesiac:");
				scanf("%d", &Miesiac);
				system("cls");
				printf("Podaj rok:");
				scanf("%d", &Rok);
				system("cls");
				printf("Podaj od ktorej godziny i minuty\n");
				printf("Godzina:");  scanf("%d", &GodzOd);
				printf("Minuta:");   scanf("%d", &MinutaOd);
				system("cls");
				printf("Podaj do ktorej godziny i minuty\n");
				printf("Godzina:");  scanf("%d", &GodzDo);
				printf("Minuta:");   scanf("%d", &MinutaDo);
				system("cls");
				printf("Podaj numer stolika ktory chcesz zarezerwowac:");
				scanf("%d", &NumerStolika);
				system("cls");
				printf("Podaj Imie:");
				scanf("%s", Imie);
				system("cls");
				printf("Podaj Nazwisko:");
				scanf("%s", Nazwisko);
				system("cls");
				printf("Podaj rodzaj rezerwacji:");
				scanf("%s", RodzajRezerwacji);
				system("cls");
				printf("Podaj numer telefonu:");
				scanf("%d", &NumerTelefonu);
				system("cls");
				WstawRezerwacjeWOkreslonymDniuUzytkownik(&dzien, Rok, Miesiac, Dzien, NumerStolika, GodzOd, GodzDo, MinutaOd, MinutaDo, Imie, Nazwisko, NumerTelefonu, RodzajRezerwacji);
				ZapisDoPliku(dzien,argv[1]);
				break;

			case 0:

				UsunWszystkieRezerwacjeAdministrator(&dzien);
				free(Imie); free(Nazwisko); free(RodzajRezerwacji);
				return 0;

			default:

				system("cls");
				break;

			}

			break;

		case 2:

			system("cls");
			WyswietlWstep();
			printf("1.Wyswietl rezerwacje w okreslonym dniu\n");
			printf("2.Usun wybrana rezerwacje\n");
			printf("3.Usun wszystkie rezerwacje\n");
			printf("4.Usun wszystkie rezerwacje w okreslonym dniu\n");
			printf("5.Wyswietl dni w ktorych wystepuja rezerwacje\n");
			printf("0.Zakoncz\n");

			scanf("%c", &znak);
			scanf("%c", &znak);

			if (isdigit(znak) == 0)
				break;

			Wybor = znak - '0';

			switch (Wybor)
			{
			case 1:

				system("cls");
				printf("Podaj dzien:");
				scanf("%d", &Dzien);
				system("cls");
				printf("Podaj miesiac:");
				scanf("%d", &Miesiac);
				system("cls");
				printf("Podaj rok:");
				scanf("%d", &Rok);
				system("cls");
				WyswietlRezerwacjeWOkreslonymDniuAdministrator(dzien, Rok, Miesiac, Dzien);
				_getch();
				break;

			case 2:

				system("cls");
				printf("Podaj dzien:");
				scanf("%d", &Dzien);
				system("cls");
				printf("Podaj miesiac:");
				scanf("%d", &Miesiac);
				system("cls");
				printf("Podaj rok:");
				scanf("%d", &Rok);
				system("cls");
				printf("Podaj od ktorej godziny i minuty\n");
				printf("Godzina:");  scanf("%d", &GodzOd);
				printf("Minuta:");   scanf("%d", &MinutaOd);
				system("cls");
				printf("Podaj do ktorej godziny i minuty\n");
				printf("Godzina:");  scanf("%d", &GodzDo);
				printf("Minuta:");   scanf("%d", &MinutaDo);
				system("cls");
				printf("Podaj numer stolika:");
				scanf("%d", &NumerStolika);
				system("cls");
				UsunWybranaRezerwacjeAdministrator(&dzien, Rok, Miesiac, Dzien, NumerStolika, GodzOd, GodzDo, MinutaOd, MinutaDo);
				ZapisDoPliku(dzien,argv[1]);
				break;

			case 3:

				system("cls");
				UsunWszystkieRezerwacjeAdministrator(&dzien);
				printf("Wszystkie rezerwacje zostaly usuniete!\n");
				Sleep(3000);
				ZapisDoPliku(dzien,argv[1]);
				break;

			case 4:

				system("cls");
				printf("Podaj dzien:");
				scanf("%d", &Dzien);
				system("cls");
				printf("Podaj miesiac:");
				scanf("%d", &Miesiac);
				system("cls");
				printf("Podaj rok:");
				scanf("%d", &Rok);
				system("cls");
				UsunWszystkieRezerwacjeWOkreslonymDniuAdministrator(&dzien, Rok, Miesiac, Dzien);
				ZapisDoPliku(dzien,argv[1]);
				break;

			case 5:

				system("cls");
				Wyswietl(dzien, WyswietlDniWKtorychRezerwacjaAdministrator);
				_getch();
				break;

			case 0:

				UsunWszystkieRezerwacjeAdministrator(&dzien);
				free(Imie); free(Nazwisko); free(RodzajRezerwacji);
				return 0;

			default:

				system("cls");
				break;
			}

			break;

		case 0:

			UsunWszystkieRezerwacjeAdministrator(&dzien);
			free(Imie); free(Nazwisko); free(RodzajRezerwacji);
			return 0;

		default:

			system("cls");
			break;
		}

	} while (Wybor != 0);

	return 0;
}






