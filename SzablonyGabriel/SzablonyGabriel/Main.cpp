#include<iostream>
#include<conio.h>
#include<string>
#include<vld.h>

constexpr int stepArray = 4;

class NegativIndex
{
	std::string message;
public:
	NegativIndex(std::string m) :message(m){}
	void DisplayMessage()
	{
		std::cout << message << std::endl;
	}
};

class WrongCharacterOrder
{
	std::string message;
public:
	WrongCharacterOrder(std::string m) :message(m) {}
	void DisplayMessage()
	{
		std::cout << message << std::endl;
	}
};

template <class T,int sizeArray>
class Array
{
	T*array;
	int size;
	int counterOfElements;
public:
	Array():size(sizeArray),counterOfElements(0)
	{
		array = new T[size];
	}
	Array(T object):counterOfElements(sizeArray),size(sizeArray)
	{
		array = new T[size];
		for (int i = 0; i < size; i++)
			array[i] = object;
	}
	Array(const Array & pattern):size(pattern.size),counterOfElements(pattern.counterOfElements)
	{
		array = new T[size];
		for (int i = 0; i < counterOfElements; i++)
			array[i] = pattern.array[i];
	}
	void display()
	{
		for (int i = 0; i < counterOfElements; i++)
			std::cout << i + 1 << " element of array is: " << array[i] << std::endl;
	}
	T operator[](int index)
	{
		if (index > counterOfElements-1) //sprawdzic
			throw std::out_of_range("You are out of the array!");

		if (index < 0)
			throw NegativIndex("Index can not be negativ!");

		return array[index];
	}
	~Array()
	{
		delete[] array;
	}
	void Add(T object);
	int getCounterOfElements() { return counterOfElements; }
};

template<class T, int sizeArray> 
void Array<T, sizeArray>::Add(T object)
{
	

	if (counterOfElements+1 > size)
	{
		size += stepArray;
		T* newArray = new T[size];
		for (int i = 0; i < counterOfElements; i++)
			newArray[i] = array[i];

			newArray[counterOfElements] = object;
		delete[] array;
		array = newArray;
	}
	else
		array[counterOfElements] = object;

	counterOfElements++;
}


template<typename T>
T count(T obj1, T obj2)
{
	if (obj1 > obj2)
		return obj1 * obj1 + obj2 * obj2;
	else
		return (obj1 + obj2)*(obj1 + obj2);
}

std::string count(char h1, char h2)
{
	if (h1 > h2)
		throw WrongCharacterOrder("Wrong character order!");
	else
	{
		std::string s;
		for (int i = 0; i < 3; i++)
		{
			s += h1;
			s += h2;
		}
		return s;
	}
}


int count(Array<int, 2> array1, Array<int, 2> array2)
{
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < array1.getCounterOfElements(); i++)
		sum1 += array1[i];

	for (int i = 0; i < array2.getCounterOfElements(); i++)
		sum2 += array2[i];

	if (sum1 > sum2)
		return  sum1 * sum1 + sum2 * sum2;
	else
		return (sum1 + sum2)*(sum1 + sum2);
}


int main()
{

	Array<std::string, 2> array1;
	array1.Add("To");
	array1.Add("jest");
	array1.Add("zadanie");
	array1.Add("na");
	array1.Add("PK4");
	array1.display();

	std::cout << "-------------------------------" << std::endl;

	std::string name = "dawid";
	Array<std::string, 2> array2(name);
	array2.display();

	std::cout << "-------------------------------" << std::endl;

	Array<std::string,2> array3(array1);
	array3.display();

	std::cout << "-------------------------------" << std::endl;

	Array<int, 2> array4;
	array4.Add(10);
	array4.Add(9);
	array4.Add(4);
	array4.Add(3);
	array4.display();

	std::cout << "-------------------------------" << std::endl;

	Array<int, 2> array5;
	array4.Add(1);
	array4.Add(2);
	array4.Add(4);
	array4.Add(7);
	array4.display();

	std::cout << "-------------------------------" << std::endl;

	try {
		std::cout << array1[7] << std::endl;
	}
	catch (NegativIndex e)
	{
		e.DisplayMessage();
	}
	catch (std::out_of_range e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------" << std::endl;


	int a = 3, b = 2;
	std::cout << count(a, b) << std::endl;

	std::cout << "-------------------------------" << std::endl;

	double c = 9.8, d = 3.1;
	std::cout << count(c, d) << std::endl;

	std::cout << "-------------------------------" << std::endl;

	char h1 = 'a', h2 = 'd';

	try {

		std::cout << count(h1, h2) << std::endl;
	}
	catch (WrongCharacterOrder e)
	{
		e.DisplayMessage();
	}

	std::cout << "-------------------------------" << std::endl;

	std::cout << count(array4, array5) << std::endl;






	

	_getch();
	return 0;
}