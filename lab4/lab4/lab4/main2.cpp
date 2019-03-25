#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include<conio.h>


class Worker
{
	std::string name;
	int ID;
public:

	Worker(std::string n,int id)
	{
		name = n;
		ID = id;
	}

	friend std::ostream& operator<<(std::ostream& screen, const Worker& w)
	{
		screen << "Name: " << w.name << " ID: " << w.ID << std::endl;
		return screen;
	}

	bool operator<(Worker w)
	{
		if (ID < w.ID)
			return true;
		else
			return false;
	}
};

int main()
{
	std::list<Worker> listOfWorkers;

	listOfWorkers.push_back(Worker("Dawid", 9));
	listOfWorkers.push_back(Worker("Tomek", 1));
	listOfWorkers.push_back(Worker("Paulina", 7));
	listOfWorkers.push_back(Worker("Natalia", 3));
	listOfWorkers.push_back(Worker("Wojtek", 6));

	listOfWorkers.sort();
	for (Worker w : listOfWorkers)
		std::cout << w;

	std::cout << "---------------------------------" << std::endl;

	std::vector<Worker> vectorOfWorkers;
	vectorOfWorkers.push_back(Worker("Dawid", 11));
	vectorOfWorkers.push_back(Worker("Tomek", 9));
	vectorOfWorkers.push_back(Worker("Paulina", 15));
	vectorOfWorkers.push_back(Worker("Natalia", 13));
	vectorOfWorkers.push_back(Worker("Wojtek", 17));


	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (vectorOfWorkers[j] < vectorOfWorkers[i])
				std::swap(vectorOfWorkers[j], vectorOfWorkers[i]);
		}
	}
	std::vector<Worker>::iterator it;
	for (it = vectorOfWorkers.begin(); it < vectorOfWorkers.end(); it++)
		std::cout << *it;
		

	_getch();
	return 0;
}