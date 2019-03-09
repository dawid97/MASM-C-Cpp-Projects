#pragma once
#include "awaria_silnika.h"

class awaria_swiecy:public awaria_silnika
{
public:
	int RozmiarKlucza;

public:
	void naprawa();
	awaria_swiecy();
	awaria_swiecy(int nrPolisy, int nrSeryjny, int rozmiarKlucza) :awaria_silnika(nrPolisy, nrSeryjny), RozmiarKlucza(rozmiarKlucza) {};
	virtual ~awaria_swiecy();
};

