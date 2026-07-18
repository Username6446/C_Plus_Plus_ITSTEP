#include <iostream>
#include <string>
#include <ctime>
#include <initializer_list>

using namespace std;

class Student
{
protected:
    string name;
    int* marks;
    int countMarks;
public:
    Student() :name("no name"), marks(nullptr), countMarks(0) {}
    Student(string name) :name(name)
    {
        countMarks = rand() % 10 + 1;
        marks = new int[countMarks];
        for (int i = 0; i < countMarks; i++)
        {
            marks[i] = rand() % 5 + 8; // 8...12
        }
    }
    virtual void Print() const
    {
        cout << "Student name :: " << name << endl;
        cout << "Count marks  :: " << countMarks << endl;
        cout << "Marks: ";
        for (int i = 0; i < countMarks; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
    virtual ~Student()
    {
        if (marks != nullptr)
            delete[] marks;
    }
};

class Aspirant : public Student
{
    string* subject;
    int count;
public:
    Aspirant(string name, initializer_list<string> list) : Student(name)
    {
        this->count = list.size();
        this->subject = new string[count];

        int i = 0;
        for (const string& sub : list)
        {
            subject[i] = sub;
            i++;
        }
    }
    void Print() const override
    {
        Student::Print();
        cout << "Subjects count: " << count << endl;
        cout << "Subjects :: ";
        for (int i = 0; i < count; i++)
        {
            cout << subject[i] << (i < count - 1 ? ", " : "");
        }
        cout << endl << endl;
    }
    ~Aspirant()
    {
        if (subject != nullptr)
            delete[] subject;
    }
};

int main()
{
    srand(time(0));

    Student st("Vasia");
    st.Print();
    cout << "----------------" << endl;

    Aspirant asp("Oleksandr", { "Math" , "Algebra", "Biologie" });
    asp.Print();
    cout << "----------------" << endl;


    Student* group[3] = {
        new Student("Vasia"),
        new Aspirant("Oleksandr", { "Math" , "Algebra", "Biologie" }),
        new Aspirant("Olga", { "UI/UX" , "Designer" }) 
    };
    for (int i = 0; i < 3; i++) {
        group[i]->Print();
        cout << "----------------" << endl;
    }
    for (int i = 0; i < 3; i++) {
        delete group[i];
    }
}