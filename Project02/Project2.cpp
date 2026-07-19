#include <iostream>

using namespace std;

int main()
{
    /*int a, b;
    cout << "Enter number :: ";
    cin >> a;
    cout << "Enter number :: ";
    cin >> b;

    cout << a << " == " << b << " --> " << (a == b) << endl;
    cout << a << " >= " << b << " --> " << (a >= b) << endl;
    cout << a << " <= " << b << " --> " << (a <= b) << endl;
    cout << a << " > " << b << " --> " << (a > b) << endl;
    cout << a << " < " << b << " --> " << (a < b) << endl;
    cout << a << " != " << b << " --> " << (a != b) << endl;*/

    /*int day;
    cout << "Enter number day :: ";
    cin >> day;

    if (day == 1) {
        cout << "Monday" << endl;
    }
    else if (day == 2) {
        cout << "Tuesday" << endl;
    }
    else if (day == 3) {
        cout << "Wednsday" << endl;
    }
    else if (day == 4) {
        cout << "Thursday" << endl;
    }
    else if (day == 5) {
        cout << "Friday" << endl;
    }
    else if (day == 6) {
        cout << "Saturday" << endl;
    }
    else if (day == 7) {
        cout << "Sunday" << endl;
    }
    else {
        cout << "Error" << endl;
    }*/

    /*int number;
    cout << "Enter number" << endl;
    cin >> number;
    if (number >= 0 && number <= 20) {
        cout << "ok" << endl;
    } else {
        cout << "no ok" << endl;
    }*/

    /*int mounth;
    cout << "Enter number mounth" << endl;
    cin >> mounth;

    if (mounth == 1 || mounth == 3 || mounth == 5 || mounth == 7 || mounth == 8 || mounth == 10 || mounth == 12) {
        cout << "31 days" << endl;
    }
    else if (mounth == 4 || mounth == 6 || mounth == 9 || mounth == 11) {
        cout << "30 days" << endl;
    } 
    else if (mounth == 2) {
        int year;
        cout << "Enter year" << endl;
        cin >> year;
        cout << (year % 4 == 0 and year % 100 != 0 or year % 400 == 0 ? "29" : "28") << "days" << endl;
    }   */

    /*int day;
    cout << "Enter number day :: ";
    cin >> day;
    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednsay" << endl;
            break;
        default:
            cout << "Error" << endl;
    }*/
        
    /*int mounth;
    cout << "Enter number mounth" << endl;
    cin >> mounth;


    switch (mounth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "31 days" << endl;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << "30 days" << endl;
        break;
    case 2:
        int year;
        cout << "Enter year" << endl;
        cin >> year;
        cout << (year % 4 == 0 and year % 100 != 0 or year % 400 == 0 ? "29" : "28") << "days" << endl;
        break;
    default:
        cout << "Error" << endl;
        break;
    }*/

   
    

    /*int day, mounth;
    cout << "Enter dd mm:: ";
    cin >> day >> mounth;
    mounth--;
    int all_days = 0;
    switch (mounth) {
    case 11:
        all_days += 30;
    case 10:
        all_days += 31;
    case 9:
        all_days += 30;
    case 8:
        all_days += 31;
    case 7:
        all_days += 31;
    case 6:
        all_days += 30;
    case 5:
        all_days += 31;
    case 4:
        all_days += 30;
    case 3:
        all_days += 31;
    case 2:
        int year;
        cout << "Enter year" << endl;
        cin >> year;
        cout << (year % 4 == 0 and year % 100 != 0 or year % 400 == 0 ? "29" : "28") << "days" << endl;
        break;
    case 1:
        all_days += 31;
    }
    all_days += day;
    cout << "All days :: " << all_days << endl;*/


    
    //// Ex 1
    //
    //int num;
    //cout << "Enter num :: ";
    //cin >> num;
    //
    //if (num % 2 == 0) {
    //    cout << "Even" <<endl;
    //}
    //else {
    //    cout << "Odd" <<endl;

    //}
    //// Ex 2
    //
    //int num1;
    //int num2;
    //cout << "Enter num1 :: ";
    //cin >> num1;
    //cout << "Enter num2 :: ";
    //cin >> num2;

    //if (num1 < num2) {
    //    cout << "Less num1 : " << num1;
    //}
    //else if (num1 > num2) {
    //    cout << "Less num2 : " << num2;
    //}
    //else {
    //    cout << "Numbers are equals : " << num1;
    //}

    //// Ex 3
    //
    //int number;
    //cout << "Enter num :: ";
    //cin >> number;

    //if (number > 0) {
    //    cout << "Positive number " << endl;
    //}
    //else if (number < 0){
    //    cout << "Negative number " <<endl;
    //}
    //else {
    //    cout << "Number is 0" <<endl;
    //}

    //// Ex 4

    //int n1;
    //int n2;
    //cout << "Enter num1 :: ";
    //cin >> n1;
    //cout << "Enter num2 :: ";
    //cin >> n2;

    //if (n1 < n2) {
    //    cout << n1 << ":" << n2;
    //}
    //else if (n1 > n2) {
    //    cout << n2 << ":" << n1;
    //}
    //else {
    //    cout << "Numbers are equals : " << n1;
    //}

    // Ex 1
    
    int n1, n2, n3, n4, n5;
    cout << "Enter 5 marks :: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    cout << (((n1 + n2 + n3 + n4 + n5) / 5.0) > 4 ? "Admitted" : "No Admitted");
    
    
    // Ex 2
    int num;
    cout << "Enter num :: ";
    cin >> num;
    if (num % 2 == 0) {
        num *= 3;
    }
    else {
        num /= 2.0;
    }
    cout << "num = " << num << endl;

    // Ex 3

    double a, b, result;
    char op;

    cout << "Enter num1: ";
    cin >> a;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter num2: ";
    cin >> b;

    switch (op) {
    case '+':
        result = a + b;
        cout << "Reuslt: " << result << endl;
        break;
    case '-':
        result = a - b;
        cout << "Reuslt: " << result << endl;
        break;
    case '*':
        result = a * b;
        cout << "Reuslt: " << result << endl;
        break;
    case '/':
        if (b != 0) {
            result = a / b;
            cout << "Reuslt: " << result << endl;
        }
        else {
            cout << "Null Exception!" << endl;
        }
        break;
    default:
        cout << "Error!" << endl;
    }
}

