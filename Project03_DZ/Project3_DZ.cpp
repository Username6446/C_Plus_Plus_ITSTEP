#include <iostream>

using namespace std;

int main()
{
    // Ex1
    
    int a;
	cout << "Enter a: ";
    cin >> a;
    int sum = 0;
    for (int i = a; i <= 500; i++) {
        sum += i;
    }

	cout << "Sum: " << sum << endl;

    // Ex2

    int x;
    int y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
	int pow = 1;
    for (int i=1;i<=y; i++) {
		pow *= x;
	}
    cout << "x^y: " << pow << endl;

    // Ex3
    double Sum = 0;
    for (int i = 1; i <= 1000; i++) {
        Sum += i;
    }
	cout << "Average : " << Sum/1000 << endl;

    // Ex4

    int A;
    cout << "Enter A: ";
    cin >> A;
    sum = 1;
    for (int i = A; i <= 20; i++) {
        sum *= i;
    }

    cout << "Sum: " << sum << endl;

    // Ex5


	int N;
    cout << "Enter N: ";
    cin >> N;
    for (int i = 1; i <= 10; i++) {
		cout << N << " x " << i << " = " << N * i << endl;
    }

}

