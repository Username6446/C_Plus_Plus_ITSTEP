#include <iostream>
using namespace std;
#include "StudentEmployee.h"
#include "Lion.h"
#include "Wolf.h"
int main()
{
	/*Employee emp("Denis", "Manager");
	emp.print();
	Student stud("Denis", "C#");
	stud.print();

	cout << endl;

	StudentEmployee se(stud, emp);
	se.print();

	StudentEmployee se2("VASIL", "C#", "Maneger");
	se2.print();*/

	Animal animal("South africa", 1);
	animal.print();

	Animal animal2("South africa", 2);
	animal.print();

	cout << "\n\n";

	Lion lion("Africa", 4, false);
	lion.print();

	cout << "\n\n";

	Wolf wolf;
	wolf.print();

	cout << "\n\n";

	Animal test = lion;
	test = (Animal)wolf;
	system("cls");

	BlueWolf bluewolf;

	Animal** zoo = new Animal * [5] {&animal, & animal2, & lion, & wolf, &bluewolf};
	for (int i = 0; i < 5; i++)
	{
		zoo[i]->print();
		cout << "\n----------------------------" << endl;
	}


}
