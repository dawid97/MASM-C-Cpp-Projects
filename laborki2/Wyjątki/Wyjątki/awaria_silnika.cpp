#include "awaria_silnika.h"
#include <iostream>
using namespace std;



awaria_silnika::awaria_silnika()
{
	//automatycznie generowany
}


awaria_silnika::~awaria_silnika()
{
	//automatycznie generowany
}

void awaria_silnika::naprawa()
{
	awaria_samochodu::naprawa();
	cout << "Nr seryjny: " << this->nrSeryjny << endl;
}
