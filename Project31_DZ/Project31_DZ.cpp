#include <iostream>
#include "FwdList.h"

int main() {
	FwdList<int> list1;
	list1.AddToTail(1);
	list1.AddToTail(2);
	list1.AddToTail(3);
	list1.AddToTail(4);

	FwdList<int> list2;
	list2.AddToTail(3);
	list2.AddToTail(4);
	list2.AddToTail(5);
	list2.AddToTail(6);

	cout << "List 1: "; list1.print();
	cout << "List 2: "; list2.print();

	FwdList<int> list3 = list1.clone();
	cout << "Cloned List 1: "; list3.print();

	FwdList<int> sumList = list1 + list2;
	cout << "List 1 + List 2: "; sumList.print();

	FwdList<int> intersectList = list1 * list2;
	cout << "List 1 * List 2: "; intersectList.print();

	return 0;
}