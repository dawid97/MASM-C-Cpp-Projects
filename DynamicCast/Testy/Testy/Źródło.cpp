#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <string>
using namespace std;


class TPojazd//klasa musi byc typem polimorficznym
{
public:
	virtual void foo(){} //musi byc co najmniej jedna funkcja wirtualna w klasie bazowej.
};

class TSamochod :public TPojazd
{

};

class TRower :public TPojazd
{

};



int main()
{
	
	TPojazd p;
	TSamochod s;
	TRower r;
	TPojazd*wsk_pojazdu;
	TSamochod*wsk_samochodu;
	

	wsk_pojazdu = &r;//tak wyniknelo z programu

	wsk_samochodu = dynamic_cast<TSamochod*>(wsk_pojazdu);

	if (wsk_samochodu)
	{
		cout << "Pokazywany teraz pojazd jest samochodem" << endl;
	}
	else
	{
		cout << "Blad, bo pokazywanym teraz pojazdem nie byl samochod" << endl;
	}

	
	TPojazd poj;
	TSamochod sam;
	TRower row;

	TPojazd & ref_pojazdu = sam;

	try
	{
		TSamochod ref_samochodu = dynamic_cast<TSamochod&>(ref_pojazdu);
		cout << "Pokazywany pojazd byl samochodem" << endl;
	}
	catch(bad_cast)
	{
		cout << "Blad, teraz pojazdem nie jest samochod" << endl;
	}

	string nazwa = typeid(TSamochod).name(); //uzycie typeid
	cout << nazwa << endl;

	

	_getch();
}