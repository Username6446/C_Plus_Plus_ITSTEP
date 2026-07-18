#include <iostream>

using namespace std;

// Написати функцію, яка видаляє з рядка символ із заданим номером.

void func1(char* str, int index) {
    str[index] = ' ';
}

// Написати функцію, яка видаляє з рядка всі входження в нього заданого символу.

void func2(char* str, char symbol) {
    int counter = 0, counter1 = 0;
    while (str[counter] != '\0') {
        if (str[counter] != symbol) {
            str[counter1] = str[counter];
            counter1++;
        }
        counter++;
    }
    str[counter1] = '\0';
}

// Написати функцію, яка вставляє в рядок у вказану позицію заданий символ.

void func3(char* str, char symbol, int index) {
    if (index >= 0 and index <= strlen(str)) {
        str[index] = symbol;
    }
    
}

// Написати програму, яка замінює всі символи крапки "." у рядку, введеному користувачем, на 
// символи знака оклику "!".

void func4(char* str) {
    int counter = 0;
    while (str[counter] != '\0') {
        if (str[counter] == '.') {
            str[counter] = '!';
        }
        counter++;
    }
}

//  Користувач вводить рядок символів і шуканий символ. Порахувати скільки разів він зустрічається в 
// рядку.

int func5(char* str, char symbol) {
    int counter = 0, counter1 = 0;
    while (str[counter] != '\0') {
        if (str[counter] == symbol) {
            counter1++;
        }
        counter++;
    }
    return counter1;
}

// Користувач вводить рядок. Визначити кількість літер, кількість цифр і кількість інших символів,
// присутніх у рядку.

int func6(char* str, char symbol) {
    int counter = 0, counter1 = 0;
    while (str[counter] != '\0') {
        if (str[counter] == symbol) {
            counter1++;
        }
        counter++;
    }
    return counter1;
}

int main()
{
    char str1[100];
    char symb;
    cout << "Enter line :: ";
    cin.getline(str1, 100);
    
    cout << "Enter symbol :: ";
    cin >> symb;
    cin.ignore();
    
    cout << func5(str1, symb);
    cout << str1 << endl;

}

