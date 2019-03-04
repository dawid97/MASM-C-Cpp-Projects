#include <iostream>
#include <typeinfo>
using namespace std;

class szklanka  //bazowa 
{
	int wsp_wytrzymalosci;
	const char* rodzaj_szkla;
public:
	szklanka() : wsp_wytrzymalosci(3), rodzaj_szkla("bardzo_twarde") {}
	virtual void f() { cout << " Jestem szklanka" << wsp_wytrzymalosci << endl; }
};
class kubek : public szklanka  //pochodna 
{
public:
	int pojemnosc;
    const char* producent;
	kubek() : pojemnosc(250), producent("IKEA") {}
	void f() { cout << "Jestem kubek " << producent << endl; }
};
int main()
{
	//z pochodnej na bazow¹  
	kubek k;
	szklanka sz;
	sz = k;
	cout << &sz << endl;
	cout << &k << endl;
	//na podstawie wypisanej informacji 
	//napisz z czym wi¹¿e siê takie rzutowanie 

	//z bazowej na pochodna 
	szklanka *przedmiot_2 = new kubek();
	kubek *przedmiot_1 = dynamic_cast<kubek*>(przedmiot_2);
	cout << przedmiot_1->pojemnosc << " " << przedmiot_1->producent << endl; //wypisze 250 i ikea 
	przedmiot_1->f();
	przedmiot_2->f(); //jest nowym kubkiem wiêc wypisuje jestem kubek 
	//ile mamy kubków podczas dzia³ajacego programu???

	kubek k_1, *k_2;
	szklanka * sz_1;
	sz_1 = &k_1;
	k_2 = dynamic_cast <kubek*>(sz_1);
	if (k_2)
		cout << "rzutowanie powiod³o siê" << endl;
	else
		cout << "rzutowanie nie powiod³o siê" << endl;
	delete przedmiot_1;
	system("pause");
	return 0;
}