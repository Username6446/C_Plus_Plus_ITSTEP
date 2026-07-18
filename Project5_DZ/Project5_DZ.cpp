#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
using namespace std;

enum Key
{
    LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80
};

int main()
{
	//Ex1
    int arr[3][3]{};
    int num;
    cout << "Enter number :: ";
    cin >> num;
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            arr[i][j] = num;
            num *= 2;
        }
    }
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
	}

    //Ex2

    cout << "Enter number :: ";
    cin >> num;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = num;
            num++;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //Ex3
	const int row = 3, col = 5;
	int arr[row][col]{};
	cout << "\n\n ============================== \n\n";
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}

	/*for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	int step = 2;
	for (size_t q = 0; q < step; q++)
	{
		for (size_t i = 0; i < row; i++)
		{
			int tmp = arr[i][col - 1];
			for (int j = col - 1; j > 0; j--)
			{
				arr[i][j] = arr[i][j - 1];
			}
			arr[i][0] = tmp;
		}
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}*/
	int key;
	do
	{
		system("cls");
		// print
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}

		key = _getch();

		switch (key)
		{
		case Key::RIGHT:
			for (size_t i = 0; i < row; i++)
			{
				int tmp = arr[i][col - 1];
				for (int j = col - 1; j > 0; j--)
				{
					arr[i][j] = arr[i][j - 1];
				}
				arr[i][0] = tmp;
			}
			break;
		case Key::LEFT:
			for (size_t i = 0; i < row; i++)
			{
				int tmp = arr[i][0];
				for (int j = 0; j < col - 1; j++)
				{
					arr[i][j] = arr[i][j + 1];
				}
				arr[i][col - 1] = tmp;
			}
			break;

		case Key::UP:
			for (size_t i = 0; i < col; i++)
			{
				int tmp = arr[0][i];
				for (size_t j = 0; j < row - 1; j++)
				{
					arr[j][i] = arr[j + 1][i];
				}
				arr[row - 1][i] = tmp;
			}
			break;
		case Key::DOWN:
			for (size_t i = 0; i < col; i++)
			{
				int tmp = arr[row - 1][i];
				for (size_t j = row - 1; j > 0; j--)
				{
					arr[j][i] = arr[j - 1][i];
				}
				arr[0][i] = tmp;
			}
			break;
		}


	} while (key != 27);

}

