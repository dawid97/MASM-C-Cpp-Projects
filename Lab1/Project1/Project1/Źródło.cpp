#include<iostream>
#include<conio.h>
#include<string>



using namespace std;

class Vector3D
{
	double x, y, z;
	static int licznik;

public:
	void setX(double a);
	void setY(double b);
	void setZ(double c);

	double getX(void);
	double getY(void);
	double getZ(void);

	Vector3D() :x(0.0), y(0.0), z(0.0) { licznik++; };
	~Vector3D()
	{
		cout << "obiekt zostal usuniety" << endl;
		licznik--;
	};

	enum rodzaj { VEC_ZERO, VEC_ONE, VEC_RAND };
	Vector3D(rodzaj numer);

	Vector3D(double a, double b, double c) :x(a), y(b), z(c) {};
	Vector3D(const Vector3D&obiekt) :x(obiekt.x), y(obiekt.y), z(obiekt.z) {};
	Vector3D(Vector3D&&obiekt) :x(obiekt.x), y(obiekt.y), z(obiekt.z) {};

	void print();
};

int Vector3D::licznik = 0;

void Vector3D::setX(double a)
{
	x = a;
	return;
}

void Vector3D::setY(double b)
{
	y = b;
	return;
}

void Vector3D::setZ(double c)
{
	z = c;
	return;
}

double Vector3D::getX(void)
{
	return x;
}

double Vector3D::getY(void)
{
	return y;
}

double Vector3D::getZ(void)
{
	return z;
}



Vector3D::Vector3D(rodzaj numer)
{
	if (numer == 0)
	{
		x = y = z = 0.0;
	}
	else if (numer == 1)
	{
		x = y = z = 1.0;
	}
	else if (numer == 2)
	{
		x = rand() % 100;
		y = rand() % 100;
		z = rand() % 100;
	}
}

void Vector3D::print()
{
	cout << "[" << x << "," << y << "," << z << "]" << endl;
}





class LinearSpace
{

	static int rozmiar;
	Vector3D**tablica = new Vector3D*[rozmiar];

public:
	LinearSpace();
	~LinearSpace();
	LinearSpace(const LinearSpace&obiekt);
	LinearSpace(LinearSpace&&obiekt);


	void insertVector1(Vector3D &obiekt);
	void insertVector2(Vector3D *obiekt);

	void insertVector3(double x, double y, double z);
	void insertVector4(Vector3D::rodzaj typ);

	void printSpace();
};

int LinearSpace::rozmiar = 5;



LinearSpace::LinearSpace()
{
	for (int i = 0; i < rozmiar; i++)
		tablica[i] = nullptr;
}

LinearSpace::~LinearSpace()
{
	cout << "przestrzen usunieta" << endl;
	delete[] tablica;
}


LinearSpace::LinearSpace(const LinearSpace&obiekt)
{
	for (int i = 0; i < rozmiar; i++)
		obiekt.tablica[i] = tablica[i];
}

LinearSpace::LinearSpace(LinearSpace&&obiekt)
{
	for (int i = 0; i < rozmiar; i++)
		obiekt.tablica[i] = tablica[i];
}


void LinearSpace::insertVector1(Vector3D &obiekt)
{
	for (int i = 0; i < rozmiar; i++)
	{
		if (tablica[i] == nullptr)
		{
			tablica[i] = &obiekt;
			return;
		}
	}

	cout << "Nie ma miejsca na dodanie wektora" << endl;

}

void LinearSpace::insertVector2(Vector3D *obiekt)
{
	for (int i = 0; i < rozmiar; i++)
	{
		if (tablica[i] == nullptr)
		{
			tablica[i] = obiekt;
			return;
		}
	}

	cout << "Nie ma miejsca na dodanie wektora" << endl;
}



void LinearSpace::insertVector3(double a, double b, double c)
{

	Vector3D* wsk = new Vector3D(a, b, c);


	for (int i = 0; i < rozmiar; i++)
	{
		if (tablica[i] == nullptr)
		{

			tablica[i] = wsk;
			return;
		}
	}


	cout << "Nie ma miejsca na dodanie wektora" << endl;
}

void LinearSpace::insertVector4(Vector3D::rodzaj typ)
{
	Vector3D* wsk = new Vector3D(typ);

	for (int i = 0; i < rozmiar; i++)
	{
		if (tablica[i] == nullptr)
		{
			tablica[i] = wsk;
			return;
		}
	}

	cout << "Nie ma miejsca na dodanie wektora" << endl;
}



void LinearSpace::printSpace()
{
	int ilosc = 0;

	for (int i = 0; i < rozmiar; i++)
	{
		if (tablica[i] != nullptr)
		{
			(*tablica[i]).Vector3D::print();
			ilosc++;
		}
	}
	cout << "Ilosc wektorow: " << ilosc << endl;
}






int main()
{

	Vector3D vektor(20, 30, 40);


	LinearSpace przestrzen;
	przestrzen.insertVector3(0, 0, 0); //wektor zerowy
	przestrzen.insertVector4(Vector3D::VEC_RAND);  //wektor randomowy

	Vector3D obiekt1(Vector3D::VEC_RAND); //wektor randomowy nie dynamicznie
	przestrzen.insertVector1(obiekt1);

	Vector3D*obiekt2 = new Vector3D(Vector3D::VEC_RAND);  //wektor randomowy dynamicznie
	przestrzen.insertVector2(obiekt2);


	przestrzen.insertVector3(1.78882, 2.12, 1);  //wektor o zadanych wspolrzednych
	przestrzen.insertVector4(Vector3D::VEC_RAND); //6 wektor o randomowych wspolrzednych//blad//

	przestrzen.printSpace();

	cout << "Press any key to continue..." << endl;

	_getch();
	return 0;

}