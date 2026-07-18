#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

enum Key
{
    LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80, ESC = 27
};




template <typename T>
void fill(T** arr, const int& row, const int& col, const int& min = 1, const int& max = 10)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = min + rand() % (max - min + 1);
        }
    }
}


template <typename T>
void print(T** arr, const int& row, const int& col, const string& prompt = "")
{

    cout << (prompt.empty() ? "" : prompt + " :: \n");

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}


template <typename T>
void fillArray(T* arr, size_t size, int min = 1, int max = 2)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}


template <typename T>
void addCol(T**& arr, const int& row, int& col, const int& index)
{
    if (index < 0 || index > col) {
        std::cout << "Error index" << std::endl;
        return;
    }

    T** tmp = new T * [row];

    for (int i = 0; i < row; i++) {
        tmp[i] = new T[col + 1];

        for (int j = 0; j < index; j++) {
            tmp[i][j] = arr[i][j];
        }

        tmp[i][index] = 0;

        for (int j = index; j < col; j++) {
            tmp[i][j + 1] = arr[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = tmp;
    col++;
}

template <typename T>
void removeCol(T**& arr, const int& row, int& col, const int& index)
{
    if (index < 0 || index >= col) {
        cout << "Error index" << endl;
        return;
    }

    T** tmp = new T * [row];
    int new_col = col - 1;

    for (int i = 0; i < row; i++) {
        tmp[i] = new T[new_col];

        for (int j = 0; j < index; j++) {
            tmp[i][j] = arr[i][j];
        }

        for (int j = index; j < new_col; j++) {
            tmp[i][j] = arr[i][j + 1];
        }
    }

    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = tmp;
    col--;
}


// Дано матрицю порядку MxN (M рядків, N стовпців). Необхідно заповнити її значеннями і написати функцію, 
// що здійснює циклічний зсув рядків та/або стовпчиків масиву вказану кількість разів і в зазначену сторону.


int main()
{
    srand(time(0));
    int row = 4, col = 6;

    int** arr = new int* [row];

    for (size_t i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    fill(arr, row, col);

    /*addCol(arr, row, col, 1);
    print(arr, row, col, "addCol 1  ");
    removeCol(arr, row, col, 1);
    print(arr, row, col, "removeCol 1  ");
    
    
    print(arr, row, col, " ");*/
    

    int step = 0;
    do {
        system("cls");
        print(arr, row, col, " ");
        int step = _getch();
        switch (step)
        {
        case Key::LEFT:
            for (int i = 0; i < row; i++) {
                int temp = arr[i][0];
                for (int j = 0; j < col - 1; j++) {
                    arr[i][j] = arr[i][j + 1];
                }
                arr[i][col - 1] = temp;
            }
            break;

        case Key::RIGHT:
            for (int i = 0; i < row; i++) {
                int temp = arr[i][col - 1];
                for (int j = col - 1; j > 0; j--) {
                    arr[i][j] = arr[i][j - 1];
                }
                arr[i][0] = temp;
            }
            break;
        case Key::UP:
            for (int i = 0; i < col; i++) {
                int temp = arr[0][i];
                for (int j = 0; j < row - 1; j++) {
                    arr[j][i] = arr[j + 1][i];
                }
                arr[row - 1][i] = temp;
            }
            break;
        case Key::DOWN:
            for (int i = 0; i < col; i++) {
                int temp = arr[row - 1][i];
                for (int j = row - 1; j > 0; j--) {
                    arr[j][i] = arr[j - 1][i];
                }
                arr[0][i] = temp;
            }
            break;
        }


    } while (step != Key::ESC);
    
 


    for (size_t i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;


}
