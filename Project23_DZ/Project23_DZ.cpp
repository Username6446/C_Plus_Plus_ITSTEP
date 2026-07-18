#include "PhoneBook.h"
#include <iostream>
using namespace std;

int main() {
    PhoneBook phoneBook;
    char choice;
    char buffer[256];

    cout << "=== PHONE BOOK ===" << endl;

    do {
        cout << R"(Menu:
1. Add contact
2. Delete contact
3. Search contact
4. Show all contacts
5. Save to file
6. Load from file
0. Exit
Your choice: )";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1': {
            char name[100], home[20], work[20], mobile[20], info[100];

            getInput("Enter full name: ", name, sizeof(name));
            getInput("Enter home phone: ", home, sizeof(home));
            getInput("Enter work phone: ", work, sizeof(work));
            getInput("Enter mobile phone: ", mobile, sizeof(mobile));
            getInput("Enter additional info: ", info, sizeof(info));

            Contact newContact(name, home, work, mobile, info);
            phoneBook.addContact(newContact);
            break;
        }

        case '2': {
            getInput("Enter full name to delete: ", buffer, sizeof(buffer));
            phoneBook.removeContact(buffer);
            break;
        }

        case '3': {
            getInput("Enter full name to search: ", buffer, sizeof(buffer));
            phoneBook.searchContact(buffer);
            break;
        }

        case '4':
            phoneBook.showAllContacts();
            break;

        case '5': {
            getInput("Enter filename to save: ", buffer, sizeof(buffer));
            phoneBook.saveToFile(buffer);
            break;
        }

        case '6': {
            getInput("Enter filename to load: ", buffer, sizeof(buffer));
            phoneBook.loadFromFile(buffer);
            break;
        }

        case '0':
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != '0');

    return 0;
}