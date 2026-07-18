#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include <cctype>

using namespace std;

void reverseText(char text[]) {
	int len = strlen(text);
	for (int i = 0; i < len / 2; i++) {
		char temp = text[i];
		text[i] = text[len - i - 1];
		text[len - i - 1] = temp;
	}
}


int task_1_1(char text[]) {
	cout << "Enter word :: ";
	char word[50];
	cin.getline(word, 50);

	int entryCount = 0;
	size_t lenText = strlen(text);
	size_t lenWord = strlen(word);

	for (size_t i = 0; i + lenWord <= lenText; i++) {
		if (strncmp(&text[i], word, lenWord) == 0) {
			entryCount++;
		}
	}

	return entryCount;
}

int task_1_2(char text[]) {
	int sentenceCount = 0;

	for (size_t i = 0; text[i]; i++) {
		if (text[i] == '.' || text[i] == '!' || text[i] == '?')
			sentenceCount++;
	}

	return sentenceCount;
}

int task_1_3(char text[]) {
	int count = 0;

	for (size_t i = 0; text[i]; i++) 
		if (text[i] == '.' || text[i] == ',')
			count++;

	return count;
}

void task_1_5(char text[]) {
	char temp[1000] = "";
	char* sentence = strtok(text, ".");

	while (sentence != NULL) {
		reverseText(sentence);
		strcat(temp, sentence);
		strcat(temp, ".");
		sentence = strtok(NULL, ".");
	}

	strcpy(text, temp);
}

void task_2_1(char text[]) {
	cout << "Enter word to replace :: ";
	char wordReplaced[50];
	cin.getline(wordReplaced, 50);

	cout << "Enter replacement word :: ";
	char wordToReplace[50];
	cin.getline(wordToReplace, 50);

	size_t lenText = strlen(text);
	size_t lenWordReplaced = strlen(wordReplaced);
	size_t lenWordToReplace = strlen(wordToReplace);

	for (size_t i = 0; i + lenWordReplaced <= lenText; i++) {
		if (strncmp(&text[i], wordReplaced, lenWordReplaced) == 0) {
			if (lenWordReplaced == lenWordToReplace) {
				for (size_t j = 0; j < lenWordReplaced; j++)
					text[i + j] = wordToReplace[j];
			}
		}
	}
}


void task_2_2(char text[]) {
	char temp[1000] = "";
	char* sentence = strtok(text, ".");

	while (sentence != NULL) {
		while (isspace(*sentence)) sentence++;

		if (isalpha(sentence[0]))
			sentence[0] = toupper(sentence[0]);

		strcat(temp, sentence);
		strcat(temp, ". ");

		sentence = strtok(NULL, ".");
	}

	strcpy(text, temp);
}


void task_2_3(char text[])
{
	int freq[256] = { 0 };

	for (size_t i = 0; i < strlen(text); i++) {
		unsigned char ch = text[i];
		if (isalpha(ch)) {
			ch = tolower(ch);
			freq[ch]++;
		}
	}

	cout << "Count of all letter ::\n";
	for (char c = 'a'; c <= 'z'; c++) {
		if (freq[c] > 0)
			cout << c << " : " << freq[c] << endl;
	}
}


int task_2_4(char text[]) {
	int count = 0;

	for (size_t i = 0; text[i]; i++) {
		if (isdigit(text[i]))
			count++;
	}

	return count;
}


void fill(int** arr, const size_t& row, const size_t& col, const int& min = 1, const int& max = 10)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = min + rand() % (max - min + 1);
		}
	}
}

void print(int** arr, const size_t& row, const size_t& col, const string& prompt = "")
{
	cout << (!prompt.empty() ? prompt + " :: \n" : "");
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int** create(const size_t& row, const size_t& col)
{
	int** tmp = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = new int[col];
	}
	return tmp;
}
void delete_(int**& arr, const size_t& row)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}

void removeRow(int**& arr, int& row, const int col, const int index)
{
	int** tmp = new int* [row - 1];

	int j = 0;
	for (int i = 0; i < row; i++)
	{
		if (i == index) {
			delete[] arr[i];
			continue;
		}
		tmp[j++] = arr[i];
	}

	delete[] arr;
	arr = tmp;
	row--;
}

void func4(int**& arr, int& row, const int col)
{
	for (int i = 0; i < row; i++)
	{
		bool flag = false;
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0) {
				flag = true;
				break;
			}
		}
		if (flag) {
			removeRow(arr, row, col, i);
			i--;
		}
	}
	cout << "\t\t\tEx 4\n\n";
}
void func5(int** arr1, int** arr2, int** arr3, int row, int col) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr3[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	cout << "\t\t\tEx 5\n\n";
}
void func6(int** arr1, int row1, int col1, int** arr2, int row2, int col2, int** arr3, int row3, int col3) {
	for (size_t i = 0; i < row1; i++)
	{
		for (size_t j = 0; j < col2; j++)
		{
			int sum = 0;

			for (size_t q = 0; q < col1; q++)
			{
				sum += arr1[i][q] * arr2[q][j];
			}

			arr3[i][j] = sum;
		}
	}
	cout << "\t\t\tEx 6\n\n";
}

//Завдання 1 
//	Є певний текст. Використовуючи стандартні рядкові функції:
//		Порахуйте кількість входжень слова, заданого користувачем;
//		Порахуйте кількість речень у тексті;
//		Порахуйте кількість крапок і ком;
//		Переверніть повністю весь текст;
//		Переверніть кожне речення в тексті.
//
//Завдання 2 
//	Є певний текст. Використовуючи стандартні рядкові функції з бібліотеки мови C:
//		Знайдіть і замініть входження певного слова на задане користувачем слово;
//		Змініть текст таким чином, щоб кожне речення починалося з великої літери;
//		Порахуйте скільки разів кожна буква зустрічається в тексті;
//		Порахуйте скільки разів цифри зустрічаються в тексті.
//
//Завдання 3
//	Написати програму, яка видаляє з двовимірного масиву, заповненого випадковими числами, рядки, що містять нульові елементи.
//
//Завдання 4
//	Написати програму, яка поелементно підсумовує два динамічні двовимірні масиви, заповнені випадковими числами, і зберігає результат у третьому масиві. Розміри вихідних масивів задаються користувачем.
//
//Завдання 5 *
//	Напишіть функцію множення матриць. Матриця являє собою таблицю чисел. Добутком матриці A розміром MxN (M рядків, N стовпців) на матрицю B розміром NxK є матриця C розміром NxK така, що
//cij= ai1b1j + ai2b2j + ... + aiNbNj, для
//1 <= i <= M і 1 <= j <= K, де
//		axy — елемент, що знаходиться на перетині рядка x і стовпця y матриці A;
//		bxy — елемент, що знаходиться на перетині рядка x і стовпця y матриці B;
//		cxy — елемент, що знаходиться на перетині рядка x і стовпця y матриці C.



int main()
{
	srand(time(0));
	/*char str[100] = "Lorem Ipsum is simply dummy text of the printing";
	cout << str;
	char inp[10];
	cin >> inp;*/



	//int size_row, size_col;
	//cout << "Enter size of Row :: ";
	//cin >> size_row;
	//cout << "Enter size of Col:: ";
	//cin >> size_col;
	//int** arr1 = create(size_row, size_col);
	//fill(arr1, size_row, size_col, 0, 3);
	//print(arr1, size_row, size_col);
	//func4(arr1, size_row, size_col);
	//print(arr1, size_row, size_col);

	/*int size_row, size_col;
	cout << "Enter size of Row :: ";
	cin >> size_row;
	cout << "Enter size of Col:: ";
	cin >> size_col;
	int** arr1 = create(size_row, size_col);
	int** arr2 = create(size_row, size_col);
	int** arr3 = create(size_row, size_col);
	fill(arr1, size_row, size_col);
	fill(arr2, size_row, size_col);
	print(arr1, size_row, size_col);
	print(arr2, size_row, size_col);
	func5(arr1, arr2, arr3, size_row, size_col);
	print(arr3, size_row, size_col);*/


	/*size_t row_a = 2, col_a = 4, row_b = 4, col_b = 3, row_c = row_a, col_c = col_b;
	if (col_a != row_b) {
		cout << "Error size Matrix";
		return 0;
	}
	int** A = create(row_a, col_a);
	int** B = create(row_b, col_b);
	int** C = create(row_c, col_c);
	fill(A, row_a, col_a);
	fill(B, row_b, col_b);
	print(A, row_a, col_a, "Print Matrix A");
	print(B, row_b, col_b, "Print Matrix B");

	func6(A, row_a, col_a, B, row_b, col_b, C, row_c, col_c);
	print(C, row_c, col_c, "Print Matrix C");


	delete_(A, row_a);
	delete_(B, row_b);
	delete_(C, row_c);*/
}
