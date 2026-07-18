#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
//__interface
// interface - пропонує абстрактну поведінку (може містити чисті віртуальні методи)

template <typename ContType>
void print(const ContType cont, const string& prompt = "")
{
    cout << "\n\n" << prompt << endl;
    for (auto& i : cont)
    {
        cout << i << "\t";
    }
    cout << endl;
}

struct IMove
{
    virtual void move() const = 0;
    virtual size_t getSpeed() const = 0;
};
struct IFly :/*public*/ IMove // by default struct inherits as public
{
    virtual void fly() const = 0;
    virtual size_t getFlyHeight() const = 0;
};
class Bird : public IFly // клас реалізує інтерфейс IFly = реалізує кожен віртуальний метод
{
    size_t height;
    size_t speed;
public:
    Bird(const size_t& height, const size_t& speed)
        :height{ height }, speed{ speed }
    {
    }
    void move() const
    {
        cout << "Bird " << typeid(*this).name() << " can walk and fly \n";
    }

    // Inherited via IFly
    virtual size_t getSpeed() const override
    {
        return speed;
    }
    virtual void fly() const override
    {
        cout << "Bird " << typeid(*this).name() << " can  fly on height " << getFlyHeight() << "\n";
    }
    virtual size_t getFlyHeight() const override
    {
        return height;
    }
};
class Eagle : public Bird
{
public:
    Eagle()
        :Bird(2000, 30)
    {}
};
class Gull : public Bird
{
public:
    Gull()
        :Bird(500, 5)
    {}
};
class Car : public IMove
{
    string brand;
public:
    Car(const string& brand)
        :brand(brand)
    { }

    // Inherited via IMove
    virtual void move() const override
    {
        cout << "Car " << brand << " can move with speed " << getSpeed() << endl;
    }
    virtual size_t getSpeed() const override
    {
        return 200;
    }
};
void demoMoveable(IMove* movable)
{
    cout << "______ Demo func ________" << endl;
    movable->move();
    cout << "Speed of moving :: " << movable->getSpeed() << endl;
}
class Owner
{
    string name;
    IMove* moveable;
public:
    Owner(const string& name, IMove* moveable)
        :name{name}, moveable{moveable}
    {}
    void go()
    {
        moveable->move();
    }
    void setMoveable(IMove* moveable)
    {
        this->moveable = moveable;
    }
};

//int main()
//{
//    Eagle eagle;
//    eagle.fly();
//
//    Gull gull;
//    gull.move();
//
//    IMove* im = &eagle;
//    im->move();
//
//    IFly& ifl = eagle;
//    ifl.fly();
//
//    Car car("BMW");
//    demoMoveable(&car);
//    demoMoveable(&eagle);
//    
//    IMove* moving[]{ &eagle, &gull, &car };
//    cout << "\n\n";
//    for (auto& i : moving)
//    {
//        demoMoveable(i);
//    }
//
//    IFly* fliers[]{ &eagle, &gull};
//    cout << "\n\n";
//    for (auto& i : fliers)
//    {
//        i->fly();
//    }
//
//    cout << "\n\n";
//
//    Owner owner("Sergir", &car);
//    owner.go();
//    owner.setMoveable(&gull);
//    owner.go();
//}

bool div3(int number)
{
    return number % 3 == 0;
}

int inc(int el)
{
    return el + 1;
}

int main()
{
    const size_t size = 5;
    array<int, size> arr{ 10,33,4,-5,77 };

    cout << "Print container array [] :: \t";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    cout << "Print container array [] :: \t";
    for (array<int,size>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;

    cout << "Print container reverse array [] :: \t";
    for (array<int,size>::reverse_iterator it = arr.rbegin(); it != arr.rend(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;

    //cout << "getValue[5] :: " << arr.at(5) << endl; error

    auto it = min_element(arr.begin(), arr.end());
    cout << "Min in array :: " << *it << endl;
    *it *= -1;
    print(arr, "After modifuing min(*-1)");

    it = max_element(arr.begin(), arr.end());
    cout << "Max in array :: " << *it << endl;

    vector<int> v(arr.rbegin(), arr.rend());
    print(v, "Vector ( as reverse copy of arr)");
    v.push_back(333);
    v.insert(v.begin() + 2, 777);
    print(v, "Vector ( after push and insert)");
    
    v.insert(v.begin() + v.size() / 2,{1,2,3,4});
    
    print(v, "Vector ( after push and insert)");

    deque<int> d{ v.begin(), v.begin() + v.size() / 2 };
    print(d, "Deque ( copy 1-st half of vector )");

    d.resize(v.size(), -1);
    print(d, "Deque ( resize )");

    copy(v.rbegin(), v.rend() - v.size() / 2, d.begin() + d.size() / 2);
    print(d, "Deque ( copy 2-nd half of vector )");

    d.push_back(222);
    print(d, "Deque (after push)");

    deque<int>::iterator itF = find(d.begin(), d.end(), 4);

    while (itF != d.end())
    {
        cout << "Found value :: " << 4 << " in index " << itF - d.begin() << endl;
        itF = find(itF+1, d.end(), 4);
    }
    cout << "\Count of value 4 :: " << count(d.begin(), d.end(), 4) << endl;
    
    itF = find_if(d.begin(), d.end(), div3);
    while (itF != d.end())
    {
        cout << "Found value :: in index " << itF - d.begin() << endl;
        itF = find_if(itF + 1, d.end(), div3);
    }
    
    print(d, "Degue");
    transform(d.begin(), d.end(), d.begin(), inc);
    print(d, "Degue ( after transform)");

    sort(d.begin(), d.end());
    print(d, "Degue ( after sort up)");
    sort(d.begin(), d.end(), greater<int>());
    print(d, "Degue ( after sort down)");
    sort(d.rbegin(), d.rend());
    print(d, "Degue ( after sort down)");

    vector<int> vect{ 1,2,3,4,5 };
    print(vect, "Print vector");
    cout << "Size :: " << vect.size() << "\tCapacity :: " << vect.capacity() << endl;

    vect.push_back(11);
    print(vect, "Print vector");
    cout << "Size :: " << vect.size() << "\tCapacity :: " << vect.capacity() << endl;
    
    vect.push_back(11);
    vect.push_back(11);
    print(vect, "Print vector");
    cout << "Size :: " << vect.size() << "\tCapacity :: " << vect.capacity() << endl;
    
}
