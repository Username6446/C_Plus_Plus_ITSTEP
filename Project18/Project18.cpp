#include <iostream>
#include <fstream> // read, write
#include <string>
using namespace std;

int main()
{
    /*
    
        ofstream --> write(cout)
        ifstream --> read(cin)
        fstream --> write, read
    
    */

    // write file

    /*string line = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    string fname = "my.txt";

    cout << "Length line :: " << line.size() << endl;*/

    /*ofstream file;

    file.open(fname, ios_base::app);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
    }
    else {
        cout << "Enter line :: ";
        getline(cin, line);
        file << line << endl;
    }
    file.close();*/

    // write file numbers

    /*string fname = "number.txt";
    ofstream file(fname, ios_base::app);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
    }
    else {
        int number;
        while (cin >> number) {
            file << number << endl;
        }
    }
    file.close(); */

    // read 

    /*string fname = "number.txt";
    ifstream file(fname);

    if (!file.is_open())
    {
        cout << "File not found" << endl;
    }
    else {
        int number;
        while (!file.eof()) {
            file >> number;
            cout << "Read number :: " << number << endl;
        }
    }*/

    //string fname = "my.txt";
    //ifstream file(fname);

    //if (!file.is_open())
    //{
    //    cout << "File not found" << endl;
    //}
    //else {
    //    // read word
    //    string line;
    //    cout << "Read Words :: " << endl;
    //    cout << "Start read :: " << file.tellg() << endl;
    //    while (file >> line) {
    //        cout << "Read line :: " << line << endl;
    //        cout << "" << file.tellg() << endl;
    //    }
    //    cout << "End  read :: " << file.tellg() << endl;

    //    // read lines
    //    file.clear();
    //    file.seekg(0);
    //    cout << "Read Lines :: " << endl;
    //    cout << "Start read :: " << file.tellg() << endl;

    //    while (getline(file, line))
    //    {
    //        cout << "Read line :: " << line << endl;
    //    }

    //    // read Symbols
    //    file.clear();
    //    file.seekg(0);
    //    cout << "Read Symbols :: " << endl;
    //    cout << "Start read :: " << file.tellg() << endl;
    //    char s;
    //    while (file.get(s))
    //    {
    //        cout << "Read line :: " << s << endl;
    //    }

    //    // read Symbols
    //    file.clear();
    //    file.seekg(0);
    //    cout << "Read Words in char [] :: " << endl;
    //    cout << "Start read :: " << file.tellg() << endl;
    //    char words[100];
    //    while (file >> words)
    //    {
    //        cout << "Read line :: " << words << endl;
    //    }

    //    // read lines
    //    file.clear();
    //    file.seekg(0);
    //    cout << "Read Words in char [] :: " << endl;
    //    cout << "Start read :: " << file.tellg() << endl;
    //    //char words[100];
    //    while (file.getline(words, 100))
    //    {
    //        cout << "Read line :: " << words << endl;
    //    }
    //}
    //    file.close();
    //    //  save lines in arrays
    //
    //    file.open(fname);
    //    if (!file.is_open())
    //    {
    //        cout << "File not found" << endl;
    //    }
    //    else {
    //        int counter = 0;
    //        string str;
    //        while (getline(file, str))
    //        {
    //            counter++;
    //        }
    //        
    //        cout << "Number of lines :: " << counter << endl;
    //        string* lines = new string[counter];
    //        file.clear();
    //        file.seekg(0);
    //        counter = 0;
    //        while (getline(file, lines[counter]))
    //        {
    //            counter++;
    //        }
    //        file.close();

    //        for (size_t i = 0; i < counter; i++) {
    //            cout << "#" << i + 1 << " :: " << lines[i] << endl;
    //        }

    //    }


    // Ex 1
    

    /*string fname = "my.txt";
    ifstream fileRead(fname);

    string fname2 = "Ex1.txt";
    ofstream fileWrite(fname2, ios_base::app);

    if (!fileRead.is_open() and !fileWrite.is_open())
    {
        cout << "File not found" << endl;
    }
    else 
    {
        string line;
        int counter = 0;
        while (fileRead >> line)
        {
            if (line.length() < 7) {
                fileWrite << "Word #" << counter++ << line << endl;
            }
        }
        fileWrite.close();
        fileRead.close();

    }*/
        
   

    // Ex 2
        
    /*string fname = "my.txt";
    ifstream fileRead(fname);

    string fname2 = "Ex2.txt";
    ofstream fileWrite(fname2, ios_base::app);

    if (!fileRead.is_open() and !fileWrite.is_open())
    {
        cout << "File not found" << endl;
    }
    else
    {
        string line;
        int counter = 0;
        while (getline(fileRead, line))
        {
            fileWrite << line << endl;
        }
        fileWrite.close();
        fileRead.close();

    }*/

    // Ex 3
        
    /*string fname = "my.txt";
    ifstream fileRead(fname);

    string fname2 = "Ex3.txt";
    ofstream fileWrite(fname2, ios_base::app);

    if (!fileRead.is_open() and !fileWrite.is_open())
    {
        cout << "File not found" << endl;
    }
    else
    {
        int counter = 0;
        string str;
        while (getline(fileRead, str))
        {
            counter++;
        }
        string* lines = new string[counter];
        fileRead.clear();
        fileRead.seekg(0);
        counter = 0;
        while (getline(fileRead, lines[counter]))
        {
            counter++;
        }
        for (int i = counter-1; i >= 0; i--) {
            fileWrite << lines[i] << endl;
        }

    }*/

    // Ex 4


    string fname = "my.txt";
    ifstream fileRead(fname);

    string fname2 = "Ex4.txt";
    ofstream fileWrite(fname2, ios_base::app);

    if (!fileRead.is_open() and !fileWrite.is_open())
    {
        cout << "File not found" << endl;
    }
    else
    {
        bool flag = true;
        int counter = 0;
        string str;
        while (getline(fileRead, str))
        {
            counter++;
        }
        string* lines = new string[counter];
        fileRead.clear();
        fileRead.seekg(0);
        counter = 0;
        while (getline(fileRead, lines[counter]))
        {
            counter++;
        }
        for (int i = 0; i < counter; i++) {
            if (lines[i].find(' ') == string::npos) {
                lines[i] += "------------";
                flag = false;
            }
        }
        for (int i = 0; i < counter; i++) {
            fileWrite << lines[i] << endl;
        }
        if (flag) {
            fileWrite << "------------" << endl;

        }
        delete[] lines;

    }

}
