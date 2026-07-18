#include <iostream>
#include <ctime>

using namespace std;

void fillArray(int* arr, size_t length, int min = 1, int max = 10)
{
    for (size_t i = 0; i < length; i++)
    {
        /* *arr = min + rand() % (max - min + 1);
         arr++;*/
        *(arr + i) = min + rand() % (max - min + 1);
    }
}

void printArray(int* arr, size_t length, string prompt = "")
{
    cout << (prompt.size() > 0 ? prompt + " :: " : "");
    for (size_t i = 0; i < length; i++)
    {
        cout << *arr++ << "\t";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    const int size = 10;
    int arr1[size]{};
    int arr2[size]{};
    int arr3[size]{};
    int arr4[size]{};
    int* ptr1 = arr1;
    int* ptr2 = arr2;
    int* ptr3 = arr3;
    int* ptr4 = arr4;
    fillArray(arr1, size);
    printArray(arr1, size);

    for (int i = 0; i < size; i++) {
        *(ptr2 + i) = *(ptr1 + i);
    }

    cout << "Result 1::" << endl;
    printArray(arr2, size);

    for (int i = 0; i < size; i++) {
        *(ptr2 + i) = *(ptr1 + i);
    }

    cout << "Result 2::" << endl;

    for (int i = 0; i < size; i++) {
        *(ptr3 + i) = *(ptr1 + i);
    }

    for (int i = 0; i < size/2; i++) {
        int temp = *(ptr3 + i);
        *(ptr3 + i) = *(ptr3 - i + size - 1);
        *(ptr3 - i + size - 1) = temp;
    }
    printArray(arr3, size);

    cout << "Result 3::" << endl;

    for (int i = 0; i < size; i++) {
        *(ptr4 + i) = *(ptr1 - i + size - 1);
    }
    printArray(arr4, size);

}
