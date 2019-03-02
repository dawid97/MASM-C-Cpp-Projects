#include "pulsar.h"

pulsar::pulsar()
{

}


pulsar::pulsar(int s, string n, int t, int ipw, int pz,int cz,typPulsara tp)
{
	this->setNazwa(n);
	this->setSrednica(s);
	this->setTemperatura(t);
	this->setIloscPlanetWokol(ipw);
	this->setPozostaleZycie(pz);
	czestotliwoscPulsacji = cz;
	TP = tp;
}


pulsar::~pulsar()
{

}

void pulsar::wypisz()
{
	cout << "pulsar" << endl;
	cout << "nazwa: " << this->getNazwa() << endl;
	cout << "srednica: " << this->getSrednica() << endl;
	cout << "temperatura: " << this->getTemperatura() << endl;
	cout << "ilosc planet wokol: " << this->getIloscPlanetWokol() << endl;
	cout << "pozostale zycie: " << this->getPozostaleZycie() << endl;
	cout << "czestotliowosc pulsacji: " << this->czestotliwoscPulsacji << endl;

	string tmp;
	switch (this->TP) 
	{
	case 0: {
		tmp = "S";
		break;
	}
	case 1: {
		tmp = "C";
		break;
	}
	case 2: {
		tmp = "D";
		break;
	}
	case 3: {
		tmp = "nieznany";
		break;
	}
	default:
		break;
	}

	cout << "typ pulsara: " << this->TP << endl;
}

ostream& operator <<(ostream& out, pulsar& pulsar)
{
	return out << *dynamic_cast<gwiazda*> (&pulsar) << " Czestotliwosc: " << pulsar.czestotliwoscPulsacji << " Typ pulsara: " << pulsar.TP;
}
