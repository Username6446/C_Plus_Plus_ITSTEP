#include <iostream>
#include "Remote.h"
using namespace std;
int main()
{
    TV samsung;
    Remote remote(&samsung);

    cout << "--- Testing Power ---" << endl;
    remote.power(); 
    samsung.showState();

    cout << "\n--- Testing Volume (+/-) ---" << endl;
    +remote;
    +remote;
    -remote;
    samsung.showState();

    cout << "\n--- Testing Channels (++ / --) ---" << endl;
    ++remote; 
    ++remote;
    samsung.showState();

    --remote; 
    samsung.showState();

    cout << "\n--- Testing Direct Channel Access (Friend) ---" << endl;
    remote.goChannel(5); 
    samsung.showState();

    remote.goChannel(99); 

    return 0;
}

