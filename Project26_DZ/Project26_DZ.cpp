#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    cout << "=== 1. Init & Assignment ===" << endl;
    String s1("Microsoft");
    String s2("Windows");
    String s3;

    s3 = s1;

    cout << "s1: "; s1.output();
    cout << "s2: "; s2.output();
    cout << "s3 (copy of s1): "; s3.output();
    cout << endl;

    cout << "=== 2. Arithmetic Operators ===" << endl;

    String sPlus = s1 + s2;
    cout << "s1 + s2 (Concat): ";
    sPlus.output();


    String sMul = s1 * s2;
    cout << "s1 * s2 (Intersection): ";
    sMul.output();

    String sDiv = s1 / s2;
    cout << "s1 / s2 (Difference): ";
    sDiv.output();
    cout << endl;

    cout << "=== 3. Increment Operators ===" << endl;
    String sInc("abc");
    cout << "Original: "; sInc.output();

    String resPrefix = ++sInc;
    cout << "After ++sInc (str is 'bcd'): "; sInc.output();
    cout << "Result of expression (is 'bcd'): "; resPrefix.output();

    String resPostfix = sInc++;
    cout << "After sInc++ (str is 'cde'): "; sInc.output();
    cout << "Result of expression (was 'bcd'): "; resPostfix.output();
    cout << endl;

    cout << "=== 4. Comparison Operators ===" << endl;
    String apple("Apple");
    String banana("Banana");
    String apple2("Apple");

    cout << "Apple == Banana: " << (apple == banana ? "True" : "False") << endl;
    cout << "Apple == Apple:  " << (apple == apple2 ? "True" : "False") << endl;
    cout << "Apple != Banana: " << (apple != banana ? "True" : "False") << endl;

    cout << "Apple < Banana:  " << (apple < banana ? "True" : "False") << endl;
    cout << "Apple > Banana:  " << (apple > banana ? "True" : "False") << endl;

    cout << "Apple >= Apple:  " << (apple >= apple2 ? "True" : "False") << endl;
    cout << "Apple <= Banana: " << (apple <= banana ? "True" : "False") << endl;
    cout << endl;

    cout << "=== 5. Static Methods ===" << endl;
    cout << "Active objects count: " << String::getCount() << endl;

    cout << "\nSorting array:" << endl;
    String arr[3];
    arr[0] = String("Zebra");
    arr[1] = String("Alpha");
    arr[2] = String("Cobra");

    cout << "Before sort:" << endl;
    for (int i = 0; i < 3; i++) { cout << "- "; arr[i].output(); }

    String::sort(arr, 3);

    cout << "After sort:" << endl;
    for (int i = 0; i < 3; i++) { cout << "- "; arr[i].output(); }

    return 0;
}