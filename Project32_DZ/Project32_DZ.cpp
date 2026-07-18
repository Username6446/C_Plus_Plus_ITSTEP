#include <iostream>
#include "DList.h" 

using namespace std;

int main()
{
    DList<int> list1;

    list1.AddHead(10);
    list1.AddTail(20);
    list1.AddTail(30);
    list1.AddTail(30);

    list1.print();
    list1.printR();

    list1.InsertAt(1, 15);
    list1.print();

    list1.InsertAfter(20, 25);
    list1.print();

    list1.Replace(30, 99);
    list1.print();

    list1.Reverse();
    list1.print();

    list1.removeHead();
    list1.removeTail();
    list1.print();

    list1.removeByData(25);
    list1.print();

    DList<int> list2;
    list2.AddTail(99);
    list2.AddTail(100);
    list2.AddTail(200);

    DList<int> listSum = list1 + list2;
    listSum.print();

    DList<int> listIntersection = list1 * list2;
    listIntersection.print();

    DList<int> listCopy(list2);
    listCopy.print();

    list1 = list2;
    list1.print();

    list1.DeleteAll();
    list1.print();

    return 0;
}