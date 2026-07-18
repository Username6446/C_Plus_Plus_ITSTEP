#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

void printVector(const vector<int>& v, const string& name) {
    cout << name << ": ";
    if (v.empty()) {
        cout << "(empty)";
    }
    else {
        for (int x : v) {
            cout << x << " ";
        }
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "\nEx 1" << endl;

    vector<int> v1;
    int n1, val;
    cout << "Enter the number of elements for v1: ";
    cin >> n1;
    cout << "Enter " << n1 << " integers for v1: ";
    for (int i = 0; i < n1; ++i) {
        cin >> val;
        v1.push_back(val);
    }

    vector<int> v2(10, 0);

    int n3;
    cout << "Enter the number of elements for v3: ";
    cin >> n3;
    vector<int> v3;
    for (int i = 0; i < n3; ++i) {
        v3.push_back(rand() % 100);
    }

    vector<int> v4 = v1;

    vector<int> v5;
    if (v3.size() >= 3) {
        v5.assign(v3.begin() + 1, v3.end() - 1);
    }
    else {
        cout << "Warning: v3 does not have enough elements to create v5 (needs at least 3)." << endl;
    }

    cout << "\nEx 2" << endl;
    printVector(v3, "v3");

    cout << "v1 in reverse order: ";
    if (!v1.empty()) {
        for (auto it = v1.rbegin(); it != v1.rend(); ++it) {
            cout << *it << " ";
        }
    }
    cout << endl;

    cout << "\nEx 3" << endl;

    for (size_t i = 0; i < v2.size(); ++i) {
        v2[i] = static_cast<int>(i) + 1;
    }
    printVector(v2, "v2 (filled)");

    auto rng = default_random_engine(static_cast<unsigned int>(time(0)));
    shuffle(v2.begin(), v2.end(), rng);
    printVector(v2, "v2 (shuffled)");

    if (v2.size() >= 2) {
        v2.erase(v2.begin() + 1);
        v2.pop_back();
    }
    printVector(v2, "v2 (after deletion)");

    cout << "\nEx 4" << endl;
    printVector(v4, "v4 (before)");

    int oldSize = v4.size();
    for (int i = 0; i < oldSize; ++i) {
        v4.insert(v4.begin() + i * 2, v4[i * 2]);
    }
    printVector(v4, "v4 (after doubling)");

    cout << "\nEx 5" << endl;
    printVector(v5, "v5 (old)");

    v5.clear();

    for (int x : v4) {
        if (x % 2 == 0) {
            v5.push_back(x);
        }
    }

    for_each(v5.begin(), v5.end(), [](int& n) {
        n /= 2;
        });

    printVector(v5, "v5 (new)");

    cout << "\nEx 6 " << endl;
    int target;
    cout << "Enter a value to search in v5: ";
    cin >> target;

    cout << "Positions of elements equal to " << target << ": ";
    bool found = false;
    for (auto it = v5.begin(); it != v5.end(); ++it) {
        if (*it == target) {
            cout << distance(v5.begin(), it) << " ";
            found = true;
        }
    }
    if (!found) cout << "not found";
    cout << endl;

    int countVal = count(v5.begin(), v5.end(), target);
    cout << "Count of value " << target << ": " << countVal << endl;

    cout << "\nEx 7" << endl;
    cout << "Before swap:" << endl;
    cout << "Size v4: " << v4.size() << ", Size v5: " << v5.size() << endl;

    v4.swap(v5);

    cout << "After swap:" << endl;
    printVector(v4, "v4");
    printVector(v5, "v5");

    return 0;
}