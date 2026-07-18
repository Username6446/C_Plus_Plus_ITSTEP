#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
	
    int numerator = 1;
    int denominator = 1;

    void simplify() {
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }


public:

    Fraction() = default;
    Fraction(int n, int d) : numerator(n), denominator(d) {
        simplify();
    }

    void out() {
        if (this->numerator == this->denominator) {
            cout << "1" << endl;
        }
        else if ((this->numerator == 0)) {
            cout << "0" << endl;
        }
        else {
            cout << this->numerator << "/" << this->denominator << endl;
        }
    }
    void inp() {
        cout << "Numerator :: ";
        cin >> this->numerator;
        cout << "Denominator :: ";
        cin >> this->denominator;
        simplify();

    }

    Fraction add(Fraction& fr2) {
        Fraction tmp;
        tmp.denominator = this->denominator * fr2.denominator;
        tmp.numerator = this->denominator * fr2.numerator + fr2.denominator * this->numerator;
        tmp.simplify();
        return tmp;
    }
    Fraction sub(Fraction& fr2) {
        Fraction tmp;
        tmp.denominator = this->denominator * fr2.denominator;
        tmp.numerator = this->denominator * fr2.numerator - fr2.denominator * this->numerator;
        tmp.simplify();
        return tmp;
    }
    Fraction mult(Fraction& fr2) {
        Fraction tmp;
        tmp.denominator = this->denominator * fr2.denominator;
        tmp.numerator = this->numerator * fr2.numerator;
        tmp.simplify();
        return tmp;
    }
    Fraction div(Fraction& fr2) {
        Fraction tmp;
        tmp.denominator = this->numerator * fr2.denominator;
        tmp.numerator = this->denominator * fr2.numerator;
        tmp.simplify();
        return tmp;
    }

};

int main()
{
    Fraction fr1;
    fr1.inp();
    fr1.out();
    Fraction fr2;
    fr2.inp();
    fr2.out();

    cout << "add :: ";
    Fraction fr3 = fr1.add(fr2);
    fr3.out();
    cout << "sub :: ";
    fr3 = fr1.sub(fr2);
    fr3.out();
    cout << "mult :: ";
    fr3 = fr1.mult(fr2);
    fr3.out();
    cout << "div :: ";
    fr3 = fr1.div(fr2);
    fr3.out();
}
