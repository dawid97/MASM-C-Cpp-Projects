#include<iostream>
#include<conio.h>

using namespace std;

class AwariaSamochodu
{
public:

	virtual void info() { cout << "Awaria Samochodu!!!" << endl; };
	virtual ~AwariaSamochodu() {}; //?
};

class AwariaSilnika:public AwariaSamochodu
{
public:

	void info() { cout << "Awaria Silnika!!!" << endl; };
	virtual ~AwariaSilnika() {};
};
	
	

class AwariaSwiecy:public AwariaSilnika
{
public:

	virtual ~AwariaSwiecy() {};
	void info() { cout << "Awaria Swiecy!!!" << endl; }
};


int main()
{
	AwariaSamochodu* tab[9];

	for (int i = 0; i < 9;) 
	{
		tab[i] = new AwariaSamochodu();
		i++;
		tab[i] = new AwariaSilnika();
		i++;
		tab[i] = new AwariaSwiecy();
		i++;
	}

	cout << typeid(*tab[0]).name() << endl;
	cout << typeid(AwariaSamochodu).name() << endl;

	for (int i = 0; i < 9; i++)
	{
		try
		{
			if (typeid(*tab[i]).name() == typeid(AwariaSamochodu).name())
			{
				throw AwariaSamochodu();
			}

			if (typeid(*tab[i]).name() == typeid(AwariaSilnika).name())
			{
				throw AwariaSilnika(); 
			}

			if (typeid(*tab[i]).name() == typeid(AwariaSwiecy).name())
			{
				throw AwariaSwiecy();
			}
		}
		catch (AwariaSamochodu & e)
		{
			e.info();
		}
		catch (AwariaSwiecy & e)
		{
			e.info();
		}
		catch (AwariaSilnika & e)
		{
			e.info();
		}
	}

	_getch();
	return 0;
}