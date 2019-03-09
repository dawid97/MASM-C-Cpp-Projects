//#include<iostream>
//#include<conio.h>
//#include<vector>
//
//using namespace std;
//
//
//
//
//int main()
//{
//	// a)
//
//	int rozmiar = 10000000000;
//	double* wsk;
//
//	try
//	{
//		wsk = new double[rozmiar];
//		
//	}
//	catch (bad_alloc& oor)
//	{
//		cout << "przechwycona nieudana rezerwacja: " << oor.what() << endl;
//	}
//
//   //////////////////////////////////////////////////////////////////////////////////////
//
//
//   //  b)
//
//	vector<int> myvector(10);
//
//	try 
//	{
//		
//		myvector.at(20) = 100;      // dodanie wartosci 100 na 20 pozycje w wektorze(wyjscie poza zakres)
//	}
//	catch (const out_of_range& oor)
//	{
//		cout << "Wyjscie poza zakres: " << oor.what() << endl;
//	}
//
//	/////////////////////////////////////////////////////////////////////////////////////
//
//	//  c)
//
//	class Pojazd 
//	{ 
//	public:
//	virtual void funkcja() {} 
//	};
//
//	class Samochod : public Pojazd 
//	{
//
//	};
//
//	
//	try
//	{
//		Pojazd p;
//		Samochod& s = dynamic_cast<Samochod&>(p);
//	}
//	catch (bad_cast& oor)
//	{
//		cout << "Blad rzutowania: " << oor.what() << endl;
//	}
//
//	
//	
//	/////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//	_getch();
//	return 0;
//}