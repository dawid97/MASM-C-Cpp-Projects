#include "Keypad.h"
using namespace std;

Keypad::Keypad()
{
	nr = 0;
}

int Keypad::getInput()
{
	cin >> nr;
	return nr;
}