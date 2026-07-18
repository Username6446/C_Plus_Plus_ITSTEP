#include <iostream>
using namespace std;

const double PI = 3.14;

void showMessage(int age, string name = "Anonim")
{
	if (age < 16)
	{
		cout << "Exit! " << name << endl;
		return;
	}

	cout << "Hello, " << name << endl;

	/*if (age >= 16)
		cout << "Hello, " << name << endl;
	else
		cout << "Exit! " << name << endl;*/
}



int sum(int a, int b)
{
	/*int res = a + b;
	return res;*/
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mult(int a, int b)
{
	return a * b;
}

double divi(int a, int b)
{
	if (b == 0) {
		return 0;
	}
	return (double)a / b;
	// double / int ==> double
}


double calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return sum(a, b);
	case '-':
		return sub(a, b);
	case '*':
		return mult(a, b);
	case '/':
		return divi(a, b);
	}
}

void func1(int a, int b) {
	cout << "Ex1" << endl;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

double func2(int a) {
	cout << "Ex2" << endl;
	double num = 1;
	for (int i = 2; i <= a; i++) {
		num *= i;
	}
	return num;
}

bool func3(int a) {
	cout << "Ex3" << endl;
	for (int i = 2; i <= (a / 2); i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

int func4(int a) {
	cout << "Ex3" << endl;
	return a * a * a;
}

int func5(int a, int b) {
	cout << "Ex5" << endl;
	return a > b ? a : b;
}

int func6(int a) {
	cout << "Ex6" << endl;
	return a > 0 ? true : false;
}

void func7(int arr[10]) {
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < 10; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
}

void func8(int arr[10]) {
	for (int i = 9; i >= 0; i--) {
		cout << arr[i] << " ";
	}
}

int func9(int arr[10]) {
	int count = 0;
	for (int i = 0; i < 10; i++) {
		bool flag = true;              
		if (arr[i] <= 1) {
			continue;
		}
		for (int j = 2; j <= arr[i] / 2; j++) {
			if (arr[i] % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			count++;
		}
	}
	return count;
}

int main()
{
	
	/*func1(3, 5);
	cout << func2(5) << "\n\n";
	cout << func3(7) << "\n\n";
	cout << func4(2) << "\n\n";
	cout << func5(2, 3) << "\n\n";
	cout << func6(-1) << "\n\n";*/

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	func7(arr);
	func8(arr);
	cout << "\n" << func9(arr) << "\n\n";

	//showMessage("Olia", 18); // Invoke
	//showMessage("Sasha", 14); // Invoke

	/*int res = sum(5, 2);
	cout << res << endl;

	int res_2 = sum(res, 33);
	cout << res_2 << endl;

	int numb_1, numb_2;
	cout << "Enter two number :: ";
	cin >> numb_1 >> numb_2;

	cout << "Sum  :: " << numb_1 << " + " << numb_2 << " = " << sum(numb_1, numb_2) << endl;
	cout << "Sub  :: " << numb_1 << " - " << numb_2 << " = " << sub(numb_1, numb_2) << endl;
	cout << "Mult :: " << numb_1 << " * " << numb_2 << " = " << mult(numb_1, numb_2) << endl;
	cout << "Div  :: " << numb_1 << " / " << numb_2 << " = " << divi(numb_1, numb_2) << endl;*/

	//int a, b;
	//char op;

	//while (true)
	//{
	//	cout << "Enter :: "; // 2 + 2
	//	cin >> a >> op >> b;
	//	cout << a << " " << op << " " << b << " = " << calculate(a, b, op) << endl;
	//}
	/*showMessage(20);
	showMessage(20, "Masha");*/

}