#pragma once
#include "BankDatabase.h"
#include<string>

constexpr int $$500 = 15;
constexpr int $$200 = 25;
constexpr int $$100 = 35;
constexpr int $$50 = 45;
constexpr int $$20 = 55;

struct TypeOfCash
{
	int $500, $200, $100, $50, $20;
};

class Safe
{
	TypeOfCash type;

	void saveSafe();
	void greenAlarm(string banknote);
	void redAlarm(string banknote);
	
public:
	Safe();
	bool reduceSafe(int amount);
	void isAlarm();
};
