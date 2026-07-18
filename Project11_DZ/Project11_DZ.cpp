#include <iostream>

using namespace std;

void fillArray(int* arr, size_t size, int min = 1, int max = 10)
{
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void printArray(int* arr, size_t size, string prompt = "")
{
    cout << (prompt.size() > 0 ? prompt + " :: \t " : "");
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    //Ex1
    /*int n;
    cout << "ENter size of arr1 :: ";
    cin >> n;
    int* arr1 = new int[n];
    int m;
    cout << "ENter size of arr1 :: ";
    cin >> m;
    int* arr2 = new int[m];
    fillArray(arr1, n);
    fillArray(arr2, m);
    printArray(arr1, n);
    printArray(arr2, m);


    int* arr3 = new int[m+n];
    int ind = 0;
    for (int i = 0; i < n; i++) {
        arr3[i] = arr1[i];
        ind++;
    }
    for (int i = 0; i < m; i++) {
        arr3[ind] = arr2[i];
        ind++;
    }
    printArray(arr3, m+n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    */
    //Ex2

    /*int n;
    cout << "ENter size of arr1 :: ";
    cin >> n;
    int* arr1 = new int[n];
    int m;
    cout << "ENter size of arr1 :: ";
    cin >> m;
    int* arr2 = new int[m];
    fillArray(arr1, n);
    fillArray(arr2, m);
    printArray(arr1, n, "arr1");
    printArray(arr2, m, "arr2");


    int* arr3 = new int[m + n];
    int ind = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr2[j] == arr1[i]) {
                flag = true;
                for (int k = 0; k < ind; k++) {
                    if (arr2[j] == arr3[ind]) {
                        flag = false;
                    }
                }
            }
        }
        
        if (flag) {
            arr3[ind] = arr1[i];
            ind++;
        }
        flag = false;
    }
    printArray(arr3, ind, "arr3");
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    */



    int n;
    cout << "ENter size of arr1 :: ";
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << " :: ";
        cin >> arr[i];
    }

    while (true) {
        
        int a;
        cout << "Choose 1 - delete Odd, 2 - delete Even, 0 - end :: ";
        cin >> a;
        int size = 0;
        if (a == 1) {
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    size++;
                }
            }
        }
        if (a == 2) {
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 1) {
                    size++;
                }
            }
        }
        if (a == 0) {
            break;
        }
        int* temp1 = new int[size];
        int temp_size = 0;
        if (a == 1) {
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    temp1[temp_size] = arr[i];
                    temp_size++;
                }
            }
        }
        if (a == 2) {
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 1) {
                    temp1[temp_size] = arr[i];
                    temp_size++;
                }
            }
        }
        printArray(temp1, size);
        delete[] temp1;

    }

    delete[] arr;

}

