#include <iostream>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

void out(const Fraction& fr) {
    if (fr.numerator == fr.denominator) {
        cout << "1" << endl;
    }
    else if ((fr.numerator == 0)) {
        cout << "0" << endl;
    }
    else {
        cout << fr.numerator << "/" << fr.denominator << endl;
    }
}
void inp(Fraction& fr) {
    cout << "Numerator :: ";
    cin >> fr.numerator;
    cout << "Denominator :: ";
    cin >> fr.denominator;

}

Fraction add(Fraction& fr1, Fraction& fr2) {
    Fraction tmp;
    tmp.denominator = fr1.denominator * fr2.denominator;
    tmp.numerator = fr1.denominator * fr2.numerator + fr2.denominator * fr1.numerator;
    return tmp;
}
Fraction sub(Fraction& fr1, Fraction& fr2) {
    Fraction tmp;
    tmp.denominator = fr1.denominator * fr2.denominator;
    tmp.numerator = fr1.denominator * fr2.numerator - fr2.denominator * fr1.numerator;
    return tmp;
}
Fraction mult(Fraction& fr1, Fraction& fr2) {
    Fraction tmp;
    tmp.denominator = fr1.denominator * fr2.denominator;
    tmp.numerator = fr1.numerator * fr2.numerator;
    return tmp;
}
Fraction div(Fraction& fr1, Fraction& fr2) {
    Fraction tmp;
    tmp.denominator = fr1.denominator / fr2.denominator;
    tmp.numerator = fr1.numerator / fr2.numerator;
    return tmp;
}

int main()
{
    Fraction fr1;
    inp(fr1);
    out(fr1);
    Fraction fr2;
    inp(fr2);
    out(fr2);

    cout << "add :: ";
    Fraction fr3 = add(fr1, fr2);
    out(fr3);
    cout << "sub :: ";
    fr3 = sub(fr1, fr2);
    out(fr3);
    cout << "mult :: ";
    fr3 = mult(fr1, fr2);
    out(fr3);
    cout << "div :: ";
    fr3 = div(fr1, fr2);
    out(fr3);
}
