#define _CRT_SECURE_NO_WARNINGS

#ifndef _STRUKTURY_H
#define _STRUKTURY_H

typedef struct Klient
{
	char*Imie;
	char*Nazwisko;
	int NumerTelefonu;
	char*RodzajRezerwacji;
}Klient;


typedef struct Rezerwacja
{
	int GodzinaOd, MinutaOd;
	int GodzinaDo, MinutaDo;
	struct Rezerwacja*NastepnaRezerwacja;
	struct Rezerwacja*PoprzedniaRezerwacja;
	struct Klient*Klient;
}Rezerwacja;


typedef struct Stolik
{
	int NumerStolika;
	int LiczbaMiejsc;
	struct Stolik*NastepnyStolik;
	struct Stolik*PoprzedniStolik;
	struct Rezerwacja*Rezerwacja;
}Stolik;


typedef struct Dzien
{
	int Rok, Miesiac, Dzien;
	struct Dzien*NastepnyDzien;
	struct Dzien*PoprzedniDzien;
	struct Stolik*Stoliki;
}Dzien;


#endif 
