#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include<conio.h>


int main()
{
	srand(time(NULL));

	std::set<int> three1;

	for (int i = 0; i < 20; i++)
		three1.insert((rand() % 10 + 1));

	for (int x : three1)
		std::cout << x << std::endl;

	std::cout << "---------------------------------" << std::endl;

	std::multiset<int> three2;

	for (int i = 0; i < 20; i++)
		three2.insert((rand() % 10 + 1));

	for (int x : three2)
		std::cout << x << std::endl;


	_getch();
	return 0;
}