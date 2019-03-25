#include <iostream>
#include <string>
#include <list>
#include <vector>
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

	friend std::ostream& operator<<(std::ostream& screen, const Worker& w);
};

std::ostream& operator<<(std::ostream& screen, const Worker& w)
{
	screen << "Name: " << w.name << " ID: " << w.ID << std::endl;
	return screen;
}

int main()
{
	std::list<Worker> listOfWorkers;

	
	listOfWorkers.push_back(Worker("Dawid",10));
	listOfWorkers.push_back(Worker("Tomek", 11));
	listOfWorkers.push_back(Worker("Paulina", 12));
	listOfWorkers.push_back(Worker("Natalia", 13));

	std::list<Worker>::iterator it;
	it = listOfWorkers.begin();
	it++;
	it++;
	listOfWorkers.insert(it, Worker("Filip",14));
	std::cout << "Size of list: " << listOfWorkers.size() << std::endl;
	
	for (Worker w : listOfWorkers)
		std::cout << w;
	listOfWorkers.clear();

	std::cout << "---------------------------------------" << std::endl;


	std::vector<Worker> vectorOfWorkers;
	std::vector<Worker>::iterator it2;

	vectorOfWorkers.push_back(Worker("Dawid", 10));
	vectorOfWorkers.push_back(Worker("Tomek", 11));
	vectorOfWorkers.push_back(Worker("Paulina", 12));
	vectorOfWorkers.push_back(Worker("Natalia", 13));

	it2 = vectorOfWorkers.begin();
	it2++;
	it2++;
	vectorOfWorkers.insert(it2, Worker("Filip",14));
	std::cout << "Size of vector: " << vectorOfWorkers.size() << std::endl;

	for (Worker w : vectorOfWorkers)
		std::cout << w;
	vectorOfWorkers.clear();

	_getch();
	return 0;
}