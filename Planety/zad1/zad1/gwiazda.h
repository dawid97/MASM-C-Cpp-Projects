#pragma once
#include "cialo_niebieskie.h"

class gwiazda:public cialo_niebieskie
{
private:
	int pozostaleZycie;
	int iloscPlanetWokol;


public:
	gwiazda();
	gwiazda(int s, string n, int t, int ipw, int pz);
	virtual ~gwiazda();
	void wypisz();
	friend ostream& operator <<(ostream& out, gwiazda& gwiazda);
	void setIloscPlanetWokol(int ipw);
	void setPozostaleZycie(int pz);
	int getIloscPlanetWokol();
	int getPozostaleZycie();
};

