#include <iostream>
#include <ctime>

using namespace std;

//int sum(int a, int b)
//{
//    return a + b;
//}
//
//double sum(double a, double b)
//{
//    return a + b;
//}
//
//string sum(string a, string b)
//{
//    return a + b;
//}
//
//char sum(char a, char b)
//{
//    return a + b;
//}

//template<typename T>
//T sum(T a, T b){
//		return a + b;
//}
//
//template<typename T, typename T2>
//auto sum(T a, T2 b){
//		return a + b;
//}
//
////double sum(int a, double b)
////{
////	return a + b;
////}
////
////double sum(double a, int b)
////{
////	return a + b;
////}
//
//template <typename T>
//void fillArray(T arr[], size_t size, int min = 1, int max = 10)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		arr[i] = min + rand() % (max - min + 1);
//	}
//}
//
//void fillArray(double arr[], size_t size, int min = 1, int max = 10)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		arr[i] = min + rand() % (max - min + 1) / 1.3;
//	}
//}


template <typename T>
void inputArray(T arr[], size_t size) {
	for(size_t i = 0; i < size; i++) {
		cout << "Enter element " << i + 1 << ": ";
		cin >> arr[i];
	}
}

template <typename T>
void printArray(T arr[], size_t size, string prompt = "")
{
	cout << prompt << (prompt.size() > 0 ?" :: \t " : "");
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template <typename T>
int firstIndexOfElem(T arr[], size_t size, T elem) {
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == elem) {
			return i;
		}
	}
	return -1;
}

int firstIndexOfElem(char arr[], size_t size, char elem) {
	for (size_t i = 0; i < size; i++) {
		if (std::tolower(arr[i]) == std::tolower(elem)) {
			return i;
		}
	}
	return -1;
}

template <typename T>
int lastIndexOfElem(T arr[], int size, T elem) {
	for (int i = size-1; i >= 0; i--) {
		if (arr[i] == elem) {
			return i;
		}
	}
	return -1;
}


template <typename T>
void randChangeElem(T arr[], size_t size) {
	for (int n = 0; n < 3; n++) {
		int index1 = rand() % size;
		int index2 = rand() % size;
		T temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

template <typename T>
void fillArrayOneElem(T arr[], size_t size, T elem) {
	for (size_t i = 0; i < size; i++) {
		arr[i] = elem;
	}
}


template <typename T>
void sortElemUp(T arr[], size_t size) {
	for (size_t n = 0; n < size; n++) {
		for (size_t i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				T temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

template <typename T>
void sortElemDown(T arr[], size_t size) {
	for (size_t n = 0; n < size; n++) {
		for (size_t i = 0; i < size - 1; i++) {
			if (arr[i] < arr[i + 1]) {
				T temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}



int main()
{
//	srand(time(0));
//	string line1 = "Apple ";
//	string line2 = "Banana";
//	std::cout << "Result sum :: " << sum(2, 7) << std::endl;
//	std::cout << "Result sum :: " << sum(2.9, 7.9) << std::endl;
//	std::cout << "Result sum :: " << sum('a', 'b') << std::endl;
//	std::cout << "Result sum :: " << sum(line1, line2) << std::endl;
//	std::cout << "Result sum :: " << sum(1, 2.3) << std::endl;
//	std::cout << "Result sum :: " << sum(2.3, 1) << std::endl;
//
//	auto number = 2;
//	auto number2 = 2.6;
//	auto symbol = 'A';
//	auto line = line1;
//
//	cout << "\n\n" << endl;
//	const size_t SIZE = 10;
//	int arr[SIZE]{};
//
//
//	fillArray(arr, SIZE);
//	printArray(arr, SIZE);
//
//	int rnd[16]{};
//	fillArray(rnd, 16, 0, 15);
//	printArray(rnd, 16, "Helper array");
//
//
//	double arr_double[SIZE]{};
//	char arr_char[SIZE]{};
//
//	fillArray(arr_double, SIZE);
//	fillArray(arr_char, SIZE, 'a', 'z');
//
//	printArray(arr_double, SIZE, "Double array");
//	printArray(arr_char, SIZE, "Char array");

	const size_t SIZE = 5;
	int arr_int[SIZE]{};
	double arr_double[SIZE]{};
	char arr_char[SIZE]{};
	string arr_string[SIZE]{};

	inputArray(arr_int, SIZE);
	printArray(arr_int, SIZE, "Integer array");
	//cout << "First index of 1 is: " << firstIndexOfElem(arr_int, SIZE, 1) << endl;
	//cout << "Last index of 1 is: " << lastIndexOfElem(arr_int, SIZE, 1) << endl;
	//randChangeElem(arr_int, SIZE);
	//fillArrayOneElem(arr_int, SIZE, 7);
	sortElemUp(arr_int, SIZE);
	printArray(arr_int, SIZE, "Integer array");
	sortElemDown(arr_int, SIZE);
	printArray(arr_int, SIZE, "Integer array");

	inputArray(arr_double, SIZE);
	printArray(arr_double, SIZE, "Double array");
	//cout << "First index of 1.1 is: " << firstIndexOfElem(arr_double, SIZE, 1.1) << endl;
	//cout << "Last index of 1.1 is: " << lastIndexOfElem(arr_double, SIZE, 1.1) << endl;
	//randChangeElem(arr_double, SIZE);
	//fillArrayOneElem(arr_double, SIZE, 7.7);
	sortElemUp(arr_double, SIZE);
	printArray(arr_double, SIZE, "Double array");
	sortElemDown(arr_double, SIZE);
	printArray(arr_double, SIZE, "Double array");


	inputArray(arr_char, SIZE);
	printArray(arr_char, SIZE, "Char array");
	//cout << "First index of q is: " << firstIndexOfElem(arr_char, SIZE, 'q') << endl;
	//cout << "Last index of q is: " << lastIndexOfElem(arr_char, SIZE, 'q') << endl;
	//randChangeElem(arr_char, SIZE);
	//fillArrayOneElem(arr_char, SIZE, 'w');
	sortElemUp(arr_char, SIZE);
	printArray(arr_char, SIZE, "Char array");
	sortElemDown(arr_char, SIZE);
	printArray(arr_char, SIZE, "Char array");

	string line = "qwe";
	inputArray(arr_string, SIZE);
	printArray(arr_string, SIZE, "String array");

	cout << "First index of qwe is: " << firstIndexOfElem(arr_string, SIZE, line) << endl;
	cout << "Last index of qwe is: " << lastIndexOfElem(arr_string, SIZE, line) << endl;
	randChangeElem(arr_string, SIZE);
	fillArrayOneElem(arr_string, SIZE, line);
	sortElemUp(arr_string, SIZE);
	printArray(arr_string, SIZE, "String array");
	sortElemDown(arr_string, SIZE);
	printArray(arr_string, SIZE, "String array");

}
