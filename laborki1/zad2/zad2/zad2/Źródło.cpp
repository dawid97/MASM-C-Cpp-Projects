#include <typeinfo>
#include <iostream>
using namespace std;
int main()
{
	double x = 18;

	if (typeid(x) == typeid(double))  // true
		cout << "r�wne" << endl;
	else
		cout << " nie rowne" << endl;
	if (typeid(x) == typeid(86.5))    // true
		cout << "r�wne" << endl;
	else
		cout << " nie rowne" << endl;
	if (typeid(x) == typeid(8))       // false
		cout << "r�wne" << endl;
	else
		cout << " nie rowne" << endl;
	if (typeid(x) == typeid(int))    // false
		cout << "r�wne" << endl;
	else
		cout << " nie rowne" << endl;
	system("pause");
	return 0;
}