#include <iostream>

using namespace std;

int main()
{   
	// Ex 1
    int num;
	cout << "Enter number: ";
    cin >> num;

    if (num < 100000 or num > 999999) {
		cout << "Error: Number must be a six-digit integer." << endl;
        return 0;
    }
	int sum1 = 0, sum2 = 0;
    sum1 += num / 100000;
	sum1 += (num / 10000) % 10;
	sum1 += (num / 1000) % 10;
	sum2 += (num / 100) % 10;
	sum2 += (num / 10) % 10;
	sum2 += num % 10;
	if (sum1 == sum2) {
		cout << "Lucky number!" << endl;
	} else {
		cout << "Not a lucky number." << endl;
	}

	// Ex 2

	int number;
	cout << "Enter number: ";
	cin >> number;
	if (number < 1000 or number > 9999) {
		cout << "Error: Number must be a four-digit integer." << endl;
		return 0;
	}

	int temp = number/1000;
	int reversed = temp*100;
	temp = (number / 10) % 10;
	reversed += temp;
	temp = (number / 100) % 10;
	reversed += temp*1000;
	temp = number % 10;
	reversed += temp * 10;

	cout << "Reversed number: " << reversed << endl;


	// Ex 3

	int a, b, c, d, e, f, g;
	cout << "Enter 7 nums:" << endl;
	cin >> a >> b >> c >> d >> e >> f >> g;

	int maxNum = a;

	if (b > maxNum) {
		maxNum = b;
	}
	if (c > maxNum) {
		maxNum = c;
	}
	if (d > maxNum) {
		maxNum = d;
	}
	if (e > maxNum) {
		maxNum = e;
	}
	if (f > maxNum) {
		maxNum = f;
	}
	if (g > maxNum) {
		maxNum = g;
	}

	cout << "Max num: " << maxNum << endl;

	// Ex 4
	int distAB, distBC, weight;
	cout << "Enter distance A-B: ";
	cin >> distAB;
	cout << "Enter distance B-C: ";
	cin >> distBC;
	cout << "Enter weight: ";
	cin >> weight;

	int fuelPerKm;

	if (weight <= 500) fuelPerKm = 1;
	else if (weight <= 1000) fuelPerKm = 4;
	else if (weight <= 1500) fuelPerKm = 7;
	else if (weight <= 2000) fuelPerKm = 9;
	else {
		cout << "Plane can't rise with that weight!" << endl;
		return 0;
	}

	int fuelAB = distAB * fuelPerKm;  
	int fuelBC = distBC * fuelPerKm; 

	if (fuelAB > 300) {
		cout << "Can't to cover the distance A-B!" << endl;
		return 0;
	}

	if (fuelBC > 300) {
		cout << "Can't to cover the distance B-C!" << endl;
		return 0;
	}

	int remaining = 300 - fuelAB;

	int refuel = 0;
	if (remaining < fuelBC) {
		refuel = fuelBC - remaining;
	}

	cout << "Min refuel in B: " << refuel << " litrs" << endl;

}

