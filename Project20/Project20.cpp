#include <iostream>
#include "main.h"

int main()
{
    Item* library = nullptr;
    size_t size = 0;
    read(library, size);
    int choice;

    while (true) {
        cout << R"(	
            Select type : 
                    1 - fill;
                    2 - print;
                    3 - add;
                    4 - delete;
                    5 - sort
                    6 - search
                    7 - select Items
                    8 - count books by genre
                    9 - delete newspapers by year
                    0 - exit
                    Enter :: )";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            int count;
            cout << "Enter number of Items :: ";
            cin >> count;
            fillLibrary(library, size, count);
            save(library, size);
            break;
        }
        case 2: {
            for (size_t i = 0; i < size; i++) {
                print(library[i]);
            }
            break;
        }
        case 3: {
            Item tmp;
            editItem(tmp);
            addItem(library, size, tmp);
            save(library, size);
            break;
        }
        case 4: {
            int ind;
            cout << "Enter index of Item to delete :: ";
            cin >> ind;
            if (ind >= 0 && ind < size) {
                deleteItem(library, size, ind);
                save(library, size);
            }
            else {
                cout << "Invalid index!\n";
            }
            break;
        }
        case 5: {
            int ch;
            cout << "Enter choice of sort by (1 - book, 2 - newspaper, 3 - magazine 4 - name) :: ";
            cin >> ch;
            if (ch < 1 || ch > 4) {
                cout << "Invalid choice!\n";
                break;
            }
            sort(library, size, ch);
            save(library, size);
            break;
        }
        case 6: {
            int ch;
            cout << "Enter choice of search by (1 - book, 2 - newspaper, 3 - magazine) :: ";
            cin >> ch;
            if (ch < 1 || ch > 3) {
                cout << "Invalid choice!\n";
                break;
            }
            cin.ignore();
            string name, author;
            cout << "Enter name :: ";
            getline(cin, name);

            if (ch == 1) {
                cout << "Enter author :: ";
                getline(cin, author);
            }

            Item* found = search(library, size, ch, name, author);
            if (found != nullptr) {
                print(*found);
            }
            else {
                cout << "Item not found.\n";
            }
            break;
        }
        case 7: {
            cout << R"(
                    Select filter type:
                    1 - Books by author
                    2 - Books by genre  
                    3 - Magazines by year
                    4 - Newspapers by year
                    Enter your choice :: )";
            int filterChoice;
            cin >> filterChoice;
            cin.ignore();

            string filterValue = "";
            int yearFilter = -1;

            switch (filterChoice) {
            case 1:
                cout << "Enter author name :: ";
                getline(cin, filterValue);
                selectItems(library, size, 1, filterValue, -1);
                break;
            case 2:
                cout << "Enter genre :: ";
                getline(cin, filterValue);
                selectItems(library, size, 2, filterValue, -1);
                break;
            case 3:
                cout << "Enter year for magazines :: ";
                cin >> yearFilter;
                selectItems(library, size, 3, "", yearFilter);
                break;
            case 4:
                cout << "Enter year for newspapers :: ";
                cin >> yearFilter;
                selectItems(library, size, 4, "", yearFilter);
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
            break;
        }
        case 8: {
            cin.ignore();
            string genre;
            cout << "Enter genre :: ";
            getline(cin, genre);
            int count = countByGenre(library, size, genre);
            cout << "Number of books with genre \"" << genre << "\": " << count << endl;
            break;
        }
        case 9: {
            int year;
            cout << "Enter year of newspapers to delete :: ";
            cin >> year;
            deleteNewspapersByYear(library, size, year);
            save(library, size);
            cout << "Deleted all newspapers from year " << year << ".\n";
            break;
        }
        default: {
            cout << "Invalid choice!\n";
            break;
        }
        }
    }

    delete[] library;
    return 0;
}