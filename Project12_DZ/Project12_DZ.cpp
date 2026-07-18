#include <iostream>
#include <ctime>
using namespace std;

void pushBack(int*& arr, int& size, int value)
{

	int* tmp = new int[size+1];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = value;
	size++;

	delete[] arr;
	arr = tmp;
}


void fillArray(int* arr, size_t size, int min = 1, int max = 10)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = min + rand() % (max - min + 1);
	}
}

void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void elem1Not2(int*& arr1, int*& arr2, int& size1, int size2) {
    int* arr = new int[0];
    int count = 0;
    bool flag;

    for (int i = 0; i < size1; i++) {
        flag = true;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                flag = false;
                break;
            }
        }
        for (int j = 0; j < count && flag; j++) {
            if (arr1[i] == arr[j]) {
                flag = false;
                break; 
            }
        }
        if (flag) {
            pushBack(arr, count, arr1[i]);
        }
    }

    delete[] arr1;
    arr1 = arr;
    size1 = count;
}

void elemNot1Not2(int*& arr1, int*& arr2, int& size1, int size2) {
    int* arr = new int[0];
    int count = 0;
    bool flag;

    for (int i = 0; i < size1; i++) {
        flag = true;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                flag = false;
                break;
            }
        }
        for (int j = 0; j < count && flag; j++) {
            if (arr1[i] == arr[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            pushBack(arr, count, arr1[i]);
        }
    }

    for (int i = 0; i < size2; i++) {
        flag = true;
        for (int j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                flag = false;
                break;
            }
        }
        for (int j = 0; j < count && flag; j++) {
            if (arr2[i] == arr[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            pushBack(arr, count, arr2[i]);
        }
    }

    delete[] arr1;
    arr1 = arr;
    size1 = count;
}

int main()
{
	srand(time(0));
	int size1 = 10, size2 = 8;
	cout << "Enter size1 :: ";
	cin >> size1;
	cout << "Enter size2 :: ";
	cin >> size2;
	
	int* arr1 = new int[size1];
	fillArray(arr1, size1);
	int* arr2 = new int[size2];
	fillArray(arr2, size2);

	print(arr1, size1);
	print(arr2, size2);
	
    int* arr1_copy = new int[size1];
    for (int i = 0; i < size1; i++) arr1_copy[i] = arr1[i];

    int* arr2_copy = new int[size2];
    for (int i = 0; i < size2; i++) arr2_copy[i] = arr2[i];

    elem1Not2(arr1, arr2_copy, size1, size2);
    print(arr1, size1);

    elemNot1Not2(arr1_copy, arr2_copy, size1, size2);
    print(arr1_copy, size1);
	


}
