#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string secretText(const string& str, const size_t& key)
{
    string secret = "";
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isalpha(str[i])) {
            secret += str[i];
            continue;
        }
        if (islower(str[i])) {
            char s = str[i] + key;
            if (s > 122) {
                s = 96 + (s - 122);
            }
            secret += s;
            continue;
        }

        if (isupper(str[i])) {
            char s = str[i] + key;
            if (s > 90) {
                s = 64 + (s - 90);
            }
            secret += s;
        }
    }
    return secret;
}

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

bool isConsonant(char ch) {
    return isalpha(ch) && !isVowel(ch);
}

int main() {

    string fname1 = "file1.txt";
    string fname2 = "file2.txt";

    ifstream file1(fname1);
    ifstream file2(fname2);

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Files not found" << endl;
        return 0;
    }

    string line;
    int count1 = 0, count2 = 0;
    while (getline(file1, line)) count1++;
    while (getline(file2, line)) count2++;

    string* temp = new string[count1 + count2];
    int t = 0;

    file1.clear();
    file1.seekg(0);
    file2.clear();
    file2.seekg(0);

    string line1, line2;
    bool flag;

    for (int i = 0; i < count1; i++) {
        getline(file1, line1);
        flag = true;
        file2.clear();
        file2.seekg(0);
        for (int j = 0; j < count2; j++) {
            getline(file2, line2);
            if (line1 == line2) {
                flag = false;
                break;
            }
        }
        if (flag) {
            temp[t++] = line1;
            cout << line1 << endl;
        }
    }

    file1.clear();
    file1.seekg(0);
    file2.clear();
    file2.seekg(0);

    for (int i = 0; i < count2; i++) {
        getline(file2, line2);
        flag = true;
        for (int j = 0; j < count1; j++) {
            getline(file1, line1);
            if (line2 == line1) {
                flag = false;
                break;
            }
        }
        for (int k = 0; k < t && flag; k++) {
            if (line2 == temp[k]) {
                flag = false;
            }
        }
        if (flag) {
            cout << line2 << endl;
        }
        file1.clear();
        file1.seekg(0);
    }

    delete[] temp;
    file1.close();
    file2.close();


    string fname3 = "file3.txt";
    ifstream file3(fname3);
    if (!file3.is_open()) {
        cout << "Files not found" << endl;
        return 0;
    }

    int numOfSymbols = 0, numOfLines = 0, numOfVowels = 0, numOfConsonants = 0, numOfDigits = 0;

    while (getline(file3, line)) numOfLines++;

    file3.clear();
    file3.seekg(0);

    char symbol;
    while (file3.get(symbol)) {
        if (isalnum(symbol)) {
            numOfSymbols++;
        }
        if (isdigit(symbol)) {
            numOfDigits++;
        }
        if (isVowel(symbol)) {
            numOfVowels++;
        }
        if (isConsonant(symbol)) {
            numOfConsonants++;
        }
    }

    string fname4 = "file4.txt";
    ofstream file4(fname4);
    if (!file4.is_open()) {
        cout << "Files not found" << endl;
        return 0;
    }

    file4 << "Num of symbols :: " << numOfSymbols << endl;
	file4 << "Num of lines :: " << numOfLines << endl;
	file4 << "Num of vowels :: " << numOfVowels << endl;
	file4 << "Num of consonants :: " << numOfConsonants << endl;
    file4 << "Num of digits :: " << numOfDigits << endl;
    file3.close();
    file4.close();


    string fname = "text.txt";
    fstream file(fname, ios_base::in);
    if (!file.is_open())
    {
        cout << "Error! File not found" << endl;
        return 0;
    }

    string all_text = "";
    string text = "";
    while (getline(file, text))
    {
        all_text += text + "\n";
    }
    cout << all_text << endl;
    file.close();

    file.open("secret.txt", ios_base::out);
    if (!file.is_open())
    {
        cout << "Error! File not found" << endl;
        return 0;
    }
    file << secretText(all_text, 3);
    file.close();
}