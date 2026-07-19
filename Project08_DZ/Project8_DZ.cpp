#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int getDaysInMonth(int year, int month) {
    int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysPerMonth[month - 1];
}

int countDaysBetween(int startDay, int startMonth, int startYear,
    int endDay, int endMonth, int endYear) {

    if (startDay == endDay && startMonth == endMonth && startYear == endYear) {
        return 0;
    }

    int totalDays = 0;

    for (int year = startYear + 1; year < endYear; year++) {
        totalDays += isLeapYear(year) ? 366 : 365;
    }

    if (startYear != endYear) {
        for (int month = startMonth; month <= 12; month++) {
            int daysInMonth = getDaysInMonth(startYear, month);
            if (month == startMonth) {
                totalDays += daysInMonth - startDay;
            }
            else {
                totalDays += daysInMonth;
            }
        }
    }

    if (startYear != endYear) {
        for (int month = 1; month < endMonth; month++) {
            totalDays += getDaysInMonth(endYear, month);
        }
        totalDays += endDay;
    }
    else {
        for (int month = startMonth; month < endMonth; month++) {
            totalDays += getDaysInMonth(startYear, month);
        }
        totalDays += endDay - startDay;
    }

    return totalDays;
}

template <typename T>
T average(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
	}
	return sum / size;  
}

template <typename T>
void countOfPosNegNull(T arr[], int size) {
	int countPos = 0, countNeg = 0, countNull = 0;
    for (int i = 0; i < size; i++) {
		if (arr[i] > 0) countPos++;
        else if (arr[i] < 0) countNeg++;
		else countNull++;
	}
	cout << "Positive: " << countPos << ", Negative: " << countNeg << ", Null: " 
        << countNull << endl;
}



int main()
{
	int days = countDaysBetween(1, 1, 2020, 1, 1, 2021);
    cout << days << endl;
	double arr[] = { 1.1, -2, 0, 4, 5 };
    cout << average(arr, 5) << endl;
    countOfPosNegNull(arr, 5);
}
