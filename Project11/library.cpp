#include "library.h"

int* createArray(size_t size)
{
	return new int[size];
}


void fillArray(int* arr, size_t size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = min + rand() % (max - min + 1);
	}
}

void printArray(int* arr, size_t size, string prompt)
{
	cout << (prompt.size() > 0 ? prompt + " :: \t " : "");
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void deleteArray(int*& arr)
{
	delete[] arr;
	arr = nullptr;
}

void pushBack(int*& arr, int& size, int value)
{

	int* tmp = new int[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = value;
	size++;
	deleteArray(arr);
	arr = tmp;
}

void pushFront(int*& arr, int& size, int value)
{
	int* temp = new int[++size];
	temp[0] = value;
	for (int i = 1; i < size; i++) {
		temp[i] = arr[i - 1];
	}
	deleteArray(arr);
	arr = temp;
}

void popBack(int*& arr, int& size)
{
	int* temp = new int[--size];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	deleteArray(arr);
	arr = temp;
}

void popFront(int*& arr, int& size)
{
	size--;
    int* temp = new int[size];
    for (int i = 0; i < size; i++) {
		temp[i] = arr[i+1];
    }
	deleteArray(arr);
	arr = temp;
}

void insert(int*& arr, int& size, int value, int index) {

	if (index < 0 or index > size) {
		cout << "Error index." << endl;
		return;
	}

	int* temp = new int[++size];
	for (int i = 0, j = 0; i < size; i++) {
		if (i == index) {
			temp[i] = value;
			continue;
		}
		
		temp[i] = arr[j++];
	}
	deleteArray(arr);
	arr = temp;

}

void deleteInd(int*& arr, int& size, int index)
{
	if (index < 0 or index > size) {
		cout << "Error index." << endl;
		return;
	}

	int* temp = new int[--size];
	for (int i = 0, j = 0; i < size+1; i++) {
		if (i == index)
			continue;
		temp[j++] = arr[i];

	}
	deleteArray(arr);
	arr = temp;
}

int* deletePrime(int*& arr, int& size)
{
	int new_size = 0, count = 0;
	int* temp = new int[size];
	bool flag = false;
	for (int i = 0; i < size; i++) {
		for (int j = 2; j < arr[i]/2; j++) {
			if (arr[i] % j == 0)
				flag = true;
		}
		if (flag) {
			temp[count++] = arr[i];
			new_size++;
		}
		flag = false;
	}
	int* temp1 = new int[new_size];
	for (int i = 0; i < new_size; i++) {
		temp1[i] = temp[i];
	}
	deleteArray(arr);
	deleteArray(temp);
	return temp1;
}

void distributionByArrays(int*& arr, int& size, int*& res1, int*& res2, int*& res3, int &len1, int& len2, int& len3)
{
	int* arr1 = new int[size];
	int* arr2 = new int[size];
	int* arr3 = new int[size];
	int t1 = 0, t2 = 0, t3 = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) {
			arr1[t1++] = arr[i];
		}
		else if (arr[i] < 0) {
			arr2[t2++] = arr[i];
		}
		else if (arr[i] == 0) {
			arr3[t3++] = arr[i];
		}
	}
	int* arr1_res = new int[t1];
	int* arr2_res = new int[t2];
	int* arr3_res = new int[t3];

	for (int i = 0; i < t1; i++) {
		arr1_res[i] = arr1[i];
	}
	for (int i = 0; i < t2; i++) {
		arr2_res[i] = arr2[i];
	}
	for (int i = 0; i < t3; i++) {
		arr3_res[i] = arr3[i];
	}
	res1 = arr1_res;
	res2 = arr2_res;
	res3 = arr3_res;
	len1 = t1;
	len2 = t2;
	len3 = t3;
	deleteArray(arr1);
	deleteArray(arr2);
	deleteArray(arr3);
	deleteArray(arr);
	
}
