#pragma once
#include "cialo_niebieskie.h"

class Planeta:public cialo_niebieskie
{
private:
	int liczbaKsiezycy;
public:
	Planeta();
	Planeta(int s,string n,int t,int lk);
	virtual ~Planeta();
	void wypisz();
	friend ostream& operator << (ostream& out, Planeta& planeta);
};

