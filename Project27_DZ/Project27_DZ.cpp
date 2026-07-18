#include "Vector.h";

int main()
{
	cout << "=== 1. Initialization ===" << endl;
	Vector v1(3, 10);
	v1.pushBack(20); 

	Vector v2(2, 5);
	cout << "v1: "; v1.print();
	cout << "v2: "; v2.print();

	cout << "\n=== 2. Operator + (Concatenation) ===" << endl;
	Vector vSum = v1 + v2;
	cout << "v1 + v2: ";
	vSum.print();
	cout << "\n=== 3. Operator - (Difference) ===" << endl;
	Vector vA(4, 10);
	vA.setValue(3, 99);
	Vector vB(2, 10);
	cout << "vA: "; vA.print();
	cout << "vB: "; vB.print();

	Vector vDiff = vA - vB;

	cout << "vA - vB: ";
	vDiff.print(); 

	cout << "\n=== 4. Operator * (Scalar Multiplication) ===" << endl;
	Vector vMult = v1 * 2;
	cout << "Original v1: "; v1.print();
	cout << "v1 * 2:      "; vMult.print();


	cout << "\n=== 5. Operator int() ===" << endl;
	int size = (int)v1;
	cout << "Size of v1: " << size << endl;

	cout << "\n=== 6. Operator char*() ===" << endl;


	char* str = (char*)v1;

	cout << "Vector as string: " << str << endl;

	delete[] str;

	return 0;
}
