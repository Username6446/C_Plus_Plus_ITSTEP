#include "Point.h"
#include "Airplane.h"
#include <cstring>
#include <iostream>

using namespace std;
int main()
{
	//Point A(2, 5);
	//Point B(7, 8);

	//cout << "A";
	//A.print();

	//cout << "B";
	//B.print();

	//Point C = A + B;

	//cout << " = ";
	//cout << "C";
	//C.print();

	//cout << endl;

	//Point D = A - B;
	//cout << "A - B ---> ";
	//cout << "D";
	//D.print();

	//Point E = D;

	//cout << "\n\n";
	//
	//cout << "A";
	//A.print();
	//cout << "B";
	//B.print();
	//cout << "D";
	//D.print();
	//cout << "E";
	//E.print();

	//cout << "\n A == D --->" << boolalpha << (A == D) << endl;
	//cout << "\n E == D --->" << boolalpha << (E == D) << endl;
	//cout << "\n A != D --->" << boolalpha << (A != D) << endl;
	//cout << "\n E != D --->" << boolalpha << (E != D) << endl;


	//cout << "\n\n";
	//cout << "A";
	//A.print();
	//(++A).print();
	//(A++).print();
	//A.print();

	Airplane a1("qwe", 3, 1);
	a1.print();
	Airplane a2("qwe", 3, 1);
	a2.print();
	cout << "a1 == a2 " << boolalpha << (a1==a2) << endl;
	a1.print();
	++a1;
	cout << "++a1" << boolalpha << endl;
	a1.print();
	--a1;
	cout << "--a1" << boolalpha << endl;
	a1.print();
	
	Airplane a3("qwe", 3, 1);
	a3.print();
	Airplane a4("qwe", 5, 1);
	a4.print();
	cout << "a3 > a4 " << boolalpha << (a3 > a4) << endl;
	cout << "a4 > a3 " << boolalpha << (a4 > a3) << endl;
}
