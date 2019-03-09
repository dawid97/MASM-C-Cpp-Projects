//#include "Thelper.h"
//#include<algorithm> //deklaracja typu wyjatkow std::invalid_argument, std::out_of_range
//#include<iostream>
//using namespace std;
//
//
//
//double pomocnik_stringowy::wczytaj_parametr(string tresc_pliku, string slowo)
//{
//	size_t pos = znajdz_slowo_kluczowe(tresc_pliku, slowo);
//	//po sukcesie wczytamy dana stojaca zaraz za znalezionym slowem kluczowym
//	string pomocniczy = tresc_pliku.substr(pos);
//	try
//	{
//		double wartosc =stod(pomocniczy);
//		return wartosc; //zwraca poprawnie wczytana wartosc
//	}
//	catch (std::invalid_argument)
//	{
//		Twyj_blad_wart kapsula;
//		kapsula.wiadomosc = "blad wczytywania wartosci liczbowej po slowie kluczowym: " + slowo;
//		throw kapsula;
//	}
//	catch (std::out_of_range)
//	{
//		Twyj_blad_wart kapsula;
//		kapsula.wiadomosc = "blad: wartosc po slowie kluczowym \"" + slowo + "\"jest za duza jak na typ double";
//		throw kapsula;
//	}
//}
//
//size_t pomocnik_stringowy::znajdz_slowo_kluczowe(string tresc_pliku, string slowo)
//{
//	size_t pozycja = tresc_pliku.find(slowo);
//	if (pozycja != string::npos)
//	{
//		//zwracamy pozycje pierwszego znaku ZA slowem kluczowym
//		return pozycja + slowo.size();
//	}
//	else
//	{
//		Twyj_sl_klucz kapsula;
//		kapsula.wiadomosc = "nie ma slowo kluczowego \'" + slowo + "\' w podanym tekscie.";
//		throw kapsula;
//	}
//}
//
//namespace pomocnik_stringowy
//{
//	double wczytaj_parametr_opcjonalny(string zrodlo, string slowo, double wartosc)
//	{
//		double p = 0;
//		try
//		{
//			p = wczytaj_parametr(zrodlo, slowo);
//		}
//		catch (Twyj_sl_klucz & k)
//		{
//			p = wartosc;
//			cout << "W pliku/stringu nie ma (opcjonalnego) slowa kluczowego'" << slowo << "'\n wiec przyjmuje dla niego wartosc domniemana: " << p << endl;
//		}
//		return p;
//	}//koniec funkcji
//}//koniec zakresu pomocnik_stringowy