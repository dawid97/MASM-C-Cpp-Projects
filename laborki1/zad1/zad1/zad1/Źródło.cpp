#include <iostream>
#include <typeinfo>
using namespace std;
struct Pojazd { };
struct Samochod : Pojazd { };
struct Budynek {
	virtual ~Budynek() { }
};
struct Dom : Budynek { };
int main()
{
	Pojazd    poj;
	Samochod  sam1, sam2;
	Samochod* p_sam1 = &sam1;
	Pojazd*   p_sam2 = &sam2;
	Pojazd&   r_sam1 = sam1;
	cout << "    poj: " << typeid(poj).name() << endl
		<< "   sam1: " << typeid(sam1).name() << endl
		<< "   sam2: " << typeid(sam2).name() << endl
		<< " p_sam1: " << typeid(p_sam1).name() << endl
		<< " p_sam2: " << typeid(p_sam2).name() << endl
		<< "*p_sam1: " << typeid(*p_sam1).name() << endl
		<< "*p_sam2: " << typeid(*p_sam2).name() << endl
		<< " r_sam1: " << typeid(r_sam1).name() << endl;

	cout << "Typy *p_sam1 i *p_sam2 sa "
		<< (typeid(*p_sam1) == typeid(*p_sam2) ?
			"takie same\n" : "rozne\n") << endl;
	Budynek  bud;
	Dom   dom1, dom2;
	Dom*  p_dom1 = &dom1;
	Budynek* p_dom2 = &dom2;
	Budynek& r_dom1 = dom1;
	cout << "    bud: " << typeid(bud).name() << endl
		<< "   dom1: " << typeid(dom1).name() << endl
		<< "   dom2: " << typeid(dom2).name() << endl
		<< " p_dom1: " << typeid(p_dom1).name() << endl
		<< " p_dom2: " << typeid(p_dom2).name() << endl
		<< "*p_dom1: " << typeid(*p_dom1).name() << endl
		<< "*p_dom2: " << typeid(*p_dom2).name() << endl
		<< " r_dom1: " << typeid(r_dom1).name() << endl;
	cout << "Typy *p_dom1 i *p_dom2 sa "
		<< (typeid(*p_dom1) == typeid(*p_dom2) ?
			"takie same\n" : "rozne\n");
	system("pause");
	return 0;
}