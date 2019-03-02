#include "cialo_niebieskie.h"



cialo_niebieskie::cialo_niebieskie()
{
	licznikObiektow++;
}


cialo_niebieskie::~cialo_niebieskie()
{
	licznikObiektow--;
}

void cialo_niebieskie::wypiszIloscObiektow()
{
		cout << "ilosc obiektow cial niebieskich=" << licznikObiektow << endl;	
}

int cialo_niebieskie::licznikObiektow = 0;

ostream& operator <<(ostream& ekran, cialo_niebieskie& cialoNiebieskie)
{
	cout << " Nazwa :" << cialoNiebieskie.nazwa << endl;
	cout << " Srednica: " << cialoNiebieskie.srednica << endl;
	cout<< " Temperatura: " << cialoNiebieskie.temperatura << endl;
	return ekran;
}

int cialo_niebieskie::getSrednica()
{
	return this->srednica;
}

string cialo_niebieskie::getNazwa()
{
	return this->nazwa;
}

int cialo_niebieskie::getTemperatura()
{
	return this->temperatura;
}

void cialo_niebieskie::setSrednica(int s)
{
	this->srednica = s;
}

void cialo_niebieskie::setNazwa(string n)
{
	this->nazwa = n;
}

void cialo_niebieskie::setTemperatura(int t)
{
	this->temperatura = t;
}


