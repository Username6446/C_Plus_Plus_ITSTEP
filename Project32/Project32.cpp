#include <iostream>
#include "Dlist.h"
using namespace std;
int main()
{
    DList<int> list;

    list.AddHead(11);
    for (size_t i = 0; i < 5; i++) {
        list.AddHead(rand()%10);
        list.print();
        list.printR();
        cout << endl;
    }

    cout << "\n\n Test addTail" << endl;
    DList<int> list2;
    for (size_t i = 0; i < 5; i++) {
        list2.AddTail(rand() % 10);
        list2.print();
        list2.printR();
        cout << endl;
    }

    cout << "\n\n Test remove Head" << endl;

    //list.print();
    system("cls");
    //list2.print();
    //list2.printR();
    //while (list2.removeByData(4)) {
    //}
    //
    //list2.print();
    //list2.printR();
    /*while (!list.isEmpty())
    {
        list.removeTail();
        list.print();
    }*/
    cout << "\n\n Test l2" << endl;

    list2.print();
    list2.printR();
    DList<int> list3(list2);
    cout << "\n\n Test l2" << endl;
    list3.print();
    list3.printR();
    
    cout << "\n\n Test l2" << endl;

    list2.print();
    list2.printR();
    DList<int> list4 = list2;
    cout << "\n\n Test l4" << endl;
    list4.print();
    list4.printR();
}

