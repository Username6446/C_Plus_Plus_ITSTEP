#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const size_t SIZE = 20;
struct Train
{
    size_t number;
    char destination[SIZE]{};
    char from[SIZE]{};
    void print() const
    {
        cout << "Number of train :: \t" << number << endl;
        cout << "place from      :: \t" << from << endl;
        cout << "Destination     :: \t" << destination << endl;
    }
};

int main()
{
    // ostream --> write // cout // file out
    // ifstream --> read // cin // file in
    // fstream --> write and read 
    char fname[SIZE] = "train.dat";
    fstream file(fname, ios_base::in | ios_base::out | ios_base::binary);
    if (!file.is_open())
    {
        cout << "Error file " << fname << endl;
        return 0;
    }
    Train train{90, "Prague", "Lviv"};
    train.print();
    file.write((char*)&train, sizeof(Train));

    Train trainArr[2] = { {22, "Warsaw", "Lviv"} ,{90, "Sopot", "Lviv"} };

    file.write(reinterpret_cast<const char*>(trainArr), sizeof(trainArr));

    vector<Train> trainVect = {
        {7, "Rivne", "Kyiv"},
        {188, "Odesa", "Poltava"}
    };
    file.write(reinterpret_cast<const char*>(trainVect.data()), trainVect.size() * sizeof(Train));

    // read
    file.seekg(0/*, ios_base::beg*/); /*, ios_base::end*/
    Train tmp;
    cout << "\n Read from file" << endl;
    while (file.read(reinterpret_cast<char*>(&tmp), sizeof(Train)))
    {
        tmp.print();
        cout << endl;
    }

    file.clear();
    file.seekg(0);
    // recover vector
    vector<Train> result;
    while (file.read(reinterpret_cast<char*>(&tmp), sizeof(Train)))
    {
        result.push_back(tmp);
    }
    cout << "\n\n Recovering vector<Trian> from file " << endl;
    for (auto& i : result)
    {
        i.print();
        cout << "-------------\n";
    }

    result.clear();
    file.clear();

    file.seekg(0, ios_base::end);
    size_t lenFile = file.tellg();
    size_t count = lenFile / sizeof(Train);
    cout << "Number of train from file :: " << count << endl;
    
    result.resize(count);
    file.clear();
    file.seekg(0);

    file.read(reinterpret_cast<char*>(result.data()), sizeof(Train)*count);
    cout << "\n\n Recovering vector<Train> from file .... other way" << endl;
    for (auto& i : result)
    {
        i.print(); 
        cout << "----------\n";
    }

    int index = 2;
    file.clear();
    file.seekg(sizeof(Train) * index);

    file.read(reinterpret_cast<char*>(&tmp), sizeof(Train));
    tmp.print();

}

