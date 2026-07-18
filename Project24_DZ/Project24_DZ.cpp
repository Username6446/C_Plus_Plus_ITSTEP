#include "Vector.h";

int main()
{
	Vector v1(4,2);
	v1.print();
	v1.pushBack(1);
	v1.print();
	v1.popBack();
	v1.print();
	v1.pushIndex(0, 9);
	v1.print();
	v1.pushIndex(2, 10);
	v1.print();
	v1.popIndex(1);
	v1.print();
	
}

