#pragma once
#include "gwiazda.h"

enum typPulsara { S, C, D, nieznany };

class pulsar:public gwiazda
{
private:
	int czestotliwoscPulsacji;
	typPulsara TP;
public:
	pulsar();
	pulsar(int s, string n, int t, int ipw, int pz, int cz,typPulsara tp);
	virtual ~pulsar();
	void wypisz();
	friend ostream& operator <<(ostream& out, pulsar& pulsar);
};

