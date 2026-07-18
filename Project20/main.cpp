#include "main.h"

void addItem(Item*& library, size_t& size, Item item)
{
    Item* tmp = new Item[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = library[i];
    }
    tmp[size] = item;
    size++;
    delete[] library;
    library = tmp;
}

string getType(Type type)
{
    switch (type)
    {
    case BOOK:
        return "Book";
    case NEWSPAPER:
        return "Newspaper";
    case MAGAZINE:
        return "Magazine";
    default:
        return "Unknown";
    }
}

void fillLibrary(Item*& library, size_t& size, const size_t& count)
{
    for (size_t i = 0; i < count; i++)
    {
        Item tmp;
        editItem(tmp);
        addItem(library, size, tmp);
    }
}

void editItem(Item& item)
{
    int type;
    while (true) {
        cout << R"(	
            Select type : 
                    1 - Book;
                    2 - Newspaper;
                    3 - Magazine;
                    Enter :: )";
        cin >> type;
        if (type < 1 || type > 3)
        {
            cout << "error type. try again.";
        }
        else {
            break;
        }
    }
    cin.clear();
    cin.ignore();

    cout << R"(
            Enter name : )";
    cin.getline(item.name, SIZE);
    cout << R"(
            Enter year : )";
    cin >> item.year;
    cin.clear();
    cin.ignore();
    switch (type)
    {
    case Type::BOOK:
        item.type = Type::BOOK;
        cout << R"(
            Enter author : )";
        cin.getline(item.author, SIZE);
        cout << R"(
            Enter genre : )";
        cin.getline(item.genre, SIZE);
        break;
    case Type::NEWSPAPER:
        item.type = Type::NEWSPAPER;
        break;
    case Type::MAGAZINE:
        item.type = Type::MAGAZINE;
        break;
    }
}

void deleteItem(Item*& library, size_t& size, const size_t& index)
{
    if (index >= size) return;

    Item* tmp = new Item[size - 1];
    for (size_t i = 0; i < size - 1; i++)
    {
        if (i < index) {
            tmp[i] = library[i];
        }
        else {
            tmp[i] = library[i + 1];
        }
    }
    delete[] library;
    library = tmp;
    size--;
}

void print(Item item)
{
    cout << "================== " << getType(item.type) << " =====================" << endl;
    cout << "\t\t Title     :: " << item.name << endl;
    if (item.type == Type::BOOK) {
        cout << "\t\t Author    :: " << item.author << endl;
        cout << "\t\t Genre     :: " << item.genre << endl;
    }
    cout << "\t\t Year      :: " << item.year << endl;
}

string toLower(const string& str)
{
    string copy = str;
    for (size_t i = 0; i < copy.size(); i++) {
        copy[i] = tolower(copy[i]);
    }
    return copy;
}

void sort(Item*& library, size_t& size, int choice)
{
    switch (choice) {
    case 1:
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = 0; j < size - i - 1; j++) {
                if (library[j].type != Type::BOOK && library[j + 1].type == Type::BOOK) {
                    swap(library[j], library[j + 1]);
                }
            }
        }
        break;
    case 2:
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = 0; j < size - i - 1; j++) {
                if (library[j].type != Type::NEWSPAPER && library[j + 1].type == Type::NEWSPAPER) {
                    swap(library[j], library[j + 1]);
                }
            }
        }
        break;
    case 3:
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = 0; j < size - i - 1; j++) {
                if (library[j].type != Type::MAGAZINE && library[j + 1].type == Type::MAGAZINE) {
                    swap(library[j], library[j + 1]);
                }
            }
        }
        break;
    case 4:
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = 0; j < size - i - 1; j++) {
                if (toLower(library[j].name) > toLower(library[j + 1].name)) {
                    swap(library[j], library[j + 1]);
                }
            }
        }
        break;
    }
}

Item* search(Item* library, size_t size, int choice, const string& name, const string& author)
{
    if (choice == 1) {
        for (size_t i = 0; i < size; i++) {
            if (library[i].type == Type::BOOK &&
                toLower(library[i].name) == toLower(name) &&
                toLower(library[i].author) == toLower(author)) {
                return &library[i];
            }
        }
    }
    else {
        Type searchType = (choice == 2) ? Type::NEWSPAPER : Type::MAGAZINE;
        for (size_t i = 0; i < size; i++) {
            if (library[i].type == searchType &&
                toLower(library[i].name) == toLower(name)) {
                return &library[i];
            }
        }
    }
    return nullptr;
}

void selectItems(Item* library, size_t size, int filterType, const string& filterValue, int yearFilter)
{
    bool found = false;

    for (size_t i = 0; i < size; i++) {
        bool match = false;

        switch (filterType) {
        case 1:
            if (library[i].type == Type::BOOK &&
                toLower(library[i].author) == toLower(filterValue)) {
                match = true;
            }
            break;

        case 2:
            if (library[i].type == Type::BOOK &&
                toLower(library[i].genre) == toLower(filterValue)) {
                match = true;
            }
            break;

        case 3:
            if (library[i].type == Type::MAGAZINE &&
                library[i].year == yearFilter) {
                match = true;
            }
            break;

        case 4:
            if (library[i].type == Type::NEWSPAPER &&
                library[i].year == yearFilter) {
                match = true;
            }
            break;
        }

        if (match) {
            print(library[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "No items found matching the criteria.\n";
    }
}
void deleteNewspapersByYear(Item*& library, size_t& size, size_t year)
{
    for (int i = size - 1; i >= 0; i--) {
        if (library[i].type == Type::NEWSPAPER && library[i].year == year) {
            deleteItem(library, size, i);
        }
    }
}

int countByGenre(Item* library, size_t size, const string& genre)
{
    int count = 0;
    string lowGenre = toLower(genre);
    for (size_t i = 0; i < size; i++) {
        if (library[i].type == Type::BOOK && toLower(library[i].genre) == lowGenre)
            count++;
    }
    return count;
}

void read(Item*& library, size_t& size)
{
    ifstream file(path, ios::binary);
    if (!file.is_open())
        return;

    file.seekg(0, ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, ios::beg);

    size = fileSize / sizeof(Item);
    library = new Item[size];

    for (size_t i = 0; i < size; i++)
    {
        file.read((char*)&library[i], sizeof(Item));
    }
    file.close();
}

void save(Item*& library, size_t& size)
{
    ofstream file(path, ios::binary | ios::trunc);
    if (!file.is_open())
    {
        cout << "Error saving file!\n";
        return;
    }
    for (size_t i = 0; i < size; i++)
    {
        file.write((char*)&library[i], sizeof(Item));
    }
    file.close();
}