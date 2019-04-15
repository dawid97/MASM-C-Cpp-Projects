#include<iostream>
#include<conio.h>
#include<vector>
#include<deque>
#include<iterator>
#include<time.h>
#include<algorithm>
#include<numeric>
#include<string>
#include<fstream>

class Klasa
{
	int ID;
	double parametr;
	std::string nazwa;
public:
	Klasa(int i, double d, std::string s)
	{
		ID = i;
		parametr = d;
		nazwa = s;
	}
	friend void wyswietl(std::vector<Klasa> wektor);
	friend bool stringSort(Klasa a, Klasa b);
	std::string getNazwa() { return this->nazwa; }
};

void wyswietl(std::vector<Klasa> wektor)
{
	for (std::vector<Klasa>::iterator it = wektor.begin(); it != wektor.end(); it++)
	{
		std::cout << (*it).ID << " " << (*it).parametr << " " << (*it).nazwa << "\n";
	}
	std::cout << std::endl;
}

void diplayDeque(std::deque<int> myDeque)
{
	for (std::deque<int>::iterator it = myDeque.begin(); it < myDeque.end(); it++)
	{
		if (it == myDeque.end() - 1)
			std::cout << *it << " " << std::endl;
		else
			std::cout << *it << " ";

	}
}

void diplayVector(std::vector<int> myVector)
{
	for (std::vector<int>::iterator it = myVector.begin(); it < myVector.end(); it++)
	{
		if (it == myVector.end() - 1)
			std::cout << *it << " " << std::endl;
		else
			std::cout << *it << " ";

	}
}

bool parzysta(int value)
{
	return (value % 2 == 0);
}

bool stringSort(Klasa a, Klasa b)
{
	return a.nazwa < b.nazwa;
}

int main()
{
	//ITERATORY

	std::vector<int>myVector;

	for (size_t i = 0; i < 10; i++)
		myVector.push_back(i);

	std::vector<int>::iterator it1 = find(myVector.begin(), myVector.end(), 5);
	std::cout << *it1 << std::endl; //5

	std::vector<int>::reverse_iterator it2(it1); //4 przechodzi o jedna pozycje wczesniej
	std::cout << *it2 << std::endl;

	std::vector<int>::iterator it3(it2.base());
	std::cout << *it3 << std::endl; //powrot do podstawowej wartosci (5)

	std::deque<int> myDeque;

	std::front_insert_iterator<std::deque<int>> front(myDeque); //iterator wstawiajacy na poczatek
	std::back_insert_iterator<std::deque<int>> back(myDeque); //iterator wstawiajacy na koniec

	*front = 5; *front = 6; *front = 7; //wstawienie na poczatek
	diplayDeque(myDeque);

	*back = 10; *back = 11; *back = 12; //wstawienie na koniec
	diplayDeque(myDeque);

	std::insert_iterator<std::deque<int>> it(myDeque, myDeque.begin() + 3); //iterator wstawiajacy na 4 pozycje
	*it = 7; //wstawienie liczby "7" na czwarta pozycje
	diplayDeque(myDeque);

	copy(myDeque.begin(), myDeque.end(), front); //skopiowanie calej kolejki i wstawienie na poczatek
	diplayDeque(myDeque);

	//ALGORYTMY

	srand(unsigned int(time(NULL)));

	std::vector<int>vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(rand() % 101); //wstawienie losowych liczb
	

	std::cout << std::count_if(vec.begin(), vec.end(),parzysta) << std::endl; //liczba parzystych liczb
	
	std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl; ////suma poszczegolnych elementow
	diplayVector(vec);

	std::reverse(vec.begin(), vec.end()); //odwrocenie wektora
	diplayVector(vec);


	std::vector<Klasa> vector;
	
	Klasa e1(1, 2.52, "TinkyWinky");
	Klasa e2(2, 3.61, "Dipsy");
	Klasa e3(3, 1.56, "LaaLaa");
	Klasa e4(4, 2.21, "Po");

	vector.push_back(e1);
	vector.push_back(e2);
	vector.push_back(e3);
	vector.push_back(e4);

	std::sort(vector.begin(), vector.end(), stringSort); //sortowanie po nazwie
	
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i].getNazwa();
	std::cout << std::endl << std::endl;


	std::fstream file;
	file.open("piosenka.txt", std::ios::in);
	std::string word;
	std::vector<std::string> words;

	while (!file.eof())
	{
		file >> word;
		if (std::find(words.begin(), words.end(), word) == words.end())
			words.push_back(word);
		
	}
	file.close();

	std::sort(words.begin(), words.end()); //sortowanie wyrazow

	for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::make_heap(words.begin(), words.end());
	int o = 1, o1 = 1;

	std::cout << std::endl;
	for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
	{
		std::cout << *it << " ";
		if (o == o1)
		{
			o = 1;
			o1 = o1 * 2;
			std::cout << std::endl;
		}
		else
			o++;
	}
	std::cout << std::endl;

	if (std::is_heap(words.begin(), words.end()))
		std::cout << "To kopiec\n";
	std::pop_heap(words.begin(), words.end());
	if (std::is_heap(words.begin(), words.end()))
		std::cout << "To kopiec\n";
	
	_getch();
	return 0;
}