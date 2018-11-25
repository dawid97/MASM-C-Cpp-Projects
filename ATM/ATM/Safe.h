#pragma once
#include "BankDatabase.h"
#include<string>
constexpr int $$500 = 15;
constexpr int $$200 = 25;
constexpr int $$100 = 35;
constexpr int $$50 = 45;
constexpr int $$20 = 55;

class Safe
{
	int $500, $200, $100, $50, $20;

	void saveToFile();
public:
	Safe();
	void greenAlarm(string banknote);
	void redAlarm(string banknote);
	bool reduceSafe(int amount);
	void czyalarm();
};
