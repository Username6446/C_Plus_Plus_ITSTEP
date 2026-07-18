#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

#include <list>
#include <forward_list>

#include <set>

#include <map>

using namespace std;

using id = size_t;
using name = string;

string text = "Nonename function";

template <typename ConType>
void print(const ConType& cont, const string& prompt = "")
{
    cout << prompt << endl;
    for(auto& i : cont)
    {
        cout << i << "\t";
    }
    cout << endl;
}

void print(map<id, name> coll)
{
    for (auto& p : coll)
    {
        cout << "Id :: " << p.first << "\t Name :: " << p.second << endl;
    }
    cout << endl;
}
void printMultMap(multimap<name, name> coll)
{
    for (auto& p : coll)
    {
        cout << "Id :: " << p.first << "\t Name :: " << p.second << endl;
    }
    cout << endl;
}

int main()
{
    auto func = [](int a, int b, int c) ->double {
        double sum = a + b + c;
        return sum / 3;
        };
    cout << "func(2,3,11) :: " << func(2, 3, 11) << endl;
    cout << "Typeid :: " << typeid(func).name() << endl;

    string localText = "function can ... ";

    auto demo = [localText] {
        cout << "Hello from lamda :" << text << endl;
        cout << "Hello from lamda :" << localText << endl;
        };
    demo();
    localText = "Other ..";
    cout << "\n\n";
    demo();
    deque<int> d{ 10,23,-100,45,67,-22,81 };
    int divisor = 9;

    auto it = find_if(begin(d), end(d), [divisor](int el) {return el % divisor == 0; });
    cout << "Divisor :: " << divisor << endl;
    if (it != end(d))
    {
        cout << "\n Was found divisible by " << divisor << " :: " << *it << " in index " << distance(begin(d), it) << endl;
    }

    print(d, "deque origin :: ");
    int mult = 3;
    vector<int> v(d.size());
    transform(begin(d), end(d), begin(v), [=](int el) {return el * mult; });
    print(d, "Deque origin :: ");
    print(v, "\n Vector after transform :: ");

    sort(begin(d), end(d), [](int a, int b) {return abs(a) < abs(b); });
    print(d, "Deque sort :: ");

    deque<string> number{ "second", "one", "two", "hundred", "trhee", "second" };
    print(number, "Deque sort :: ");
    sort(begin(number), end(number), [](string a, string b) {return a.size() < b.size(); });
    print(number, "Deque sort :: ");

    system("cls");

    forward_list<int> fl{ 10,23,45,-1,100,-55,10,-22,10,200 };
    fl.push_front(5);
    print(fl, "Forward list :: ");
    auto it1 = begin(fl);
    advance(it1, 3);
    fl.insert_after(it1, 77);
    print(fl, "Forward list :: ");

    it1 = find(fl.begin(), fl.end(), 100);
    if (it1 != fl.end())
    {
        cout << "100 was found " << endl;
        auto tmpIt = it1;
        ++tmpIt;
        if (tmpIt != fl.end())
        {
            cout << "Will be deleted :: " << *tmpIt << endl;
            fl.erase_after(it1);
        }
        else {
            cout << "Erase after 100 is imposible (because it is last element) " << endl;
        }

    }
    print(fl, "After erase_after");

    fl.remove(10);
    print(fl, "After remove");

    int bound = 50;
    fl.remove_if([bound](auto el) {return el < bound; });
    print(fl, "After remove_if < 50 :: ");

    system("cls");

    list<string> li{ "c++", "java", "c#", "python" };
    li.push_back("js");
    li.push_back("assembler");
    print(li, "List :: ");

    char letter = 'c';
    li.remove_if([letter](string el) {return el.find(letter) != string::npos; });
    print(li, "List :: ");


    system("cls");

    multiset<int> ms{ 10,22,10,22,33,-33,100,200,100,1,100 };
    print(ms, "Print set");
    ms.insert(77);
    print(ms, "Print set");

    cout << "Min :: " << *ms.begin() << endl;
    cout << "Max :: " << *ms.rbegin() << endl;

    int key = 100;
    auto it2 = ms.find(key);
    if (it2 != ms.end())
    {
        cout << "Key " << key << " was found " << ms.count(key) << "times" << endl;
        ms.erase(key);
    }
    else {
        cout << "Key " << "not found" << endl;
    }

    print(ms, "Print set");

    key = 22;
    it2 = ms.lower_bound(key); // >= key
    if (it2 != ms.end())
    {
        cout << "Lower bound key :: " << *it2 << "in index " << distance(begin(ms), it2) << endl;
    }

    key = 33;
    it2 = ms.upper_bound(key); // > key
    if (it2 != ms.end())
    {
        cout << "Upper bound key :: " << *it2 << "in index " << distance(begin(ms), it2) << endl;
    }

    set<int> s(ms.begin(), ms.end());
    print(s, "Print set");
    set<int> s2{ 100, 65,77,88,300,100, 200, 300, 10 ,22 };
    print(s2, "Print set");
    ostream_iterator<int> outIt(cout, "\t");
    cout << "--------------- UNION --------------" << endl;
    set_union(begin(s), end(s), begin(s2), end(s2), outIt);

    cout << "\n--------------- COMMON (INTERSECTION) --------------" << endl;
    set_intersection(begin(s), end(s), begin(s2), end(s2), outIt);

    cout << "\n--------------- DIFFERENCE (s1-s2) --------------" << endl;
    set_difference(begin(s), end(s), begin(s2), end(s2), outIt);

    cout << "\n--------------- DIFFERENCE (s2-s1) --------------" << endl;
    set_difference(begin(s2), end(s2), begin(s), end(s), outIt);

    system("cls");

    map<id, name> people{
        pair<id, name>(555,"Ann"), // method1
        make_pair(777, "Tom"), // method2
        {222, "Olena"} // method3
    };

    print(people);

    people.insert({ 333, "Ivan" });
    people.insert({ 333, "Den" });

    people[555] = "ANNA";
    people[888] = "Matviy";
    cout << "\n\n";

    print(people);

    id k = 333;
    //cout << "Test get by key" << k << ":::::" << people[k] << endl;
    //cout << "Test get by key" << k << ":::::" << people.at(k) << endl;

    auto it4 = people.find(k);
    if (it4 != people.end())
    {
        cout << "Was found id" << k << "in index " << distance(begin(people), it4) << " name " << (*it4).second << endl;
    }
    //remove_if(begin(people), end(people), [](auto el) {return el.second == "Matviy"; });
    cout << "\n\n";
    print(people);

    multimap<string, string> library
    {
        {"Iron Flame","Rebecca Yarros" },
        { "The Ever King", "LJ Andrews"},
        { "Harry Potter and the Philosopher's Stone","J.K. Rowling"},
        { "Harry Potter and the Philosopher's Stone","J.K. Rowling"},
    };

    printMultMap(library);

    library.insert({"Harry Potter and the Philosopher's Stone", "Test test" });
    printMultMap(library);
}