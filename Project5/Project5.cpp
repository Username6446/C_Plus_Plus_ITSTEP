#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    //srand(time(0));
    //const int SIZE = 10;
    //int arr[SIZE]{};

    //for (int i = 0; i < SIZE;) {
    //	bool flag = true;
    //	int number = rand() % 10 + 1;
    //	for (int j = 0; j < i; j++) {
    //		if (arr[j] == number) {
    //			flag = false;
    //			break;
    //		}
    //		
    //	}
    //	if (flag) {
    //		arr[i] = number;
    //		i++;
    //	}
    //}

    //cout << "Before Sorted array :: \t";
    //for (int i = 0; i < SIZE; i++) {
    //	cout << arr[i] << "\t";
    //}
    //cout << endl;
    //cout << "Bubble Sorted" << endl;

    //for (int i = 0; i < SIZE - 1; i++) {
    //	for (int j = 0; j < SIZE - 1; j++) {
    //		if (arr[j] > arr[j + 1]) {
    //			int tmp = arr[j];
    //			arr[j] = arr[j + 1];
    //			arr[j + 1] = tmp;
    //		}
    //	}
    //}
    //cout << "After Sorted array :: \t";
    //for (int i = 0; i < SIZE; i++) {
    //	cout << arr[i] << "\t";
    //}
    //cout << endl;

    ////////////////////////////////////

    //cout << "Insert Sorted" << endl;
    //cout << "Before Sorted array :: \t";
    //for (int i = 0; i < SIZE; i++) {
    //	cout << arr[i] << "\t";
    //}
    //cout << endl;

    //for (int i = 1; i < SIZE; i++) {
    //	int key = arr[i];
    //	int j = i - 1;
    //	while (j >= 0 and key < arr[j]) {
    //		arr[j + 1] = arr[j];
    //		j--;
    //	}
    //	arr[j + 1] = key;
    //}

    //const int row = 3, col = 4;

    ////int arr[row][col]{};

    ///*int arr[][col]
    //{
    //    {1,2,5},
    //    {4,5,6,11},
    //    {7,8,9}
    //};*/

    //int arr[row][col]{};

    ///*
    //arr[0][0] = rand() % 10 + 1;
    //arr[0][1] = rand() % 10 + 1;
    //arr[0][2] = rand() % 10 + 1;
    //arr[0][3] = rand() % 10 + 1;*/
    ///*for (size_t i = 0; i < col; i++)
    //{
    //    arr[0][i] = rand() % 10 + 1;
    //}
    //for (size_t i = 0; i < col; i++)
    //{
    //    arr[1][i] = rand() % 10 + 1;
    //}
    //for (size_t i = 0; i < col; i++)
    //{
    //    arr[2][i] = rand() % 10 + 1;
    //}*/
    ////fill array
    //for (size_t j = 0; j < row; j++) // row
    //{
    //    for (size_t i = 0; i < col; i++) // col
    //    {
    //        arr[j][i] = rand() % 10 + 1;
    //    }
    //}
    ////print
    //for (size_t j = 0; j < row; j++) // row
    //{
    //    for (size_t i = 0; i < col; i++) // col
    //    {
    //        cout << arr[j][i] << "\t";
    //    }
    //    cout << endl;
    //}

    //int arr_2[3][row][col]{
    //    {
    //        {1,2,3},
    //        {1,2,3},
    //        {1,2,3}
    //    },
    //    {
    //        {1,2,3},
    //        {1,2,3},
    //        {1,2,3}
    //    },
    //    {
    //        {1,2,3},
    //        {1,2,3},
    //        {1,2,3}
    //    },
    //};
    //cout << "\n\n";
    //for (size_t i = 0; i < 3; i++)
    //{
    //    for (size_t j = 0; j < row; j++)
    //    {
    //        for (size_t q = 0; q < col; q++)
    //        {
    //            arr_2[i][j][q] = rand() % 10 + 1;
    //            cout << arr_2[i][j][q] << "\t";
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    //}
    
    //Ex1

    srand(time(0));
    const int row = 3, col = 4;
    int arr[row][col]{};
    for (size_t j = 0; j < row; j++)
    {
        for (size_t i = 0; i < col; i++)
        {
            arr[j][i] = rand() % 10 + 1;
        }
    }
    int sum = 0;
    int min = arr[0][0];
    int max = arr[0][0];
    for (size_t j = 0; j < row; j++)
    {
        for (size_t i = 0; i < col; i++)
        {
            if (arr[j][i] < min) min = arr[j][i];
            if (arr[j][i] > max) max = arr[j][i];
            sum += arr[j][i];
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }
    cout << "Sum = " << sum << endl;
    cout << "Average = " << sum / 12.0 << endl;
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;

    srand(time(0));
    int arr_2[4][4]{};

    for (size_t j = 0; j < 4; j++)
    {
        for (size_t i = 0; i < 4; i++)
        {
            arr_2[j][i] = rand() % 10 + 1;
        }
    }

  
    for (size_t j = 0; j < row; j++)
    {
        sum = 0;
        for (size_t i = 0; i < col; i++)
        {
            sum += arr[j][i];
            cout << arr[j][i] << "\t";
        }
        cout << "|\t" << sum;
        cout << endl;
    }
	cout << "----------------------------------" << endl;
	int SUM = 0;
    for (size_t j = 0; j < col; j++)
    {
        sum = 0;
        for (size_t i = 0; i < row; i++)
        {
            sum += arr[i][j];
        }
        SUM += sum;
        cout << sum << "\t";
    }
    cout << "|\t" << SUM;


    //Ex3

    int matrix[5][5]{};
    int matrix_2[5][10]{};
    for (size_t j = 0; j < 5; j++)
    {
        for (size_t i = 0; i < 10; i++)
        {
            matrix_2[j][i] = rand() % 51;
        }
    }

    for (size_t j = 0; j < 5; j++)
    {
        for (size_t i = 0; i < 5; i++)
        {
            matrix[j][i] = matrix_2[j][i * 2] + matrix_2[j][i * 2 + 1];
        }
    }
}