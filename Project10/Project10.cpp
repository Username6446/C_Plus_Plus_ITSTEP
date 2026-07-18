#include <iostream>
#include <ctime>

using namespace std;



void Swap(int& first, int& second)
{
    int tmp = first;
    first = second;
    second = tmp;
}

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


void min_max(int* arr, size_t length, int& min, int& max)
{
    min = *arr;
    max = *arr;
    for (size_t i = 0; i < length; i++, arr++)
    {
        if (min > *arr)
            min = *arr;
        if (max < *arr)
            max = *arr;
    }
}

int func1(int* a, int* b) {
    if ((*a) > (*b)) {
        return (*a);
    }else if((*a) < (*b)) {
        return (*b);
    }
    else {
        return 0;
    }
}
char func2() {
    int num;
    cin >> num;
    int* a = &num;
    if ((*a) >0) {
        return '+';
    }
    else if ((*a) < 0) {
        return '-';
    }
    else {
        return 0;
    }

}
void func3(int& first, int& second) {
    int tmp = first;
    first = second;
    second = tmp;
}
double func4() {
    double num1, num2;
    char symb;
    double* p1 = &num1;
    double* p2 = &num2;
    char* p3 = &symb;
    cout << "Enter num1 :: ";
    cin >> *(p1);
    cout << "Enter operator (+, -, /, *)";
    cin >> *(p3);
    cout << "Enter num2 :: ";
    cin >> *(p2);
    switch (*(p3)) {
    case '+':
        return (*(p1)) + (*(p2));
    case '-':
        return (*(p1)) - (*(p2));
    case '/':
        if ((*(p2) == 0))
            return 0;
        return (*(p1)) / (*(p2));
    case '*':
        return (*(p1)) * (*(p2));
    }
    return 0;

}
int func5(int* arr, int length) {
    int temp = 0;
    for (int i = 0; i < length; i++) {
        temp += (*(arr + i));
    }
    return temp;
}


void func6(int* arr, int size) {
    int temp = 0;
    for (int i = 0; i < size - 1; i += 2) {
        temp = *(arr + i);
        *(arr + i) = *(arr + i + 1);
        *(arr + i + 1) = temp;
    }
}

void func7(int* arr1, int size1, int* arr2, int size2, int* arr3) {
    int i = 0, j = 0, k = 0;

    for (int i = 0; i < size1; i++)
        *(arr3 + i) = *(arr1 + i);

    for (int i = 0; i < size2; i++)
        *(arr3 + size1 + i) = *(arr2 + i);


    int size = size1 + size2 - 1;
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if ((*(arr3 + j)) < arr3[minIndex])
                minIndex = j;
        }
        int temp = (*(arr3 + i));
        (*(arr3 + i)) = (*(arr3 + minIndex));
        (*(arr3 + minIndex)) = temp;
    }

}

int main()
{
    srand(time(0));


    int a = 6, b = 5;
    int* ptr_a = &a;
    int* ptr_b = &b;

    const int size = 10;
    int arr[size]{ 1,2,3,4,5,6,7,8,9,10 };
    int arr2[size]{ 1,2,3,4,5,6,7,8,9,10 };
    int arr3[size+size]{};
    /*cout << func1(ptr_a, ptr_b) << endl;
    cout << func2() << endl;
    cout << "A :: " << a << "\t B :: " << b << endl;
    func3(a, b);
    cout << "A :: " << a << "\t B :: " << b << endl;
    cout << "Result :: " << func4() << endl;
    cout << "Sum :: " << func5(arr, size) << endl;*/

    printArray(arr, size);
    func6(arr, size);
    printArray(arr, size);
    
    func6(arr, size);
    cout << "\n\n\n";
    
    printArray(arr, size);
    printArray(arr2, size);
    func7(arr, size,arr2, size, arr3);
    printArray(arr3, size+size);



    /*int a = 5, b = 7;
    int* ptr_a = &a;
    cout << "A :: " << a << "\t B :: " << b << endl;
    cout << "Address a  = " << ptr_a << "\t Value :: " << *ptr_a << endl;
    cout << "Address a  = " << &b << "\t Value :: " << b << endl;
    Swap(a, b);
    cout << "A :: " << a << "\t B :: " << b << endl;

    const int SIZE = 10;
    int arr[SIZE]{ 1,12,33,4,5,6,74,8,9 };
    int* ptr = arr;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    cout << "Address array :: " << ptr + 1 << "\t Value :: " << *(ptr + 1) << endl;
    cout << "Address array :: " << ptr + 2 << "\t Value :: " << *(ptr + 2) << endl;
    cout << "Address array :: " << ptr + 3 << "\t Value :: " << *(ptr + 3) << endl;
    cout << endl;

    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr++;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr++;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr++;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr++;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr++;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr--;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr--;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr--;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr--;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr--;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr--;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;
    ptr--;
    *ptr = 222;
    cout << "Address array :: " << ptr << "\t Value :: " << *ptr << endl;

    fillArray(arr, SIZE);
    printArray(arr, SIZE, "Print Array");

    int min, max;
    min_max(arr, SIZE, min, max);
    cout << "Min :: " << min << endl;
    cout << "Max :: " << max << endl;*/

    
}


