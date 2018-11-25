#include "Safe.h"

Safe::Safe()
{
	fstream plik;
	plik.open("cash.txt", ios::in);
	plik>>$500 >> $200>>$100>>$50>>$20;//cos ten plik z nominalami nie dziala xd//no niby dziala ale trzeba dodac grren alarm i red
	plik.close();
}

void Safe::saveToFile()
{
	fstream plik;
	plik.open("cash.txt", ios::out);
	plik << $500 << endl<< $200 <<endl<< $100<<endl << $50<<endl << $20;
	plik.close();
}

void Safe::redAlarm(string banknote)
{
	fstream plik;
	plik.open("alarm.txt", ios::app);
	plik << "Red Alarm " << banknote << endl;
	plik.close();
}

void Safe::greenAlarm(string banknote)
{
	fstream plik;
	plik.open("alarm.txt", ios::app);
	plik << "Green Alarm " << banknote << endl;
	plik.close();
}

bool Safe::reduceSafe(int amount)
{
	int counter = amount;
	int _500 = 0, _200 = 0, _100 = 0, _50 = 0, _20 = 0;

	while (counter >= 500 && $500 > 0)
	{
		_500 += 1;
		counter -= 500;
		$500 -= 1;

	}
	while (counter >= 200 && $200>0)
	{
		_200 += 1;
		counter -= 200;
		$200 -= 1;
	}
	while (counter >= 100 && $100>0)
	{
		_100 += 1;
		counter -= 100;
		$100 -= 1;
	}
	while (counter >= 50 && $50 > 0)
	{
		_50 += 1;
		counter -= 50;
		$50 -= 1;
	}
	while (counter >= 20 && $20>0)
	{
		_20 += 1;
		counter -= 20;
		$20 -= 1;
	}

	if (counter == 0)
	{
		saveToFile();
		return true;
	}
	else
	{
		$500 += _500;
		$200 += _200;
		$100 += _100;
		$50 += _50;
		$20 += _20;
		return false;
	}
}

void Safe::czyalarm()
{
	ofstream plik;
	plik.open("alarm.txt");
	plik.close();

	if ($500 < $$500 && $500>0)
		greenAlarm("500zl");
	if ($500 == 0)
		redAlarm("500zl");
	if($200<$$200 && $200>0)
		greenAlarm("200zl");
	if ($200 == 0)
		redAlarm("200zl");
	if ($100 < $$100 && $100>0)
		greenAlarm("100zl"); 
	if ($100 == 0)
		redAlarm("100zl");
	if ($50 < $$50 && $50>0)
		greenAlarm("50zl");
	if ($50 == 0)
		redAlarm("50zl");
	if ($20 < $$20 && $20>0)
		greenAlarm("20zl");
	if ($20 == 0)
		redAlarm("20zl");
}