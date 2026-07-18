#include <iostream>
#include <windows.h>
using namespace std;

int func1(int a, int b) {
    int res = a;
    for (int i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

int func2(int a, int b) {
    int res = 0;
    for (int i = a; i <= b; i++) {
        res += i;
    }
    return res;
}

int func3_1(int a) {
    int sum = 0;
    for (int i = 1; i < a; i++) {
		if (a % i == 0)
        sum += i;
    }
    return sum == a;
}

void func3(int a, int b) {
    for (int i = a; i < b; i++) {
		if(func3_1(i)) cout << i << " ";
    }
}

void func4(string num, int m) {
    string mastes[] = { u8"♠", u8"♥", u8"♦", u8"♣" };
    cout << num << mastes[m] << endl;
}

void func5(int n) {
    if (n < 100000 || n > 999999) {
        cout << n << " is NOT a six-digit number!" << endl;
        return;
    }

    if ((n % 10 + n / 10 % 10 + n / 100 % 10)== (n / 100000 + n / 10000 % 10 + n/1000%10 ))
        cout << n << " is a happy six-digit number :)" << endl;
    else
        cout << n << " is NOT a happy six-digit number :(" << endl;
}



int main()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << func1(2, 4) << endl;
    cout << func2(2, 4) << endl;
    func3(2, 1000);
    cout << endl;
    func4("A", 0); 
	func5(123421);
      

}

