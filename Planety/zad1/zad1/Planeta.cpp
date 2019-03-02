#include "Planeta.h"

Planeta::Planeta()
{

}


Planeta::Planeta(int s, string n, int t, int lk)
{
	this->setSrednica(s);
	this->setNazwa(n);
	this->setTemperatura(t);
	liczbaKsiezycy = lk;
}


Planeta::~Planeta()
{

}

void Planeta::wypisz()
{
	cout << "planeta" << endl;
	cout << "nazwa: "<<this->getNazwa() << endl;
	cout << "liczbaKsiezycy: "<<this->liczbaKsiezycy << endl;
	cout << "srednica: "<<this->getSrednica() << endl;
	cout << "temperatura: "<<this->getTemperatura() << endl;
}

ostream& operator << (ostream& out, Planeta& planeta)
{
	return out << *dynamic_cast<cialo_niebieskie*> (&planeta) << " Liczba ksiezycy: " << planeta.liczbaKsiezycy << endl;
}


