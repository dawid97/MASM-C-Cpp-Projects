//#include<iostream>
//#include<conio.h>
//using namespace std;
//double ryzykowna(double promien);
//struct Tblad_ujemnego_promienia
//{};
//
//int main()
//{
//	try                                                                                                  
//	{
//		double wartosc = ryzykowna(5.5);
//		cout << "a) Pole kola = " << wartosc << endl;
//
//		wartosc = ryzykowna(-6);
//		cout << "b) Pole kola = " << wartosc << endl;
//	}
//	catch (Tblad_ujemnego_promienia kapsula)
//	{
//		cout << "Sytuacja bledu - zadany promien nie moze byc ujemny" << endl;
//	}
//	cout << "Dalsze, zwykle instrukcje" << endl;
//
//	_getch();
//	return 0;
//}
//
//double ryzykowna(double r)
//{
//	cout << "obliczamy pole kola o promieniu " << r << endl;
//	if (r >= 0)
//	{
//		return 3.14*r*r;
//	}
//	else
//	{
//		cout << "!!!Rzucenie wyjatku!!!" << endl;
//		Tblad_ujemnego_promienia kapsula;
//		throw kapsula;
//	}
//}