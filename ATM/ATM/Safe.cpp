#include "Safe.h"

fstream & operator>>(fstream & file, TypeOfCash & type)
{
	file.open("Cash.txt", ios::in);
	file >> type.$500 >> type.$200 >> type.$100 >> type.$50 >> type.$20;
	file.close();
	return file;
}

fstream & operator<<(fstream & file, TypeOfCash & type)
{
	file.open("Cash.txt", ios::out);
	file << type.$500 << endl << type.$200 << endl << type.$100 << endl << type.$50 << endl << type.$20;
	file.close();
	return file;
}
	
Safe::Safe()
{
	fstream file;
	file >> type;
}

void Safe::saveSafe()
{
	fstream file;
	file << type;
}

void Safe::redAlarm(string banknote)
{
	fstream file;
	file.open("Alarm.txt", ios::app);
	file << "Red Alarm " << banknote << endl;
	file.close();
}

void Safe::greenAlarm(string banknote)
{
	fstream file;
	file.open("Alarm.txt", ios::app);
	file << "Green Alarm " << banknote << endl;
	file.close();
}

bool Safe::reduceSafe(int amount)
{
	int counter = amount;
	int _500 = 0, _200 = 0, _100 = 0, _50 = 0, _20 = 0;

	while (counter >= 500 && type.$500 > 0)
	{
		_500 += 1;
		counter -= 500;
		type.$500 -= 1;

	}
	while (counter >= 200 && type.$200>0)
	{
		_200 += 1;
		counter -= 200;
		type.$200 -= 1;
	}
	while (counter >= 100 && type.$100>0)
	{
		_100 += 1;
		counter -= 100;
		type.$100 -= 1;
	}
	while (counter >= 50 && type.$50 > 0)
	{
		_50 += 1;
		counter -= 50;
		type.$50 -= 1;
	}
	while (counter >= 20 && type.$20>0)
	{
		_20 += 1;
		counter -= 20;
		type.$20 -= 1;
	}

	if (counter == 0)
	{
		saveSafe();
		return true;
	}
	else
	{
		type.$500 += _500;
		type.$200 += _200;
		type.$100 += _100;
		type.$50 += _50;
		type.$20 += _20;
		return false;
	}
}

void Safe::isAlarm()
{
	ofstream file;
	file.open("Alarm.txt");
	file.close();

	if (type.$500 < $$500 && type.$500>0)
		greenAlarm("500zl");
	if (type.$500 == 0)
		redAlarm("500zl");
	if(type.$200<$$200 && type.$200>0)
		greenAlarm("200zl");
	if (type.$200 == 0)
		redAlarm("200zl");
	if (type.$100 < $$100 && type.$100>0)
		greenAlarm("100zl"); 
	if (type.$100 == 0)
		redAlarm("100zl");
	if (type.$50 < $$50 && type.$50>0)
		greenAlarm("50zl");
	if (type.$50 == 0)
		redAlarm("50zl");
	if (type.$20 < $$20 && type.$20>0)
		greenAlarm("20zl");
	if (type.$20 == 0)
		redAlarm("20zl");
}