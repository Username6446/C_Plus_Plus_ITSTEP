#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	//// Ex1
	//srand(time(0));
	//int arr[10] = { 0 };
	//for (int i = 0; i < 10; i++)
	//{
	//	arr[i] = rand() % 10;
	//	cout << arr[i] << " ";
	//}

	//int max = arr[0];
	//int min= arr[0];
	//for (int i = 0; i < 10; i++) {
	//	if(arr[i] > max) {
	//		max = arr[i];
	//	}
	//	if(arr[i] < min) {
	//		min = arr[i];
	//	}
	//}
	//cout << "\nMax: " << max << "\nMin: " << min << endl;


	// Ex2
    double salary_12[12] = { 0 };
    for (int i = 0; i < 12; i++) {
        cout << "Enter earn for " << i + 1 << " month: ";
        cin >> salary_12[i];
        
    }
	double max_12 = 0;
	double min_12 = 0;
	double ind_max = 0;
	double ind_min = 0;
	int start = 0;
	int end = 0;
	cout << "Enter start:";
	cin >> start;
	cout << "Enter end:";
	cin >> end;
	for(int i = start-1; i < end; i++) {
		if (i == 0) {
			max_12 = salary_12[i];
			min_12 = salary_12[i];
		}
		if (salary_12[i] > max_12) {
			max_12 = salary_12[i];
			ind_max = i;
		}
		else if (salary_12[i] < min_12) {
			min_12 = salary_12[i];
			ind_min = i;
		}
	}
	cout << "Max earn from " << start << " to " << end << " mounth: " << ind_max+1 << endl;
	cout << "Min earn from " << start << " to " << end << " mounth: " << ind_min+1 << endl;

	//Ex3

	const int N = 10;
	double arr3[N] = { 1,3,-1,3,2,8,-3,5,2,9 };
	double sum = 0;
	double sum_pair = 1;
	double sum_min_max = 1;
	double sum_first_last = 0;
	double first_neg = 0;
	double last_neg = 0;
	for (int i = 0; i < N; i++) {
		if(arr3[i] < 0 && first_neg == 0) {
			first_neg = i;
		}
		else if (arr3[i] < 0) {
			last_neg = i;
		}
		if(i%2 == 0) {
			sum_pair *= arr3[i];
		}
		if (arr3[i] < 0) {
			sum += arr3[i];
		}
		if (i == 0) {
			max_12 = salary_12[i];
			min_12 = salary_12[i];
		}
		if (salary_12[i] > max_12) {
			max_12 = salary_12[i];
			ind_max = i;
		}
		else if (salary_12[i] < min_12) {
			min_12 = salary_12[i];
			ind_min = i;
		}
	}
	if (ind_max < ind_min) {
		ind_max = ind_min + ind_max;
		ind_min = ind_max - ind_min;
		ind_max = ind_max - ind_min;
	}
	for(int i=ind_min; i<=ind_max; i++) {
		sum_min_max *= arr3[i];
	}
	for (int i = first_neg; i <= last_neg; i++) {
		sum_first_last += arr3[i];
	}
	cout << "Sum neg: " << sum << endl;
	cout << "Sum between min and max: " << sum_min_max << endl;
	cout << "Sum pair: " << sum_pair << endl;
	cout << "Sum between first and last neg: " << sum_first_last << endl;

}
