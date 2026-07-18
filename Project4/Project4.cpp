#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    //srand(time(0));
    //const int SIZE = 10;
    //int arr[SIZE];

    //int length = sizeof(arr) / sizeof(arr[0]);

    ////Input value
    ///*for (size_t i = 0; i < length; i++)
    //{
    //    cout << "Enter number :: ";
    //    cin >> arr[i];
    //}*/
    ////for (size_t i = 0; i < 10; i++)
    ////{
    ////    //cout << "Random :: " << rand() % 10 + 1 << endl; // [0 + 1 .... 9 + 1]
    ////    //cout << "Random :: " << rand() % (15 + 1)  + 5 << endl; // [5 - 20] - [0 + 5 ..... 15 + 5 = 20]
    ////    //rand() % (max - min + 1) + min
    ////}

    //// Fill
    //for (size_t i = 0; i < length;)
    //{
    //    bool flag = true;
    //    int number = rand() % 10 + 1;

    //    for (size_t j = 0; j < i; j++)
    //    {
    //        if (arr[j] == number) {
    //            flag = false;
    //            break;
    //        }
    //    }

    //    if (flag)
    //    {
    //        arr[i] = number;
    //        i++;
    //    }
    //}

    //cout << "Print Array :: \t ";
    //for (size_t i = 0; i < length; i++)
    //{
    //    cout << arr[i] << "\t";
    //}
    //cout << endl;


    //cout << "Reverse Array :: \t ";
    //for (int i = length - 1; i >= 0; i--)
    //{
    //    cout << arr[i] << "\t";
    //}
    //cout << endl;


    //string colors[3]{ "red","green","blue" };
    //for (size_t i = 0; i < 3; i++)
    //{
    //    cout << colors[i] << endl;
    //}
	

	////Task 1
	//double salary_6[6] = { 0 };
	//double sum_6 = 0;
	//for(int i = 0; i < 6; i++) {
	//	cout << "Enter earn for " << i + 1 << " month: ";
	//	cin >> salary_6[i];
	//	sum_6 += salary_6[i];
	//}
	//cout << "6 mounth earn : " << sum_6 << endl;

	////Task 2

	//const int length = 10;
	//int arr[length] = { 1,2,3,4,5,6,7,8,9,10 };

 //   cout << "Reverse Array ::";
 //   for (int i = length - 1; i >= 0; i--)
 //   {
 //       cout << arr[i] << "\t";
 //   }
 //   cout << endl;

 //   //Task 3

 //   double sides[5] = { 0 };
 //   double Perimetr = 0;
 //   for (int i = 0; i < 5; i++) {
 //       cout << "Enter " << i+1 << " side of pentagon : ";
 //       cin >> sides[i];
 //       Perimetr += sides[i];
 //   }
 //   cout << "Perimetr : " << Perimetr << endl;


 //   //Task 4
 //   double salary_12[12] = { 0 };
 //   double max_12 = 0;
 //   double min_12 = 0;
 //   double ind_max = 0;
 //   double ind_min = 0;
 //   for (int i = 0; i < 12; i++) {
 //       cout << "Enter earn for " << i + 1 << " month: ";
 //       cin >> salary_12[i];
 //       if (i == 0) {
 //           max_12 = salary_12[i];
 //           min_12 = salary_12[i];
	//	}
 //       if (salary_12[i] > max_12) {
 //           max_12 = salary_12[i];
	//		ind_max = i;
	//	}
 //       else if (salary_12[i] < min_12) {
 //           min_12 = salary_12[i];
 //           ind_min = i;
	//	}
 //   }
 //   
	//cout << "Max earn in mounth: " << ind_max+1 << endl;
	//cout << "Min earn in mounth: " << ind_min+1 << endl;


 //   //Task 5
        
int arr5[9] = { 1,2,0,3,0,2,4, 0, 1 }; // 1 2 3 2 4 1 0 0 0
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            if(arr5[j] == 0 and arr5[j]+1 != 0) {
                arr5[j] = arr5[j + 1];
                arr5[j + 1] = 0;
			}
        }
	}

    for (int i = 0; i < 9; i++) {
        if (arr5[i] == 0) {
            arr5[i] = -1;
        }
    }

    cout << "Arr  :: \t";
    for (int i = 0; i < 7; i++) {
        cout << arr5[i] << "\t";
    }
	cout << endl;

 //   //Task 6


    srand(time(0));
    int arr1[5] = { 0 };
    int arr2[5] = { 0 };
    int arr3[10] = { 0 };

    for (int i = 0; i < 5; i++) {
        arr1[i] = rand() % 20 - 10;
        arr2[i] = rand() % 20 - 10;
    }
    cout << "Array 1:\t";

    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << "\t";
    }
    cout << endl;
    cout << "Array 2:\t";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << "\t";
    }
    cout << endl;
    int count = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (count >= 10) break;
            if (i == 1 and arr1[j] > 0) {
                arr3[count] = arr1[j];
                count++;
            }
            else if (i == 2 and arr2[j] > 0) {
                arr3[count] = arr2[j];
                count++;
            }
            else if (i == 3 and arr1[j] == 0) {
                arr3[count] = arr1[j];
                count++;
            }
            else if (i == 4 and arr2[j] == 0) {
                arr3[count] = arr2[j];
                count++;
            }
            else if (i == 5 and arr1[j] < 0) {
                arr3[count] = arr1[j];
                count++;
            }
            else if (i == 6 and arr2[j] < 0) {
                arr3[count] = arr2[j];
                count++;
            }
        }
    }
    cout << "Array 3:\t";
    for (int i = 0; i < 10; i++) {
        cout << arr3[i] << "\t";
    }
    cout << endl;



}

