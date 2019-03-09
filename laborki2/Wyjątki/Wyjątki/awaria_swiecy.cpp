#include "awaria_swiecy.h"
#include <iostream>
using namespace std;



awaria_swiecy::awaria_swiecy()
{
	//automatycznie generowany
}


awaria_swiecy::~awaria_swiecy()
{
	//automatycznie generowany
}

void awaria_swiecy::naprawa()
{
	awaria_silnika::naprawa();
	cout << "Rozmiar: " << this->RozmiarKlucza << endl;
}
