#pragma once
#include<string>
#include<iostream>
using namespace std;
class cialo_niebieskie
{
private:
	int srednica;
	string nazwa;
	static int licznikObiektow;
	int temperatura;

public:
	cialo_niebieskie();
	virtual ~cialo_niebieskie();
	virtual void wypisz() = 0;
	static void wypiszIloscObiektow();
	friend ostream& operator <<(ostream& ekran, cialo_niebieskie& cialoNiebieskie);

	int getSrednica();
	string getNazwa();
	int getTemperatura();

	void setSrednica(int s);
	void setNazwa(string n);
	void setTemperatura(int t);
};

