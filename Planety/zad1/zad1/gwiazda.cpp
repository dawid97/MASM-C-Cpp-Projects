#include "gwiazda.h"

gwiazda::gwiazda()
{

}

gwiazda::gwiazda(int s, string n, int t, int ipw,int pz)
{
	this->setNazwa(n);
	this->setSrednica(s);
	this->setTemperatura(t);
	iloscPlanetWokol = ipw;
	pozostaleZycie = pz;
}


gwiazda::~gwiazda()
{

}

void gwiazda::wypisz()
{
	cout << "gwiazda" << endl;
	cout << "nazwa: " << this->getNazwa() << endl;
	cout << "srednica: " << this->getSrednica() << endl;
	cout << "temperatura: " << this->getTemperatura() << endl;
	cout << "ilosc planet wokol: "<<this->iloscPlanetWokol << endl;
	cout << "pozostale zycie: "<<this->pozostaleZycie << endl;
}

void gwiazda::setIloscPlanetWokol(int ipw)
{
	this->iloscPlanetWokol = ipw;
}

void gwiazda::setPozostaleZycie(int pz)
{
	this->pozostaleZycie = pz;
}

ostream& operator <<(ostream& out, gwiazda& gwiazda)
{
	return out << *dynamic_cast<cialo_niebieskie*> (&gwiazda) << " Pozostalo czasu: " << gwiazda.pozostaleZycie << " Planety dooko³a: " << gwiazda.iloscPlanetWokol << endl;
}

int gwiazda::getIloscPlanetWokol()
{
	return this->iloscPlanetWokol;
}

int gwiazda::getPozostaleZycie()
{
	return this->pozostaleZycie;
}
