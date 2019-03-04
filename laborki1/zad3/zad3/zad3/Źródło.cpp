#include <iostream>
using namespace std;
struct struktura_1
{
	virtual ~struktura_1()
	{};

};
struct  struktura_2 :public struktura_1
{

};
int main()
{
	struktura_2 obiekt;
	struktura_1 *wsk = &obiekt;
	void *wsk2 = dynamic_cast<void*>(wsk);
	cout << wsk << endl;
	cout << wsk2 << endl;
	cout << &obiekt << endl;
	system("pause");
	return 0;
}