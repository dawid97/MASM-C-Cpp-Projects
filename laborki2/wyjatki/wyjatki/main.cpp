//#include "Thelper.h"
//#include<iostream>
//#include<conio.h>
//using namespace std;
//
////tresc pliku reprezentowana przez tzw. surowy string
//string parametry_txt = R"(Poczatek pliku z danymi
//                         linijka z jakimis informacjami ogolnymi
//                         beta               45.3
//                         alfa               23
//                         delta              1024
//                         omega             88.2
//                         jota               44.4
//                         flaga_operacji     1
//                         PI                 3.1416
//                       )";
//
//int main()
//{
//	//z tresci stringu parametry_txt(jakby z pliku dyskowego) chcemy przeczytaæ
//	//wartosci odpowiadajace konkretnie nazwanym parametrom
//	double omega = 0;
//	double beta = 0;
//	double nowy_par = 0;
//
//	try
//	{
//		omega = pomocnik_stringowy::wczytaj_parametr(parametry_txt, "omega");
//		cout << "Poprawnie wczytany parametr omega = " << omega << endl;
//
//		beta = PS::wczytaj_parametr(parametry_txt, "beta");
//		cout << "Poprawnie wczytany parametr beta = " << beta << endl;
//	}//koniec bloku try
//	catch (PS::Twyj_sl_klucz & k)
//	{
//		cout << k.wiadomosc << endl;
//		cout << "porada: dodaj to slowo kluczowe (oraz wartosc) do tresci stringu 'parametry_txt'" << endl;
//		_getch();
//		return 0;
//	}
//	catch (PS::Twyj_blad_wart & k)
//	{
//		cout << k.wiadomosc << endl;
//		cout << "porada: popraw zapis liczby po tym slowie kluczowym w tresci stringu 'parametry_txt'" << endl;
//		throw;  //rzuc ponownie ten sam obiekt wyjatku ktory przylecial i zostal zlapany
//	}
//	catch (...) //lapie wszystkie wyjatki
//	{
//		cout << "przechwycono nieznany wyjatek.konczymy program" << endl;
//		throw; //oddajemy ten wyjatek systemowi operacyjnemu
//	}
//
//	cout << "proba przeczytania parametru, ktorego moze nie byc..." << endl;
//	nowy_par = PS::wczytaj_parametr_opcjonalny(parametry_txt, "nowy_par", 22);
//	cout << "Ustalony nowy_par= " << nowy_par << endl;
//
//	auto fun4() -> int;
//	{
//		return 0;
//	}
//
//	//dalsza czesc programu korzystajaca z tych parametrow
//	_getch();
//	return 0;
//}