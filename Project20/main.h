#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Type {
    BOOK = 1, NEWSPAPER = 2, MAGAZINE = 3
};

const size_t SIZE = 50;
const string path = "library.dat";

struct Item {
    Type type;
    char name[SIZE]{};
    size_t year;
    char author[SIZE]{ '\0' };
    char genre[SIZE]{ '\0' };
};

void addItem(Item*& library, size_t& size, Item item);
string getType(Type type);
void fillLibrary(Item*& library, size_t& size, const size_t& count);
void editItem(Item& item);
void deleteItem(Item*& library, size_t& size, const size_t& index);
void print(Item item);
string toLower(const string& str);
void sort(Item*& library, size_t& size, int choice);
Item* search(Item* library, size_t size, int choice, const string& name, const string& author = "");
int countByGenre(Item* library, size_t size, const string& genre);
void deleteNewspapersByYear(Item*& library, size_t& size, size_t year);
void selectItems(Item* library, size_t size, int filterType, const string& filterValue, int yearFilter);

void read(Item*& library, size_t& size);
void save(Item*& library, size_t& size);