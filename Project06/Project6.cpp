#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

enum CodeKey {
    LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80,
};

int main()
{
	/*srand(time(0));
	const int row = 4, col = 5;
	int arr[row][col]{};
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}

	int key;
	do
	{

		system("cls");
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
		case CodeKey::RIGHT:
			for (size_t i = 0; i < row; i++)
			{
				int tmp = arr[i][col - 1];
				for (size_t j = col - 1; j > 0; j--)
				{
					arr[i][j] = arr[i][j - 1];
				}
				arr[i][0] = tmp;
			}
			break;
		case CodeKey::LEFT:
			for (size_t i = 0; i < row; i++)
			{
				int tmp = arr[i][0];
				for (size_t j = 0; j < col - 1; j++)
				{
					arr[i][j] = arr[i][j + 1];
				}
				arr[i][col - 1] = tmp;
			}
			break;
		case CodeKey::UP:
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
		case CodeKey::DOWN:
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
	} while (key != 27);*/


	////Ex1
	//srand(time(0));
	//int arr1[10]{};
	//for (size_t j = 0; j < 10; j++)
	//{
	//	arr1[j] = rand() % 10;
	//}
	//cout << "Start array::" << endl;
	//for (size_t j = 0; j < 10; j++)
	//{
	//	cout << arr1[j] << "\t";
	//}
	//cout << endl;
	//int max = arr1[0];
	//int min = arr1[0];
	//int indexMax = 0;
	//int indexMin = 0;
	//for (int i = 0; i < 10; i++) {
	//	if (arr1[i] > max) {
	//		max = arr1[i];
	//		indexMax = i;
	//	}
	//	else if (arr1[i] < min) {
	//		min = arr1[i];
	//		indexMin = i;
	//	}
	//}
	//arr1[indexMax] = min;
	//arr1[indexMin] = max;

	//cout << "Result::" << endl;
	//for (size_t j = 0; j < 10; j++)
	//{
	//	cout << arr1[j] << "\t";
	//}
	//cout << endl;
	////Ex2

	//srand(time(0));
	//int arr2[10]{};
	//for (size_t j = 0; j < 10; j++)
	//{
	//	arr2[j] = rand() % 10;
	//}
	//cout << "Start array::" << endl;
	//for (size_t j = 0; j < 10; j++)
	//{
	//	cout << arr2[j] << "\t";
	//}
	//cout << endl;
	//max = arr2[0];
	//min = arr2[0];
	//indexMax = 0;
	//indexMin = 0;
	//for (int i = 0; i < 10; i++) {
	//	if (arr2[i] > max) {
	//		max = arr2[i];
	//		indexMax = i;
	//	}
	//	else if (arr2[i] < min) {
	//		min = arr2[i];
	//		indexMin = i;
	//	}
	//}
	//
	//indexMax = indexMax > indexMin ? indexMin : indexMax;
	//indexMin = indexMax < indexMin ? indexMin : indexMax;

	//for (int i = indexMax; i < indexMin; i++) {
	//	arr2[i] *= 2;
	//}

	//cout << "Result::" << endl;
	//for (size_t j = 0; j < 10; j++)
	//{
	//	cout << arr2[j] << "\t";
	//}
	//cout << endl;

	//////Ex3
	//
	//const int len = 10;
	//srand(time(0));
	//int arr3[len]{};
	//for (size_t j = 0; j < len; j++)
	//{
	//	arr3[j] = rand() % 10;
	//}
	//cout << "Start array::" << endl;
	//for (size_t j = 0; j < len; j++)
	//{
	//	cout << arr3[j] << "\t";
	//}
	//cout << endl;

	//int temp = 0;
	//for (int i = 0; i < len-1; i+=2) {
	//	temp = arr3[i];
	//	arr3[i] = arr3[i + 1];
	//	arr3[i + 1] = temp;

	//}

	//cout << "Result::" << endl;
	//for (size_t j = 0; j < len; j++)
	//{
	//	cout << arr3[j] << "\t";
	//}
	//cout << endl;


	////////Ex4

	//const int len = 10;
	//srand(time(0));
	//int arr4[len]{};
	//for (size_t j = 0; j < len; j++)
	//{
	//	arr4[j] = rand() % 10;
	//}
	//cout << "Start array::" << endl;
	//for (size_t j = 0; j < len; j++)
	//{
	//	cout << arr4[j] << "\t";
	//}
	//cout << endl;

	//int count = 0;
	//bool flag = true;
	//int resultArr[len]{};
	//for (int i = 0; i < len; i ++) {
	//	for (int j = i+1; j < len; j++) {
	//		if (arr4[i] == arr4[j]) {
	//			for (int k = 0; k < count; k++) {
	//				if (arr4[i] == resultArr[k]) {
	//					flag = false;
	//				}
	//			}
	//			if (flag) {
	//				resultArr[count] = arr4[i];
	//				count++;
	//				flag = true;
	//			}
	//				
	//			
	//		}
	//	}
	//}

	//cout << "Result::" << endl;
	//for (size_t j = 0; j < len; j++)
	//{
	//	if(resultArr[j]!=0)
	//		cout << resultArr[j] << "\t";
	//}
	//cout << endl;


	//////Ex5
	//

	//const int len = 10;
	//srand(time(0));
	//int arr5[len]{};
	//for (size_t j = 0; j < len; j++)
	//{
	//	arr5[j] = rand() % 10;
	//}
	//cout << "Start array::" << endl;
	//for (size_t j = 0; j < len; j++)
	//{
	//	cout << arr5[j] << "\t";
	//}
	//cout << endl;

	//int tmp = 0;
	//int ind = 0;
	//int Min = 0;
	//for (int i = 0; i < len; i++) {
	//	tmp = arr5[i];
	//	Min = arr5[i];
	//	ind = i;
	//	for (int j = i; j < len; j++) {
	//		if (arr5[j] < Min) {
	//			Min = arr5[j];
	//			ind = j;
	//		}
	//	}
	//	arr5[i] = Min;
	//	arr5[ind] = tmp;
	//	
	//}


	//cout << "Result::" << endl;
	//for (size_t j = 0; j < len; j++)
	//{
	//	cout << arr5[j] << "\t";
	//}
	//cout << endl;
	//

	////////Ex6

	//const int row = 8, col = 8;
	//char arr[row][col]{};
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		arr[i][j] = '-';
	//	}
	//}

	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		cout << arr[i][j] << "\t";
	//	}
	//	cout << "\n\n";
	//}

	//char letter;
	//cout << "Enter letter (a-h) :: ";
	//cin >> letter;
	//int num;
	//cout << "Enter number (1-8) :: ";
	//cin >> num;

	//int num2 = 0;

	//

	//switch (letter) {
	//	case('a'):
	//		num2 = 1;
	//		break;
	//	case('b'):
	//		num2 = 2;
	//		break;
	//	case('c'):
	//		num2 = 3;
	//		break;
	//	case('d'):
	//		num2 = 4;
	//		break;
	//	case('e'):
	//		num2 = 5;
	//		break;
	//	case('f'):
	//		num2 = 6;
	//		break;
	//	case('g'):
	//		num2 = 7;
	//		break;
	//	case('h'):
	//		num2 = 8;
	//		break;
	//}
	//	
	//num--;
	//num2--;

	//arr[num][num2] = 'T';

	//for (int i = 0; i < 8; i++) {
	//	if (i != num) {
	//		arr[i][num2] = '*';
	//	}
	//	if (i != num2) {
	//		arr[num][i] = '*';
	//	}
	//	
	//}

	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		cout << arr[i][j] << "\t";
	//	}
	//	cout << "\n\n";
	//}

	//////Ex7
	//

	//const int row = 8, col = 8;
	//char arr[row][col]{};
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		arr[i][j] = '-';
	//	}
	//}

	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		cout << arr[i][j] << "\t";
	//	}
	//	cout << "\n\n";
	//}

	//char letter;
	//cout << "Enter letter (a-h) :: ";
	//cin >> letter;
	//int num;
	//cout << "Enter number (1-8) :: ";
	//cin >> num;

	//int num2 = 0;



	//switch (letter) {
	//case('a'):
	//	num2 = 1;
	//	break;
	//case('b'):
	//	num2 = 2;
	//	break;
	//case('c'):
	//	num2 = 3;
	//	break;
	//case('d'):
	//	num2 = 4;
	//	break;
	//case('e'):
	//	num2 = 5;
	//	break;
	//case('f'):
	//	num2 = 6;
	//	break;
	//case('g'):
	//	num2 = 7;
	//	break;
	//case('h'):
	//	num2 = 8;
	//	break;
	//}

	//num--;
	//num2--;

	//arr[num][num2] = 'O';

	//for (int i = 0; i < 8; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		if (((num2 - num + i) == j) and arr[i][j]!='O') {
	//			arr[i][j] = '*';
	//		}
	//		if (((num+num2-i) == j) and arr[i][j] !='O') {
	//			arr[i][j] = '*';
	//		}
	//	}
	//}

	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++)
	//	{
	//		cout << arr[i][j] << "\t";
	//	}
	//	cout << "\n\n";
	//}

	////Ex8
	

	const int row = 8, col = 8;
	char arr[row][col]{};
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = '-';
		}
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n\n";
	}

	char letter;
	cout << "Enter letter (a-h) :: ";
	cin >> letter;
	int num;
	cout << "Enter number (1-8) :: ";
	cin >> num;

	int num2 = 0;



	switch (letter) {
	case('a'):
		num2 = 1;
		break;
	case('b'):
		num2 = 2;
		break;
	case('c'):
		num2 = 3;
		break;
	case('d'):
		num2 = 4;
		break;
	case('e'):
		num2 = 5;
		break;
	case('f'):
		num2 = 6;
		break;
	case('g'):
		num2 = 7;
		break;
	case('h'):
		num2 = 8;
		break;
	}

	num--;
	num2--;

	arr[num][num2] = 'H';

	int moves[8][2] = { {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2} };

	for (int i = 0; i < 8; i++) {
		int newRow = num + moves[i][0];
		int newCol = num2 + moves[i][1];
		if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
			arr[newRow][newCol] = '*';
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n\n";
	}


}