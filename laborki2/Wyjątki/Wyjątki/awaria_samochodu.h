#pragma once
class awaria_samochodu
{
private:
	int nrPolisy;
public:
	int getPolisa();
	virtual void naprawa();
	awaria_samochodu();
	awaria_samochodu(int nrPolisy) :nrPolisy(nrPolisy) {};
	virtual ~awaria_samochodu();
};

