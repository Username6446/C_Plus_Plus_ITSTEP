#include <iostream>
#include <vector>
#include "Animal.h"
#include "Lion.h"
#include "Wolf.h"

using namespace std;

enum Colors
{
    REd, GREEN, BLUE
};

struct Point
{
    int x = 0, y = 0;
    virtual void print() const
    {
        cout << "{" << x << ", " << y << "}" << endl;
    }
};

struct Point3D : Point // public inheritance by default for struct
{
    int z = 0;

    void print() const override
    {
        cout << "{" << x << ", " << y << ", " << z << "}" << endl;
    }
};

struct String
{
    string str; // - 1
};

int main()
{
    /*Animal animal("S", 3);  // cannot create object of abstract class
    animal.print();*/
    //Lion lion("south africa", 3);
    //lion.print();
    //lion.move();
    //Wolf wolf("North africa", 1);
    //wolf.print();
    //vector<Animal*> zoo{ &lion, (Animal*)&wolf, new Lion("CENTRAL AFRICA", 6, true) };
    //for (size_t i = 0; i < zoo.size(); i++)
    //{
    //    zoo[i]->print();
    //    zoo[i]->eat();
    //    zoo[i]->move();
    //}
    //delete zoo[2];
    //cout << "\n\n End of main" << endl;

    char ch = { 90 };

    int numb = 2;
    int a = { numb };

    cout << "Char(122) = " << char(122) << endl;
    cout << "int() Colors::GREEN= " << (int)Colors::GREEN << endl;

    Point point;
    point.x = 1;
    point.y = 2;

    //String str = (String&)point; // dont hae error of compilation
    //cout << "String number = (String&)point :: " << str.str << endl;

    cout << "\n ______________________________ Static_cast ______________________________ \n";
    cout << "Static_cast<char>(Colors::GREEN) = " << static_cast<char>(Colors::GREEN) << endl;

    //String str = static_cast<String&>(point); // compile error - good

    Point3D point3d;
    point3d.x = 1;
    point3d.y = 2;
    point3d.z = 3;

    Point point_ = point3d; // ok accesed from derivative to base type
    cout << "\n\npoint_ :: ";
    point_.print();
    
    //Point3D point3 = (Point3D&)point; // ok accesed from derivative to base type

    if (typeid(point_) == typeid(Point3D))
    {
        Point3D point3 = static_cast<Point3D&>(point_);
        cout << "\n\npoint3 :: ";
        point3.print();
    }




}
