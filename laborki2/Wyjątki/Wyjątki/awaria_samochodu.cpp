#include "awaria_samochodu.h"
#include <iostream>
using namespace std;



awaria_samochodu::awaria_samochodu()
{
	//automatycznie generowany
}


awaria_samochodu::~awaria_samochodu()
{
	//automatycznie generowany
}

int awaria_samochodu::getPolisa()
{
	return this->nrPolisy;
}

void awaria_samochodu::naprawa()
{
	cout << "nr Polisy: " << this->nrPolisy << endl;
}
