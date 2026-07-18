#include <ctime>
#include "library.h"

using namespace std;


int main()
{

	// new
	// delete


	/*int* ptr = new int;
	cout << ptr << "\t" << * ptr << endl;*/

	/*srand(time(0));
	int size = 10;
	cout << "Enter size :: ";
	cin >> size;
	int* ptr = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = rand() % 10 + 1;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << ptr[i] << "\t";
	}cout << endl;

	delete []ptr;*/


	//int i = 1;
	//while (true)
	//{
	//	long long* ptr = new long long[1000000];
	//	cout << "Block #" << i++ << endl;
	//	//delete[] ptr;
	//}


	srand(time(0));

	int size = 10;
	int size1 = 5;
	int size2 = 5;
	int size3 = 5;

	int* arr = createArray(size);

	int* arr1 = createArray(size1);
	int* arr2 = createArray(size2);
	int* arr3 = createArray(size3);

	fillArray(arr, size, -10, 10);
	printArray(arr, size, "Print Array Create   ");
	distributionByArrays(arr, size, arr1, arr2, arr3, size1, size2, size3);
	printArray(arr1, size1, "Print Array 1 ");
	printArray(arr2, size2, "Print Array 2 ");
	printArray(arr3, size3, "Print Array 3 ");

	/*pushBack(arr, size, 33);
	printArray(arr, size, "Print Array pushBack ");

	cout << endl;
	popFront(arr, size);
	printArray(arr, size, "Print Array popFront");

	insert(arr, size, 10, 1);
	printArray(arr, size, "Print Array Insert");

	pushFront(arr, size, 33);
	printArray(arr, size, "Print Array popBack");

	popBack(arr, size);
	printArray(arr, size, "Print Array popBack");

	deleteInd(arr, size, 1);
	printArray(arr, size, "Print Array deleteInd");*/



	/*int size2 = 15;
	int* arr2 = createArray(size2);
	fillArray(arr2, size2, 10, 50);
	printArray(arr2, size2, "Print Array 2 Create ");

	deleteArray(arr2);
	if(arr2 != nullptr)
		printArray(arr2, size2, "Print Array 2 Create ");*/


}

//Функція розподілу динамічної пам'яті. +
//Функція ініціалізації динамічного масиву. + 
//Функція друку динамічного масиву. + 
//Функція видалення динамічного масиву. +
//Функція додавання елемента в кінець масиву.
//Функція додавання елемента на початок масиву.
//Функція видалення елемента в кінеці масиву.
//Функція видалення елемента на початку масиву.
//Функція вставки елемента за вказаним індексом.
//Функція видалення елемента за вказаним індексом.