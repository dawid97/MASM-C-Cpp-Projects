#pragma once
#include "awaria_samochodu.h"

class awaria_silnika:public awaria_samochodu 
{
private:
	int nrSeryjny;
public:
	awaria_silnika();
	awaria_silnika(int nrPolisy, int nrSeryjny) :awaria_samochodu(nrPolisy), nrSeryjny(nrSeryjny) {};
	virtual ~awaria_silnika();
	void naprawa();
};

