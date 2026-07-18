#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class City
{
private:
    char* name = nullptr;
    char* country = nullptr;
    size_t population = 0;
    void CopystrField(char*& dest, const char* source)
    {
        if (name != nullptr)
            delete[] dest;
        size_t size = strlen(source) + 1;
        dest = new char[size];
        strcpy_s(dest, size, source);
    }
    bool isValidName(const char* name)
    {
        if (name == nullptr or name != "\0") {
            return false;
        }
        return true;
    }


public:
    City() = default;
    City(const char* name) : City(name, "NoCountry")
    {
        cout << "Ctor with 1 parameter " << endl;
    }

    City(const char* name, const char* country) : City(name, country, 0) 
    {
        cout << "Ctor with 2 parameter " << endl;
    }

    City(const char* name, const char* country, const size_t& population) : population{population}
    {
        cout << "Ctor with 3 parameter " << endl;
        setName(name);
        setCountry(country);
    }

    void setName(const char* name)
    {
        CopystrField(this->name, name);
    }
    
    void setCountry(const char* country)
    {
        if(isValidName(name))
            CopystrField(this->country, country);
    }
    
    const char* getName() const
    {
        return this->name;
    }
    
    const char* getCountry() const
    {
        return this->country;
    }

    ~City()
    {
        cout << "Dtor with  " << this->name << endl;
        if (this->name != nullptr)
            delete[] this->name;
        if (this->country!= nullptr)
            delete[] this->country;

    }
    void print() const
    {
        cout << "Name       :: " << this->name << endl;
        cout << "Country    :: " << this->country << endl;
        cout << "Population :: " << this->population << endl;
    }

};


class Dot
{
private:
    int x = 0;
    int y = 0;
    int z = 0;
public:

    Dot() = default;

    Dot(int x) : x(x) {}

    Dot(int x, int y) : x(x), y(y) {}

    Dot(int x, int y, int z) : x(x), y(y), z(z) {} 


    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    void setZ(int z) {
        this->z = z;
    }

    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    int getZ() const {
        return z;
    }

    void print() {
        cout << "X :: " << x << endl;
        cout << "Y :: " << y << endl;
        cout << "Z :: " << z << endl;
        cout << endl;
    }
    
    void input() {
        cout << "X :: "; cin >> x;
        cout << "Y :: "; cin >> y;
        cout << "Z :: "; cin >> z;
    }

    void FileSave(const char* filename) {
        fstream file(filename, ios_base::out);
        if (!file.is_open())
        {
    	    cout << "File not found" << endl;
    	    return;
        }
        file << "X :: " << x << endl;
        file << "Y :: " << y << endl;
        file << "Z :: " << z << endl;
    }
    void FileRead(const char* filename) {
        fstream file(filename, ios_base::in);
        if (!file.is_open())
        {
            cout << "File not found" << endl;
            return;
        }
        string text;
        while (getline(file, text)) {
            cout << text << endl;
        }
    }
};

int main()
{
    /*char* tmp = new char['R', 'i', 'v', 'v', 'n', 'e', '\0'];*/
    /*string test = "Rivne";
    City rivne("Rivne", "Ukraine", 234325);
    rivne.print();

    City paris("Paris");
    paris.print();*/

    /*delete[] tmp;
    tmp = nullptr;*/

    //Dot d1;
    //d1.print();
    //d1.input();
    //d1.print();
    Dot d2(3,4,5);
    //d2.print();
    //d2.input();
    //d2.print();
    //d2.FileSave("data.txt");
    d2.FileRead("data.txt");

}
