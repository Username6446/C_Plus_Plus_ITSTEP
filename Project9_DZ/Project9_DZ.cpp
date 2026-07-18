#include <iostream>
#include <ctime>

using namespace std;

template <typename T, size_t SIZE = 5>
void fillMatrix(T arr[][SIZE], int size = 5, T min = 1, T max = 10) {
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
			arr[i][j] = min + rand() % (max - min); 
		}
    }
}

template <typename T, size_t SIZE = 5>
void printMatrix(T arr[][SIZE], int size = 5) {
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
	cout << endl;
}

template <typename T, size_t SIZE = 5>
void minMaxOfMainDiagonal(T arr[][SIZE], int size = 5) {
	T min = arr[0][0];
	T max = arr[0][0];
    for (int i = 0; i < size; i++) {
		if (arr[i][i] < min) min = arr[i][i];
		if (arr[i][i] > max) max = arr[i][i];
    }
	cout << "Min: " << min << endl;
	cout << "Max: " << max << "\n\n";
}



template<typename T>
void quickSort(T arr[], int left, int right)
{
	int tmp_l = left;
	int tmp_r = right;

	T pivot = arr[left];

	while (left < right)
	{
		while (pivot > arr[right] and left < right) right--;
		if (left != right) {
			arr[left] = arr[right];
			left++;
		}

		while (pivot < arr[left] and left < right) left++;
		if (left != right)
		{
			arr[right] = arr[left];
			right--;
		}
	}

	arr[left] = pivot;
	int index = left;
	left = tmp_l;
	right = tmp_r;

	if (index > left)
	{
		quickSort(arr, left, index - 1);
	}
	if (index < right)
	{
		quickSort(arr, index + 1, right);
	}

}


template<typename T, size_t SIZE = 5>
void sortedOfRow(T arr[][SIZE], int size = 5) {
	for(int i = 0; i < size; i++) {
		quickSort(arr[i], 0, size - 1);
	}
}


int maxDivisor(int a, int b, int d = 0) {
	if (d == 0) d = (a < b) ? a : b; 
	if (d == 0) return 1;            
	if (a % d == 0 && b % d == 0) return d;
	return maxDivisor(a, b, d - 1);
}

// Написати гру "Бики та корови". Програма "загадує" чотирицифрове число і 
// гравець повинен вгадати його. Після введення користувачем числа програма повідомляє,
// скільки цифр числа вгадано (бики) і скільки цифр вгадано і 
// стоїть на потрібному місці (корови). Після відгадування числа на екран необхідно 
// вивести кількість зроблених користувачем спроб. У програмі необхідно використовувати 
// рекурсію.

void numberToDigits(int number, int digits[], int index = 3) {
    if (index < 0) return;
    digits[index] = number % 10;
    numberToDigits(number / 10, digits, index - 1);
}

void game() {
	srand(time(0));

	int number = 1000 + rand() % 9000;
	int secret[4]{};
	numberToDigits(number, secret);

	int guess, attempts = 0;
	
	cout << "\nGame 'Bulls and Cows'!\n";

	do {
		cout << "Enter your guess (4-digit number): ";
		cin >> guess;
		attempts++;

		int guessDigits[4]{};
		numberToDigits(guess, guessDigits);

		int bulls = 0, cows = 0;

		for (int i = 0; i < 4; i++)
			if (guessDigits[i] == secret[i])
				bulls++;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (i != j && guessDigits[i] == secret[j])
					cows++;

		cout << "Bulls: " << bulls << " Cows: " << cows << endl;

	} while (guess != number);

	cout << "Correct The number is :: " << number << endl;
	cout << "Attempts :: " << attempts << endl;
}



int main()
{
    srand(time(0));
    int arr[5][5]{};
	fillMatrix(arr);
    printMatrix(arr);
	minMaxOfMainDiagonal(arr);
	sortedOfRow(arr);
    printMatrix(arr);
	
	int n1 = 36, n2 = 24;
	cout << maxDivisor(n2, n1);

	game();
	return 0;

}

