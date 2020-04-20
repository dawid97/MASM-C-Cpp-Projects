#define _CRT_SECURE_NO_WARNINGS

#ifndef _FUNKCJE_H
#define _FUNKCJE_H

#include "struktury.h"


int PoprawnoscDaty(int rr, int mm, int dd);
int PoprawnoscGodziny(int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo);
int PoprawnoscStolika(int NumerStolika);
int PoprawnoscNumeruTelefonu(int NumerTelefonu);


int KolizjaRezerwacji(Rezerwacja*rezerwacja, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo);


Dzien*SzukajDnia(Dzien*dzien, int rr, int mm, int dd);
Stolik*SzukajStolika(Stolik*stolik, int NumerStolika);
Rezerwacja*SzukajRezerwacji(Rezerwacja*rezerwacja, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo);



void WyswietlDate(int rr, int mm, int dd);
void WyswietlGodzine(int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo);
void WyswietlRezerwacje(Rezerwacja*rezerwacja);
void WyswietlKlienta(Klient*klient);
void WyswietlStolik(Stolik*stolik);
void WyswietlDzien(Dzien*dzien);
void WyswietlWstep(void);
void WyswietlDostepneStoliki(void);



void WstawStoliki(Stolik**stolik);
void WstawRezerwacje(Rezerwacja**rezerwacja, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo);
void WstawKlienta(Klient**klient, char*Imie, char*Nazwisko, int NumerTelefonu, char*RodzajRezerwacji);
void WstawDzien(Dzien**dzien, int rr, int mm, int dd);



void UsunKlienta(Klient**klient);
void UsunWybranaRezerwacje(Rezerwacja**rezerwacja, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo);
void UsunStoliki(Stolik**stolik);
void UsunWybranyDzien(Dzien**dzien, int rr, int mm, int dd);
void UsunWszystkieRezerwacje(Rezerwacja**rezerwacja);


void ZapisDoPliku(Dzien*dzien, char*NazwaPliku);
void WyswietlRezerwacjeWOkreslonymDniuAdministrator(Dzien*dzien, int rr, int mm, int dd);
void WstawRezerwacjeWOkreslonymDniuUzytkownik(Dzien**dzien, int rr, int mm, int dd, int NumerStolika, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo, char*Imie, char*Nazwisko, int NumerTelefonu, char*RodzajRezerwacji);
void WyswietlRezerwacjeWOkreslonymDniuUzytkownik(Dzien*dzien, int rr, int mm, int dd);
void UsunWybranaRezerwacjeAdministrator(Dzien**dzien, int rr, int mm, int dd, int NumerStolika, int GodzinaOd, int GodzinaDo, int MinutaOd, int MinutaDo);
void UsunWszystkieRezerwacjeAdministrator(Dzien**dzien);
void UsunWszystkieRezerwacjeWOkreslonymDniuAdministrator(Dzien**dzien, int rr, int mm, int dd);
void OdtworzStruktureZPliku(Dzien**dzien,char*NazwaPliku);

typedef int ( * WskNaFunkcje)(Dzien*);
int WyswietlDniWKtorychRezerwacjaAdministrator(Dzien*dzien);
int Wyswietl(Dzien*dzien, WskNaFunkcje funkcja);

int Menu(int argc, char*argv[]);
#endif 

