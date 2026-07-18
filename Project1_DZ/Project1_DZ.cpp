#include <iostream>

using namespace std;
//using std::cout;
//using std::endl;
//using std::boolalpha;

int main()
{
    cout << "\t\t\tEx1\n\n";
    int r1 = 2;
    int r2 = 4;
    int r3 = 8;
    double r0 = (double)1 / ((double)1 / r1 + (double)1 / r2 + (double)1 / r3);
    cout << "Res :: " << r0 << endl;
    
    cout << "\t\t\tEx2\n\n ";

    const double PI = 3.14;
    
    double L;
	cout << "L = ";
	cin >> L;
    double R = L / 2 / PI;
	double S = PI * R * R;
	cout << "Area = " << S << endl;
    
    cout << "\t\t\tEx3\n\n ";

    double v, t, a;
	cout << "v = ";
	cin >> v;
	cout << "t = ";
    cin >> t;
	cout << "a = ";
	cin >> a;
	S = v * t + a * t * t / 2;
    cout << "S = " << S << endl;

}

