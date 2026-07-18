#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

int main()
{
    Library myLib;
    int choice;

    do {
        cout << "\n========== LIBRARY MENU ==========\n";
        cout << "1. Print all books\n";
        cout << "2. Add book\n";
        cout << "3. Search book (Author + Title)\n";
        cout << "4. Search books by Author\n";
        cout << "5. Issue book (Give to reader)\n";
        cout << "6. Return book\n";
        cout << "7. Sort books\n";
        cout << "8. Remove book (by details)\n";
        cout << "9. Remove book (by index)\n";
        cout << "10. Edit book (by index)\n";
        cout << "0. Exit\n";
        cout << "Select option: ";
        cin >> choice;
        cin.ignore();

        string auth, title;
        size_t yr;
        int idx;

        switch (choice)
        {
        case 1:
            myLib.print();
            break;
        case 2:
            myLib.addBook();
            break;
        case 3:
            cout << "Enter Author: "; getline(cin, auth);
            cout << "Enter Title: "; getline(cin, title);
            myLib.searchBook(auth, title);
            break;
        case 4:
            cout << "Enter Author: "; getline(cin, auth);
            myLib.searchByAuthor(auth);
            break;
        case 5:
            cout << "Enter Title to issue: "; getline(cin, title);
            myLib.issueBook(title);
            break;
        case 6:
            cout << "Enter Title to return: "; getline(cin, title);
            myLib.returnBook(title);
            break;
        case 7:
            myLib.sortBooks();
            myLib.print();
            break;
        case 8:
            cout << "Enter Author: "; getline(cin, auth);
            cout << "Enter Title: "; getline(cin, title);
            cout << "Enter Year: "; cin >> yr; cin.ignore();
            myLib.removeBookByDetails(auth, title, yr);
            break;
        case 9:
            myLib.print();
            cout << "Enter index to remove: "; cin >> idx; cin.ignore();
            myLib.removeBookByIndex(idx);
            break;
        case 10:
            myLib.print();
            cout << "Enter index to edit: "; cin >> idx; cin.ignore();
            myLib.editBook(idx);
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}